#include "HabitacionJunior.h"
#include <iostream>
#include <string>
using namespace std;

//implementación de Habitación JUNIOR
HabitacionJunior::HabitacionJunior(int numero):Habitacion(numero){ 
}

bool HabitacionJunior::checkin(const string &nombre, int adultos, int infantes, double credito){
    if (this->adultos+this->infantes<=4){
        return Habitacion::checkin(nombre, adultos, infantes, credito);
    }else{
        return false;
    }
}

double HabitacionJunior::getTarifaBase() const{ 
    return Habitacion::getTarifaBase()+Habitacion::getTarifaBase()*.20;
}

string HabitacionJunior::toString() const{
    return Habitacion::toString()+",Habitación Junior";
}