#include "pelicula.h"
#include "cine.h"
#include "sala.h"
#include "factura.h"
#include "boleto.h"
#include "vista.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{

    Vista vista;
    Factura factura;
    vector<Factura> facturas;
    int count=0;
    int numeroCompra=0;//Boleto
    //string comidaIngresada;
    double boletosCantidad=0;
    int opcion;
    int opcionCine=1;
    int sala;
    char fila;
    int columna;
    Cine cine;
    string comidaComprada = cine.mostrarComidaComprada(opcionCine);

    vector<Bar> menu = cine.getMenu();
    cout << "+ + M I C I N E + + \n\n";
    do {
        cout << "+ + + M E N U + + + \n\n";
        cout << "1. Mostrar cartelera\n";
        cout << "2. Mostrar sala\n";
        cout << "3. Comprar Boleto\n";
        cout << "4. Boletos Comprados\n";
        cout << "5. Menu Comida\n";
        cout << "6. Genera Factura\n";
        cout << "7. Imprime Factura\n";
        cout << "8. Salir\n\n";
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;
        switch (opcion) {
        case 1: {
            // Mostrar cartelera
            cout << cine.mostrarCartelera() << endl;
            break;
        }
        case 2: {
            // Mostrar sala de un cine
            //cout << "Seleccione una sala de cine: ";
            cout << cine.mostrarCartelera() << endl;
            cout << "Seleccione una sala de cine: ";
            cin >> opcionCine;
            cout<<cine.mostrarSala(opcionCine);

            break;
        }
        case 3: {

            cout<<cine.mostrarCartelera()<<endl;
            do{

                cout << "Seleccione una sala de cine para comprar boleto: ";
                cin >> opcionCine;
                cout << "Cuantos boletos desea comprar? : ";
                cin >> numeroCompra;

            }while(opcionCine<=0);
            do {

                cout << cine.mostrarSala(opcionCine);

                cout << "Ingrese la fila y columna del asiento que desea comprar (por ejemplo: A1): ";
                cin >> fila;  // Obtiene la fila

                cin >> columna; // Obtiene la columna

                Boleto* boleto = nullptr;
                if (cine.comprarBoleto(opcionCine, fila, columna, boleto)) {
                    vista.imprimirBoleto(*boleto);

                } else {
                    // Manejar el error
                    cout << "No se pudo comprar el boleto. Por favor, verifica la sala y el asiento.\n";
                }
                count++;

            } while(count != numeroCompra);

            count = 0;

            break;

        }
        case 4: {
            cout << "Seleccione una sala de cine para ver los boletos comprados: ";
            cin >> opcionCine;
            cout << cine.mostrarBoletosComprados(opcionCine);


            break;
        }
        case 5: {
            /* vamos a usar la opcion 5 para hacer el bar y la opcion 6 para la factura
             * la opcion 7 va ser salir y talvez vaya en la opcion 1, la opcion de cambiar la pelicula.*/
            cine.mostrarCartelera();
            cout << "Seleccione una sala de cine: ";
            cin >> opcionCine;
            vista.menuBar(menu);
            cout << "Ingrese una comida: ...\n";
            cin.ignore();
            cin >> comidaComprada;
            cine.ordenComida(opcionCine,comidaComprada);
            cout<<cine.mostrarComidaComprada(opcionCine);

            break;
        }
        case 6: {
            //Falta de terminar
            cout << "Factura:\n";
            cout << "Ingrese el numero de la sala para la cual desea la factura: ";
            cin >> sala;

            string nombre;
            cout << "Ingrese su nombre: ";
            getline(cin >> ws, nombre);
            string telefono;
            cout << "Ingrese su número de telefono: ";
            cin >> telefono;
            string correo;
            cout << "Ingrese su correo electronico: ";
            cin >> correo;
            cine.generarFactura(sala,nombre, telefono, correo);
            Factura nuevaFactura = *cine.generarFactura(sala, nombre, telefono, correo);
            facturas.push_back(nuevaFactura);

            break;
        }
        case 7: {
            //Falta de terminar
            cout << "Imprime Factura...\n";
             if (!facturas.empty()) {
                 // Sólo imprime la última factura generada
                 Factura& ultimaFactura = facturas.back();
                 cout << ultimaFactura.generarFactura() << endl;
             } else {
                 cout << "No hay facturas para imprimir.\n";
             }
            break;
        }
        case 8: {

            cout << "Saliendo...\n";

            break;
        }
        default:
            cout << "Opción no valida. Intente nuevamente.\n";
            break;
        }
    } while (opcion != 8);

    return 0;
}

