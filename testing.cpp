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

int signUp_sadtest() {
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