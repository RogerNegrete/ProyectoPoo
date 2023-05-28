#include "sala.h"
Sala::Sala(int pelicula, char *filas, int numero) : numero(numero) {
    for (int i = 0; i < 5; i++) {
        this->filas[i] = filas[i];
    }

    // Inicializar los asientos como disponibles (true)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            asientos[i][j] = true;
        }
    }
}

int Sala::getNumero() const
{
    return numero;
}

const char *Sala::getFilas() const
{
    return filas;
}
void Sala::cambiarEstadoAsiento(int fila, int columna) {
    if (fila >= 0 && fila < 5 && columna >= 0 && columna < 5) {
        asientos[fila][columna] = !asientos[fila][columna];
    }
}
bool Sala::getAsiento(int fila, int columna) const {
    if (fila >= 0 && fila < 5 && columna >= 0 && columna < 5) {
        return asientos[fila][columna];
    }
    return false;
}

