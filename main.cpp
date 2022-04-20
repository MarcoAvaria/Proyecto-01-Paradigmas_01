#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "usuario.h"
#include "administrador.h"
#include "marca.h"
#include "planificacion.h"
#include "turno.h"
#include "turno_dia.h"
#include "turno_tarde.h"

using namespace std;


//void muestra_vector(const vector<string>&);

int main() {
  //Usuario p("marco");
  //p.show_name();
  
  ifstream file_users;
  file_users.open("./Usuarios.txt");
  ifstream file_turns;
  file_turns.open("./Turnos.txt");
  ifstream file_schedule;
  file_schedule.open("./Planificacion.txt");
  ifstream file_records;
  file_records.open("./Marcas.txt");
  
  string line;

  /*
    Se crean vectores con lineas de los
    archivos .txt ingresados, para reservar el
    espacio para después convertirlos en
    objetos de sus respectivas futuras clases,
    por ello se almacenan como string.
  */
  vector<string> lines_users;
  vector<string> lines_turns;
  vector<string> lines_schedule;
  vector<string> lines_records;

  /*
    Se crean los vectores de los tipos de clases
    a reservar.
  */
  vector<Usuario> usuarios;
  vector<Planificacion> allschedule;
  vector<Turno> allturns;
  vector<Marca> allrecords;

  /*
    Cada linea de los correspondientes archivos
    se almacenan en los vectores de sus
    corresponidentes tipos
  */
  while (getline(file_users, line)){
    lines_users.push_back(line);
  }
  while (getline(file_turns, line)){
    lines_turns.push_back(line);
  }
  //  ESTO ES PARA TOMAR LOS DATOS DE PLANIFICACION.TXT
  while (getline(file_schedule, line)){
    lines_schedule.push_back(line);
  }
  while (getline(file_records, line)){
    lines_records.push_back(line);
  }


  /*
    Se crean variables de uso temporal y
    luego, por cada línea representando un
    usuario, se extraen las propiedades de los
    futuros objetos y finalmente, las propiedades
    almacenadas en variables temporales se
    instancia la clase para obtener un objeto de
    clase Usuario (un "usuario" como metadato).
    
    Luego se repite el proceso con las siguientes
    lineas.

    Al final de cada iteración del ciclo for
    el objeto se almacena en el vector de tipo del
    objeto guardado.
  */
  string id_temp;
  string name_temp;
  for(const auto &i : lines_users){
    string cadena;
    stringstream cadena_virtual(i);
    getline(cadena_virtual,cadena,';');
    id_temp = cadena;
    getline(cadena_virtual,cadena,';');
    name_temp = cadena;
    usuarios.push_back(Usuario(id_temp, name_temp));
  }
  /*
    Se realiza el mismo proceso anterior pero
    ahora con los datos de turnos.txt
    y se almacenan como objetos de su respectiva
    clase en su respectivo vector de objeto.
  */
  string start_time, end_time;
  int  id_turn, minutes_allowed, turn_type;
  for(const auto &i : lines_turns){
    string cadena;
    stringstream cadena_virtual(i);
    getline(cadena_virtual,cadena,';');
    id_turn = stoi(cadena);
    getline(cadena_virtual,cadena,';');
    start_time = cadena;
    getline(cadena_virtual,cadena,';');
    end_time = cadena;
    getline(cadena_virtual,cadena,';');
    minutes_allowed = stoi(cadena);
    getline(cadena_virtual,cadena,';');
    turn_type = stoi(cadena);
    // Aquí se decide si es turno_dia o turno_tarde
    if (turn_type == 1){
      allturns.push_back(Turno_Dia(id_turn, start_time, end_time, minutes_allowed));
    }
    else if (turn_type == 2){
      allturns.push_back(Turno_Tarde(id_turn, start_time, end_time, minutes_allowed));
    }
  }
  /*
    Se realiza el mismo proceso anterior pero
    ahora con los datos de planificacion.txt
    y se almacenan como objetos de su respectiva
    clase en su respectivo vector de objeto.
  */
  string date_turn, id_user;
  bool status;
  int  delay, early_retirement;
  // Se utiliza el int id_turn declarado anteriormente
  for(const auto &i : lines_schedule){
    string cadena;
    stringstream cadena_virtual(i);
    getline(cadena_virtual,cadena,';');
    id_turn = stoi(cadena);
    getline(cadena_virtual,cadena,';');
    date_turn = cadena;
    getline(cadena_virtual,cadena,';');
    // *** DEBERÍA SER NECESARIO CONVERTIR ESTE STRING EN BOOL
    if (cadena=="False"){
      status = false;
    }
    else if (cadena=="True"){
      status = true;
    }
    getline(cadena_virtual,cadena,';');
    delay = stoi(cadena);
    getline(cadena_virtual,cadena,';');
    early_retirement = stoi(cadena);
    getline(cadena_virtual,cadena,';');
    id_user = cadena;
    allschedule.push_back(Planificacion(id_turn, date_turn, status, delay, early_retirement, id_user, allturns));
  }

  /*
    Se realiza el mismo proceso anterior pero
    ahora con los datos de Marcas.txt
    y se almacenan como objetos de su respectiva
    clase en su respectivo vector de objeto.
  */
  string date_record, time_record;
  int type_record;
  for(const auto &i : lines_records){
    string cadena;
    stringstream cadena_virtual(i);
    getline(cadena_virtual,cadena,';');
    id_temp = cadena;
    getline(cadena_virtual,cadena,';');
    date_record = cadena;
    getline(cadena_virtual,cadena,';');
    time_record = cadena;
    getline(cadena_virtual,cadena,';');
    type_record = stoi(cadena);
    allrecords.push_back(Marca(id_temp, date_record, time_record, type_record));
  }
  

  /*
  for(size_t i = 0; i < allschedule.size(); i++){
    allschedule[i].presentacionplan();
  }
  */

  
  /*
  for(const auto &i : lines_schedule){
    string cadena;
    stringstream cadena_virtual(i);
    // cout << i << " 1" << endl;
    cout<<endl;

    for(int j=0; j<=5; j++){
      getline(cadena_virtual, cadena, ';');
      if (j==5)
      {
        cout<<cadena<<endl;
        
      }
    while(getline(cadena_virtual, cadena))cout<<cadena<<endl;
    //while(getline(cadena_virtual, cadena, ';'))cout<<cadena<<endl;
    }
  }*/

  Administrador admin("18781445-6","Marco");
  //usuarios = admin.asignarturnos("1565514F", usuarios, allschedule);
  //usuarios = admin.asignarturnos("1678721F", usuarios, allschedule);

  for(size_t i = 0; i < usuarios.size(); i++)
  {
    usuarios = admin.asignarturnos(usuarios[i].id_user(), usuarios, allschedule);
  }
  for(size_t i = 0; i < usuarios.size(); i++)
  {
    usuarios[i].marcar(usuarios[i].id_user(), allrecords, usuarios);
  }

  for(size_t i = 0; i < usuarios.size(); i++)
  {
    usuarios[i].informe();
  }
  
  /*
  // CICLO FOR PARA COMPROBAR CORRECTAR ASIGNACIÓN DE MARCAS DE UN USUARIO
  for(size_t i = 0; i < usuarios[0].all_records.size(); i++){
    cout<<usuarios[0].all_records[i].dia<<"-"<<usuarios[0].all_records[i].hora<<"-"<<usuarios[0].all_records[i].identificador<<"-"<<usuarios[0].all_records[i].tipo<<endl;  
  }

  for(size_t i = 0; i < usuarios[1].all_records.size(); i++){
    cout<<usuarios[1].all_records[i].dia<<"-"<<usuarios[1].all_records[i].hora<<"-"<<usuarios[1].all_records[i].identificador<<"-"<<usuarios[1].all_records[i].tipo<<endl;  
  }
  */
  
  
  

  /*
  // CICLOS FOR PARA COMPROBAR LA CORRECTA ASIGNACIÓN DE PLANIFICACION
  for(size_t i = 0; i < usuarios.size(); i++){
    for(size_t j = 0; j < ((usuarios[i].plans).size()); j++){
      cout << usuarios[i].get_name();
      usuarios[i].plans[j].presentacionplan();
    }
    cout << "Impresión de prueba" <<endl;
  }
  */
  
  
  
  /*
  for(size_t i = 0; i < ((usuarios[0].plans).size()); i++){
    allschedule[i].presentacionplan();
    cout << "Impresión de prueba" <<endl;
  }*/
  
  /*
  for(size_t i = 0; i < usuarios.size(); i++){
    usuarios[i].show_name();
  }
  */

  /*
  string line_schedule;
  while (getline(file_schedule, line)){
    line_schedule = line;
    for(const auto &i : lines){
      string cadena;
      stringstream cadena_virtual(i);
    for(int i = 0; i <= 5; i++)
      {
        getline(cadena_virtual, cadena, ';');
        if (i==5){
          if()
        }
      }  
  }
  */
  
  

  /*
    string lectura; // Aquí vamos a ir leyendo cada valor por separado
    string cadena = "soy;una cadena;separada por punto y coma"; // La cadena que vamos a separar
    stringstream input_stringstream(cadena); // Convertir la cadena a un stream
    while (getline(input_stringstream, lectura, ';'))
    {
        cout << "Un valor: " << lectura << endl;
    }
  */
}

/*
void muestra_vector(const vector<int>& v)
{
  for (auto x : v)
    cout << x << " ";
  cout << endl;
}*/