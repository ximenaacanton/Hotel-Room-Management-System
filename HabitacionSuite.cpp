#include "HabitacionSuite.h"
#include <iostream>
#include <string>
using namespace std;

//implementación de Habitación suite
HabitacionSuite::HabitacionSuite(int numero):Habitacion(numero){ 
}

bool HabitacionSuite::checkin(const string &nombre, int adultos, int infantes, double credito){
    if (this->adultos+this->infantes<=6){
        return Habitacion::checkin(nombre, adultos, infantes, credito);
    }else{
        return false;
    }
}

double HabitacionSuite::getTarifaBase() const{ 
    return Habitacion::getTarifaBase()+Habitacion::getTarifaBase()*.30;
}

string HabitacionSuite::toString() const{
    return Habitacion::toString()+",Habitación Suite";
}