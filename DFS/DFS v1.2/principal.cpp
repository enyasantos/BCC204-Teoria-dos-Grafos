#include <iostream>
#include <cstdlib>
#include <vector>
#include "DFS.hpp"

using namespace std;

int main()
{
    vector<int> ordem;
    int n, m, b, i;
    cin >> n >> m >> b >> i;

    GraphDFS graph(n, m, b, i);

    graph.criaMatrizAdj();

    //graph.printListaAdj();

    graph.DFS(&ordem);

    for(auto el: ordem)
        cout << el << endl;

    return 0;
}
