#include "IdAutomaton.h"

void IdAutomaton::S0(const std::string &input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
}

void IdAutomaton::S1(const std::string &input) {
    if (isalpha(input[index]) || isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else if (input.substr(inputRead) == "Schemes"
          || input.substr(inputRead) == "Rules"
          || input.substr(inputRead) == "Facts"
          || input.substr(inputRead) == "Queries") {
        Serr();
    }
}
