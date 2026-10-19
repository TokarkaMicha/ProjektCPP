#ifndef LISTA_H
#define LISTA_H
#include "Wezel.h"

class Lista {
private:
    Wezel* glowa;
    Wezel* ogon;
    int rozmiar;
public:
    Lista();
    ~Lista();

    void dodajNaPoczatek(int w);
    void dodajNaKoniec(int w);
    void dodajPodIndeks(int indeks, int w);
    void wyswietl() const;
};
#endif