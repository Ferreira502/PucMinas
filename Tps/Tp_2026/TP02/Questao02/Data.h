#ifndef DATA_H
#define DATA_H

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

Data parse_data(char*);

void formatar_data(Data*, char*);

#endif