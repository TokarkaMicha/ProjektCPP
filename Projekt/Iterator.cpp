#include "Iterator.h"

Iterator::Iterator(Wezel* start) : akt(start) {}
bool Iterator::jest() const { return akt != nullptr; }
void Iterator::dalej() { if (akt) akt = akt->nast; }
void Iterator::wstecz() { if (akt) akt = akt->poprz; }
int Iterator::pobierz() const { return akt ? akt->wartosc : -1; }
Wezel* Iterator::pobierzWezel() const { return akt; }