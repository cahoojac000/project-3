#ifndef PROJECT_2_DATALOGPROGRAM_H
#define PROJECT_2_DATALOGPROGRAM_H

#include <vector>
#include <sstream>
#include <set>
#include "Predicate.h"
#include "Rule.h"

class DatalogProgram {
public:
    DatalogProgram() {}
    std::string toString();
    void AddScheme(const std::string& id, std::vector<Parameter>& parameters);
    void AddFact(const std::string& id, std::vector<Parameter>& parameters);
    void AddRule(const Predicate& head, std::vector<Predicate>& predicates);
    void AddQuery(const Predicate& predicate);
    std::set<std::string> CreateDomain();
    std::vector<Predicate> getSchemes() { return schemes; }
    std::vector<Predicate> getFacts() { return facts; }
private:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Rule> rules;
    std::vector<Predicate> queries;
};


#endif
