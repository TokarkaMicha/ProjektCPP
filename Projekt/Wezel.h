#ifndef WEZEL_H
#define WEZEL_H

class Wezel {
public:
    int wartosc;
    Wezel* nast;
    Wezel* poprz;

    Wezel(int w);
};
#endif