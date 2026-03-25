#include <iostream>
using namespace std;
#include "problema9.h"

int longitud_arreglo(char* ptr){
    int contador=0 ;
    while( *ptr != '\0'){
        contador++;
        ptr++;

    }
    return contador;
}

void agreg_ceros(char* numero, char*& nuevo,int n){

    int longitud= longitud_arreglo(numero);
    int longitud_nueva=0;
    int modulo = 0 ;
    int ceros =0 ;

    if(longitud % n != 0){
        modulo = longitud % n ;
        ceros = n - modulo;
        longitud_nueva = longitud + ceros;

        //reservo la nueva memoria dinamica
        nuevo = new char[longitud_nueva+1];

        // pongo los ceros al inicio
        for(int i =0; i< ceros;i++){
            nuevo[i]='0';
        }

        // copio la cadena original despues de los ceros

        for(int j=0; j< longitud;j++){
            nuevo[j+ceros]= numero[j];
        }
    nuevo[longitud_nueva]='\0';

    cout <<"cadena nueva: "<< nuevo<< endl;
     }

}

int sumar_bloques (char* cadena, int n){
    int longitud = longitud_arreglo(cadena);
    int suma=0;

    for(int i=0; i<longitud ;i+=n){

        int numero=0;
        for (int j=0;j<n;j++){
            numero = numero*10+(cadena[i+j]-'0');
        }

        suma+=numero;

    }
    return suma;
}



void problema9(){
    int n;
    char numero[15];
    char* nuevo= nullptr;
    cout <<"ingrese un numero n: "<< endl;
    cin >> n;

    cout <<"ingrese una cadena de caracteres numericos: "<< endl;
    cin >> numero;
    cout<<"original: "<< numero <<endl;
    agreg_ceros(numero,nuevo,n);
    cout << "suma: "<< sumar_bloques(nuevo,n)<<endl;

    delete[] nuevo;



}
