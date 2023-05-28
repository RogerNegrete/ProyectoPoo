#include "boleto.h"

Cine *Boleto::getCine() const
{
    return cine;
}

void Boleto::setCine(Cine *newCine)
{
    cine = newCine;
}

Boleto::Boleto()
{

}

Boleto::Boleto(int sala, Pelicula* pelicula, char fila, int columna)
    : sala(sala), fila(fila), columna(columna), pelicula(pelicula)
{

}

int Boleto::getNumeroBoleto() const
{
    return numeroBoleto;
}

void Boleto::setNumeroBoleto(int newNumeroBoleto)
{
    numeroBoleto = newNumeroBoleto;
}


char Boleto::getFila() const
{
    return fila;
}

int Boleto::getColumna() const
{
    return columna;
}

Pelicula Boleto::getPelicula() const
{
    return *pelicula;
}


int Boleto::getSala() const
{
    return sala;
}
