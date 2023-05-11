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

#include "Product.h"
#include "Compra.h"
using namespace std;


class Tienda{
private:
    string filename= "C:\\Users\\hola\\CLionProjects\\TareaIngsS\\IngSofwaTarea\\tienda.csv";
    vector<Product> productos;

public:
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

    void comprar (){
        vector<Product>::iterator it;
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
                return p.nombre == name;
            });
        } while (it == productos.end() ||  it->stock == 0);

        cout << "Stock actual del producto " << it->nombre << ": " << it->stock << endl;
        int cantidad = 0;
        cout << "Ingrese la cantidad a comprar:";
        cin >> cantidad; cout << endl;
        while (cantidad < 0 || it->stock - cantidad < 0) {
            cout << "La cantidad ingresada no esta disponible." << endl;
            cout << "Ingrese la cantidad a comprar: ";
            cin >> cantidad; cout << endl;
        }
        it->stock -= cantidad;

        

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
        ofstream escribir(filename);
        for(auto &i : productos){
            escribir<<i.nombre;
            escribir<<",";
            escribir<<i.precio;
            escribir<<",";
            escribir<<i.stock;
            escribir<<endl;
        }
        escribir.close();
    }

};




#endif //INGSOFWATAREA_TIENDA_H
