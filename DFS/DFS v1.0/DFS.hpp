#ifndef DFS_H
#define DFS_H

#include <vector>

using namespace std;

struct ENTRADA {
    int n, m, b, i;
};

void getIn(ENTRADA *);

int ** alocaMatrizNula(int, int);

void freeMatriz(int **, int);

void criaMatrizAdj(int ** matrizAdj, int nArestas, int b);

void imprimeMatriz(int ** matrizAdj, int lin, int col);

void buscaProfundidade(int **, int, int, vector<int> &);

void imprimeOrdem(vector<int> &);

#endif
