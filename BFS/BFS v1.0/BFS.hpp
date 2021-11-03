#ifndef BFS_H
#define BFS_H

#include <list>
#include <vector>

using namespace std;

class GraphBFS {
private:
    list<int> *listaAdj;
    int vertices;
    int arestas;
    int tipo;
    int verticeInicial;
public:
    GraphBFS(int vertices, int arestas, int tipo, int verticeInicial);

    void setVertices(int vertices);

    int getVertices() const;

    void setArestas(int arestas);

    int getArestas() const;

    void setTipo(int tipo);

    int getTipo() const;

    void setVerticeInicial(int verticeInicial);

    int getVerticeInicial() const;

    list<int> * getListaAdj() const;

    void addAresta(int origem, int destino);

    list<int> getVizinhos(int origem);

    int getNumVizinhos(int origem);

    void criaListaAdj();

    void printListaAdj();

    vector<bool> initListFalse();

    void BFS(list<int> *ordem);
};

#endif
