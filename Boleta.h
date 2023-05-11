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
    Boleta(int _id, float _total, string _nombreCliente) : Compra(_id, _total), nombreCliente(_nombreCliente) {}

    void mostrarDetalles() {
        cout << "Boleta" << endl;
        Compra::mostrarDetalles();
        cout << "Nombre del cliente: " << nombreCliente << endl;
    }
};

#endif //INGSOFWATAREA_BOLETA_H
