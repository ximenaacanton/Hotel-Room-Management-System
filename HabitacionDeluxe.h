#ifndef HABITACIONDeluxe_H
#define HABITACIONDeluxe_H

#include <iostream>
#include <string>
#include "Habitacion.h"
using namespace std;
class HabitacionDeluxe: public Habitacion{
    public:
        HabitacionDeluxe(int numero); 
        bool checkin(const string &nombre, int adultos, int infantes, double credito);   
        double getTarifaBase() const; 
        string toString() const;
};

#endif