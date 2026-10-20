#include <iostream>
#include "Fabryka.h"
#include "Lista.h"
using namespace std;
int main() {
    Lista* mojaLista = Fabryka::lista();

    cout << "--- 1. Dodawanie elementow na poczatek ---\n";
    mojaLista->dodajNaPoczatek(20);
    mojaLista->dodajNaPoczatek(10);
    mojaLista->wyswietl();

    cout << "\n--- 2. Dodawanie elementow na koniec ---\n";
    mojaLista->dodajNaKoniec(30);
    mojaLista->dodajNaKoniec(40);
    mojaLista->wyswietl();

    cout << "\n--- 3. Dodawanie pod indeks 2 (Wartosc: 25) ---\n";
    mojaLista->dodajPodIndeks(2, 25);
    mojaLista->wyswietl();

    delete mojaLista;

    return 0;
}