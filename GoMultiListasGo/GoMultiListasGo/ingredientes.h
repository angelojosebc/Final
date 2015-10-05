#ifndef __INGREDIENTES_H__
#define __INGREDIENTES_H__

#include <string>

class CIngrediente {
    std::string nombre;
    int cantidad;
public:
    CIngrediente(std::string nombre = "", int cantidad = 0) {
        this->nombre = nombre;
        this->cantidad = cantidad;
    }
    ~CIngrediente() {}

    std::string getNombre() { return nombre; }
    int getCantidad() { return cantidad; }
    void setNombre(std::string nombre) { this->nombre = nombre; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }
};

#endif