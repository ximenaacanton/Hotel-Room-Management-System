/*
Ximena Cantón Ayllón 
Hotel Room Management System 
*/
#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>
#include <string>
using namespace std;

class Habitacion{
    protected:
        //atributos
        int numero;
        string nombre;
        int adultos;
        int infantes;
        double credito;
        double cargo;
        bool disponible;

    public:
        //constructor default
        Habitacion();
        //constructor con parametros
        Habitacion(int numero);

        //getters
        int getNumero() const;
        bool isDisponible() const;

        //setter
        void setNumero(int numero);

        //check in
        virtual bool checkin(const string &nombre, int adultos, int infantes, double credito); //const: constante //tipo string //&: referencia 

        //check out
        bool checkout();

        //getTarifaBase
        virtual double getTarifaBase() const; //método virtual porque cambia segun la habitación

        //realizarCargo
        bool realizarCargo(double cantidad);

        //toString
        virtual string toString() const; //método virtual

        virtual ~Habitacion() = default;

        friend double operator+(double tarifaBaseAcumulado, const Habitacion& habitacion);

};

#endif