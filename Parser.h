#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H

#include <iostream>
#include "Token.h"
#include "DatalogProgram.h"

class Parser {
public:
    explicit Parser(std::vector<Token*> tokens);
    ~Parser();
    DatalogProgram parse();

    bool match(TokenType compare);
    bool matchD(TokenType compare);

    void datalogProgram();
    void scheme();
    void idList();
    void schemeList();
    void factList();
    void fact();
    void stringList();
    void ruleList();
    void rule();
    void headPredicate();
    void predicate();
    void predicateList();
    void parameter();
    void parameterList();
    void query();
    void queryList();
    void Error();

    DatalogProgram program;
    bool Failed() const { return failed; }

    void AddParam();
    void SetId();
private:
    std::vector<Token*> tokens;
    std::string id;
    std::vector<Parameter> parameters;
    Predicate head;
    std::vector<Predicate> predicates;
    bool failed = false;
};


#endif
