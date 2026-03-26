#include <cstdint>
#include <iostream>
using namespace std;
#include "problema17.h"

int sumaDivisoresPropios(int numero){
    int suma = 0;
    for(int i=1; i< numero;i++){
        if(numero % i == 0){
            suma +=i;
        }
    }
    return suma;
}

bool esAmigable(int n){

    int b = sumaDivisoresPropios(n);

    if(b != n && sumaDivisoresPropios(b) == n){
        return true;
    }

    return false;
}

int sumaAmigosMenores(int n){
    int suma=0;

    for(int i=0; i<n;i++){
        if(esAmigable(i)){
            suma += i;
        }
    }
    return suma;
}


int problema17(){
    int n ;
    cout << "ingrese un numero N: "<< endl;
    cin >> n;

    cout<<"el resultado de la suma es: "<< sumaAmigosMenores(n);

    return 0 ;

}
