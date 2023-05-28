#include "pelicula.h"

Pelicula::Pelicula()
{

}

Pelicula::Pelicula(int id, string hora, string titulo, int duracion, bool estreno)
:id(id),titulo(titulo),duracion(duracion),estreno(estreno),hora(hora)
{

}

int Pelicula::getId() const
{
    return id;
}

void Pelicula::setId(int newId)
{
    id = newId;
}

const string &Pelicula::getTitulo() const
{
    return titulo;
}

void Pelicula::setTitulo(const string &newTitulo)
{
    titulo = newTitulo;
}

int Pelicula::getDuracion() const
{
    return duracion;
}

void Pelicula::setDuracion(int newDuracion)
{
    duracion=newDuracion;
}



bool Pelicula::getEstreno() const
{
    return estreno;
}

void Pelicula::setEstreno(bool newEstreno)
{
    estreno = newEstreno;
}

const string &Pelicula::getHora() const
{
    return hora;
}

void Pelicula::setHora(const string &newHora)
{

    hora = newHora;
}



