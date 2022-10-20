#ifndef PROJECT_3_TUPLE_H
#define PROJECT_3_TUPLE_H

#include <vector>
#include <string>

class Tuple {
public:
    explicit Tuple(const std::vector<std::string>& values) { this->values = values; }
    Tuple() = default;
    ~Tuple() = default;

    bool operator< (const Tuple& rhs) const { return values < rhs.values; }
    std::vector<std::string> getValues() const { return values; }
private:
    std::vector<std::string> values;
};


#endif
