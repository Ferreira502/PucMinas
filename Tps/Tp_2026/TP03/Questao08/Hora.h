#ifndef HORA_H
#define HORA_H

typedef struct Hora
{
    int hora;
    int minuto;
} Hora;

Hora parse_hora(char*);

void formatar_hora(Hora*, char*);

#endif