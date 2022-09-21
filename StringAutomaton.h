#ifndef PROJECT_1_STRINGAUTOMATON_H
#define PROJECT_1_STRINGAUTOMATON_H

#include "Automaton.h"

class StringAutomaton : public Automaton {
public:
    StringAutomaton() : Automaton(TokenType::STRING) {}

    void S0(const std::string& input) override;

private:
    void S1(const std::string& input);
    void S2(const std::string& input);
};


#endif
