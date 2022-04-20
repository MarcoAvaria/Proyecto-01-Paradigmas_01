#pragma once
#include <string>
#include "usuario.h"

using namespace std;

class Administrador : public Usuario {
  public:
    Administrador(string identificador, string nombre);
    string get_name_admin();
    vector<Usuario> asignarturnos(string id_user, vector<Usuario> usuarios, vector<Planificacion> allschedule);
    void agregarusuarios();
    void eliminarusuario();    
};