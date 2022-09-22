//
// Created by Jacob Cahoon on 9/21/22.
//

#include "Interpreter.h"

Interpreter::Interpreter(const DatalogProgram &program) {
    this->program = program;
    createDatabase();
}

void Interpreter::createDatabase() {
    for (auto& scheme : program.getSchemes()) {
        std::vector<std::string> header;
        for (auto& attribute : scheme.getParams()) {
            header.push_back(attribute.toString());
        }
        database.addScheme(scheme.getId(), header);
    }
    for (auto& fact : program.getFacts()) {
        std::vector<std::string> values;
        for (auto& value : fact.getParams()) {
            values.push_back(value.toString());
        }
        database.addFacts(fact.getId(), values);
    }
}
