#include <iostream>
using namespace std;
#include "problema7.h"

int cont_caracteres(char *ptr){
    int i =0;
    while(*ptr != '\0'){
        i++;
        ptr++;

    }
    return i; // i es un contador para saber la longitud de la cadena ingresada

}

// funcion que me va a decir si la letra es igual a alguna de las letras anteriores

bool se_repite(char*ptr,int limite,char actual ){
    for(int i=0; i<limite;i++){
        if(*(ptr+i) == actual){
            return false;
        }

    }
    return true;
}


void llenar_nueva(char* cadena, char*&nueva ){

    int n= cont_caracteres(cadena);
    nueva =new char[n+1]; // reservo memoria en el heap
    int i =0;  //contador para la cadena original
    int j=0;
    while(*(cadena+i) != '\0'){
        if(se_repite(cadena,j,*(cadena+j))) {
          *(nueva+j)=*(cadena+i);
            j++;

        }
        i++;
    }

    *(nueva+j)='\0';
}




int problema7(){
    char cadena[100];
    char* nueva = nullptr;

    cout << "ingrese una cadena de maximo 100 caracteres: "<<endl;
    cin >> cadena ;
    llenar_nueva(cadena,nueva);
    cout << "cadena original :"<<cadena<<", "<< "cadena sin letras repetidas: "<< nueva <<endl;
    delete[]nueva;
    return 0;

}







