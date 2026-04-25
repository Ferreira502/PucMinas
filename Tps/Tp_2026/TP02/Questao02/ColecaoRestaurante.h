#ifndef COLECAORESTAURANTE_H
#define COLECAORESTAURANTE_H

#include "Restaurante.h"

typedef struct ColecaoRestaurante
{
    int tamanho;
    Restaurante restaurantes[500];
} ColecaoRestaurante;

int getTamanho(ColecaoRestaurante*);

void adicionar(ColecaoRestaurante*, Restaurante);

Restaurante* getRestaurantes(ColecaoRestaurante*);

void imprimir(ColecaoRestaurante*);

ColecaoRestaurante lerCsv();

#endif