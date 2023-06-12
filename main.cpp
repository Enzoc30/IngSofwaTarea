#include <iostream>
#include "testing.cpp"
#include "Tienda.h"
using namespace std;

int run() {

    Tienda store ;
    int opcion;
    cout << "[--- BIENVENIDOS A FARMACIA NEZMO ---]" << endl;

    store.logIn();

    do {
        store.showCredentials();
        cout << "---------------- Menu ----------------" << endl;
        cout << "\t[1] Mostrar productos" << endl;
        cout << "\t[2] Actualizar stock" << endl;
        cout << "\t[3] Agregar producto" << endl;
        cout << "\t[4] Comprar producto" << endl;
        cout << "\t[5] Salir" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Ingrese una opcion:";
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
                cout << "Adios! Gracias por venir :)" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

int main(){
    signUp_sadtest();
    return 0;
}