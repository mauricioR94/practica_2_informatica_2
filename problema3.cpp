#include <iostream>
#include "problema3.h"

using namespace std;

bool comp_cads(const char* a ,const char* b){
    while(*a != '\0' and *b != '\0'){
        if(*a != *b){
            return false;
            cout<< a <<endl;
        }

        else{
           a++;
           b++;

        }

    }
    if(*a == '\0'  and *b == '\0'){
        return true;
    }
    else {
        return false;
    }
}

void problema3(){
    char cadena1[100];
    char cadena2[100];
    cin.ignore(); // limpiar buffer
    cout << "ingrese la primera cadena de caracteres menor de 100 caracteres  a :"<<endl;
    cin.getline(cadena1, 100);

    cout << "ingrese la segunda cadena de caracteres menor de 100 caracteres b :"<<endl;
    cin.getline(cadena2, 100);

    bool resultado = comp_cads(cadena1, cadena2);

    if(resultado){
        cout << "Las cadenas son iguales" << endl;
    }
    else{
        cout << "Las cadenas son diferentes" << endl;
    }
}


