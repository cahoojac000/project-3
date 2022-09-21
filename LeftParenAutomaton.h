#ifndef PROJECT_1_LEFTPARENAUTOMATON_H
#define PROJECT_1_LEFTPARENAUTOMATON_H

#include "Automaton.h"

class LeftParenAutomaton : public Automaton {
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}

    void S0(const std::string& input) override;
};


#endif
