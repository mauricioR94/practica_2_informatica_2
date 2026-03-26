#include <cstdint>
#include <iostream>
using namespace std;
#include "problema11.h"

// funcion para crear la sala de cine
uint32_t* crear_sala(){

    //reserva de momoria en el heap para el tablero
    uint32_t* sala = new uint32_t[FILAS];

    for(int i=0; i < FILAS;i++){
        sala[i]=0;
    }

    return sala;
}

// funcion para liberar memoria

void liberarSala(uint32_t* sala){
    delete []sala;
}


int convertirFila(char fila){
    // convierte a mayuscula
    fila = toupper(fila);

    if (fila >= 'A' && fila <'A'+ FILAS){  // DESDE LA 'A'=65 HASTA LA 'O'=79
        return fila - 'A';

    }

    return -1;
}

//validar que el asiento este entre 1 y 20
bool asientoValido(int asiento){
    if(asiento >=1 && asiento <= ASIENTOS ){
        return true;
    }
    return false ;

}

bool estaReservado(uint32_t filaBits, int asiento){
    int posicion = asiento -1;
    uint32_t mascara = 1<< posicion;

    if ((filaBits & mascara) != 0){
        return true;

    }

    else{
        return false;

    }
}

bool reservarAsiento(uint32_t* sala, char fila, int asiento ){
    // convertir el valor de la letra a un numero que indica la fila
    int i = convertirFila(fila);

    // validar si el asiento esta entre 1 y 20

    if(i ==-1 || !asientoValido(asiento)){
        return false;
    }

    uint32_t mascara = 1 << (asiento-1);

    if ((sala[i] & mascara)!=0){
        return false;
    }

    sala[i] |= mascara;

    return true ;

}

bool cancelarReserva(uint32_t* sala, char fila, int asiento){
    int i = convertirFila(fila);
    // validar si el asiento esta entre 1 y 20

    if(i ==-1 || !asientoValido(asiento)){
        return false;
    }
    uint32_t mascara = 1 << (asiento-1);

    if ((sala[i] & mascara)==0){
        return false;
    }

    sala[i] &= ~ mascara;

    return true ;

}

void mostrarSala(const uint32_t* sala){
    cout << "\n+++++++++++++++++++++SALA DE CINE++++++++++++++++++++++\n";
    cout << "    ";

    for (int j = 1; j <= ASIENTOS; j++){
        cout << j << "   ";
    }
    cout << endl;

    for (int i = 0; i < FILAS; i++){
        cout << char('A' + i) << " : ";

        for (int j = 1; j <= ASIENTOS; j++){
            if (estaReservado(sala[i], j)){  //sala[i] es la fila actual en forma de bits
                cout << "+   ";
            }
            else{
                cout << "-   ";
            }
        }

        cout << endl;
    }
}




int problema11() {
    uint32_t* sala = crear_sala();

    int opcion;
    char fila;
    int asiento;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Mostrar sala" << endl;
        cout << "2. Reservar asiento" << endl;
        cout << "3. Cancelar reserva" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
            mostrarSala(sala);
            break;

        case 2:
            cout << "Ingrese la fila (A-O): ";
            cin >> fila;
            cout << "Ingrese el asiento (1-20): ";
            cin >> asiento;

            if (reservarAsiento(sala, fila, asiento)) {
                cout << "Reserva realizada con exito." << endl;
            } else {
                cout << "No se pudo reservar el asiento." << endl;
            }
            break;

        case 3:
            cout << "Ingrese la fila (A-O): ";
            cin >> fila;
            cout << "Ingrese el asiento (1-20): ";
            cin >> asiento;

            if (cancelarReserva(sala, fila, asiento)) {
                cout << "Reserva cancelada con exito." << endl;
            } else {
                cout << "No se pudo cancelar la reserva." << endl;
            }
            break;

        case 4:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 4);

    liberarSala(sala);
    return 0;
}
