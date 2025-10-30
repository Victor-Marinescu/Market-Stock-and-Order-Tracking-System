#ifndef COMANDA_H
#define COMANDA_H

#include "Produs.h"

class Comanda
{
protected:
    int id;
    int zi, luna, an; // Data comenzii
    int nrProduse;    // Numarul total de produse din comanda
    Produs *produse;  // Vector alocat dinamic pentru produsele din comanda
    static int ID_c;

public:
    Comanda();

    Comanda &operator=(Comanda);

    // Overloading fstream operators
    friend std::ifstream &operator>>(std::ifstream &in, Comanda &c);
    friend std::ostream &operator<<(std::ostream &, const Comanda &);

    // Setter methods
    void setID(const int id);
    void setNrProduse(const int nr);
    void setZi(const int zi);
    void setLuna(const int luna);
    void setAn(const int an);

    // Getter methods
    int getID();
    int getZi();
    int getLuna();
    int getAn();
    int getNrProduse();
    Produs getProdus(int i);

    friend void scad_stoc(const Comanda &c, Produs *p, int n);

    // TODO: de implementat
};

#endif
