#ifndef __POSTRE_H__
#define __POSTRE_H__

#include "ingredientes.h"
#include <list>

class CPostre {
    int id;
    std::string nombre;
    std::list<CIngrediente*>* ingredientes;
public:
    CPostre(int id = 0,
        std::string nombre = "") {
        this->id = id;
        this->nombre = nombre;
        ingredientes = new std::list<CIngrediente*>();
    }
    ~CPostre() {
        delete ingredientes;
    }
    int getId() { return id; }
    std::string getNombre() { return nombre; }
    std::list<CIngrediente*>* getIngredientes() {
        return ingredientes;
    }
    void setId(int id) { this->id = id; }
    void setNombre(std::string nombre) { this->nombre = nombre; }
};

#endif