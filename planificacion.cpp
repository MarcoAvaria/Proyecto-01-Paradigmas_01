#pragma once
#include <iostream>
#include "planificacion.h"
#include "turno.h"

using namespace std;

//Planificacion::Planificacion(){}

Planificacion::Planificacion(int identificador, string dia, bool estado, int atraso, int retiro_anticipado, string id_the_user, vector<Turno> allturns) {
  this->id_plan = identificador;
  this->dia = dia;
  this->estado = estado;
  this->atraso = atraso;
  this->retiro_anticipado = retiro_anticipado;
  this->id_the_user = id_the_user;
  for(size_t i = 0; i < allturns.size(); i++){
    if (identificador == allturns[i].id_turn()){
      this->turno.push_back(allturns[i]);
    }
  }
  //
  //cout << "Este PLANIFICACIÓN pertenece al usuario de código: " << identificador << endl;
}

void Planificacion::presentacionplan(){
  cout<<"-"<< this->id_plan<<" || "<< this->dia;
  cout<<" || "<< this->estado <<"-"<< this->atraso;
  cout<<"-"<< this->retiro_anticipado;
  cout<<"-"<< this->id_the_user;
  cout<<"-"<< this->turno[0].id_turno << endl;
}

string Planificacion::id_user(){
  return this->id_the_user;
}

string Planificacion::get_day(){
  return this->dia;
}