//
// Created by Jacob Cahoon on 9/14/22.
//

#include "Predicate.h"

Predicate::Predicate(std::string id, std::vector<Parameter> parameters) {
    this->id = id;
    this->parameters = parameters;
}

Predicate::Predicate() {

}

std::string Predicate::toString() {
    std::stringstream ss;
    ss << id << "(";
    for (long unsigned int i = 0; i < parameters.size(); i++) {
        if (i != parameters.size() - 1) {
            ss << parameters.at(i).toString() << ",";
        }
        else {
            ss << parameters.at(i).toString() << ")";
        }
    }
    return ss.str();
}
