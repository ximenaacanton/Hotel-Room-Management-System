#ifndef HABITACIONSuite_H
#define HABITACIONSuite_H

#include <iostream>
#include <string>
#include "Habitacion.h"
using namespace std;
class HabitacionSuite: public Habitacion{
    public:
        HabitacionSuite(int numero); 
        bool checkin(const string &nombre, int adultos, int infantes, double credito);   
        double getTarifaBase() const; 
        string toString() const;
};

#endif