#include "vista.h"
#include "boleto.h"
Vista::Vista()
{

}

string Vista::imprimirBoleto(const Boleto& boleto) const {
    string boletoInfo;
    string linea = "=========================================================\n";

    boletoInfo += "Boleto " + to_string(boleto.getNumeroBoleto()) + "\n";
    boletoInfo += linea;

    string sala = "|| Sala: " + to_string(boleto.getSala());
    sala.resize(56, ' ');
    sala += "||\n";
    boletoInfo += sala;

    string hora = "|| Hora: " + boleto.getPelicula().getHora();
    hora.resize(56, ' ');
    hora += "||\n";
    boletoInfo += hora;

    string asiento = "|| Asiento: " + string(1, boleto.getFila()) + to_string(boleto.getColumna());
    asiento.resize(56, ' ');
    asiento += "||\n";
    boletoInfo += asiento;

    string pelicula = "|| Pelicula: " + boleto.getPelicula().getTitulo();
    pelicula.resize(56, ' ');
    pelicula += "||\n";
    boletoInfo += pelicula;

    boletoInfo += linea;

    return boletoInfo;
}

void Vista::menuBar(const vector<Bar>& menu)
{
    cout << "Menú del Bar:\n";
    for (const Bar& comida : menu) {
        cout << "Opcion de Comida: " << comida.idComida<<"\n";
        cout << "Nombre: " << comida.nombreComida << "\n";
        cout << "Precio: " << comida.precioComida << "\n";
        cout << "---------------------\n";
    }
}
