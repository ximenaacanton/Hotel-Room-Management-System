#include "Habitacion.h"
#include "HabitacionJunior.h"
#include "HabitacionSuite.h"
#include "HabitacionDeluxe.h"
#include "Hotel.h"
#include <vector>
#include <iostream> 
using namespace std;

int main(){
    string nombreHotel; //VARIABLE EN MAIN
    cout<<"Ingresa nombre del hotel: ";
    cin>>nombreHotel;

    int numJunior,
        numSuite,
        numDeluxe;
    cout<<"Ingresa el número de habitaciones Junior: ";
    cin>>numJunior;
    cout<<"Ingresa el número de habitaciones Suite: ";
    cin>>numSuite;
    cout<<"Ingresa el número de habitaciones Deluxe: ";
    cin>>numDeluxe;

    Hotel hotel(nombreHotel, numJunior, numSuite, numDeluxe); //CREA HOTEL

    int opcion=0; //opcion menú main
    while(opcion!=6){
        cout << "\nMenú de opciones:\n";
        cout << "1) Hacer check-in\n";
        cout << "2) Hacer check-out\n";
        cout << "3) Realizar cargos a habitación\n";
        cout << "4) Ingresos por tarifas\n";
        cout << "5) Generar reporte de ocupación\n";
        cout << "6) Salir\n";
        cout << "Ingresa la opción que desees: ";
        cin >> opcion;     

        
        if(opcion==1){
            string nombreHuesped;
            int adultos,
                infantes,
                tipoHabitacion;
            double credito;
            cout<<"Ingresa el nombre del huésped: ";
            cin>>nombreHuesped;
            cout<<"Ingresa el número de adultos: ";
            cin>>adultos;    
            cout<<"Ingresa el número de infantes: ";
            cin>>infantes;
            cout<<"Ingresa el crédito de la habitación: ";
            cin>>credito;
            cout<<"Tipo de habitación (1=Junior, 2=Suite, 3=Deluxe): ";
            cin>>tipoHabitacion;

            if((adultos+infantes)>8){
                cout<<"El número de personas excede el máximo permitido en cualquier habitación. Haga reservaciones separadas."<<endl;
                continue;
            }
            
            int numeroHabitacion=hotel.checkin(nombreHuesped, adultos, infantes, credito, tipoHabitacion);
            if(numeroHabitacion!=-1){//-1 significa que no hizo el checkin
                cout<<"Check-in exitoso. Su número de habitación es: "<<numeroHabitacion<<endl;
            }else{
                cout<<"No hay habitaciones disponibles del tipo seleccionado o la cantidad de personas se excede del límite permitido en ese tipo de habitación."<<endl;
            }
        }else if(opcion==2){
            int numeroHabitacion;
            cout<<"Número habitación para check-out: ";
            cin>>numeroHabitacion;

            if(hotel.checkout(numeroHabitacion)){
                cout<<"Check-out exitoso.";
            } else{
                cout<<"No se pudo realizar check out.";
            }

        }else if (opcion==3) {
            int numeroHabitacion;
            double cantidad;
            cout << "Número de la habitación para realizar el cargo: ";
            cin >> numeroHabitacion;
            cout << "Cantidad a cargar: ";
            cin >> cantidad;
            if (hotel.realizarCargosHabitacion(numeroHabitacion, cantidad)) {
                cout << "Cargo realizado exitosamente.\n";
            }else{
                cout << "No se pudo realizar el cargo.\n";
            }

        } else if (opcion ==4) {
            double totalIngresos = hotel.getTotalXTarifaBase();
            cout<< "Ingresos totales por tarifas: "<<totalIngresos<<endl;
        } else if (opcion ==5) {
            cout<<hotel<<endl;
        } else if (opcion ==6) {
            cout << "Saliendo del programa.\n";
        } else {
            cout << "Opción inválida. Por favor intentelo de nuevo.\n";
        }
           
    }
    return 0;
}
