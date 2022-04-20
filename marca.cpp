#pragma once
#include <iostream>
#include "marca.h"

using namespace std;

//Marca::Marca(){}

Marca::Marca(string identificador, string dia, string hora, int tipo) {
  this->identificador = identificador;
  this->dia = dia;
  this->hora = hora;
  this->tipo = tipo;
  //cout << "Este registro (MARCA) pertenece al usuario de código: " << identificador << endl;
}

string Marca::get_day(){
  return this->dia;
}
