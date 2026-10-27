#ifndef LISTA_H
#define LISTA_H
#include "Wezel.h"
#include "Iterator.h"

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
    
    void usunZPoczatku();
    void usunZKonca();
    void usunPodIndeksem(int indeks);

    void wyswietl() const;
    void wyswietlOdwrotnie() const;
    void czysc();
    
    Iterator* pobierzIterator() const;
};
#endif