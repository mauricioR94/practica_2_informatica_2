#ifndef PROBLEMA11_H
#define PROBLEMA11_H
#include <cstdint>
const int FILAS = 15;
const int ASIENTOS = 20;

uint32_t* crear_sala();
void liberarSala(uint32_t* sala);
int convertirFila(char fila);
bool asientoValido(int asiento);
bool estaReservado(uint32_t filaBits, int asiento);
bool reservarAsiento(uint32_t* sala, char fila, int asiento );
bool cancelarReserva(uint32_t* sala, char fila, int asiento);
void mostrarSala(const uint32_t* sala);

int problema11();
#endif // PROBLEMA11_H
