#pragma once
#include <string>
#include "turno.h"

using namespace std;

class Turno_Tarde : public Turno {
  public:
    Turno_Tarde(int id_turno, string hora_inicio, string hora_fin, int minutos_retiro_anticipado);
    void totalhorasmenosanticipo();
  protected:
    int minutos_retiro_anticipado;
};