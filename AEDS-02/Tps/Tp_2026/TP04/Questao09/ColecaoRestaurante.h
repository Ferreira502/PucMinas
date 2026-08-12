#ifndef COLECAORESTAURANTE_H
#define COLECAORESTAURANTE_H

#include "Restaurante.h"

typedef struct ColecaoRestaurante
{
    int tamanho;
    Restaurante restaurantes[500];
} ColecaoRestaurante;

int get_tamanho(ColecaoRestaurante*);
void adicionar(ColecaoRestaurante*, Restaurante);
Restaurante* get_restaurantes(ColecaoRestaurante*);
void imprimir(ColecaoRestaurante*);
ColecaoRestaurante ler_csv();

#endif