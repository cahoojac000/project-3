//
// Created by Jacob Cahoon on 9/21/22.
//

#include "Interpreter.h"

Interpreter::Interpreter(const DatalogProgram &program) {
    this->program = program;
    createDatabase();
}

void Interpreter::createDatabase() {
    addSchemesToDatabase();
    addFactsToDatabase();
    for (auto& query : program.getQueries()) {
        std::cout << query.toString() << "?";
        std::cout << evaluatePredicate(query)->toString();
    }
}

void Interpreter::addSchemesToDatabase() {
    for (auto& scheme : program.getSchemes()) {
        std::vector<std::string> header;
        for (auto& attribute : scheme.getParams()) {
            header.push_back(attribute.toString());
        }
        database.addScheme(scheme.getId(), header);
    }
}

void Interpreter::addFactsToDatabase() {
    for (auto& fact : program.getFacts()) {
        std::vector<std::string> values;
        for (auto& value : fact.getParams()) {
            values.push_back(value.toString());
        }
        database.addFacts(fact.getId(), values);
    }
}

Relation* Interpreter::evaluatePredicate(const Predicate& predicate) {
    Relation relation = *database.getRelation(predicate.getId());
    int index = 0;
    for (auto& parameter : predicate.getParams()) {
        if (parameter.getIsConstant()) {
             relation = relation.select(index, parameter.toString());
        }
        else {
            if (relation.columnMap.find(parameter.toString()) != relation.columnMap.end()) {
                //TODO: What is going on here?
                relation = relation.select(index, relation.columnMap.find(parameter.toString())->second);
            }
            else {
                relation.columnMap.insert({parameter.toString(), index});
                relation.columnVector.push_back(index);
            }
        }
        index++;
    }
    if (!relation.columnMap.empty()) relation = relation.project(relation.columnVector);
    std::vector<std::string> newHeader;
    for (int i : relation.columnVector) {
        newHeader.push_back(predicate.getParams().at(i).toString());
    }
    relation = relation.rename(newHeader);
    auto* newRelation = new Relation(relation);

    return newRelation;
}
