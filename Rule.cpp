//
// Created by Jacob Cahoon on 9/14/22.
//

#include "Rule.h"

Rule::Rule(Predicate head, std::vector<Predicate> predicates) {
    this->head = head;
    this->body = predicates;
}

std::string Rule::toString() {
    std::stringstream ss;
    ss << head.toString() << " :- ";
    for (long unsigned int i = 0; i < body.size(); i++) {
        if (i != body.size() - 1) {
            ss << body.at(i).toString() << ",";
        }
        else {
            ss << body.at(i).toString() << ".";
        }
    }
    return ss.str();
}
