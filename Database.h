#ifndef PROJECT_3_DATABASE_H
#define PROJECT_3_DATABASE_H

#include <map>
#include <string>
#include "Relation.h"

class Database {
public:
    Database() = default;
    ~Database() = default;

    void addScheme(const std::string& name, const std::vector<std::string>& header);
    void addFacts(const std::string& name, const std::vector<std::string>& values);
private:
    std::map<std::string, Relation> database;
};


#endif
