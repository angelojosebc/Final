#ifndef __GESTORPOSTRES_H__
#define __GESTORPOSTRES_H__

#include "postre.h"

class CGestorPostre {
    std::list<CPostre*>* postres;
    void(*mostrarIngrediente)(CIngrediente*);
    void(*mostrarPostre)(CPostre*);
	void(*eliminarPostre)(CPostre*);
public:
    CGestorPostre(void(*mostrarIngrediente)(CIngrediente*),
        void(*mostrarPostre)(CPostre*)) {
        postres = new std::list<CPostre*>();
        this->mostrarIngrediente = mostrarIngrediente;
        this->mostrarPostre = mostrarPostre;
    }
    ~CGestorPostre() {
        delete postres;
		
    }
    CPostre* InsertarPostre(std::string nombre) {
        int max = 0;
        std::list<CPostre*>::iterator it = postres->begin();
        for (; it != postres->end(); it++)
            if ((*it)->getId() > max)
                max = (*it)->getId();
        CPostre* postre = new CPostre(max + 1, nombre);
        if (postre == nullptr)
            return nullptr;
        postres->push_back(postre);
        return postre;
    }
    CPostre* BuscarPostre(int id) {
        std::list<CPostre*>::iterator it = postres->begin();
        for (; it != postres->end(); it++)
            if ((*it)->getId() == id)
                return (*it);
        return nullptr;
    }
    CPostre* BuscarPostre(std::string nombre) {
        std::list<CPostre*>::iterator it = postres->begin();
        for (; it != postres->end(); it++)
            if ((*it)->getNombre() == nombre)
                return (*it);
        return nullptr;
    }
    CIngrediente* InsertarIngrediente(CPostre* postre,
        std::string nombre,
        int cantidad) {
        if (postre != nullptr) {
            postre->getIngredientes()->push_back(
                new CIngrediente(nombre, cantidad));
        }
        return nullptr;
    }
    CIngrediente* InsertarIngrediente(int idPostre,
        std::string nombre,
        int cantidad) {
        CPostre* postre = BuscarPostre(idPostre);
        InsertarIngrediente(postre, nombre, cantidad);
    }
    CIngrediente* InsertarIngrediente(std::string nombrePostre,
        std::string nombre,
        int cantidad) {
        CPostre* postre = BuscarPostre(nombrePostre);
        InsertarIngrediente(postre, nombre, cantidad);
    }
    void MostrarIngredientesDePostre(std::string nombrePostre) {
        CPostre* postre = BuscarPostre(nombrePostre);
        if (postre != nullptr) {
            std::list<CIngrediente*>::iterator it;
            it = postre->getIngredientes()->begin();
            for (; it != postre->getIngredientes()->end(); it++)
                mostrarIngrediente(*it);
        }
    }
    void MostrarPostresPorIngrediente(std::string nombreIngrediente) {
        std::list<CPostre*>::iterator it = postres->begin();
        for (; it != postres->end(); it++)
            if (ContieneIngrediente(*it, nombreIngrediente))
                mostrarPostre(*it);
    }
    bool ContieneIngrediente(CPostre* postre, std::string nombreIngrediente) {
        std::list<CIngrediente*>::iterator it;
        it = postre->getIngredientes()->begin();
        for (; it != postre->getIngredientes()->end(); it++)
            if ((*it)->getNombre() == nombreIngrediente)
                return true;
        return false;
    }
	void Eliminar_postrespor_ingrediente(std::string nombreIngrediente)
	{
		std::list<CPostre*>::iterator it = postres->begin();
		for (; it != postres->end(); it++)
			if (ContieneIngrediente(*it, nombreIngrediente))
				eliminarPostre(*it);
	}
};

#endif