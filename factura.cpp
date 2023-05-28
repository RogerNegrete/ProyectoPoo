#include "factura.h"
#include "cine.h"


Factura::Factura()
{

}

Factura::Factura(const string &nombre, const string &telefono, const string &correo)
    : nombre(nombre), telefono(telefono), correo(correo)
{

}
Factura::~Factura()
{

}

void Factura::agregarBoleto(Boleto* boleto) {
    boletos.push_back(boleto);
}

void Factura::agregarComida(Bar const& comida) {
    comidaComprada.push_back(comida);
}
double Factura::calcularTotal() const {
    double total = 0.0;

    // Calcula el total de los boletos
    for (auto boleto : boletos) {
        total += boleto->getCine()->getPRECIO_BOLETO();
    }

    // Calcula el total de la comida
    for (const auto &comida : comidaComprada) {
        total += comida.precioComida;
    }

    return total;
}

string Factura::generarDescripcion() const {
    string descripcion;

    // Agrega la información de los boletos
    descripcion += "Boletos:\n";
    for (auto boleto : boletos) {
        descripcion += "  - Pelicula: " + boleto->getPelicula().getTitulo() + "\n";
        descripcion += "    Sala: " + to_string(boleto->getSala()) + "\n";
        descripcion += "    Asiento: " + to_string(boleto->getFila()) + ", " + to_string(boleto->getColumna()) + "\n";
        descripcion += "    Precio Boleto: $" + to_string(boleto->getCine()->getPRECIO_BOLETO()) + "\n\n";
    }

    // Agrega la información de la comida
    descripcion += "Comida:\n";
    for (const auto &comida : comidaComprada) {
        descripcion += "  - " + comida.getNombreComida() + " - $" + to_string(comida.getPrecioComida()) + "\n";
    }

    return descripcion;
}

string Factura::generarFactura() const {
    string factura;
    int anchoCuadrado = 50; // Ajusta el ancho del cuadrado según tus necesidades

    factura += string(anchoCuadrado, '=') + "\n";
    factura += "FACTURACION: M I C I N E...\n";
    factura += string(anchoCuadrado, '=') + "\n";
    factura += "Cliente: " + nombre + "\n";
    factura += "Teléfono: " + telefono + "\n";
    factura += "Correo: " + correo + "\n";
    factura += string(anchoCuadrado, '=') + "\n";
    factura += generarDescripcion();
    factura += string(anchoCuadrado, '-') + "\n";
    factura += "Total a pagar: $" + to_string(calcularTotal()) + "\n";
    factura += string(anchoCuadrado, '=') + "\n";

    return factura;
}

