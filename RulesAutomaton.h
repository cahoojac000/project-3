#ifndef PROJECT_1_RULESAUTOMATON_H
#define PROJECT_1_RULESAUTOMATON_H

#include "Automaton.h"

class RulesAutomaton : public Automaton {
public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}

    void S0(const std::string& input) override;

private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
};


#endif
