//
// Created by Jacob Cahoon on 9/14/22.
//

#ifndef PROJECT_2_RULE_H
#define PROJECT_2_RULE_H

#include "Predicate.h"

class Rule {
public:
    Rule(Predicate head, std::vector<Predicate> predicates);
    std::string toString();
private:
    Predicate head;
    std::vector<Predicate> body;
};


#endif //PROJECT_2_RULE_H
