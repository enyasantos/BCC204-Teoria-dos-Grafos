#ifndef DFS_H
#define DFS_H

#include <vector>

using namespace std;

class GraphDFS {
private:
    /*atributos*/
    int **matrizAdj;
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

    int ** getMatrizAdj() const;

    void addAresta(int origem, int destino, int peso);

    int ** getVizinhos(int origem);

    int getNumVizinhos(int origem);

    vector<pair<bool, int>> initVector(int n);

    int ** alocaMatrizNula();

    void freeMatriz();
public:
    GraphDFS(int vertices, int arestas, int tipo, int verticeInicial);

    void criaMatrizAdj();

    void printMatrizAdj();

    void DFS(vector<int> *ordem);

    
};

#endif
