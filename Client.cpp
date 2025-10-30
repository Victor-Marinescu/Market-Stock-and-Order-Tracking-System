#include "Client.h"

Client::Client()
{
    nume[0] = '\0';
}

Client &Client::operator=(Client c)
{
    strcpy(this->nume, nume);
    this->comanda = comanda;
    return *this;
}
void Client::setNume(char *nume)
{
    strcpy(this->nume, nume);
}
void Client::setComanda(Comanda comanda)
{
    this->comanda = comanda;
}

char *Client::getNume()
{
    return (this->nume);
}
Comanda Client::getComanda()
{
    return (this->comanda);
}

std::ifstream &operator>>(std::ifstream &in, Client &c)
{
    char s[60];
    in >> s;
    strcpy(c.nume, s);
    in >> s;
    strcat(c.nume, " ");
    strcat(c.nume, s);
    in >> c.comanda;
    in.get();
    return in;
}
std::ofstream &operator<<(std::ofstream &out, Client &c)
{
    // std::cout<<c.comanda.getID();
    float s = 0;
    out << "Nume: " << c.nume << "\nComanda ID: " << c.comanda.getID() << "\nData comenzii: " << c.comanda.getZi() << "/" << c.comanda.getLuna() << "/" << c.comanda.getAn() << "\nProduse comandate:\n";
    for (int i = 0; i < c.comanda.getNrProduse(); i++)
    {
        out << c.comanda.getProdus(i).getCantitate() << " X " << c.comanda.getProdus(i).getDenumire() << " (" << c.comanda.getProdus(i).getPret() << ")\n";
        s += c.comanda.getProdus(i).getPret() * c.comanda.getProdus(i).getCantitate();
    }
    out << "Total comanda: " << s << " RON";
    return out;
}
// implementare clasa Client
