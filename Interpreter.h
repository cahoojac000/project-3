//
// Created by Jacob Cahoon on 9/21/22.
//

#ifndef PROJECT_3_INTERPRETER_H
#define PROJECT_3_INTERPRETER_H

#include "DatalogProgram.h"
#include "Database.h"

class Interpreter {
public:
    explicit Interpreter(const DatalogProgram& program);
    ~Interpreter() = default;
    void createDatabase();
    void addSchemesToDatabase();
    void addFactsToDatabase();
    Relation* evaluatePredicate(const Predicate& predicate);
private:
    DatalogProgram program;
    Database database;
};


#endif //PROJECT_3_INTERPRETER_H
