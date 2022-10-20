#include "DatalogProgram.h"

void DatalogProgram::AddScheme(const std::string& id, std::vector<Parameter>& parameters) {
    this->schemes.push_back(Predicate(id, parameters));
    parameters.clear();
}

void DatalogProgram::AddFact(const std::string& id, std::vector<Parameter>& parameters) {
    this->facts.push_back(Predicate(id, parameters));
    parameters.clear();
}

void DatalogProgram::AddRule(const Predicate& head, std::vector<Predicate>& predicates) {
    this->rules.push_back(Rule(head, predicates));
    predicates.clear();
}

void DatalogProgram::AddQuery(const Predicate& predicate) {
    this->queries.push_back(predicate);
}

std::string DatalogProgram::toString() {
    std::set<std::string> domain = CreateDomain();
    std::stringstream ss;
    ss << "Schemes(" << schemes.size() << "):" << std::endl;
    for (auto & scheme : schemes) {
        ss << "  " << scheme.toString() << std::endl;
    }
    ss << "Facts(" << facts.size() << "):" << std::endl;
    for (auto & fact : facts) {
        ss << "  " << fact.toString() << "." << std::endl;
    }
    ss << "Rules(" << rules.size() << "):" << std::endl;
    for (auto & rule : rules) {
        ss << "  " << rule.toString() << std::endl;
    }
    ss << "Queries(" << queries.size() << "):" << std::endl;
    for (auto & querie : queries) {
        ss << "  " << querie.toString() << "?" << std::endl;
    }
    ss << "Domain(" << domain.size() << "):" << std::endl;
    for (const auto & it : domain) {
        ss << "  " << it << std::endl;
    }
    return ss.str();
}

std::set<std::string> DatalogProgram::CreateDomain() {
    std::set<std::string> domain;
    for (auto & fact : facts) {
        for (long unsigned int i = 0; i < fact.getParams().size(); i++) {
            domain.insert(fact.getParams().at(i).toString());
        }
    }
    return domain;
}
