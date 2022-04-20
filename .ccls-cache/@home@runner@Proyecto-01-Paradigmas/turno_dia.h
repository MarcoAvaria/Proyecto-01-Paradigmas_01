#pragma once
#include <string>
#include "turno.h"

using namespace std;

class Turno_Dia : public Turno {
  public:
    Turno_Dia(int id_turno, string hora_inicio, string hora_fin, int minutos_atraso_permitidos);
    void totalhorasmenosatraso();
  protected:
    int minutos_atraso_permitidos;
};