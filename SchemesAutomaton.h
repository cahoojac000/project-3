#ifndef PROJECT_1_SCHEMESAUTOMATON_H
#define PROJECT_1_SCHEMESAUTOMATON_H

#include "Automaton.h"

class SchemesAutomaton : public Automaton {
public:
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}

    void S0(const std::string& input) override;

private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);
};


#endif
