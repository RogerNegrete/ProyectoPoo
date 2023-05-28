#ifndef CINE_H
#define CINE_H

#include "sala.h"
#include "boleto.h"
#include "pelicula.h"
#include "vista.h"
#include "bar.h"
#include "factura.h"
#include <iostream>
#include <vector>
#include <string>

class Cine
{
private:
    Vista* vista;
    Factura facturaCliente;
    const int CARTELERA=10;
    vector<Pelicula*>* peliculas = new vector<Pelicula*>(CARTELERA);
    vector<Sala> salas;
    //Boletos
    vector<int> boletosPorSala;
    vector<vector<Boleto*>> boletosVendidos;
    const float PRECIO_BOLETO=3.15;
    float boletosCantidad=0;
    // Bar
    vector<Bar>menu;
    vector<Bar>compras;
    vector<vector<Bar>> comidasCompradasPorSala;

public:

    Cine();
    Cine(const Boleto&asiento);
    ~Cine();
    string mostrarCartelera();
    string mostrarSala(int peliculaId);
    void ocuparAsiento(int peliculaId, int fila, int columna);
    bool comprarBoleto(int sala, char fila, int columna, Boleto*& boletoComprado);
    string mostrarBoletosComprados(int sala);
    float getPRECIO_BOLETO() const;
    //Bar
    bool ordenComida(int sala, const string& nombreComida);
    void agregarComidaAlMenu(const Bar& comida);
    string mostrarComidaComprada(int sala) const;
    const vector<Bar> &getMenu() const;
    //Factura
    Factura* generarFactura(int sala, const string& nombre, const string& telefono, const string& correo);
};
#endif // CINE_H
