#include <iostream>
#include <cstdlib>
#include "DFS.hpp"

using namespace std;

int main()
{
    vector<int> ordem;
    ENTRADA in;
    getIn(&in);

    int **matrizAdj = alocaMatrizNula(in.n, in.n);

    criaMatrizAdj(matrizAdj, in.m, in.b);

    //imprimeMatriz(matrizAdj, in.n, in.n);

    buscaProfundidade(matrizAdj, in.n, in.i, ordem);

    imprimeOrdem(ordem);

    freeMatriz(matrizAdj, in.n);
    
    return 0;
}
