#ifndef FABRYKA_H
#define FABRYKA_H
#include "Lista.h"
#include "Wezel.h"
#include "Iterator.h"

class Fabryka {
public:
    static Lista* lista();
    static Wezel* wezel(int w);
    static Iterator* iterator(Wezel* start);
};
#endif