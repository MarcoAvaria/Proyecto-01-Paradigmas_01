#pragma once
#include <string>
#include <vector>
#include "planificacion.h"
#include "marca.h"

using namespace std;

class Usuario{
  //Planificacion Plan;
  public:
    Usuario(string identificador, string nombre);
    void prueba();
    virtual void show_name();
    virtual void show_id();
    void marcar(string identificador, vector<class Marca> allrecords, vector<class Usuario> usuarios);
    void informe();
    string get_name();
    string id_user();
    vector<class Planificacion> plans;
    vector<class Planificacion> get_plans();
    vector<class Marca> all_records;
  protected:
    string identificador;
    string nombre;
    string marcas;
    //class Planificacion;
    //Planificacion::Planificacion(string identificador);
    //Planificacion plan(string identificador);

};