#include "GestorPostres.h"

#include <iostream>
#include <stdio.h>

using namespace std;

void imprimirIngredienteEnConsola(CIngrediente* ingrediente) {
    cout << "Nombre: " << ingrediente->getNombre()
        << ", Cantidad: " << ingrediente->getCantidad()
        << endl;
}

void imprimirPostreEnConsola(CPostre* postre) {
    cout << "Id: " << postre->getId()
        << ", Nombre: " << postre->getNombre()
        << endl;
}
void AgregarPostre(CGestorPostre* gp) {
    string nombre;
    cout << "Ingrese el nombre del postre: ";
    cin >> nombre; // TODO usar leer cadena considerando espacios en blanco
    CPostre* p = gp->InsertarPostre(nombre);
    if (p != nullptr) {
        char conf;
        do {
            string nombreIngrediente;
            int cantidad;
            cout << "Ingrese el nombre del ingrediente para "
                << nombre << ": ";
            cin >> nombreIngrediente;
            cout << "Ingrese la cantidad de "
                << nombreIngrediente << " para "
                << nombre << ": ";
            cin >> cantidad;
            gp->InsertarIngrediente(p, nombreIngrediente, cantidad);
            cout << "Desea ingresar más ingredientes? (s)i o (n)o: ";
            cin >> conf;
        } while (conf != 'n');
    } else {
        cout << " --- No se pudo agregar el postre! --- " << endl;
    }
}
void AgregarIngrediente(CGestorPostre* gp) {
    string nombre;
    cout << "Ingrese el nombre del postre: ";
    cin >> nombre; // TODO usar leer cadena considerando espacios en blanco
    CPostre* p = gp->BuscarPostre(nombre);
    char conf;
    do {
        string nombreIngrediente;
        int cantidad;
        cout << "Ingrese el nombre del ingrediente para "
            << nombre << ": ";
        cin >> nombreIngrediente;
        cout << "Ingrese la cantidad de "
            << nombreIngrediente << " para "
            << nombre << ": ";
        cin >> cantidad;
        gp->InsertarIngrediente(p, nombreIngrediente, cantidad);
        cout << "Desea ingresar más ingredientes? (s)i o (n)o: ";
        cin >> conf;
    } while (conf != 'n');
}
void MostrarIngredientes(CGestorPostre* gp) {
    string nombre;
    cout << "Ingrese el nombre del postre: ";
    cin >> nombre; // TODO usar leer cadena considerando espacios en blanco
    gp->MostrarIngredientesDePostre(nombre);
}
void MostrarPostres(CGestorPostre* gp) {
    string nombre;
    cout << "Ingrese el nombre del ingrediente: ";
    cin >> nombre; // TODO usar leer cadena considerando espacios en blanco
    gp->MostrarPostresPorIngrediente(nombre);
}
void EliminarPostre(CGestorPostre*gp)
{
	string nombre;
	cout << "Ingrese el nombre del ingrediente: ";
	cin >> nombre; // TODO usar leer cadena considerando espacios en blanco
	gp->Eliminar_postrespor_ingrediente(nombre);
}
int main() {
    char op;
    CGestorPostre* gp = new CGestorPostre(
        imprimirIngredienteEnConsola,
        imprimirPostreEnConsola);
    do {
		
		cout << "MENU" << endl
            << "****" << endl
            << endl
            << "1. Nuevo postre" << endl
            << "2. Agregar ingrediente" << endl
            << "3. Mostrar ingredientes de un postre" << endl
            << "4. Mostrar postres dado ingrediente" << endl
			<< "5. Eliminar postres dado ingrediente"<<endl
            << endl
            << "s. Salir" << endl
            << endl
            << "Escoja una opcion: ";

        cin >> op;
        switch (op) {
        case '1': AgregarPostre(gp); break;
        case '2': AgregarIngrediente(gp); break;
        case '3': MostrarIngredientes(gp); break;
        case '4': MostrarPostres(gp); break;
		case '5':EliminarPostre(gp); break;
        case 's': cout << " --- Bye bye! --- " << endl; break;
        default: cout << " --- Opción incorrecta! --- " << endl;
        }
    } while (op != 's');
    system("pause");
    return 0;
}