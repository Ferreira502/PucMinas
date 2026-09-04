#include <iostream>
#include "Grafo.h"
#include "Leitura.h"

using namespace std;

int main() {
    int n = lerQuantidadeVertices();

    Grafo grafo(n);

    lerArestas(grafo);

    grafo.mostrarMatriz();

    return 0;
}