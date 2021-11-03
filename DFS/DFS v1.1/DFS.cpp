#include <iostream>
#include <stack>
#include "DFS.hpp"

#define BIDIRECIONAL 0
#define DIRECIONAL 1

using namespace std;

void getIn(ENTRADA *in) 
{
    cin >> in->n >> in->m >> in->b >> in->i;
}

int ** alocaMatrizNula(int lin, int col) {
    int **aux = (int **) malloc(sizeof(int *) * lin);
    if(aux == NULL)
    {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for(int j = 0; j < lin; j++) 
    {
        aux[j] = (int *) malloc(sizeof(int) * lin);
        if(aux == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
        for(int k = 0; k < col; k++) 
            aux[j][k] = 0;
    }
    return aux;
}

void freeMatriz(int **mat, int lin) 
{
    for(int i = 0; i < lin; i++) 
        free(mat[i]);
    free(mat);
}

void criaMatrizAdj(int ** matrizAdj, int nArestas, int b) 
{
    for(int j = 0; j < nArestas; j++) 
    {
        int verticeOrigem, verticeDestino, arestaPeso;
        cin >> verticeOrigem >> verticeDestino >> arestaPeso;
        matrizAdj[verticeOrigem - 1][verticeDestino - 1] = arestaPeso;
        if(b == BIDIRECIONAL)
            matrizAdj[verticeDestino - 1][verticeOrigem - 1] = arestaPeso;
    }
}

void imprimeMatriz(int ** matrizAdj, int lin, int col) 
{
    for(int j = 0; j < lin; j++) 
    {
        for(int k = 0; k < col; k++)
            cout << matrizAdj[j][k] << " ";
        cout << endl;
    }
}

vector<pair<bool, int>> initVector(int n) 
{
    vector<pair<bool, int>> aux;
    for(int i = 0; i < n; i++) 
        aux.push_back(make_pair(false, 0));
    return aux;
}

void buscaProfundidade(int ** mat,int n,int v, vector<int> & ordem) 
{
    vector<pair<bool, int>> visitados = initVector(n); //<estado da visita (true ou false), ultima coluna visitada na mastriz>
    stack<int> stack; //pilha de execução do DFS

    stack.push(v); //item na qual inicia a busca
    ordem.push_back(v);

    while(!stack.empty()) 
    {
        int vertice = stack.top();
        visitados[vertice - 1].first = true;
        if(visitados[vertice - 1].first == false || visitados[vertice - 1].second < (n - 1)) 
        { //se o item não foi vísitado ou ainda há celulas na matriz para verificar se há vizinhança
            for(int i = visitados[vertice - 1].second; i < n; i++) 
            {// busca na matriz de adjacencia se há vizinhaça
                visitados[vertice - 1].second = i;
                if(mat[vertice - 1][i] != 0) 
                {// se houver vizinhaça
                    if(visitados[i].first != true) 
                    {// se a vertice ainda nçao tiver sido acessada
                        stack.push(i + 1);
                        ordem.push_back(stack.top());
                        visitados[vertice - 1].second = i + 1;
                        break;
                    }
                }
            }
        } else 
        { // caso a vertice tenha sido acessada e já tiver verificado se há vizinhaça 
            stack.pop();
        }
    }
}

void imprimeOrdem(vector<int> & ordem) 
{
    for(int i: ordem) {
        cout << i << endl;
    }
}
