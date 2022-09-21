#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"
#include <cctype>
#include <iostream>

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    void CreateAutomata();
public:
    Lexer();
    ~Lexer();
    void Run(std::string& input);
    void printTokens();
    std::vector<Token*> getTokens();
};

#endif