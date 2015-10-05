#include <iostream>
#include <list>

using namespace std;

template <class T>
class It {
public:
    T e;
    int n;
    T operator*() {
        return e;
    }
    void operator++() {
        cout << "moving to the next element!";
    }
};
int main() {
    list<float> numeros;
    float num;
    It<int> f;
    f.e = 99;
    int a = *f;
    cout << a;
    f++;
    do {
        cout << "ingrese un número: ";
        cin >> num;
        numeros.push_back(num);
    } while (num != 0.0f);

    cout << "Tamaño: " << numeros.size() << endl;
    list<float>::iterator it;
    for (it = numeros.begin(); it != numeros.end(); it++) {
        cout << " " << *it;
    }
    cout << endl;

    system("pause");
    return 0;
}
