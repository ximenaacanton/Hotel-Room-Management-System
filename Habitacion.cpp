/*
Ximena Cantón Ayllón 
Hotel Room Management System 
*/
#include "Habitacion.h"
#include <iostream>
#include <string>
using namespace std;


Habitacion::Habitacion(){ //Constructor default
    this->nombre=""; 
    this->numero=0;
    this->adultos=0;
    this->infantes=0;
    this->credito=0.0;
    this->cargo=0.0;
    this->disponible=true;
}

Habitacion::Habitacion(int numero){ //Constructor que recibe como parámetro el número de la habitación
    this->numero=numero;
    this->nombre=""; 
    this->adultos=0;
    this->infantes=0;
    this->credito=0.0;
    this->cargo=0.0;
    this->disponible=true;
}


int Habitacion::getNumero()const{ //implementación de los getters
    return this->numero;
}

bool Habitacion::isDisponible()const{
    return this->disponible;
}


void Habitacion::setNumero(int numero){ //implementación del setter
    this->numero=numero;
}

//implementación de check in
bool Habitacion::checkin(const string &nombre, int adultos, int infantes, double credito){ 
    if (this->disponible){
        this->nombre=nombre;
        this->adultos=adultos;
        this->infantes=infantes;
        this->credito=credito;
        this->cargo=0.0;
        this->disponible=false;
        return true;
    } else{
        return false;
    }
}

//implementación de check out
bool Habitacion::checkout(){
    if (!this->disponible) { // La habitación está ocupada
        this->nombre="";
        this->adultos=0;
        this->infantes=0;
        this->credito=0.0;
        this->cargo=0.0;
        this->disponible=true;
        return true;
    } else {
        return false;
    }
}

//implementación getTarifaBase
double Habitacion::getTarifaBase() const{ //const: constante
    const double tarifaAdulto=650.0;
    const double tarifaInfante=250.0;
    return(this->adultos*tarifaAdulto)+(this->infantes*tarifaInfante);
}

//implementación realizarCargo
bool Habitacion::realizarCargo(double cantidad){
    if(cantidad>0 && (this->cargo+cantidad)<=this->credito){
        this->cargo=cantidad+this->cargo;
        return true;
    } else{
        return false;
    }
}

//implementación toString
string Habitacion::toString() const{
    return to_string(this->numero)+",Huesped:"+this->nombre+",Tarifa Base:"+to_string(this->getTarifaBase())+",Credito:"+to_string(this->credito)+",Cargos:"+to_string(this->cargo);
}

//sobrecarga +
double operator+(double tarifaBaseAcumulado, const Habitacion& habitacion){
    return tarifaBaseAcumulado+habitacion.getTarifaBase();
}