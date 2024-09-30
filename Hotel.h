/*
Ximena Cantón Ayllón 
Hotel Room Management System 
*/
#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include "Habitacion.h"
#include <vector>
using namespace std;

class Hotel{
    private:
        //atributos
        vector<Habitacion*>habitaciones;//vector 
        string nombre;

    public:
        //Constructor que recibe el nombre del hotel
        Hotel(const string &nombre, int numJunior, int numSuite, int numDeluxe);

        // Destructor para liberar memoria
        ~Hotel();

        //check in 
        int checkin(const string &nombre, int adultos, int infantes, double credito, int tipoHabitacion);

        //check out
        bool checkout(int numeroHabitacion);

        //realizarCargosHabitacion
        bool realizarCargosHabitacion(int numeroHabitacion, double cantidad);

        //getTotalXTarifaBase
        double getTotalXTarifaBase() const;

        //imprimeOcupacion
        void imprimeOcupacion();

        Habitacion* operator[](int numeroHabitacion);
        friend ostream& operator<<(ostream& os, const Hotel& hotel);
};
#endif