#ifndef HABITACIONJUNIOR_H
#define HABITACIONJUNIOR_H

#include <iostream>
#include <string>
#include "Habitacion.h"
using namespace std;
class HabitacionJunior: public Habitacion{
    public:
        HabitacionJunior(int numero); 
        bool checkin(const string &nombre, int adultos, int infantes, double credito);   
        double getTarifaBase() const; 
        string toString() const;
};

#endif