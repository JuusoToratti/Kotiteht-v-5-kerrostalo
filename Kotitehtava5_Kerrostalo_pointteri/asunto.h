#ifndef ASUNTO_H
#define ASUNTO_H

#include <iostream>

class Asunto {
public:
    Asunto();
    void maarita(int asukasMaara, int neliot);
    virtual double laskeKulutus(double kulutus);

private:
    int asukasMaara;
    int neliot;
};

class Kerros : public Asunto {
public:
    void maarita(int asukasMaara, int neliot, int kerrosNumero);
    double laskeKulutus(double kulutus) override;

private:
    int kerrosNumero;
};

class Katutaso : public Kerros {
public:
    void maarita(int asukasMaara, int neliot, int kerrosNumero, bool onkoLiiketila);
    double laskeKulutus(double kulutus) override;

private:
    bool onkokatutila;
};

class Kerrostalo {
public:
    Kerrostalo();
    void maaritaAsunnot();
    double laskeKulutus(double hinta);

private:
    Katutaso* eka;
    Kerros* toka;
    Kerros* kolmas;
};

#endif
