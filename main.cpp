#include <iostream>
#include "testing.cpp"
#include "Tienda.h"
using namespace std;

int run() {
    Tienda store ;
    int opcion;
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

int tests(){
    signUp_happytest();
    signUp_unhappytest();
    logIn_happytest();
    logIn_unhappytest();
    showCredentials_test();
    print_test();
    addStock_happytest();
    addStock_unhappytest();
    add_addStock_happytest();
    add_addStock_unhappytest();
    add_happytest();
    add_unhappytest();
    comprar_happytest();
    comprar_unhappytest();
    nocomprar_happytest();
    nocomprar_unhappytest();
    return 0;
}

int main(){
    int s = 0;
    do {
        cout << "[--- BIENVENIDOS A FARMACIA NEZMO ---]" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "[1] Ejecutar programa\t[2] Correr tests" << endl;
        cin >> s;
        if(s==1)
            run();
        else if(s==2)
            tests();
    } while(s!=1 && s!=2);
    return 0;
}
