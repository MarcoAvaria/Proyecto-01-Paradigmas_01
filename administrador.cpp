#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "administrador.h"
#include "planificacion.h"
#include "usuario.h"

using namespace std;

Administrador::Administrador(string identificador, string nombre) : Usuario(identificador, nombre) {
  cout << "Creado/a el/la ADMINISTRADOR, nombre: " << nombre << endl;
  this->identificador = identificador;
  this->nombre = nombre;
}

string Administrador::get_name_admin(){
  return this->nombre;
}

vector<Usuario> Administrador::asignarturnos(string id_user, vector<Usuario> usuarios, vector<Planificacion> allschedule){
  cout << "ASIGNANDO TURNOS...\n" << endl;
  for(size_t i = 0; i < usuarios.size(); i++){
    if (id_user == usuarios[i].id_user()){
      for(size_t j = 0; j < allschedule.size(); j++){
        if (allschedule[j].id_user() == usuarios[i].id_user())
        {
          //cout<<"cadena1: "<< i << endl;
          //allschedule[j].presentacionplan();
          usuarios[i].plans.push_back(allschedule[j]);
          //usuarios[i].plans[j].presentacionplan();
          //cout<<"cadena2: "<< j << endl
        }
        //cout<<"Fuera!"<<endl;
        //usuarios[i].plans[j].presentacionplan();
      }
      //cout<<"Fuera! 22222222222"<<endl;
    }
    //cout<<"Fuera! xxx xxx xxx"<<endl;
  }
  //cout<<"Fuera!               OUT !!!"<<endl;

  return usuarios;
  /*
  for (const auto &i : lines_users){
    string cadena;
    stringstream cadena_virtual(i);
    while(getline(cadena_virtual, cadena, ';')){
      if (id_user == cadena){
        cout<<"Existe un usuario con ese ID"<< endl;
        cout<<"...\n...\n...\n...Asignando planificación..."<<endl;
        
        while (getline(file_schedule, line)){
          lines_schedule.push_back(line);
        }
      }
    }
  }*/
}

void Administrador::agregarusuarios(){
  cout << "AGREGANDO USUARIOS... (AUN NO HACE ALGO) " << endl;
}

void Administrador::eliminarusuario(){
  cout << "ELIMINANDO USUARIOS... (AUN NO HACE ALGO) " << endl;
}

