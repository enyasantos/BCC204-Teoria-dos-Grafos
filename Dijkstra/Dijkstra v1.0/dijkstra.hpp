#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <list>
#include <vector>

using namespace std;

class GraphDijkstra {
private:
    /*atributos*/
    list<pair<int, int>> *listaAdj;
    int vertices;
    int arestas;
    int tipo;
    int verticeInicial;
    vector<int> dt;
    vector<int> rot;

    /*métodos*/
    void setVertices(int vertices);

    int getVertices() const;

    void setArestas(int arestas);

    int getArestas() const;

    void setTipo(int tipo);

    int getTipo() const;

    void setVerticeInicial(int verticeInicial);

    int getVerticeInicial() const;

    vector<int> getDt() const;

    void addDt(int i, int v);

    vector<int> getRot() const;

    void addRoot(int i, int v);

    list<pair<int,int>> * getListaAdj() const;

    void addAresta(int origem, int destino, int peso);

    list<pair<int,int>> getVizinhos(int origem);

    int getNumVizinhos(int origem);

    vector<bool> initList(bool value);

    void initDijkstra();

    int getMin(vector<bool> A);
public:
    GraphDijkstra(int vertices, int arestas, int tipo, int verticeInicial);

    void criaListaAdj();

    void printListaAdj();

    void dijkstra();

    void printDijkstra();
};

#endif
