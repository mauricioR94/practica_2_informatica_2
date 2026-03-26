#include <cstdint>
#include <iostream>
using namespace std;
#include "problema13.h"

int** crearMatriz(int filas , int columnas){
    int** matriz = new int*[filas];

    for(int i=0 ; i<filas;i++){
        matriz[i]= new int[columnas];
    }

    return matriz;
}

void liberarMatriz(int** matriz , int filas){
    for(int i=0; i<filas;i++){
        delete [] matriz[i] ;

    }

    delete[] matriz;

}

bool esEstrella(int** matriz, int i, int j ){
    float promedio=0;

    int c = matriz[i][j];    //centro (estrella)
    int l = matriz[i][j-1];  //izquierda
    int r = matriz[i][j+1];  //derecha
    int f = matriz[i-1][j];  //arriba
    int b = matriz[i+1][j];   //abajo

    promedio = (c+f+b+l+r)/5.0;

    if(promedio > 6){
        return true;
    }
    else {
        return false;
    }

}
void cargarMatrizEjemplo(int** matriz, int filas, int columnas){
    int datos[6][8] = {
        {0, 3, 4, 0, 0, 0, 6, 8},
        {5, 13, 6, 0, 0, 0, 2, 3},
        {2, 6, 2, 7, 3, 0, 10, 0},
        {0, 0, 4, 15, 4, 1, 6, 0},
        {0, 0, 7, 12, 6, 9, 10, 4},
        {5, 0, 6, 10, 6, 4, 8, 0}
    };

    for(int i=0; i< filas;i++ ){
        for(int j=0; j< columnas;j++){
            matriz[i][j]=datos[i][j];

        }
    }
}


int contarEstrellas(int** matriz, int filas, int columnas){
    int contador = 0;
    // recorrer cada una de lsa casillas internas de la matriz
    for (int i= 1; i< filas-1; i++){
        for(int j=1; j<columnas-1; j++){

            if(esEstrella(matriz,i,j)){
                contador++;
            }

        }
    }
    return contador;

}

int problema13(){

    int filas=6;
    int columnas = 8;
    int** matriz =nullptr;
    // creo el espacio en memoria
    matriz= crearMatriz(filas,columnas);

    cargarMatrizEjemplo(matriz,filas,columnas);

    cout <<"el numero de estrellas es :" << contarEstrellas(matriz,filas,columnas)<<endl;
    liberarMatriz(matriz, filas);
    return 0;



}
