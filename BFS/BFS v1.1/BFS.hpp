#ifndef BFS_H
#define BFS_H

#include <list>
#include <vector>

using namespace std;

class GraphBFS {
private:
    /*atributos*/
    list<pair<int, int>> *listaAdj;
    int vertices;
    int arestas;
    int tipo;
    int verticeInicial;

    /*métodos*/
    void setVertices(int vertices);

    int getVertices() const;

    void setArestas(int arestas);

    int getArestas() const;

    void setTipo(int tipo);

    int getTipo() const;

    void setVerticeInicial(int verticeInicial);

    int getVerticeInicial() const;

    list<pair<int, int>> * getListaAdj() const;

    void addAresta(int origem, int destino, int peso);

    list<pair<int, int>> getVizinhos(int origem);

    int getNumVizinhos(int origem);

    vector<bool> initList(bool value);
public:
    GraphBFS(int vertices, int arestas, int tipo, int verticeInicial);

    void criaListaAdj();

    void printListaAdj();

    void BFS(vector<int> *ordem);
};

#endif
