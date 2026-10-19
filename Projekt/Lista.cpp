#include "Lista.h"
#include "Fabryka.h"
#include <iostream>

Lista::Lista() : glowa(nullptr), ogon(nullptr), rozmiar(0) {}

Lista::~Lista() {
    while (glowa) {
        Wezel* tmp = glowa;
        glowa = glowa->nast;
        delete tmp;
    }
}

void Lista::dodajNaPoczatek(int w) {
    Wezel* n = Fabryka::wezel(w);
    if (!glowa) {
        glowa = ogon = n;
    } else {
        n->nast = glowa;
        glowa->poprz = n;
        glowa = n;
    }
    rozmiar++;
}

void Lista::dodajNaKoniec(int w) {
    Wezel* n = Fabryka::wezel(w);
    if (!ogon) {
        glowa = ogon = n;
    } else {
        ogon->nast = n;
        n->poprz = ogon;
        ogon = n;
    }
    rozmiar++;
}

void Lista::dodajPodIndeks(int indeks, int w) {
    if (indeks <= 0) {
        dodajNaPoczatek(w);
        return;
    }
    if (indeks >= rozmiar) {
        dodajNaKoniec(w);
        return;
    }

    Iterator* it = Fabryka::iterator(glowa);
    for (int i = 0; i < indeks; ++i) {
        it->dalej();
    }

    Wezel* akt = it->pobierzWezel();
    Wezel* n = Fabryka::wezel(w);

    n->poprz = akt->poprz;
    n->nast = akt;
    if (akt->poprz) akt->poprz->nast = n;
    akt->poprz = n;

    delete it;
    rozmiar++;
}

void Lista::wyswietl() const {
    if (!glowa) {
        std::cout << "Lista jest pusta.\n";
        return;
    }
    Iterator* it = Fabryka::iterator(glowa);
    std::cout << "Lista (od poczatku): ";
    while (it->jest()) {
        std::cout << "[" << it->pobierz() << "] ";
        it->dalej();
    }
    std::cout << "\n";
    delete it;
}