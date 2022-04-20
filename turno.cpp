#include <iostream>
#include "turno.h"

using namespace std;

Turno::Turno(){};

Turno::Turno(int id_turno, string hora_inicio, string hora_fin) {
  this->id_turno = id_turno;
  this->hora_inicio = hora_inicio;
  this->hora_fin = hora_fin;
  //cout << "Este TURNO tiene id_turno: " << id_turno << endl;
}

void Turno::total_horas(){
  cout << "AQUÍ DEBERÍA ENTREGAR EL TOTAL DE HORAS (Aun no hace algo)" << endl;
};

int Turno::id_turn(){
  return this->id_turno;
}