#include <iostream>
#include "problema1.h"

using namespace std;

void problema1(){
    int cash;
    int cantidad ;
    cout<<"ingrese la cantidad de dinero :";
    cin >> cash;

    int den []={50000,20000,10000,5000,2000,1000,500,200,100,50};

    for(int i=0;i <= sizeof(den)/sizeof(den[0]);i++){
        cantidad = cash/den[i];
        cash= cash % den[i];
        cout << "$"<< den[i] << " = " <<cantidad  << endl;

        if(cash < 50  and den[i] == 50){

        cout <<"faltante = "<< cash <<endl;

        }



    }



}
