#include "Restaurante.h"
#include <stdio.h>
#include <string.h>

int lerCampo(char *linha, int pos, char *campo)
{
    int i = 0;
    
    while (linha[pos] != ',' && linha[pos] != '\0' && linha[pos] != '\n')
    {
        campo[i] = linha[pos];
        i++;
        pos++;
    }
    
    campo[i] = '\0';
    
    pos++; 

    return pos;
}

Restaurante ler_restaurante(char *linha)
{
    Restaurante r;
    char campo[100];
    char horarioAbertura[10];
    char horarioFechamento[10];
    char dataStr[20];
    char abertoStr[10];
    char cozinha[100];
    int pos = 0;
    int j = 0, k = 0;

    // id
    pos = lerCampo(linha, pos, campo);
    sscanf(campo, "%d", &r.id);

    // nome
    pos = lerCampo(linha, pos, r.nome);

    // cidade
    pos = lerCampo(linha, pos, r.cidade);

    // capacidade
    pos = lerCampo(linha, pos, campo);
    sscanf(campo, "%d", &r.capacidade);

    // avaliacao
    pos = lerCampo(linha, pos, campo);
    sscanf(campo, "%lf", &r.avaliacao);

    // cozinha
    pos = lerCampo(linha, pos, cozinha);
    
    while (cozinha[j] != ';')
    {
        r.tipo1[k++] = cozinha[j++];
    }

    r.tipo1[k] = '\0';
    j++;
    k = 0;

    while (cozinha[j] != '\0')
    {
        r.tipo2[k++] = cozinha[j++];
    }
    
    r.tipo2[k] = '\0';

    // faixa preco
    pos = lerCampo(linha, pos, r.faixaPreco);

    // horario
    pos = lerCampo(linha, pos, campo);

    j = 0; k = 0;

    while (campo[j] != '-')
    {
        horarioAbertura[k++] = campo[j++];
    }

    horarioAbertura[k] = '\0';
    j++;
    k = 0;

    while (campo[j] != '\0')
    {
        horarioFechamento[k++] = campo[j++];
    }
    
    horarioFechamento[k] = '\0';

    r.horarioAbertura = parse_hora(horarioAbertura);
    r.horarioFechamento = parse_hora(horarioFechamento);

    // data
    pos = lerCampo(linha, pos, dataStr);
    r.dataAbertura = parse_data(dataStr);

    // aberto
    pos = lerCampo(linha, pos, abertoStr);
    
    if (abertoStr[0] == 't')
    {
        r.aberto = 1;
    }
    
    else
    {
        r.aberto = 0;
    }
    
    return r;
}

void formatar_restaurante(Restaurante *r, char *buffer)
{
    char dataStr[20];
    char horarioAbertura[10];
    char horarioFechamento[10];

    formatar_data(&r->dataAbertura, dataStr);
    formatar_hora(&r->horarioAbertura, horarioAbertura);
    formatar_hora(&r->horarioFechamento, horarioFechamento);

    char abertoStr[10];
    if (r->aberto == 1)
    {
        sprintf(abertoStr, "true");
    }

    else
    {
        sprintf(abertoStr, "false");
    }
    
    sprintf(buffer, "[%d ## %s ## %s ## %d ## %.1f ## [%s,%s] ## %s ## %s-%s ## %s ## %s]",
        r->id, r->nome, r->cidade, r->capacidade, r->avaliacao,
        r->tipo1, r->tipo2, r->faixaPreco,
        horarioAbertura, horarioFechamento,
        dataStr, abertoStr);
}