//
// Created by hola on 10/5/2023.
//

#ifndef INGSOFWATAREA_BOLETA_H
#define INGSOFWATAREA_BOLETA_H

#include <iostream>
#include "Compra.h"
using namespace std;

class Boleta : public Compra{
private:
    string nombreCliente;
    string numeroBoleta;
    string tipoPago;
public:
    Boleta(int _id, double _total, string _fecha, string _proveedor, string nombre , string numBoleta, string methodPay) : Compra(_id,  _total,  _fecha,  _proveedor) {
        nombreCliente = nombre ;
        numeroBoleta = numBoleta;
        tipoPago = methodPay;

    }
    void mostrarDatos() {
        cout << "============== BOLETA ==============" << endl;
        Compra::mostrarDatos();
        cout << "\tNombre del cliente: " << nombreCliente << endl;
        cout << "\tNúmero de Boleta: " << numeroBoleta << endl;
        cout << "\tTipo de Pago: " << tipoPago << endl;
        cout << " =====================================" << endl;

    }
};

#endif //INGSOFWATAREA_BOLETA_H
