#include <iostream>
#include <fstream>

#include "Client.h"

int main(int argc, char *argv[])
{

    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;
    std::ifstream stoc(argv[1]);
    std::ifstream clienti(argv[2]);

    // std::ifstream stoc("teste/input/test5/produse.txt");
    // std::ifstream clienti("teste/input/test5/clienti.txt");
    std::ofstream stoc_ramas("output_stoc_ramas.txt");
    std::ofstream output_comenzi("output_comenzi.txt");

    int nr_prod = 0;
    stoc >> nr_prod;

    int nr_comenzi = 0;
    clienti >> nr_comenzi;
    clienti.get();

    Produs *p;
    p = new Produs[nr_prod];

    Client *c;
    c = new Client[nr_comenzi];

    for (int i = 0; i < nr_prod; i++)
    {
        stoc >> p[i];
    }
    // caz limita de 0 clienti
    if (nr_comenzi == 0)
    {
        output_comenzi << "Nu exista clienti in magazin.";
    }
    //cu fiecare citire de comanda se scade stoc
    for (int i = 0; i < nr_comenzi; i++)
    {
        clienti >> c[i];
        scad_stoc(c[i].getComanda(), p, nr_prod);
    }
    // output
    stoc_ramas << "Stoc ramas";
    for (int i = 0; i < nr_prod; i++)
    {
        stoc_ramas << p[i];
    }

    for (int i = 0; i < nr_comenzi; i++)
    {
        c[i].getComanda().setID(i);
        output_comenzi << c[i];

        if (i < nr_comenzi - 1)
            output_comenzi << "\n\n";
    }
    
    // TODO: nu scrieti cod functional aici, implementati clasele sau functii care sa rezolve
    //  pastrati main-ul cat mai curat si simplu de inteles
    return 0;
}
