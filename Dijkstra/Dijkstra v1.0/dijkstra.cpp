#include <iostream>
#include "dijkstra.hpp"

#define BIDIRECIONAL 0
#define DIRECIONAL 1
#define INFINITO 2147483647

using namespace std;

//classe
GraphDijkstra::GraphDijkstra(int vertices, int arestas, int tipo, int verticeInicial) 
{
    setVertices(vertices);
    setArestas(arestas);
    setTipo(tipo);
    setVerticeInicial(verticeInicial);
    this->listaAdj = new list<pair<int, int>>[getVertices()];
    this->dt = vector<int>(getVertices());
    this->rot = vector<int>(getVertices());
}

void GraphDijkstra::setVertices(int vertices)  
{
    this->vertices = vertices;
}

int GraphDijkstra::getVertices() const 
{
    return this->vertices;
}

void GraphDijkstra::setArestas(int arestas)  
{
    this->arestas = arestas;
}

int GraphDijkstra::getArestas() const 
{
    return this->arestas;
}

void GraphDijkstra::setTipo(int tipo)  
{
    this->tipo = tipo;
}

int GraphDijkstra::getTipo() const
{
    return this->tipo;
}

void GraphDijkstra::setVerticeInicial(int verticeInicial)  
{
    this->verticeInicial = verticeInicial;
}

int GraphDijkstra::getVerticeInicial() const 
{
    return this->verticeInicial;
}

list<pair<int,int>> * GraphDijkstra::getListaAdj() const 
{
    return this->listaAdj;
}

void GraphDijkstra::addAresta(int origem, int destino, int peso) 
{
    this->getListaAdj()[origem].push_back(make_pair(destino, peso));
}

list<pair<int,int>> GraphDijkstra::getVizinhos(int origem) 
{
    return this->getListaAdj()[origem];
}

int GraphDijkstra::getNumVizinhos(int origem) 
{
    return this->getListaAdj()[origem].size();
}

vector<int> GraphDijkstra::getDt() const {
    return this->dt;
}

void GraphDijkstra::addDt(int i,int v) {
    this->dt[i] = v;
}

vector<int> GraphDijkstra::getRot() const {
    return this->rot;
}

void GraphDijkstra::addRoot(int i, int v) {
    this->rot[i] = v;
}

void GraphDijkstra::criaListaAdj() 
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

void GraphDijkstra::printListaAdj() 
{
    for(int i = 0; i < getVertices(); i++) {
        cout << (i + 1) << " -> ";
        for(auto el: getVizinhos(i)) {
            cout << "[" << el.first << " | " << el.second << "]  ";
        }
        cout << endl;
    }
}

vector<bool> GraphDijkstra::initList(bool value) {
    vector<bool> aux;
    for(int i = 0; i < getVertices(); i++) {
        aux.push_back(value);
    }
    return aux;
}

void GraphDijkstra::initDijkstra() {
    for(int i = 0; i < getVertices(); i++) {
        if(i != (getVerticeInicial() - 1)) {
            addDt(i, INFINITO);
            addRoot(i, 0);
        } else {
            addDt(i, 0);
            addRoot(i, 0);
        }
        
    }
}

int GraphDijkstra::getMin(vector<bool> A) {
    int min = INFINITO;
    int index = -1;
    int n = A.size();
    for(int i = 0; i < n; i++) {
        if(A[i] && getDt()[i] < min) {
            min = getDt()[i];
            index = i + 1;
        }
    }
    return index;
}

bool haVerticesAbertos(vector<bool> F) {
    for(bool el : F) {
        if(!el)
            return true;
    }
    return false;
}

void GraphDijkstra::dijkstra() 
{
    int u, peso;
    initDijkstra();
    vector<bool> abertos = initList(true);
    vector<bool> fechados = initList(false);

    while(haVerticesAbertos(fechados))
    {
        int vertice = getMin(abertos);
        if(abertos[vertice - 1]) 
        {
            abertos[vertice - 1] = false;
            fechados[vertice - 1] = true;

            for(pair<int, int> vizinho: getVizinhos(vertice - 1)) 
            {
                u = vizinho.first - 1;
                peso = vizinho.second;
                if((getDt()[vertice - 1] + peso) < getDt()[u]) {
                    addDt(u, getDt()[vertice - 1] + peso);
                    addRoot(u, vertice);
                }   
            }
        }
    }
}

void GraphDijkstra::printDijkstra() {
    vector <int> estrutura;
    for(int i = 0; i < getVertices(); i++) {
        if(i != (getVerticeInicial() - 1)) {
            cout << (i + 1) << " (" << getDt()[i] << "): ";
            int aux = getRot()[i];
            estrutura.push_back(i + 1);
            while(aux != getVerticeInicial())
            {
                estrutura.push_back(aux);
                aux = getRot()[aux - 1];
            }
            estrutura.push_back(aux);
    
            for(int i = (estrutura.size() - 1); i >= 0; i--) {
                cout << estrutura[i] << " ";
            }
            cout << endl;
            estrutura.clear();
        }
    }
}