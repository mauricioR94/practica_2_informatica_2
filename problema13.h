#ifndef PROBLEMA13_H
#define PROBLEMA13_H
int** crearMatriz(int filas , int columnas);
void liberarMatriz(int** matriz , int filas);
bool esEstrella(int** matriz, int i, int j );
void cargarMatrizEjemplo(int** matriz, int filas, int columnas);
int contarEstrellas(int** matriz, int filas, int columnas);
int problema13();
#endif // PROBLEMA13_H
