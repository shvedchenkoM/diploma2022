#include "Prima_and_Kraskala.h"
#include<iostream>

void Prima_and_Kraskala::solve_Prima(MetroMap &graph) {
    int n = graph.getSize();

    const int INF = 1000000000; // значение "бесконечность"


    std::vector<bool> used (n);
    std::vector<int> min_e (n, INF), sel_e (n, -1);
    min_e[0] = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        if (min_e[v] == INF) {
            std::cout << "No MST!";
            exit(0);
        }

        used[v] = true;
        if (sel_e[v] != -1)
            std::cout << v << " " << sel_e[v] << std::endl;

        for (int to=0; to<n; ++to)
            if (graph.getDistance_by_Dijkstra(v,to) < min_e[to]) {
                min_e[to] = graph.getDistance_by_Dijkstra(v,to);
                sel_e[to] = v;
            }
    }

    int ans = 0;
    for(int i = 0; i < min_e.size(); ++i){
        ans+=min_e[i];
    }
    std::cout<<"AN\n"<<ans*2<<std::endl;
}

