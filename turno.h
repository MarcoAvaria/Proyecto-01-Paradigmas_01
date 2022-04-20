#pragma once
#include <string>
#include "planificacion.h"

using namespace std;

class Turno {
  public:
    Turno();
    Turno(int id_turno, string hora_inicio, string hora_fin);
    void total_horas();
    int id_turn();
    int id_turno;
    string hora_inicio;
    string hora_fin;
  //protected:
};