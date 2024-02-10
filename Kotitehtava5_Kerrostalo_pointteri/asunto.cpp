#include "asunto.h"

Asunto::Asunto() {
    std::cout << "Asunto luotu" << std::endl;
    maarita(2, 100);
}

void Asunto::maarita(int asukasMaara, int neliot) {
    this->asukasMaara = asukasMaara;
    this->neliot = neliot;
    std::cout << "Asunto maaritelty - Asukkaita: " << asukasMaara << ", Neliot: " << neliot << std::endl;
}

double Asunto::laskeKulutus(double kulutus) {
    double kokonaisKulutus = kulutus * neliot;
    std::cout << "Kokonaiskulutus: " << kokonaisKulutus << std::endl;

    return kokonaisKulutus;
}

void Kerros::maarita(int asukasMaara, int neliot, int kerrosNumero) {
    std::cout << "Kerros luotu" << std::endl;
    Asunto::maarita(asukasMaara, neliot);
    this->kerrosNumero = kerrosNumero;
}

double Kerros::laskeKulutus(double kulutus) {
    double kerrosKulutus = Asunto::laskeKulutus(kulutus) + kerrosNumero;

    return kerrosKulutus;
}

void Katutaso::maarita(int asukasMaara, int neliot, int kerrosNumero, bool onkokatutila) {
    std::cout << "Katutaso luotu" << std::endl;
    Kerros::maarita(asukasMaara, neliot, kerrosNumero);
    this->onkoLiiketila = onkoLiiketila;
}

double Katutaso::laskeKulutus(double kulutus) {
    double katutasoKulutus = Kerros::laskeKulutus(kulutus) + (onkokatutila ? 10.0 : 0.0);

    return katutasoKulutus;
}

Kerrostalo::Kerrostalo() {
    std::cout << "Kerrostalo luotu" << std::endl;
    eka = new Katutaso();
    toka = new Kerros();
    kolmas = new Kerros();
}

void Kerrostalo::maaritaAsunnot() {
    eka->maarita(2, 100, 1, true);
    toka->maarita(2, 100, 2);
    kolmas->maarita(2, 100, 3);
}

double Kerrostalo::laskeKulutus(double hinta) {
    double kulutus = eka->laskeKulutus(hinta) + toka->laskeKulutus(hinta) + kolmas->laskeKulutus(hinta);
    std::cout << "Kerrostalon kokonaiskulutus: " << kulutus << std::endl;
    return kulutus;
}

int main() {
    Kerrostalo* kerrostalo = new Kerrostalo();

    double hinta = 1.0;
    kerrostalo->maaritaAsunnot();
    double kokonaiskulutus = kerrostalo->laskeKulutus(hinta);

    std::cout << "Kerrostalon kokonaiskulutus, kun hinta = " << hinta << " on " << kokonaiskulutus << std::endl;


    delete kerrostalo;

    return 0;
}
/*Lisääminen

Asunto, Kerros, ja Katutaso luokille on lisätty private-attribuutit (asukasMaara, neliot, kerrosNumero, onkoLiiketila) ja niihin liittyvät setterit (maarita-metodit).
Kerrostalo luokalla on nyt osoittimet eka, toka ja kolmas luokkiin Katutaso, Kerros ja Kerros vastaavasti.
main-funktiosta on poistettu suorat instanssit luokista. Sen sijaan Kerrostalo luokkaa luodaan heapista new-operaattorilla.
