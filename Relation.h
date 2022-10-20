#ifndef PROJECT_3_RELATION_H
#define PROJECT_3_RELATION_H

#include <set>
#include <string>
#include <map>
#include <sstream>
#include "Tuple.h"
#include "Header.h"

class Relation {
public:
    Relation(std::string name, std::map<std::string, int> columnMap, std::vector<int> columnVector);
    Relation(const std::string& name, const Header& header);
    Relation() = default;
    ~Relation() = default;

    void addTuple(const std::vector<std::string>& values);
    Relation select(const int& index, const std::string& value);
    Relation select(const int& index1, const int& index2);
    Relation project(const std::vector<int>& indices);
    Relation rename(const std::vector<std::string>& attributes);
    std::string toString();
    std::string getName() { return name; }
    Header getHeader() { return header; }
    std::set<Tuple> getCollection() { return collection; }
    std::vector<int> getColumnVector() const { return columnVector; }
    std::map<std::string, int> columnMap;
    std::vector<int> columnVector;
private:
    std::string name;
    Header header;
    std::set<Tuple> collection;
};


#endif
