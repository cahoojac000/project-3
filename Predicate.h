//
// Created by Jacob Cahoon on 9/14/22.
//

#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H

#include "Parameter.h"
#include <vector>
#include <sstream>

class Predicate {
public:
    Predicate(std::string id, std::vector<Parameter> parameters);
    Predicate();
    std::vector<Parameter> getParams() { return parameters; }
    std::string toString();
    std::string getId() { return id; }
private:
    std::string id;
    std::vector<Parameter> parameters;
};


#endif //PROJECT_2_PREDICATE_H
