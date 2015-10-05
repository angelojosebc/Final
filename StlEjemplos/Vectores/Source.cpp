#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<float> numeros;

    cout << "Capacidad: " << numeros.capacity() << endl;
    cout << "Tamaño: " << numeros.size() << endl;

    for (int i = 0; i < 100; ++i) {
        numeros.push_back(i / 33.0f);
        cout << "I: " << i << endl;
        cout << "Capacidad: " << numeros.capacity() << endl;
        cout << "Tamaño: " << numeros.size() << endl;
        //numeros[i] = i / 33.0f;
    }
    cout << "Capacidad: " << numeros.capacity() << endl;
    cout << "Tamaño: " << numeros.size() << endl;

    for (int i = 0; i < 10; ++i) {
        cout << " " << numeros[i];
    }
    cout << endl;

    system("pause");
    return 0;
}