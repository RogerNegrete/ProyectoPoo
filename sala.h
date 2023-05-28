#ifndef SALA_H
#define SALA_H
#include "bar.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class  Sala
{
private:
    char filas[5];
    int numero;
    bool asientos[5][5];
    vector<Bar> compras;

public:
    Sala(int pelicula, char *filas, int numero);

friend class Cine;

int getNumero() const;
const char* getFilas() const;
void cambiarEstadoAsiento(int fila, int columna);
bool getAsiento(int fila, int columna) const;


};

#endif // SALA_H
