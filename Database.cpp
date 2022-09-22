//
// Created by Jacob Cahoon on 9/21/22.
//

#include "Database.h"

void Database::addScheme(const std::string& name, const std::vector<std::string>& header) {
    database.insert({name, Relation(name, Header(header))});
}

void Database::addFacts(const std::string& name, const std::vector<std::string>& values) {
    database.find(name)->second.addTuple(values);
}
