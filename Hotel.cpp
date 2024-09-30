/*
Ximena Cantón Ayllón 
Hotel Room Management System 
*/
#include "Hotel.h"
#include "HabitacionJunior.h"
#include "HabitacionSuite.h"
#include "HabitacionDeluxe.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Hotel::Hotel(const string &nombre, int numJunior, int numSuite, int numDeluxe){
    this->nombre=nombre;
    int numeroHabitacion=100;
    for (int i = 0; i < numJunior; ++i) {
        habitaciones.push_back(new HabitacionJunior(numeroHabitacion++));
    }
        for (int i = 0; i < numSuite; ++i) {
        habitaciones.push_back(new HabitacionSuite(numeroHabitacion++));
    }
        for (int i = 0; i < numDeluxe; ++i) {
        habitaciones.push_back(new HabitacionDeluxe(numeroHabitacion++));
    }
}

//destructor para liberar la memoria
Hotel::~Hotel() {
    for (Habitacion*habitacion:habitaciones) { 
        delete habitacion;
    }
}

//implementación de check in
int Hotel::checkin(const string &nombre, int adultos, int infantes, double credito, int tipoHabitacion){
    for (Habitacion*habitacion:habitaciones){
        if(habitacion->isDisponible()){ //getter en habitacion
            if ((tipoHabitacion==1 && dynamic_cast<HabitacionJunior*>(habitacion)) ||
                (tipoHabitacion==2 && dynamic_cast<HabitacionSuite*>(habitacion)) ||
                (tipoHabitacion==3 && dynamic_cast<HabitacionDeluxe*>(habitacion))) {
                if (habitacion->checkin(nombre, adultos, infantes, credito)) {            
                    return habitacion->getNumero(); //getter en habitacion
                }
        }
        }
    }
    return -1; //ESTA LLENO
}

//implementación de check out
bool Hotel:: checkout(int numeroHabitacion){
    for (Habitacion*habitacion:habitaciones){
        if(habitacion->getNumero()==numeroHabitacion){
            return habitacion->checkout(); //método check out en habitacion
        }
    }
    return false; //no se realizó check out
}

//implementación de realizarCargosHabitacion
bool Hotel::realizarCargosHabitacion(int numeroHabitacion, double cantidad){
    for (Habitacion*habitacion:habitaciones){
        if(habitacion->getNumero()==numeroHabitacion){
            return habitacion->realizarCargo(cantidad);
        }
    }
    return false; //no se realizó cargo
}

//implementación de getTotalXTarifaBase
double Hotel:: getTotalXTarifaBase()const {
    double total=0.0;
    for (Habitacion*habitacion:habitaciones){
        if(!habitacion->isDisponible()){
            total=total+habitacion->getTarifaBase();
        }
    }
    return total;
}

//implementación de imprimeOcupacion
void Hotel:: imprimeOcupacion(){
    cout<<"Ocupación en "<<nombre<<endl;
    for (Habitacion*habitacion:habitaciones){
        if(!habitacion->isDisponible()){
            cout<<habitacion->toString()<<endl;
        }
    }    
}

Habitacion* Hotel::operator[](int numeroHabitacion){
    for (Habitacion*habitacion:habitaciones){
        if(habitacion->getNumero()==numeroHabitacion){
            return habitacion;
        }
    }
    return nullptr; //indica que no se encontró habitación con el número especificado.
}

ostream& operator<<(ostream& os, const Hotel& hotel){
    os<<"Hotel: "<<hotel.nombre<<endl;
    for (Habitacion* habitacion:hotel.habitaciones){
        if(!habitacion->isDisponible()){
            os<<habitacion->toString()<<endl;
        }
    }
    os<<"Total acumulado por tarifa base: $"<<hotel.getTotalXTarifaBase()<<endl;
    return os;
}