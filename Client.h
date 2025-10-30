#ifndef CLIENT_H
#define CLIENT_H

#include "Comanda.h"

class Client
{

    char nume[60];   // Numele clientului
    Comanda comanda; // comanda clientului

public:
    Client();
    Client &operator=(Client);

    // Setter methods
    void setNume(char *nume);
    void setComanda(Comanda comanda);
   
    // Getter methods
    char *getNume();
    Comanda getComanda();


    // Overloading fstream operators
    friend std::ifstream &operator>>(std::ifstream &in, Client &c);
    friend std::ofstream &operator<<(std::ofstream &out, Client &c);
    // TODO: de implementat
};

#endif
