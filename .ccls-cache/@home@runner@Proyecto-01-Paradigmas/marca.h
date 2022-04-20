#pragma once
#include <string>
#include "usuario.h"

using namespace std;

class Marca{
  public:
    //Marca();
    Marca(string identificador, string dia, string hora, int tipo);
    string identificador;
    string dia;
    string hora;
    string get_day();
    int tipo;
  //protected:
};