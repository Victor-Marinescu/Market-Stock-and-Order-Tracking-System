#include "Produs.h"
int Produs::ID = 0;
Produs::Produs() : id(ID++)
{
    pret = 0.0;
    cantitate = 0;
    denumire[0] = '\0';
}
Produs &Produs::operator=(const Produs &other)
{
    if (this != &other)
    {
        strcpy(this->denumire, other.denumire);
        this->pret = other.pret;
        this->cantitate = other.cantitate;
    }
    return *this;
}

void Produs::setDenumire(const char *nume)
{
    strcpy(this->denumire, nume);
}
void Produs::setPret(const float pret)
{
    this->pret = pret;
}
void Produs::setCantitate(const int cantitate)
{
    this->cantitate = cantitate;
}


char *Produs::getDenumire()
{
    return (this->denumire);
}
float Produs::getPret() const
{
    return (this->pret);
}
int Produs::getCantitate() const
{
    return (this->cantitate);
}
int Produs::getID() const
{
    return (this->ID);
}


std::ifstream &operator>>(std::ifstream &in, Produs &p)
{
    in >> p.denumire >> p.pret >> p.cantitate;
    return in;
}
std::ofstream &operator<<(std::ofstream &out, const Produs &p)
{
    out << "\n"
        << p.id << ". " << p.denumire << ": " << p.cantitate << ", Pret: " << p.pret;

    return out;
}
// implementare clasa Produs