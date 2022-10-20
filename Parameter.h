//
// Created by Jacob Cahoon on 9/14/22.
//

#ifndef PROJECT_2_PARAMETER_H
#define PROJECT_2_PARAMETER_H

#include <iostream>

class Parameter {
public:
    Parameter(const std::string& text);
    ~Parameter();
    std::string toString() { return text; }
    bool getIsConstant() { return isConstant; }
private:
    std::string text;
    bool isConstant = false;
};


#endif //PROJECT_2_PARAMETER_H
