//
// Created by Jacob Cahoon on 9/21/22.
//

#include "Relation.h"

Relation::Relation(const std::string& name, const Header& header) {
    this->name = name;
    this->header = header;
}

Relation Relation::select(const int &index, const std::string &value) {
    Relation newRelation;
    newRelation.header = header;
    newRelation.name = name;
    newRelation.columnMap = columnMap;
    newRelation.columnVector = columnVector;
    for (auto& tuple : collection) {
        if (tuple.getValues().at(index) == value) {
            newRelation.collection.insert(tuple);
        }
    }
    return newRelation;
}

Relation Relation::select(const int &index1, const int &index2) {
    Relation newRelation;
    newRelation.header = header;
    newRelation.name = name;
    newRelation.columnMap = columnMap;
    newRelation.columnVector = columnVector;
    for (auto& tuple : collection) {
        if (tuple.getValues().at(index1) == tuple.getValues().at(index2)) {
            newRelation.collection.insert(tuple);
        }
    }
    return newRelation;
}

Relation Relation::project(const std::vector<int>& indices) {
    Relation newRelation(name, columnMap, columnVector);
    for (auto i = 0; i < columnVector.size(); i++) {
        newRelation.header.attributes.push_back(header.attributes.at(columnVector.at(i)));
    }
    for (auto& tuple : collection) {
        std::vector<std::string> values;
        for (int i = 0; i < indices.size(); i++) {
            values.push_back(tuple.getValues().at(indices.at(i)));
        }
        newRelation.addTuple(values);
    }
    return newRelation;
}

Relation Relation::rename(const std::vector<std::string>& attributes) {
    Relation newRelation(name, columnMap, columnVector);
    newRelation.header.attributes = attributes;
    newRelation.collection = collection;
    return newRelation;
}

std::string Relation::toString() {
    std::stringstream ss;
    if (collection.empty()) { ss << " No" << std::endl; return ss.str(); }
    ss << " Yes(" << collection.size() << ")";
    for (auto& tuple : collection) {
        ss << std::endl;
        if (!columnMap.empty()) { ss << "  "; }
        for (unsigned long int i = 0; i < header.attributes.size(); i++) {
            if (i == header.attributes.size() - 1) {
                ss << header.attributes.at(i) << "=" << tuple.getValues().at(i);
            }
            else {
                ss << header.attributes.at(i) << "=" << tuple.getValues().at(i) << ", ";
            }
        }
    }
    if (!columnMap.empty()) { ss << std::endl; }
    return ss.str();
}

void Relation::addTuple(const std::vector<std::string>& values) {
    collection.insert(Tuple(values));
}

Relation::Relation(std::string name, std::map<std::string, int> columnMap, std::vector<int> columnVector) {
    this->name = name;
    this->columnMap = columnMap;
    this->columnVector = columnVector;
}