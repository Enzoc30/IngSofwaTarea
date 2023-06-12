#include "Tienda.h"
#include <assert.h>

int signUp_happytest() {
    Tienda* store = new Tienda;
    store->signUp();
    string dni_a = store->active_user.dni;
    delete store;

    string linea, dni;
    string dni_b = "";
    ifstream get_user("../users.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, dni, ',');
            if (dni == dni_a){
                dni_b = dni;
                break;
            }
        }
        get_user.close();
    }

    assert(dni_a==dni_b);
    return 0;
}

int signUp_unhappytest() {
    Tienda* store = new Tienda;
    store->signUp();
    string dni_a = "";
    delete store;

    string linea, dni;
    bool exists = false;
    ifstream get_user("../users.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, dni, ',');
            if (dni == dni_a){
                exists = true;
                break;
            }
        }
        get_user.close();
    }

    assert(exists==false);
    return 0;
}

int logIn_happytest(){
    Tienda* store = new Tienda;
    store->logIn();
    string dni_a = store->active_user.dni;
    delete store;

    string linea, dni;
    string dni_b = "";
    ifstream get_user("../users.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, dni, ',');
            if (dni == dni_a){
                dni_b = dni;
                break;
            }
        }
        get_user.close();
    }

    assert(dni_a==dni_b);
    return 0;
}

int logIn_unhappytest() {
    Tienda* store = new Tienda;
    store->logIn();
    string dni_a = "";
    delete store;

    string linea, dni;
    bool exists = false;
    ifstream get_user("../users.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, dni, ',');
            if (dni == dni_a){
                exists = true;
                break;
            }
        }
        get_user.close();
    }

    assert(exists==false);
    return 0;
}

int showCredentials_test(){
    Tienda* store = new Tienda;
    store->active_user.nombre = "";
    store->active_user.saldo = 0.0;
    store->showCredentials();
    assert(1==1);
    return 0;
}

int print_test(){
    Tienda* store = new Tienda;
    store->print();
    assert(1==1);
    return 0;
}

int addStock_happytest(){
    string stock_a = to_string(10);
    string nombre_a = "Aspirina";
    Tienda* store = new Tienda;
    store->addStock();
    delete store;

    string linea, nombre, precio, stock;
    bool exists = false;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && stock == stock_a){
                exists = true;
                break;
            }
        }
        get_user.close();
    }

    assert(exists==true);
    return 0;
}

int addStock_unhappytest(){
    string stock_a = to_string(10);
    string nombre_a = "Aspirina";
    Tienda* store = new Tienda;
    store->addStock();
    delete store;

    string linea, nombre, precio, stock;
    bool exists = false;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && stock == stock_a){
                exists = true;
                break;
            }
        }
        get_user.close();
    }

    assert(exists==false);
    return 0;
}

int add_addStock_happytest(){
    string stock_a = to_string(10);
    string nombre_a = "Aspirina";
    Tienda* store = new Tienda;
    store->add();
    delete store;

    string linea, nombre, precio, stock;
    bool exists = false;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && stock == stock_a){
                exists = true;
                break;
            }
        }
        get_user.close();
    }

    assert(exists==true);
    return 0;
}

int add_addStock_unhappytest(){
    string stock_a = to_string(10);
    string nombre_a = "Aspirina";
    Tienda* store = new Tienda;
    store->add();
    delete store;

    string linea, nombre, precio, stock;
    bool exists = false;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && stock == stock_a){
                exists = true;
                break;
            }
        }
        get_user.close();
    }

    assert(exists==false);
    return 0;
}

int add_happytest(){
    string nombre_a = "Paolocetamol";
    string precio_a = to_string(40);
    string stock_a = to_string(10);
    Tienda* store = new Tienda;
    store->add();
    delete store;

    string linea, nombre, precio, stock;
    bool exists = false;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && precio == precio_a && stock == stock_a){
                exists = true;
                break;
            }
        }
        get_user.close();
    }

    assert(exists==true);
    return 0;
}

int add_unhappytest(){
    string nombre_a = "Paolocetamol";
    string precio_a = to_string(40);
    string stock_a = to_string(10);
    Tienda* store = new Tienda;
    store->add();
    delete store;

    string linea, nombre, precio, stock;
    bool exists = false;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && precio == precio_a && stock == stock_a){
                exists = true;
                break;
            }
        }
        get_user.close();
    }

    assert(exists==false);
    return 0;
}

int comprar_happytest() {
    string nombre_a = "Aspirina";
    int stock_a = 2;
    string linea, nombre, precio, stock;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a){
                stock_a = stoi(stock) - stock_a;
                break;
            }
        }
        get_user.close();
    }

    Tienda* store = new Tienda;
    store->comprar();
    delete store;

    linea = "", nombre = "", precio = "", stock = "";
    bool exists = false;
    ifstream get_user_2("../tienda.csv", ios::in | ios::out);
    if (get_user_2.is_open()) {
        while (getline(get_user_2, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && stock == to_string(stock_a)){
                exists = true;
                break;
            }
        }
        get_user_2.close();
    }

    assert(exists==true);
    return 0;
}

int comprar_unhappytest() {
    string nombre_a = "Aspirina";
    int stock_a = 2;
    string linea, nombre, precio, stock;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a){
                stock_a = stoi(stock) - stock_a;
                break;
            }
        }
        get_user.close();
    }

    Tienda* store = new Tienda;
    store->comprar();
    delete store;

    linea = "", nombre = "", precio = "", stock = "";
    bool exists = false;
    ifstream get_user_2("../tienda.csv", ios::in | ios::out);
    if (get_user_2.is_open()) {
        while (getline(get_user_2, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && stock == to_string(stock_a)){
                exists = true;
                break;
            }
        }
        get_user_2.close();
    }

    assert(exists==false);
    return 0;
}

int nocomprar_happytest() {
    string nombre_a = "Aspirina";
    int stock_a = 0;
    string linea, nombre, precio, stock;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a){
                stock_a = stoi(stock);
                break;
            }
        }
        get_user.close();
    }

    Tienda* store = new Tienda;
    store->comprar();
    delete store;

    linea = "", nombre = "", precio = "", stock = "";
    bool exists = false;
    ifstream get_user_2("../tienda.csv", ios::in | ios::out);
    if (get_user_2.is_open()) {
        while (getline(get_user_2, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && stock == to_string(stock_a)){
                exists = true;
                break;
            }
        }
        get_user_2.close();
    }

    assert(exists==true);
    return 0;
}

int nocomprar_unhappytest() {
    string nombre_a = "Aspirina";
    int stock_a = 0;
    string linea, nombre, precio, stock;
    ifstream get_user("../tienda.csv", ios::in | ios::out);
    if (get_user.is_open()) {
        while (getline(get_user, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a){
                stock_a = stoi(stock);
                break;
            }
        }
        get_user.close();
    }

    Tienda* store = new Tienda;
    store->comprar();
    delete store;

    linea = "", nombre = "", precio = "", stock = "";
    bool exists = false;
    ifstream get_user_2("../tienda.csv", ios::in | ios::out);
    if (get_user_2.is_open()) {
        while (getline(get_user_2, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, precio, ',');
            getline(ss, stock, ',');
            if (nombre == nombre_a && stock == to_string(stock_a)){
                exists = true;
                break;
            }
        }
        get_user_2.close();
    }

    assert(exists==false);
    return 0;
}