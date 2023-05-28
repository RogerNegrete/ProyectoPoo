#include "cine.h"


Cine::Cine()
{
    vista = new Vista();
    peliculas = new vector<Pelicula*>;
    boletosPorSala.resize(CARTELERA, 0);

    //Peliculas
    peliculas->push_back( new Pelicula(1,"18:00", "Avengers: Endgame", 117, true));
    peliculas->push_back( new Pelicula(2,"19:30", "Mario Bross", 130, false));
    peliculas->push_back( new Pelicula(3,"21:00", "Jhon Wick", 122, true ));
    peliculas->push_back( new Pelicula(4,"22:30", "Spiderman", 122, false ));
    peliculas->push_back( new Pelicula(5,"23:30", "Rapidos y Furiosos", 150, false ));
    boletosVendidos.resize(peliculas->size());


    //Menu de las Comidas
    menu.push_back(Bar(1,"Hamburguesa", 8.5));
    menu.push_back(Bar(2,"Pizza", 10.0));
    menu.push_back(Bar(3,"Hot Dog", 5.0));
    menu.push_back(Bar(4,"Nachos", 6.5));
    menu.push_back(Bar(5,"Palomitas", 3.0));
    menu.push_back(Bar(6,"Sándwich", 4.0));
    menu.push_back(Bar(7,"Helado", 3.5));
    menu.push_back(Bar(8,"Jugo", 6.0));
    menu.push_back(Bar(9,"CocaCola", 7.0));
    menu.push_back(Bar(10,"Agua", 6.0));
    comidasCompradasPorSala.resize(peliculas->size());
}
//asientos sin usar¿?, no es necesaria aqui ya que ya estan hechos (creo)
//Cine::Cine(const Boleto& asientos)
Cine::Cine(const Boleto& asiento )
{

}


Cine::~Cine()
{
    delete vista;
}
float Cine::getPRECIO_BOLETO() const
{
    return PRECIO_BOLETO;
}

void Cine::agregarComidaAlMenu(const Bar& comida)
{
    menu.push_back(comida);
}

const vector<Bar> &Cine::getMenu() const
{
    return menu;
}



string Cine::mostrarCartelera() {


    char filas[] = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < peliculas->size(); i++) {
        salas.push_back(Sala((*peliculas)[i]->getId(), filas, i + 1));
    }

    string cartelera = "Cartelera:\n\n";
    for (int i = 0; i < peliculas->size(); i++) {
        cartelera += to_string((*peliculas)[i]->getId()) + " - "+ (*peliculas)[i]->getHora() + " - " +(*peliculas)[i]->getTitulo() + " (" + to_string((*peliculas)[i]->getDuracion()) + ")" ;
        if ((*peliculas)[i]->getEstreno()) {
            cartelera += " - *ESTRENO*";
        }
        cartelera += "\n";
    }
    return cartelera;
}
string Cine::mostrarSala(int peliculaId) {
    string resultado;
    if (peliculaId > 0 && peliculaId <= salas.size()) {
        const Sala& sala = salas[peliculaId - 1];
        resultado = "- - A S I E N T O S - -\n\n";
        resultado += "  1 2 3 4 5\n";
        char filaLetra = 'A';
        for (int i = 0; i < 5; i++) {
            resultado += filaLetra++; // Las filas se nombran de 'A' a 'E'
            resultado += " ";
            for (int j = 0; j < 5; j++) {
                resultado += (sala.getAsiento(i, j) ? 'O' : 'X');
                resultado += " ";
            }
            resultado += "\n\n";
        }
    } else {
        // Si no se encuentra la sala correspondiente al ID de la película
        resultado = "No se encontró una sala con la película ID: " + to_string(peliculaId) + "\n";
    }
    return resultado;
}

void Cine::ocuparAsiento(int peliculaId, int fila, int columna) {
    if (peliculaId > 0 && peliculaId <= salas.size()) {
        salas[peliculaId - 1].cambiarEstadoAsiento(fila, columna);

    }
}

