#include "Data.h"
#include <stdio.h>

Data parse_data(char *s)
{
    Data data;
    sscanf(s, "%d-%d-%d", &data.ano, &data.mes, &data.dia);
    return data;
}

void formatar_data(Data *data, char *saidaLinha)
{
    sprintf(saidaLinha, "%02d/%02d/%04d", data->dia, data->mes, data->ano );
}