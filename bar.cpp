#include "bar.h"

Bar::Bar(int idComida, string nombreComida, double precioComida)
{
    this->idComida=idComida;
    this->nombreComida = nombreComida;
    this->precioComida= precioComida;

}

Bar::~Bar()
{

}

int Bar::getIdComida() const
{
    return idComida;
}

string Bar::getNombreComida() const
{
    return nombreComida;
}

double Bar::getPrecioComida() const
{
    return precioComida;
}
