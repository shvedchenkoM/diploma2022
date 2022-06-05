#include "Edge.hpp"

Edge::Edge(const Vertex &start_, const Vertex &end_, double distance_) : start(start_), end(end_),
                                                                           distance(distance_) {

}

Vertex Edge::getVertex(VertexType vertexType) {
    if (vertexType == startVertex) {
        return start;
    }
    return end;
}

[[maybe_unused]] void Edge::setVertex(VertexType vertexType, const Vertex &vertex) {
    if (vertexType == startVertex) {
        start = vertex;
    } else {
        end = vertex;
    }
}

double Edge::getDistance() const {
    return this->distance;
}

[[maybe_unused]] void Edge::setDistance(double distance_) {
    this->distance = distance_;
}

std::ostream &operator<<(std::ostream &out, const Edge &edge) {
    out << edge.start << " " << edge.end << " " << edge.distance;
    return out;
}

std::istream &operator>>(std::istream &in, Edge &edge) {
    in >> edge.start >> edge.end >> edge.distance;
    return in;
}

Edge::Edge() = default;
