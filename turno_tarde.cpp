#include <iostream>
#include "turno_tarde.h"

using namespace std;

Turno_Tarde::Turno_Tarde(int id_turno, string hora_inicio, string hora_fin, int minutos_retiro_anticipado) : Turno(id_turno, hora_inicio, hora_fin) {
  this->id_turno = id_turno;
  this->hora_inicio = hora_inicio;
  this->hora_fin = hora_fin;
  this->minutos_retiro_anticipado = minutos_retiro_anticipado;
  //cout << "Este TURNO_TARDE tiene id_turno: " << id_turno << endl;
}

void Turno_Tarde::totalhorasmenosanticipo(){
  cout << "FUNCION DE TURNO_TARDE (Aún no hace algo)" << endl;
};