bool Cine::comprarBoleto(int sala, char fila, int columna, Boleto*& boletoComprado) {
    if (sala > 0 && sala <= salas.size()) {
        int filaIndice = static_cast<int>(fila - 'A');
        if (!salas[sala - 1].getAsiento(filaIndice, columna - 1)) {
            return false;  // Asiento ocupado
        }
        salas[sala - 1].cambiarEstadoAsiento(filaIndice, columna - 1);
        int numeroBoleto = boletosVendidos[sala - 1].size() - 1;
        boletoComprado = new Boleto(sala, (*peliculas)[sala - 1], fila, columna);
        boletosVendidos[sala - 1].push_back(boletoComprado);
        boletosPorSala[sala - 1]++;
        boletosCantidad = boletosPorSala[sala - 1] * PRECIO_BOLETO;
        boletoComprado->setNumeroBoleto(boletosPorSala[sala - 1]);
        boletoComprado->setCine(this);
        cout << "Boletos reservados exitosamente: "<<"Sala "<<sala<<" Asiento: "<<fila<<columna<<"\n\n";
        return true;
    } else {
        return false;  // Sala no encontrada
    }

}

string Cine::mostrarBoletosComprados(int sala) {
    string boletosInfo;
    //advertencia corregida ((comparison of integer expressions of different signedness)
    if (sala > 0 && sala <= static_cast<int>(salas.size())) {
        if (boletosVendidos[sala - 1].empty()) {
            boletosInfo = "No hay boletos comprados para la sala " + to_string(sala) + "\n";
        } else {
            boletosInfo = "Boletos comprados para la sala " + to_string(sala) + ":\n";
            for (const auto& boleto : boletosVendidos[sala - 1]) {
                boletosInfo += vista->imprimirBoleto(*boleto) + "\n";
                boletosCantidad = boletosPorSala[sala - 1] * PRECIO_BOLETO;// Calcular el total de boletos por sala

            }
            boletosInfo += "Total: " + to_string(boletosCantidad) + "\n";

        }
    } else {
        boletosInfo = "No se encontró la sala: " + to_string(sala) + "\n";
    }
    return boletosInfo;
}


string Cine::mostrarComidaComprada(int sala) const {
    string resultado;

    if (sala <= 0 || sala > static_cast<int>(salas.size())) {
        resultado = "No se encontró la sala: " + to_string(sala) + "\n";
    } else {
        const vector<Bar>& comidas = comidasCompradasPorSala[sala - 1];
        if (comidas.empty()) {
            resultado = "No se compró comida para la sala " + to_string(sala) + "\n";
        } else {
            resultado = "Comida comprada para la sala " + to_string(sala) + ":\n";
            for (const auto& comida : comidas) {
                resultado += "- " + comida.getNombreComida() + " (Precio: " + to_string(comida.getPrecioComida()) + ")\n";
            }
        }
    }

    return resultado;
}
bool Cine::ordenComida(int sala, const string& nombreComida) {
    // Verifica si la sala es válida
    if (sala <= 0 || sala > static_cast<int>(salas.size())) {
        return false; // Sala inválida
    }

    // Busca la comida en el menú
    const Bar* comidaSeleccionada = nullptr;
    for (const auto& comida : menu) {
        if (comida.getNombreComida() == nombreComida) {
            comidaSeleccionada = &comida;
            break;
        }
    }

    if (comidaSeleccionada == nullptr) {
        return false; // Comida no encontrada en el menú
    }

    // Añade la comida al vector de compras de la sala especificada
    comidasCompradasPorSala[sala - 1].push_back(*comidaSeleccionada);

    return true; // Comida agregada a la orden de la sala
}
Factura* Cine::generarFactura(int sala, const string& nombre, const string& telefono, const string& correo) {
    Factura* factura = new Factura(nombre, telefono, correo);

    // Comprueba si la sala es válida
    if (sala < 1 || sala > boletosVendidos.size() || sala > comidasCompradasPorSala.size()) {
        delete factura;  // No olvides eliminar la factura para evitar fugas de memoria
        return nullptr; // Sala inválida
    }

    // Obtener los boletos comprados para la sala especificada
    vector<Boleto*> boletos = boletosVendidos[sala - 1];
    // Agregar los boletos a la factura
    for (auto boleto : boletos) {
        factura->agregarBoleto(boleto);
    }

    // Obtener la comida comprada para la sala especificada
    vector<Bar> comidas = comidasCompradasPorSala[sala - 1];
    // Agregar la comida comprada a la factura
    for (const auto &comida : comidas) {
        factura->agregarComida(comida);
    }

    return factura;
}
