#include "Hora.h"
#include <stdio.h>

Hora parse_hora(char *s)
{
    Hora hora;
    sscanf(s, "%d:%d", &hora.hora, &hora.minuto);
    return hora;
}

void formatar_hora(Hora *hora, char *saidaLinha)
{
    sprintf(saidaLinha, "%02d:%02d", hora->hora, hora->minuto);
}