#include <cstdint>
#include <iostream>
using namespace std;
#include "problema15.h"

void obtenerBordes(const int* R,int& izq, int& sup, int& der, int& inf){

    izq= R[0];        //x
    sup= R[1];        //y
    der= R[0] + R[2]; //x+ ancho
    inf= R[1] + R[3]; //y+ alto


}

void interseccionRecs(const int* A, const int* B, int* C){
    int izqA, supA, derA, infA;
    int izqB, supB, derB, infB;


    // obtener bordes de A
    obtenerBordes(A, izqA, supA,derA,infA);

    //obtener los bordes de B
    obtenerBordes(B, izqB, supB,derB,infB);

    // CALCULAR INTERSECCION
    int izqC, supC, derC, infC;

    // interseccion izquierda
    if( izqA > izqB){
        izqC = izqA;
    }
    else{
        izqC = izqB;
    }
    // interseccion superior
    if( supA > supB){
        supC = supA;
    }
    else{
        supC = supB;
    }

    // interseccion derecha
    if (derA < derB) {
        derC = derA;
    }
    else {
        derC = derB;
    }
    // interseccion inferior
    if (infA < infB) {
        infC = infA;
    }
    else {
        infC = infB;
    }


    // verificar si la interseccion es valida

    if( derC > izqC && infC > supC){
        C[0] = izqC;
        C[1] = supC;
        C[2] = derC - izqC;
        C[3] = infC - supC;

    }

    else {
        C[0] = 0;
        C[1] = 0;
        C[2] = 0;
        C[3] = 0;
    }


}

void mostrarRec(const int* R){
    cout<< "{"<<R[0]<<", "<<R[1]<<", "<<R[2]<<", "<<R[3]<<"}"<<endl;
}


int problema15(){



    int A[4];
    int B[4];
    int C[4];
    // ingresar los datos del rectangulo A
    cout <<"ingreseel valor de X_A :"<< endl;
    cin >> A[0];

    cout <<"ingreseel valor de Y_A :"<< endl;
    cin >> A[1];

    cout <<"ingreseel valor de alto_A :"<< endl;
    cin >> A[2];

    cout <<"ingreseel valor de ancho_A :"<< endl;
    cin >> A[3];

    // ingresar los datos del rectangulo B
    cout <<"ingreseel valor de X_B :"<< endl;
    cin >> B[0];

    cout <<"ingreseel valor de Y_B :"<< endl;
    cin >> B[1];

    cout <<"ingreseel valor de alto_B :"<< endl;
    cin >> B[2];

    cout <<"ingreseel valor de ancho_B :"<< endl;
    cin >> B[3];

    interseccionRecs(A, B, C);

    cout << "Rectangulo A: ";
    mostrarRec(A);

    cout << "Rectangulo B: ";
    mostrarRec(B);

    cout << "Interseccion C: ";
    mostrarRec(C);

    return 0;
}
