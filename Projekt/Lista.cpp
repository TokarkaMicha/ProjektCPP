#include "Lista.h"
#include "Fabryka.h"
#include <iostream>

Lista::Lista() : glowa(nullptr), ogon(nullptr), rozmiar(0) {}

Lista::~Lista() {
    czysc();
}

void Lista::czysc() {
    while (glowa) {
        usunZPoczatku();
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
    if (indeks <= 0) { dodajNaPoczatek(w); return; }
    if (indeks >= rozmiar) { dodajNaKoniec(w); return; }

    Iterator* it = Fabryka::iterator(glowa);
    for (int i = 0; i < indeks; ++i) it->dalej();

    Wezel* akt = it->pobierzWezel();
    Wezel* n = Fabryka::wezel(w);

    n->poprz = akt->poprz;
    n->nast = akt;
    if (akt->poprz) akt->poprz->nast = n;
    akt->poprz = n;

    delete it;
    rozmiar++;
}

void Lista::usunZPoczatku() {
    if (!glowa) return;
    Wezel* tmp = glowa;
    glowa = glowa->nast;
    if (glowa) glowa->poprz = nullptr;
    else ogon = nullptr;
    delete tmp;
    rozmiar--;
}

void Lista::usunZKonca() {
    if (!ogon) return;
    Wezel* tmp = ogon;
    ogon = ogon->poprz;
    if (ogon) ogon->nast = nullptr;
    else glowa = nullptr;
    delete tmp;
    rozmiar--;
}

void Lista::usunPodIndeksem(int indeks) {
    if (indeks < 0 || indeks >= rozmiar || !glowa) return;
    if (indeks == 0) { usunZPoczatku(); return; }
    if (indeks == rozmiar - 1) { usunZKonca(); return; }

    Iterator* it = Fabryka::iterator(glowa);
    for (int i = 0; i < indeks; ++i) it->dalej();

    Wezel* akt = it->pobierzWezel();
    akt->poprz->nast = akt->nast;
    akt->nast->poprz = akt->poprz;
    
    delete akt;
    delete it;
    rozmiar--;
}

void Lista::wyswietl() const {
    if (!glowa) {
        std::cout << "Lista jest pusta.\n";
        return;
    }
    Iterator* it = Fabryka::iterator(glowa);
    std::cout << "Lista: ";
    while (it->jest()) {
        std::cout << "[" << it->pobierz() << "] ";
        it->dalej();
    }
    std::cout << "\n";
    delete it;
}

void Lista::wyswietlOdwrotnie() const {
    if (!ogon) {
        std::cout << "Lista jest pusta.\n";
        return;
    }
    Iterator* it = Fabryka::iterator(ogon);
    std::cout << "Lista (od konca): ";
    while (it->jest()) {
        std::cout << "[" << it->pobierz() << "] ";
        it->wstecz();
    }
    std::cout << "\n";
    delete it;
}

Iterator* Lista::pobierzIterator() const {
    return Fabryka::iterator(glowa);
}