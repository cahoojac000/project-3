#include "Parameter.h"

Parameter::Parameter(const std::string& text) {
    this->text = text;
    if (!text.empty() && text.at(0) == '\'') {
        this->isConstant = true;
    }
}

Parameter::~Parameter() {

}
