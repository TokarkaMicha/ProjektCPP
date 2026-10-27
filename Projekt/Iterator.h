#ifndef ITERATOR_H
#define ITERATOR_H
#include "Wezel.h"

class Iterator {
private:
    Wezel* akt;
public:
    Iterator(Wezel* start);
    bool jest() const;
    void dalej();
    void wstecz();
    int pobierz() const;
    Wezel* pobierzWezel() const;
};
#endif