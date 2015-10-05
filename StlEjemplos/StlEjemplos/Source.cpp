#include <iostream>

#include <string>

using namespace std;

int main() {
    string mensaje;
    string mensaje2("hola");
    mensaje = "Hola"; // equivalente strcpy
    mensaje += ", mundo!"; // equivalente a strcat

    cout << mensaje << endl;
    cout << "Longitud de cadena: " << mensaje.length() << endl; // usando strlen
    if (mensaje == mensaje2) { // strcmp
        cout << "si" << endl;
    } else {
        cout << "no" << endl;
    }

    system("pause");

    return 0;
}