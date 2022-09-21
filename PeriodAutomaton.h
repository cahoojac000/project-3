#ifndef PROJECT_1_PERIODAUTOMATON_H
#define PROJECT_1_PERIODAUTOMATON_H

#include "Automaton.h"

class PeriodAutomaton : public Automaton {
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}

    void S0(const std::string& input) override;
};


#endif
