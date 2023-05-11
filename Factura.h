//
// Created by hola on 10/5/2023.
//

#ifndef INGSOFWATAREA_FACTURA_H
#define INGSOFWATAREA_FACTURA_H

#include <iostream>
#include "Compra.h"
using namespace std;

class Factura : public Compra{
private:
    string nombreProveedor;
    string tipoFactura;
    string numeroFactura;

public:
    Factura(int _id, double _total, string _fecha, string _proveedor,  string nameproveedor, string _numeroFactura, string _tipoFactura) : Compra(_id,  _total,  _fecha,  _proveedor) {
        this->nombreProveedor =  nameproveedor;
        this->tipoFactura = _tipoFactura;
        this->numeroFactura = _numeroFactura;
    }
    void mostrarDatos() {
        cout << " ============== FACTURA ==============" << endl;
        Compra::mostrarDatos();
        cout << "\tNumero de Factura:    " << numeroFactura << endl;
        cout << "\tNombre del proveedor:    " << nombreProveedor << endl;
        cout << "\tTipo de Factura:    " << tipoFactura << endl;
        cout << " =====================================" << endl;

    }
};

#endif //INGSOFWATAREA_FACTURA_H
