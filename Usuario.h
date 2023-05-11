//
// Created by Sof on 10/05/2023.
//

#ifndef INGSOFWATAREA_USUARIO_H
#define INGSOFWATAREA_USUARIO_H

#include <iostream>
#include <utility>
#include <vector>
using namespace std;


struct User{
    string dni;
    string nombre;
    double saldo;

    User() = default;

    User(string dni, string nombre, double saldo){
        this->dni = move(dni);
        this->nombre = move(nombre);
        this->saldo = saldo;
    }

    ~User() = default;
};

#endif //INGSOFWATAREA_USUARIO_H
