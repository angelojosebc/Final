#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Libro {
    long codigo;
    string titulo;
    string autor;
    int anio;
    string editorial;
public:
    Libro(long codigo = 0,
          string titulo = "",
          string autor = "",
          int anio = 0,
          string editorial = "") {
        this->codigo = codigo;
        this->titulo = titulo;
        this->autor = autor;
        this->anio = anio;
        this->editorial = editorial;
    }
    long    getCodigo() { return codigo; }
    string  getTitulo() { return titulo; }
    string  getAutor() { return autor; }
    int     getAnio() { return anio; }
    string  getEditorial() { return editorial; }
    void  setCodigo(long codigo) { this->codigo = codigo; }
    void  setTitulo(string titulo) { this->titulo = titulo; }
    void  setAutor(string autor) { this->autor = autor; }
    void  setAnio(int anio) { this->autor = autor; }
    void  setEditorial(string editorial) { this->editorial = editorial; }
    void GuardarEnArchivo(FILE* file) {
        int ltitulo = titulo.length();
        int lautor = autor.length();
        int leditorial = editorial.length();
        fprintf(file, "%ld\n",codigo);
        fprintf(file, "%d\n%s\n", ltitulo, titulo.c_str());
        fprintf(file, "%d\n%s\n", lautor, autor.c_str());
        fprintf(file, "%d\n", anio);
        fprintf(file, "%d\n%s\n", leditorial, editorial.c_str());
    }
    void LeerDeArchivo(FILE* file) {
        int ltitulo;
        int lautor;
        int leditorial;
        char* ttitulo;
        char* tautor;
        char* teditorial;
        fscanf(file, "%ld", &codigo);
        fscanf(file, "%d", &ltitulo);
        ttitulo = new char[ltitulo + 1];
        fgets(ttitulo, 1000, file);
        fscanf(file, "%d", &lautor);
        tautor = new char[lautor + 1];
        fgets(tautor, 1000, file);
        fscanf(file, "%d", &anio);
        fscanf(file, "%d", &leditorial);
        teditorial = new char[leditorial + 1];
        fgets(teditorial, 1000, file);
        titulo = string(ttitulo);
        editorial = string(teditorial);
        autor = string(tautor);
    }
};

class GestorLibros {
    list<Libro*> libros;
    bool compararParte(const char* a, const char* b) {
        int la = strlen(a);
        int lb = strlen(b);
        bool encontrado;
        for (int i = 0; i <= la - lb; ++i) {
            if (a[i] == b[0]) {
                encontrado = true;
                for (int j = 0; j < lb; ++j) {
                    if (b[j] != a[i + j]) {
                        encontrado = false;
                        break;
                    }
                }
                if (encontrado) return true;
            }
        }
        return false;
    }
public:
    GestorLibros() {}
    Libro* BuscarLibroPorTitulo(string titulo) {
        list<Libro*>::iterator it;
        for (it = libros.begin(); it != libros.end(); it++) {
            if (compararParte((*it)->getTitulo().c_str(), titulo.c_str())) {
                return *it;
            }
        }
        return nullptr;
    }
    bool RegistrarLibro(Libro* libro) {
        list<Libro*>::iterator it;
        for (it = libros.begin(); it != libros.end(); it++) {
            if ((*it)->getCodigo() == libro->getCodigo()) {
                return false;
            }
        }
        libros.push_back(libro);
        return true;
    }
    void LeerDeArchivo(FILE* file) {
        int total;
        fscanf(file, "%d", &total);
        libros.clear();
        for (int i = 0; i < total; ++i) {
            Libro* libro = new Libro();
            libro->LeerDeArchivo(file);
            libros.push_back(libro);
        }
    }
    void EscribirArchivo(FILE* file) {
        fprintf(file, "%d\n", libros.size());
        list<Libro*>::iterator it;
        for (it = libros.begin(); it != libros.end(); it++) {
            (*it)->GuardarEnArchivo(file);
        }
    }
};

int main() {
    FILE* archivo = fopen("examen.txt", "r+t");
    GestorLibros* gl = new GestorLibros();

    if (archivo != nullptr) {
        gl->LeerDeArchivo(archivo);
        fclose(archivo);
    }

    char op;
    do {
        cin >> op;
        switch (op) {
        case '1': 
            long cod;
            cin >> cod;
            gl->RegistrarLibro(new Libro(cod, "Hola mundo", "L", 200, "Coquito"));
            break;
        case '2': break;
        case 'S': cout << " ---- Bye Bye!! ----" << endl; break;
        default: cout << " ---- ERROROROR!! ----" << endl;
        }
    } while (op != 'S');

    archivo = fopen("examen.txt", "w+t");
    if (archivo != nullptr) {
        gl->EscribirArchivo(archivo);
        fclose(archivo);
    }

    system("pause");
    return 0;
}
