#ifndef VISTA_H
#define VISTA_H
#include <iomanip>
#include "boleto.h"
#include "bar.h"
#include "factura.h"
class Vista
{
public:
    Vista();
    string imprimirBoleto(const Boleto& boleto) const;
    void menuBar(const vector<Bar>& menu);
    void imprimirComidaComprada(const string& comidaComprada) const;
    friend class Factura;
    string generarLinea(char caracter, int longitud) const;
    int calcularAnchoCuadrado() const;
};

#endif // VISTA_H
