#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

/*
struct Product{
    string nombre;
    double precio;
    int stock;

    Product() = default;

    Product(string name, double price , int stock){
        nombre = name ;
        precio = price;
        this->stock = stock;
    }

    ~Product() = default;
};


class Tienda{
private:
    string filename= "C:\\Users\\hola\\CLionProjects\\IngSoftware\\tienda.csv";
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
        cout << "Ingresar nombre Producto : ";
        cin >> nombre;
        auto it = find_if(productos.begin(), productos.end(), [&](Product& p) {
            return p.nombre == nombre;
        });

        if(it != productos.end()){
            cout <<  "El producto ya esta existe, podría aumentar el stock " << endl;
            addStock2(it);
            return ;
        }else {
            double precio;
            int cantidad;
            cout << "Ingresar precio del producto: ";
            cin >> precio;
            cout << "Ingresar cantidad del producto: ";
            cin >> cantidad;
            Product product(nombre, precio, cantidad);
            productos.push_back(product);
        }
    }

    void addStock(){
        vector<Product>::iterator it;
        do{
            string name;
            cout <<  "El nombre del producto que quiere cambiar eL Stock:  " << endl;
            cin >> name;
            it = find_if(productos.begin(), productos.end(), [&](Product &p) {
                return p.nombre == name;
            });
        } while (it == productos.end());
        addStock2(it);
    }


    void addStock2(vector<Product>::iterator & ite  ){
        cout << "Stock Actual del Producto " << ite->nombre << " : " << ite->stock << endl;
        cout <<"Nuevo valor del Stock: " ;
        cin >> ite->stock; cout << endl;
    }

    void comprar (){
        vector<Product>::iterator it;
        cout << "****************LISTA*****************" << endl;
        for(auto &i : productos){
            cout  << "\t"<< i.nombre  << endl;}
        cout << "**************************************" << endl;
        do{
            string name;
            cout <<  "El nombre del producto que quiere comprar:  " ;
            cin >> name ; cout << endl;
            it = find_if(productos.begin(), productos.end(), [&](Product &p) {
                return p.nombre == name;
            });
        } while (it == productos.end() ||  it->stock == 0);

        cout << "Stock Actual del Producto " << it->nombre << " : " << it->stock << endl;
        int cantidad = 0;
        cout << "Ingrese la cantidad a comprar: ";
        cin >> cantidad; cout << endl;
        while (cantidad < 0 || it->stock - cantidad < 0) {
            cout << "La cantidad ingresada no es válida." << endl;
            cout << "Ingrese la cantidad a comprar: ";
            cin >> cantidad; cout << endl;
        }
        it->stock -= cantidad;

    }

    void print(){
        cout << "        Tienda" << endl;
        for(auto &i : productos){
            cout << "------------------------" << endl;
            cout << "Nombre : " << i.nombre << endl;
            cout << "Precio : " << i.precio << endl;
            cout << "Stock : " << i.stock << endl;
            cout << "------------------------" << endl;
        }
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

int main2() {

    Tienda store ;
    int opcion;
    do {
        cout << "-----------------Menu-----------------" << endl;
        cout << "\t[1] Mostrar Productos" << endl;
        cout << "\t[2] Aniadir Stock" << endl;
        cout << "\t[3] Aniadir Producto" << endl;
        cout << "\t[4] Comprar Producto" << endl;
        cout << "\t[5] Salir" << endl;
        cout << "--------------------------------------" << endl;
        cout << "\t Ingrese una opcion:  ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                store.print();
                break;
            case 2:
                store.addStock();
                break;
            case 3:
                store.add();
                break;
            case 4:
                store.comprar();
                break;
            case 5:
                cout << "Adios!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
*/