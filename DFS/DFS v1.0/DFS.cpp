#include <iostream>
#include <stack>
#include "DFS.hpp"

#define BIDIRECIONAL 0
#define DIRECIONAL 1

using namespace std;

void getIn(ENTRADA *in) {
    cin >> in->n >> in->m >> in->b >> in->i;
}

int ** alocaMatrizNula(int lin, int col) {
    int **aux = (int **) malloc(sizeof(int *) * lin);
    if(aux == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for(int j = 0; j < lin; j++) {
        aux[j] = (int *) malloc(sizeof(int) * lin);
        for(int k = 0; k < col; k++) 
            aux[j][k] = 0;
    }
    return aux;
}

void freeMatriz(int **mat, int lin) {
    for(int i = 0; i < lin; i++) 
        free(mat[i]);
    free(mat);
}

void criaMatrizAdj(int ** matrizAdj, int nArestas, int b) {
    for(int j = 0; j < nArestas; j++) {
        int verticeOrigem, verticeDestino, arestaPeso;
        cin >> verticeOrigem >> verticeDestino >> arestaPeso;
        matrizAdj[verticeOrigem - 1][verticeDestino - 1] = arestaPeso;
        if(b == BIDIRECIONAL)
            matrizAdj[verticeDestino - 1][verticeOrigem - 1] = arestaPeso;
    }
}

void imprimeMatriz(int ** matrizAdj, int lin, int col) {
    for(int j = 0; j < lin; j++) {
        for(int k = 0; k < col; k++) {
            cout << matrizAdj[j][k] << " ";
        }
        cout << endl;
    }
}

vector<bool> initGraph(int n) {
    vector<bool> aux;
    for(int i = 0; i < n; i++) {
        aux.push_back(false);
    }
    return aux;
}

void buscaProfundidade(int ** mat,int n,int v, vector<int> & ordem) {
    vector<bool> visitados = initGraph(n);
    stack<int> stack;
    stack.push(v);

    while(!stack.empty()) {
        int vertice = stack.top();
        stack.pop();
        if(visitados[vertice - 1] == false) {
            visitados[vertice - 1] = true;
            ordem.push_back(vertice);
            for(int i = n; i > 0; i--) {
                if(mat[vertice - 1][i] != 0) {
                    stack.push(i);
                }
            }
        }
    }
}

void imprimeOrdem(vector<int> & ordem) {
    for(int i: ordem) {
        cout << i << endl;
    }
}
