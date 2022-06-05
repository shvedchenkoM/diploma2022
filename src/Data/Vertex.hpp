#ifndef DIPLOMA_VERTEX_HPP
#define DIPLOMA_VERTEX_HPP

#include <string>
#include <vector>
#include <fstream>
class Vertex {
private:
    std::string name;
    int id{};
    std::vector<std::string> data;
public:
    Vertex(std::string, int);

    Vertex(Vertex const &);

    Vertex();

    std::string getName();

    [[maybe_unused]] void setName(std::string);

    [[nodiscard]] int getId() const;

    void setId(int);

    [[maybe_unused]] std::vector<std::string> getData();

    [[maybe_unused]] void setData(std::vector<std::string>);

    friend std::ostream &operator<<(std::ostream &, const Vertex &);
    friend std::istream& operator>> (std::istream &, Vertex &);


};


#endif //DIPLOMA_VERTEX_HPP
