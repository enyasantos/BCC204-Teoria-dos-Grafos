#include <iostream>
#include <queue>
#include "BFS.hpp"

#define BIDIRECIONAL 0
#define DIRECIONAL 1

using namespace std;

//classe
GraphBFS::GraphBFS(int vertices, int arestas, int tipo, int verticeInicial) 
{
    setVertices(vertices);
    setArestas(arestas);
    setTipo(tipo);
    setVerticeInicial(verticeInicial);
    this->listaAdj = new list<pair<int, int>>[getVertices()];
}

void GraphBFS::setVertices(int vertices)  
{
    this->vertices = vertices;
}

int GraphBFS::getVertices() const 
{
    return this->vertices;
}

void GraphBFS::setArestas(int arestas)  
{
    this->arestas = arestas;
}

int GraphBFS::getArestas() const 
{
    return this->arestas;
}

void GraphBFS::setTipo(int tipo)  
{
    this->tipo = tipo;
}

int GraphBFS::getTipo() const
{
    return this->tipo;
}

void GraphBFS::setVerticeInicial(int verticeInicial)  
{
    this->verticeInicial = verticeInicial;
}

int GraphBFS::getVerticeInicial() const 
{
    return this->verticeInicial;
}

list<pair<int, int>> * GraphBFS::getListaAdj() const 
{
    return this->listaAdj;
}

void GraphBFS::addAresta(int origem, int destino, int peso) 
{
    this->getListaAdj()[origem].push_back(make_pair(destino, peso));
}

list<pair<int, int>> GraphBFS::getVizinhos(int origem) 
{
    return this->getListaAdj()[origem];
}

int GraphBFS::getNumVizinhos(int origem) 
{
    return this->getListaAdj()[origem].size();
}

void GraphBFS::criaListaAdj() 
{
    for(int j = 0; j < getArestas(); j++) 
    {
        int verticeOrigem, verticeDestino, arestaPeso;
        cin >> verticeOrigem >> verticeDestino >> arestaPeso;
        addAresta(verticeOrigem - 1, verticeDestino, arestaPeso);
        if(getTipo() == BIDIRECIONAL)
            addAresta(verticeDestino - 1, verticeOrigem, arestaPeso);
    }
}

void GraphBFS::printListaAdj() 
{
    for(int i = 0; i < getVertices(); i++) {
        cout << (i + 1) << " -> ";
        for(auto el: getVizinhos(i)) {
            cout << "[" << el.first << " | " << el.second << "]  ";
        }
        cout << endl;
    }
}

vector<bool> GraphBFS::initList(bool value) {
    vector<bool> aux;
    for(int i = 0; i < getVertices(); i++) {
        aux.push_back(value);
    }
    return aux;
}

void GraphBFS::BFS(vector<int> *ordem) 
{
    vector<bool> visitados = initList(false);
    queue<int> queue;

    queue.push(getVerticeInicial());

    while(!queue.empty()) 
    {
        int vertice = queue.front();
        queue.pop();
        if(!visitados[vertice - 1]) 
        {
            ordem->push_back(vertice);
            visitados[vertice - 1] = true;
            for(pair<int, int> el: getVizinhos(vertice - 1)) 
            {
                if(!visitados[el.first - 1]) 
                    queue.push(el.first);
            }
        }
    }
}