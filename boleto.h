#ifndef BOLETO_H
#define BOLETO_H

class Cine;
#include "pelicula.h"

class Boleto
{
private:
    int numeroBoleto;
    int sala;
    char fila;
    int columna;
    Pelicula *pelicula;
    Cine* cine;

public:
    Boleto();
    Boleto(int sala, Pelicula* pelicula, char fila, int columna);
    int getSala() const;
    char getFila() const;
    int getColumna() const;
    Pelicula getPelicula() const;

    friend class Cine;

    int getNumeroBoleto() const;
    void setNumeroBoleto(int newNumeroBoleto);
    Cine *getCine() const;
    void setCine(Cine *newCine);
};

#endif // BOLETO_H
