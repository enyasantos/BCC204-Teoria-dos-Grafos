#include <iostream>
#include <cstdlib>
#include <list>
#include "dijkstra.hpp"

using namespace std;

int main()
{
    int n, m, b, i;
    cin >> n >> m >> b >> i;

    GraphDijkstra graph(n, m, b, i);

    graph.criaListaAdj();

    //graph.printListaAdj();

    graph.dijkstra();

    graph.printDijkstra();

    return 0;
}