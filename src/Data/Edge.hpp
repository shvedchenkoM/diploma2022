#ifndef DIPLOMA_EDGE_HPP
#define DIPLOMA_EDGE_HPP


#include "Vertex.hpp"
#include <fstream>

enum VertexType{
    startVertex,
    endVertex
};

class Edge {
private:
    Vertex start;
    Vertex end;
    long double distance{};
public:
    Edge(const Vertex&, const Vertex&, double);
    Edge();
    Vertex getVertex(VertexType);

    [[maybe_unused]] void setVertex(VertexType,const Vertex&);
    [[nodiscard]] double getDistance() const;

    [[maybe_unused]] [[maybe_unused]] void setDistance(double);
    friend std::ostream &operator<<(std::ostream &, const Edge &);
    friend std::istream& operator>> (std::istream &, Edge &);
};


#endif //DIPLOMA_EDGE_HPP
