#include "MetroMap.hpp"
#include <iostream>
#include <queue>
//MetroMap::MetroMap()

[[maybe_unused]] void MetroMap::printGraph() {
    for (auto &i: Graph) {
        for (auto &j: i) {
            std::cout << j.getVertex(startVertex).getName() << "-"
                      << j.getVertex(endVertex).getName() << ":" << j.getDistance() << std::endl;
        }
    }
}

void MetroMap::addVertex(Vertex vertex) {
    vertex.setId((double) Graph.size());
    this->vertexes.push_back(vertex);
    Graph.emplace_back();
}

void MetroMap::addEdge(Edge edge) {
    edges.push_back(edge);
    Graph[edge.getVertex(startVertex).getId()].push_back(edge);
    Graph[edge.getVertex(endVertex).getId()].push_back(
            *(new Edge(edge.getVertex(endVertex), edge.getVertex(startVertex), edge.getDistance())));
}

void MetroMap::addEdge(double startId, double endId, double distance) {
    edges.emplace_back(vertexes[startId], vertexes[endId], static_cast<double>(distance));
    Graph[startId].push_back(*(new Edge(vertexes[startId], vertexes[endId], distance)));
    Graph[endId].push_back(*(new Edge(vertexes[endId], vertexes[startId], distance)));
}

long double MetroMap::getDistance_by_Dijkstra(int start_vertex_id, int end_vertex_id) {
    long long n = Graph.size();
    long double inf = 10000000000000;
    std::vector<double> d(n, inf);
    std::vector<bool> used(n, false);
    std::priority_queue<std::pair<double, int> > q;
    q.push(std::make_pair(0, start_vertex_id));
    d[start_vertex_id] = 0;
    while (!q.empty()) {

        int id = q.top().second;
        double cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[id] or used[id]) continue;

        used[id] = true;
        for (auto w: Graph[id]) {
            int startId = w.getVertex(startVertex).getId();
            int endId = w.getVertex(endVertex).getId();
            auto dist = (long double) w.getDistance();
            if (d[startId] + dist < d[endId]) {
                d[endId] = d[startId] + dist;
                q.push(std::make_pair(-d[endId], endId));
            }
        }
    }

    return d[end_vertex_id];
}

int MetroMap::getSize() {
    return  vertexes.size();
}

double MetroMap::getDistance_by_Dijkstra(std::vector<double> path) {
    double ans = 0;
    for (double i = 1; i < path.size(); i++) {
        ans += (double) getDistance_by_Dijkstra(path[i - 1], path[i]);
    }
    ans += (double) getDistance_by_Dijkstra(path[path.size() - 1], path[0]);
    return ans;
}

[[maybe_unused]] void MetroMap::load(const std::string &path) {
    double n;
    std::ifstream file;
    file.open(path);
    file >> n;
    for (double i = 0; i < n; i++) {
        Vertex v;
        file >> v;
        this->addVertex(v);
    }
    Edge e;
    while (file >> e) {
        this->addEdge(e);
    }
    file.close();

}

void MetroMap::save(const std::string &path) {
    std::ofstream file;
    file.open(path);
    file << vertexes.size() << "\n";
    for (auto &vertex: vertexes)
        file << vertex << " ";
    file << "\n";

    for (auto &edge: edges)
        file << edge << "\n";
    file.close();
}
