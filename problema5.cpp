#include <iostream>
#include "problema5.h"
using namespace std;


int cont_digitos(int digit){
    int i=0;
    if (digit == 0)
        i = 1;

    while (digit != 0 ){
        digit/=10;
        i++;
    }

    return i;
}

// reservar memoria, llenar los espacios de memoria con los numeros pero desde el msb al menor valor
void res_llena( int num, char *&p){
    int n = cont_digitos(num);
    p = new char[n+1];

    // definir el fin de cadena
    p[n+1]= '\0';

    for(int i=n;i>0;i--){
        p[i]=(num %10)+'0'; //+48
        num /= 10;
    }

}
void problema5(){
    int digit;
    cout<< "INGRESE UN NUMERO ENTERO 0"<<endl;
    cin >> digit;
    char* cadena = nullptr;

    res_llena(digit,cadena);

      cout << cadena << endl;

    delete[] cadena;

    cont_digitos(digit);
}



