#pragma once
#include <string>
#include "usuario.h"
#include "turno.h"

using namespace std;

class Planificacion{
  public:
    //Planificacion();
    Planificacion(int id_plan, string dia, bool estado, int atraso, int retiro_anticipado, string id_the_user, vector<class Turno> allturns);
    void presentacionplan();
    void tiempoplanificacion();
    string id_user();
    //class Turno turno();
    //Turno *pturno = new Turno;
    vector<class Turno> turno;
    string get_day();

  protected:
    int id_plan;
    string dia;
    bool estado;
    int atraso;
    int retiro_anticipado;
    string id_the_user;
};