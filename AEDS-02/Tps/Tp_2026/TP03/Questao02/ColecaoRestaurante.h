#ifndef COLECAORESTAURANTE_H
#define COLECAORESTAURANTE_H

#include "Restaurante.h"

typedef struct Colecao_restaurante
{
    int tamanho;
    Restaurante restaurantes[500];
} Colecao_restaurante;

int get_tamanho(Colecao_restaurante*);
void adicionar(Colecao_restaurante*, Restaurante);
Restaurante* get_restaurantes(Colecao_restaurante*);
void imprimir(Colecao_restaurante*);
Colecao_restaurante ler_csv();

#endif