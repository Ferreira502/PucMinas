#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Data.h"
#include "Hora.h"

typedef struct Restaurante
{
    int id;
    char nome[100];
    char cidade[100];
    int capacidade;
    double avaliacao;
    char tipo1[50];
    char tipo2[50];
    char faixaPreco[10];
    Hora horario_abertura;
    Hora horario_fechamento;
    Data data_abertura;
    int aberto;
    
} Restaurante;

int ler_campo(char*, int, char*);
Restaurante ler_restaurante(char*);
void formatar_restaurante(Restaurante*, char*);

#endif