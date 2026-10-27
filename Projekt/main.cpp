#include <iostream>
#include "Fabryka.h"
#include "Lista.h"
#include "Iterator.h"
using namespace std;
int main() {
    Lista* mojaLista = Fabryka::lista();

    cout << "--- Test dodawania elementow ---\n";
    mojaLista->dodajNaKoniec(799);
    mojaLista->dodajNaKoniec(67);
    mojaLista->dodajNaKoniec(60);
    mojaLista->dodajNaKoniec(11);
    mojaLista->wyswietl();
    mojaLista->wyswietlOdwrotnie();

    cout << "\n--- Test usuwania z poczatku i konca ---\n";
    mojaLista->usunZPoczatku();
    mojaLista->usunZKonca();
    mojaLista->wyswietl();

    cout << "\n--- Test czyszczenia listy ---\n";
    mojaLista->czysc();
    mojaLista->wyswietl();
    
    cout << "--- Test dodawania elementow ---\n";
    mojaLista->dodajNaKoniec(321);
    mojaLista->dodajNaKoniec(799);
    mojaLista->dodajNaKoniec(67);
    mojaLista->dodajNaKoniec(11);

    cout << "\n--- 3. Test iteratora (nastepny i poprzedni element) ---\n";
    Iterator* it = mojaLista->pobierzIterator();
    if (it->jest()) {
        cout << "Aktualny element: " << it->pobierz() << "\n";
        it->dalej();
        cout << "Nastepny element: " << it->pobierz() << "\n";
        it->dalej();
        cout << "Nastepny element: " << it->pobierz() << "\n";
        it->wstecz();
        cout << "Poprzedni element: " << it->pobierz() << "\n";
    }
    delete it;

    cout << "\n--- 4. Usuwanie spod wskazanego indeksu ---\n";
    mojaLista->usunPodIndeksem(2);
    mojaLista->wyswietl();

    cout << "\n--- 5. Usuwanie z poczatku i konca ---\n";
    mojaLista->usunZPoczatku();
    mojaLista->usunZKonca();
    mojaLista->wyswietl();

    cout << "\n--- 6. Czyszczenie calej listy ---\n";
    mojaLista->czysc();
    mojaLista->wyswietl();

    delete mojaLista;
    return 0;
}