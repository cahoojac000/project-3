#ifndef PROJECT_1_IDAUTOMATON_H
#define PROJECT_1_IDAUTOMATON_H

#include "Automaton.h"
#include <cctype>

class IdAutomaton : public Automaton {
public:
    IdAutomaton() : Automaton(TokenType::ID) {}

    void S0(const std::string& input) override;

private:
    void S1(const std::string& input);
};


#endif
