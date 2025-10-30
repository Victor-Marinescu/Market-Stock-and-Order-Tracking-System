#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <cstring>
#include <fstream>
class Produs
{
    const int id;          // Cod unic al produsului
    char denumire[50];     // Denumirea produsului (șir de caractere)
    float pret;            // Prețul produsului
    int cantitate;         // Cantitatea pe stoc a produsului
    static int ID;         // Static member for unique ID generation

public:
    Produs();
    Produs &operator=(const Produs &);

    // Overloading fstream operators
    friend std::ifstream &operator>>(std::ifstream &, Produs &);
    friend std::ofstream &operator<<(std::ofstream &, const Produs &);

    // Setter methods
    void setDenumire(const char *nume);
    void setPret(const float pret);
    void setCantitate(const int cantitate);

    // Getter methods
    char *getDenumire();
    int getCantitate() const;
    int getID() const;
    float getPret() const;
    int get_ID();
};  

#endif
