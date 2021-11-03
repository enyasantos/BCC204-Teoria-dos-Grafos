#include <iostream>
#include <stack>
#include "DFS.hpp"

#define BIDIRECIONAL 0
#define DIRECIONAL 1

using namespace std;

//classe
GraphDFS::GraphDFS(int vertices, int arestas, int tipo, int verticeInicial) 
{
    setVertices(vertices);
    setArestas(arestas);
    setTipo(tipo);
    setVerticeInicial(verticeInicial);
    this->matrizAdj = alocaMatrizNula();
}

void GraphDFS::setVertices(int vertices)  
{
    this->vertices = vertices;
}

int GraphDFS::getVertices() const 
{
    return this->vertices;
}

void GraphDFS::setArestas(int arestas)  
{
    this->arestas = arestas;
}

int GraphDFS::getArestas() const 
{
    return this->arestas;
}

void GraphDFS::setTipo(int tipo)  
{
    this->tipo = tipo;
}

int GraphDFS::getTipo() const
{
    return this->tipo;
}

void GraphDFS::setVerticeInicial(int verticeInicial)  
{
    this->verticeInicial = verticeInicial;
}

int GraphDFS::getVerticeInicial() const 
{
    return this->verticeInicial;
}

int ** GraphDFS::getMatrizAdj() const 
{
    return this->matrizAdj;
}

int ** GraphDFS::alocaMatrizNula()
{
    int **aux = (int **) malloc(sizeof(int *) * getVertices());
    if(aux == NULL)
    {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for(int j = 0; j < getVertices(); j++) 
    {
        aux[j] = (int *) malloc(sizeof(int) * getVertices());
        if(aux == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
        for(int k = 0; k < getVertices(); k++) 
            aux[j][k] = 0;
    }
    return aux;
}

void GraphDFS::criaMatrizAdj() 
{
    for(int j = 0; j < getArestas(); j++) 
    {
        int verticeOrigem, verticeDestino, arestaPeso;
        cin >> verticeOrigem >> verticeDestino >> arestaPeso;
        matrizAdj[verticeOrigem - 1][verticeDestino - 1] = arestaPeso;
        if(getTipo() == BIDIRECIONAL)
            matrizAdj[verticeDestino - 1][verticeOrigem - 1] = arestaPeso;
    }
}

void GraphDFS::printMatrizAdj() 
{
    for(int j = 0; j < getVertices(); j++) 
    {
        for(int k = 0; k < getVertices(); k++)
            cout << matrizAdj[j][k] << " ";
        cout << endl;
    }
}

vector<pair<bool, int>> GraphDFS::initVector(int n) {
    vector<pair<bool, int>> aux;
    for(int i = 0; i < n; i++) 
        aux.push_back(make_pair(false, 0));
    return aux;
}

void GraphDFS::DFS(vector<int> *ordem) 
{
    vector<pair<bool, int>> visitados = initVector(getVertices()); //<estado da visita (true ou false), ultima coluna visitada na mastriz>
    stack<int> stack; //pilha de execução do DFS

    stack.push(getVerticeInicial()); //item na qual inicia a busca
    ordem->push_back(getVerticeInicial());

    while(!stack.empty()) 
    {
        int vertice = stack.top();
        visitados[vertice - 1].first = true;
        if(visitados[vertice - 1].first == false || visitados[vertice - 1].second < (getVertices() - 1)) 
        { //se o item não foi vísitado ou ainda há celulas na matriz para verificar se há vizinhança
            for(int i = visitados[vertice - 1].second; i < getVertices(); i++) 
            {// busca na matriz de adjacencia se há vizinhaça
                visitados[vertice - 1].second = i;
                if(getMatrizAdj()[vertice - 1][i] != 0) 
                {// se houver vizinhaça
                    if(visitados[i].first != true) 
                    {// se a vertice ainda nçao tiver sido acessada
                        stack.push(i + 1);
                        ordem->push_back(stack.top());
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