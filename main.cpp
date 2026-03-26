#include <iostream>
using namespace std;

// Incluir todos los .h
#include "problema1.h"
#include "problema3.h"
#include "problema5.h"
#include "problema7.h"
#include "problema9.h"
#include "problema11.h"
#include "problema13.h"
#include "problema15.h"
#include "problema17.h"
int main() {
    int opcion;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Problema 1" << endl;
        cout << "3. Problema 3" << endl;
        cout << "5. Problema 5" << endl;
        cout << "7. Problema 7" << endl;
        cout << "9. Problema 9" << endl;
        cout << "11. Problema 11" << endl;
        cout << "13. Problema 13" << endl;
        cout << "15. Problema 15" << endl;
        cout << "17. Problema 17" << endl;
        cin >> opcion;

        switch(opcion) {
        case 1:
            problema1();
            break;


        case 3:{
            problema3();
            break;
            }

        case 5:{
            problema5();
            break;
        }
        case 7:{
            problema7();
            break;
        }

        case 9:{
            problema9();
            break;
        }

        case 11:{
            problema11();
            break;
        }
        case 13:{
            problema13();
            break;
        }
        case 15:{
            problema15();
            break;
        }
        case 17:{
            problema17();
            break;
        }
        }




    }while(opcion != 0);

    return 0;
}
