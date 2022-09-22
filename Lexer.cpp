#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "QuestionMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "PeriodAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"

Lexer::Lexer(std::string inputString) {
    CreateAutomata();
    Run(inputString);
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for (auto& i : automata) {
        delete i;
    }
    for (auto& i : tokens) {
        delete i;
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new QuestionMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    while (!input.empty()) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata[0];

        if (isspace(input[0])) {
            if (input[0] == '\n') {
                lineNumber++;
            }
            input.erase(0, 1);
        }
        else {
            for (long unsigned int i = 0; i < automata.size(); i++) {
                int inputRead = automata[i]->Start(input);
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automata[i];
                }
            }
            if (maxRead > 0) {
                std::string description = input.substr(0, maxRead);
                Token* newToken = maxAutomaton->CreateToken(description, lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                if (maxAutomaton->GetTokenType() != TokenType::COMMENT) {
                    tokens.push_back(newToken);
                }
            }
            else {
                maxRead = 1;
                Token* newToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                tokens.push_back(newToken);
            }
            input.erase(0, maxRead);
        }
    }
    Token* newToken = new Token(TokenType::END_OF_FILE, "", lineNumber);
    tokens.push_back(newToken);
}

void Lexer::printTokens() {
    for (long unsigned int i = 0; i < tokens.size(); i++) {
        std::cout << tokens[i]->toString();
    }
    std::cout << "Total Tokens = " << tokens.size() << std::endl;
}

std::vector<Token*> Lexer::getTokens() {
    return tokens;
}