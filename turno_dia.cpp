#include <iostream>
#include "turno_dia.h"

using namespace std;

Turno_Dia::Turno_Dia(int id_turno, string hora_inicio, string hora_fin, int minutos_atraso_permitidos) : Turno(id_turno, hora_inicio, hora_fin) {
  this->id_turno = id_turno;
  this->hora_inicio = hora_inicio;
  this->hora_fin = hora_fin;
  this->minutos_atraso_permitidos = minutos_atraso_permitidos;
  //cout << "Este TURNO_DÍA tiene id_turno: " << id_turno << endl;
}

void Turno_Dia::totalhorasmenosatraso() {
  cout << "AQUÍ DEBERÍA ENTREGAR EL TOTAL DE HORAS (Aun no hace algo)" << endl;
};