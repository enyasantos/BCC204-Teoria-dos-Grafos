#include <iostream>
#include <cstdlib>
#include <vector>
#include "BFS.hpp"

using namespace std;

int main()
{
    vector<int> ordem;
    int n, m, b, i;
    cin >> n >> m >> b >> i;

    GraphBFS graph(n, m, b, i);

    graph.criaListaAdj();

    //graph.printListaAdj();

    graph.BFS(&ordem);

    for(auto el: ordem)
        cout << el << endl;

    return 0;
}
