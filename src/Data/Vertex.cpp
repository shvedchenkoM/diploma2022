#include "Vertex.hpp"

#include <utility>

Vertex::Vertex(std::string name_, int id_) : name(std::move(name_)), id(id_) {

}

std::string Vertex::getName() {
    return this->name;
}

[[maybe_unused]] void Vertex::setName(std::string name_) {
    this->name = std::move(name_);
}

int Vertex::getId() const {
    return this->id;
}

void Vertex::setId(int id_) {
    this->id = id_;
}

[[maybe_unused]] std::vector<std::string> Vertex::getData() {
    return this->data;
}

[[maybe_unused]] void Vertex::setData(std::vector<std::string> data_) {
    this->data = std::move(data_);
}

Vertex::Vertex(const Vertex &vertex_) {
    this->data = vertex_.data;
    this->id = vertex_.id;
    this->name = vertex_.name;
}

Vertex::Vertex() = default;

std::ostream &operator<<(std::ostream &out, const Vertex &vertex) {
    out << vertex.name << " " << vertex.id;
    return out;
}

std::istream &operator>>(std::istream &in, Vertex &vertex) {
    in >> vertex.name;
    in >> vertex.id;
    return in;
}
