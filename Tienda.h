//
// Created by hola on 10/5/2023.
//

#ifndef INGSOFWATAREA_TIENDA_H
#define INGSOFWATAREA_TIENDA_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

#include "Product.h"
#include "Boleta.h"
#include "Compra.h"
#include "Factura.h"
#include "Usuario.h"
using namespace std;


class Tienda{
private:
    string filename= "../tienda.csv";
    vector<Product> productos;

public:
    User active_user = User("77777777", "admin", 1000000);
    Tienda() {
        ifstream archivo(filename);
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                string nombre;
                double precio;
                int cantidad;
                stringstream ss(linea);
                getline(ss, nombre, ',');
                ss >> precio;
                ss.ignore();
                ss >> cantidad;
                Product product(nombre, precio, cantidad);
                productos.push_back(product);
            }
            archivo.close();

        }
    }

    void logIn(){
        string credentials;
        string dni;
        string nombre;
        double saldo;
        cout << "Ingrese su DNI para ingresar. En caso no tenga cuenta, escriba 0 para registrarse." << endl;
        cin >> credentials;

        if (credentials == "0"){
            signUp();
            return;
        }

        ifstream archivo("../users.csv");
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                getline(ss, dni, ',');
                if (dni == credentials){
                    getline(ss, nombre, ',');
                    ss >> saldo;
                    ss.ignore();
                    active_user = User(dni, nombre, saldo);
                    archivo.close();
                    return;
                }
            }
        }

        cout << "User no encontrado." << endl;
        logIn();
    }

    void signUp(){
        string dni;
        string nombre;
        double saldo;
        cout << "Puede proceder a registrarse." << endl;
        cout << "DNI: ";
        cin >> dni;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Saldo a depositar: ";
        cin >> saldo;
        active_user = User(dni,nombre,saldo);
    }

    void showCredentials(){
        cout << endl;
        cout << "BIENVENID@ " << active_user.nombre << endl;
        cout << "SALDO: " << active_user.saldo << endl;
    }

    void add(){
        string nombre;
        cout << "Ingresar nombre del nuevo producto: ";
        cin >> nombre;
        auto it = find_if(productos.begin(), productos.end(), [&](Product& p) {
            return p.nombre == nombre;
        });

        if(it != productos.end()){
            cout <<  "El producto ya existe, puede aumentar el stock." << endl;
            addStock2(it);
            return ;
        }else {
            double precio;
            int cantidad;
            cout << "Ingresar precio del nuevo producto: ";
            cin >> precio;
            cout << "Ingresar cantidad del nuevo producto: ";
            cin >> cantidad;
            Product product(nombre, precio, cantidad);
            productos.push_back(product);
        }
    }

    void addStock(){
        vector<Product>::iterator it;
        do{
            string name;
            cout << "---------------------" << endl;
            cout << "******************** LISTA ********************" << endl;
            cout << "\tPRODUCTO\t\tSTOCK" << endl;
            for(auto &i : productos){
                cout  << "\t" << i.nombre << "\t\t" << i.stock << endl;}
            cout << "***********************************************" << endl;
            cout << "---------------------" << endl;
            cout <<  "Nombre del producto que quiere actualizar su stock:" << endl;
            cin >> name;
            it = find_if(productos.begin(), productos.end(), [&](Product &p) {
                return p.nombre == name;
            });
        } while (it == productos.end());
        addStock2(it);
    }

    void addStock2(vector<Product>::iterator & ite){
        cout << "Stock actual del producto " << ite->nombre << ": " << ite->stock << endl;
        cout << "Nuevo valor del stock: " ;
        cin >> ite->stock; cout << endl;
    }

    void comprar(){
        vector<Product>::iterator it;
        Product to_buy;
        cout << "******************** LISTA ********************" << endl;
        cout << "\tPRODUCTO\t\tPRECIO" << endl;
        for(auto &i : productos){
            cout  << "\t" << i.nombre << "\t\t" << i.precio << endl;}
        cout << "***********************************************" << endl;
        do{
            string name;
            cout <<  "Nombre del producto que quiere comprar:" ;
            cin >> name;
            it = find_if(productos.begin(), productos.end(), [&](Product &p) {
                to_buy = p;
                return p.nombre == name;
            });
        } while (it == productos.end() ||  it->stock == 0);

        cout << "Stock actual del producto " << it->nombre << ": " << it->stock << endl;
        int cantidad = 0;
        cout << "Ingrese la cantidad a comprar. En caso desee salir, escriba 0: ";
        cin >> cantidad; cout << endl;
        if (cantidad == 0){
            return;
        }

        while (cantidad < 0 || it->stock - cantidad < 0) {
            cout << "La cantidad ingresada no esta disponible." << endl;
            cout << "Ingrese la cantidad a comprar. En caso desee salir, escriba 0: ";
            cin >> cantidad; cout << endl;
            if (cantidad == 0){
                return;
            }
        }
        while (cantidad*to_buy.precio > active_user.saldo){
            cout << "Usted cuenta con " << active_user.saldo << " soles, pero su compra es de " << cantidad*to_buy.precio << "." << endl;
            cout << "Ingrese la cantidad a comprar. En caso desee salir, escriba 0: ";
            cin >> cantidad; cout << endl;
            if (cantidad == 0){
                return;
            }
        }
        it->stock -= cantidad;
        active_user.saldo -= cantidad*to_buy.precio;
        TipoCompras(to_buy.precio);
    }

    void TipoCompras(double monto) {
        cout << "Compra en proceso ..." << endl;
        int opcion = 0;
        string fecha, proveedor = "FARMACIA NEZMO";
        string numeroBoleta, tipoPago, nombrePersona;
        string numeroFactura, tipoFactura;
        cout << "=== Menu ===" << endl;
        cout << "[1] Registrar Compra" << endl;
        cout << "[2] Registrar Boleta" << endl;
        cout << "[3] Registrar Factura" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        time_t tiempoActual = time(nullptr);
        tm* fechaHora = localtime(&tiempoActual);
        char fecha1[11];
        strftime(fecha1, sizeof(fecha1), "%d/%m/%Y", fechaHora);
        fecha = fecha1;

        if (opcion == 1) {
            cout << "=== Registro de Compra ===" << endl;
            auto *compra = new Compra(1, monto, fecha, proveedor);
            cout << " ============== COMPRA ==============" << endl;
            compra->mostrarDatos();
            cout << " =====================================" << endl;
        }
        else if (opcion == 2) {
            cout << "=== Registro de Boleta ===" << endl;
            cout << "Ingrese el número de boleta: ";
            cin >> numeroBoleta;
            cout << "Ingrese el tipo Pago: ";
            cin >> tipoPago;
            cout << "Ingrese su nombre : ";
            cin >> nombrePersona;
            Compra *boleta = new Boleta(1, monto, fecha, proveedor, nombrePersona, numeroBoleta, tipoPago);
            boleta->mostrarDatos();
        }else if (opcion == 3) {
            cout << "=== Registro de Factura ===" << endl;
            cout << "Ingrese el número de Factura: ";
            cin >> numeroBoleta;
            cout << "Ingrese el nombre de la empresa: ";
            cin >> nombrePersona;
            cout << "Ingrese el tipo de Factura";
            cin >> tipoPago;
            Compra *factura = new Factura(1, monto, fecha, proveedor, nombrePersona, numeroBoleta, tipoPago);
            factura->mostrarDatos();
        }else{
            cout << "=== Registro de Compra ==="<< endl;
            auto *compra1 = new Compra(1, monto, fecha, proveedor);
            cout << " ============== COMPRA ==============" << endl;
            compra1->mostrarDatos();
            cout << " =====================================" << endl;
        }

    }
    void print(){
        cout << "******************** LISTA ********************" << endl;
        cout << "\tPRODUCTO\t\tPRECIO\tSTOCK" << endl;
        for(auto &i : productos){
            cout << "\t" << i.nombre << "\t\t" << i.precio << "\t" << i.stock << endl;
        }
        cout << "***********************************************" << endl;
        cout << endl;
    }


    ~Tienda(){
        ofstream file(filename);
        for(auto &i : productos){
            file<<i.nombre<<",";
            file<<i.precio<<",";
            file<<i.stock<<endl;
        }
        file.close();

        bool new_user = true;
        long long pos;
        ifstream get_user("../users.csv", ios::in | ios::out);
        if (get_user.is_open()) {
            string linea, dni;
            while (getline(get_user, linea)) {
                stringstream ss(linea);
                getline(ss, dni, ',');
                if (dni == active_user.dni){
                    new_user = false;
                    break;
                }
                pos = get_user.tellg();
            }
            get_user.close();
        }


        ofstream write_user("../users.csv", ios::in | ios::out);
        if (!new_user){
            write_user.seekp(pos-1, ios::beg);
        }
        else{
            write_user.seekp(0, ios::end);
        }
        write_user<<active_user.dni << ",";
        write_user<<active_user.nombre << ",";
        write_user<<active_user.saldo << endl;
        write_user.close();
    }

};




#endif //INGSOFWATAREA_TIENDA_H
