#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

using namespace std;

Usuario::Usuario(string identificador, string nombre) {
  this->identificador = identificador;
  this->nombre = nombre;
  cout << "creado USUARIO, nombre " << nombre << endl;
}

string Usuario::get_name(){
  return this->nombre;
}

string Usuario::id_user(){
  return this->identificador;
}

void Usuario::prueba(){
  cout<<"Funciona la función de prueba"<<endl;
}

void Usuario::show_name(){
  cout << "USUARIO -> NOMBRE: " << this->nombre << endl;
}

void Usuario::show_id(){
  cout << "USUARIO -> ID: " << this->identificador << endl;
}

void Usuario::marcar(string identificador, vector<class Marca>allrecords, vector<class Usuario> usuarios){
  //cout << "FUNCIÓN MARCAR DE 'USUARIO' (AUN NO HACE NADA)" << endl;
  for(size_t i = 0; i < allrecords.size(); i++){
    if (identificador == allrecords[i].identificador){
      this->all_records.push_back(allrecords[i]);
    }
  }
}

void Usuario::informe(){
  cout <<"Generando informe..."<<endl;
  string file_name(string(this->identificador)+=".txt");
  //cout << "FUNCIÓN INFORME DE 'USUARIO' (AUN NO HACE NADA)" << endl;
  //cout << string(this->identificador)<<".txt"<<endl;

  ofstream archivo;
  int j = 0;
  archivo.open(file_name.c_str(), fstream::out);
  for(size_t i = 0; i < this->plans.size(); i++){
    //cout<< "Cantida de JOTA -> "<< j<<endl;
    archivo << this->plans[i].get_day()<<";";
    archivo << this->plans[i].turno[0].hora_inicio <<";";
    archivo << this->plans[i].turno[0].hora_fin <<";";
    if (this->plans[i].get_day() == this->all_records[j].get_day() ){
      //cout<<"IF --"<< this->all_records[j].get_day()<<" - " << this->plans[i].get_day()<<endl;
      archivo << "True"<<";"<<endl;
      //j = j+2;
    }
    else{
      //cout<<this->plans[i].get_day()<<endl;
      //cout<<"ELSE --"<<this->all_records[j].get_day()<<" - " << this->plans[i].get_day()<<endl;
      archivo << "False"<<";"<<endl;
      if (j!=0) {j = j-2;}
    }
    j+=2;
  }
  cout <<"Informe completado"<<endl;
}

vector<class Planificacion> Usuario::get_plans(){
  return this->plans;
}