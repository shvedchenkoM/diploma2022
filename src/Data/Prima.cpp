#include "Prima.hpp"
#include<iostream>

void Prima::solve_Prima(MetroMap &graph) {
    int n = graph.getSize();

    const int INF = 1000000000; // значение "бесконечность"


    std::vector<bool> used(n);
    std::vector<int> min_e(n, INF), sel_e(n, -1);
    min_e[0] = 0;
    for (int i = 0; i < n; ++i) {
//        std::cout<<i<<std::endl;
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        if (min_e[v] == INF) {
            std::cout << "No MST!";
            exit(0);
        }

        used[v] = true;
//        if (sel_e[v] != -1)
//            std::cout << v << " " << sel_e[v] << std::endl;

        for (int to = 0; to < n; ++to) {
            int calc = INF;
            if (graph.isEdge(v, to)) {
                calc = graph.getDistance_by_Dijkstra(v, to);
//                std::cout<<1<<std::endl;
            }
            if (calc < min_e[to]) {
//                std::cout << graph.getDistance_by_Dijkstra(v, to) << '\n';
                min_e[to] = calc;
                sel_e[to] = v;
            }
        }
    }

    double ans = 0;
    for (int i = 0; i < sel_e.size(); ++i) {
        if (sel_e[i] == -1)
            continue;
//        std::cout << graph.getDistance_by_Dijkstra(i, sel_e[i]) << '\n';
        ans += graph.getDistance_by_Dijkstra(i, sel_e[i]);
    }
    std::cout << ans * 2 << std::endl;
}
