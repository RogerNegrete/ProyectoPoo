#ifndef FACTURA_H
#define FACTURA_H
#include <string>
#include <vector>
#include "boleto.h"
#include "bar.h"


class Factura
{
private:
    string nombre;
    string telefono;
    string correo;
    vector<Boleto*> boletos;
    vector<Bar> comidaComprada;

public:
    Factura();
    Factura(const string& nombre, const string& telefono, const string& correo);
    ~Factura();
    void agregarBoleto(Boleto* boleto);
    void agregarComida(const Bar& comida);
    //Factura
    double calcularTotal() const;
    string generarDescripcion() const;
    string generarFactura() const;

};

#endif // FACTURA_H
