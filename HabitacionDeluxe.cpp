#include "HabitacionDeluxe.h"
#include <iostream>
#include <string>
using namespace std;

//implementación de Habitación deluxe
HabitacionDeluxe::HabitacionDeluxe(int numero):Habitacion(numero){ 
}

bool HabitacionDeluxe::checkin(const string &nombre, int adultos, int infantes, double credito){
    if (this->adultos+this->infantes<=8){
        return Habitacion::checkin(nombre, adultos, infantes, credito);
    }else{
        return false;
    }
}

double HabitacionDeluxe::getTarifaBase() const{ 
    return Habitacion::getTarifaBase()+Habitacion::getTarifaBase()*.50;
}

string HabitacionDeluxe::toString() const{
    return Habitacion::toString()+",Habitación Deluxe";
}