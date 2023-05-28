#ifndef BAR_H
#define BAR_H
#include <string>
#include <iostream>
using namespace std;
class Bar
{
public:
    Bar(int idComida,string nombreComida, double precioComida);
    ~Bar();
    int idComida=0;
    string nombreComida;
    double precioComida=0;

    string getNombreComida() const;
    int getIdComida() const;
    double getPrecioComida() const;
};

#endif // BAR_H
