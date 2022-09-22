//
// Created by Jacob Cahoon on 9/21/22.
//

#include "Relation.h"

Relation::Relation(const std::string& name, const Header& header) {
    this->name = name;
    this->header = header;
}

Relation Relation::select(const int &index, const std::string &value) {
    return {std::string(), Header()};
}

Relation Relation::select(const int &index1, const int &index2) {
    return {std::string(), Header()};
}

Relation Relation::project(const std::vector<int>& indices) {
    return {std::string(), Header()};
}

Relation Relation::rename(const Header& newHeader) {
    return {std::string(), Header()};
}

std::string Relation::toString() {
    std::stringstream ss;
    for (auto& h : header.attributes) {
        for (Tuple t : collection) {
            for (auto& s : t.getValues())
            ss << h << "=\'" << s << "\', ";
        }
    }
    return ss.str();
}

void Relation::addTuple(const std::vector<std::string>& values) {
    collection.insert(Tuple(values));
}
