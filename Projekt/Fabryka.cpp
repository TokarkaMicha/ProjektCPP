#include "Fabryka.h"

Lista* Fabryka::lista() { return new Lista(); }
Wezel* Fabryka::wezel(int w) { return new Wezel(w); }
Iterator* Fabryka::iterator(Wezel* start) { return new Iterator(start); }