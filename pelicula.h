#ifndef PELICULA_H
#define PELICULA_H
#include <iostream>
#include <vector>
using namespace std;

class Pelicula
{
private:
    int id;
    string titulo;
    int duracion;
    bool estreno;
    string hora;
    Pelicula*pelicula;
public:
    Pelicula();
    Pelicula(int id, string hora, string titulo, int duracion, bool estreno);

    int getId() const;
    void setId(int newId);
    const string &getTitulo() const;
    void setTitulo(const string &newTitulo);
    int getDuracion() const;
    void setDuracion(int newDuracion);
    bool getEstreno() const;
    void setEstreno(bool newEstreno);
    const string &getHora() const;
    void setHora(const string &newHora);
};

#endif // PELICULA_H
