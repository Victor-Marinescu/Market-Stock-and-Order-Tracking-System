#include "Comanda.h"
int Comanda::ID_c = 0;
Comanda::Comanda()
{
    id = ID_c++;
    zi = luna = an = nrProduse = 0;
    // produse=new Produs[nrProduse];
}

std::ifstream &operator>>(std::ifstream &in, Comanda &c)
{

    in >> c.zi >> c.luna >> c.an >> c.nrProduse;
    c.produse = new Produs[c.nrProduse];
    in.get();
    for (int i = 0; i < c.nrProduse; i++)
    {
        char s[50];
        in >> s;
        c.produse[i].setDenumire(s);

        int x;
        in >> x;
        c.produse[i].setCantitate(x);
    }
    return in;
}



void Comanda::setID(const int id)
{
    this->id = id;
}
void Comanda::setNrProduse(const int nr)
{
    this->nrProduse = nr;
}
void Comanda::setZi(const int zi)
{
    this->zi = zi;
}
void Comanda::setLuna(const int luna)
{
    this->luna = luna;
}
void Comanda::setAn(const int an)
{
    this->an = an;
}

int Comanda::getID()
{
    return (this->id);
}
int Comanda::getZi()
{
    return (this->zi);
}
int Comanda::getLuna()
{
    return (this->luna);
}
int Comanda::getAn()
{
    return (this->an);
}
int Comanda::getNrProduse()
{
    return (this->nrProduse);
}
Produs Comanda::getProdus(int i)
{
    return (this->produse[i]);
}
Comanda &Comanda::operator=(Comanda)
{
    this->id = id;
    this->zi = zi;
    this->luna = luna;
    this->an = an;
    this->nrProduse = nrProduse;
    this->produse = produse;
    return *this;
}


void scad_stoc(const Comanda &c, Produs *p, int n)
{

    for (int i = 0; i < c.nrProduse; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(c.produse[i].getDenumire(), (p)[j].getDenumire()) == 0)
            {
                c.produse[i].setPret(p[j].getPret());
                (p)[j].setCantitate((p)[j].getCantitate() - c.produse[i].getCantitate());
            }
        }
    }
}

// implementare clasa Comanda
