#ifndef DIPLOMA_METROMAP_HPP
#define DIPLOMA_METROMAP_HPP

#include <vector>
#include "Edge.hpp"
#include <map>

class MetroMap {
private:
    std::vector<Vertex> vertexes;
    std::vector<Edge> edges;
    std::vector<std::vector<Edge>>
            Graph;
public:
    int getSize();

    void addVertex(Vertex);

    void addEdge(Edge);

    void addEdge(double, double, double);


    bool isEdge(int x, int y) {
        for (auto e: edges) {
            if ((e.getVertex(startVertex).getId() == x and e.getVertex(endVertex).getId() == y) || (e.getVertex(startVertex).getId() == y and e.getVertex(endVertex).getId() == x) ) {
                return true;
            }
        }
        return false;
    }

    long double getDistance_by_Dijkstra(int start_vertex_id, int end_vertex_id);

    double getDistance_by_Dijkstra(std::vector<double> path);

    [[maybe_unused]] void load(const std::string &path);

    void save(const std::string &path);


//    Debug
    [[maybe_unused]] void printGraph();
};


#endif //DIPLOMA_METROMAP_HPP
