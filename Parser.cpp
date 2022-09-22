#include "Parser.h"
#include <utility>

Parser::Parser(std::vector<Token *> tokens) {
    this->tokens = std::move(tokens);
}

Parser::~Parser() = default;

DatalogProgram Parser::parse() {
    try {
        datalogProgram();
        return program;
    }
    catch (Token& error) {
        std::cout << "Failure!" << std::endl << "  " << error.toString();
        failed = true;
        return {};
    }
}

void Parser::datalogProgram() {
    if (match(TokenType::SCHEMES)) {
        if (match(TokenType::COLON)) {
            scheme();
            schemeList();
            if (match(TokenType::FACTS)) {
                if (match(TokenType::COLON)) {
                    factList();
                    if (match(TokenType::RULES)) {
                        if (match(TokenType::COLON)) {
                            ruleList();
                            if (match(TokenType::QUERIES)) {
                                if (match(TokenType::COLON)) {
                                    query();
                                    queryList();
                                    if (!match(TokenType::END_OF_FILE)) {
                                        Error();
                                    }
                                }
                                else {
                                    Error();
                                }
                            }
                            else {
                                Error();
                            }
                        }
                        else {
                            Error();
                        }
                    }
                    else {
                        Error();
                    }
                }
                else {
                    Error();
                }
            }
            else {
                Error();
            }
        }
        else {
            Error();
        }
    }
    else {
        Error();
    }
}

void Parser::scheme() {
    if (matchD(TokenType::ID)) {
        SetId();
        if (match(TokenType::LEFT_PAREN)) {
            if (matchD(TokenType::ID)) {
                AddParam();
                idList();
            }
            else {
                Error();
            }
            if (!match(TokenType::RIGHT_PAREN)) {
                Error();
            }
            else {
                program.AddScheme(id, parameters);
            }
        }
        else {
            Error();
        }
    }
    else {
        Error();
    }
}

void Parser::idList() {
    if (match(TokenType::COMMA)) {
        if (matchD(TokenType::ID)) {
            AddParam();
            idList();
        }
        else {
            Error();
        }
    }
}

void Parser::schemeList() {
    if (matchD(TokenType::ID)) {
        scheme();
        schemeList();
    }
}

void Parser::factList() {
    if (matchD(TokenType::ID)) {
        fact();
        factList();
    }
}

void Parser::fact() {
    if (matchD(TokenType::ID)) {
        SetId();
        if (match(TokenType::LEFT_PAREN)) {
            if (matchD(TokenType::STRING)) {
                AddParam();
                stringList();
                if (match(TokenType::RIGHT_PAREN)) {
                    if (!match(TokenType::PERIOD)) {
                        Error();
                    }
                    else {
                        program.AddFact(id, parameters);
                    }
                }
                else {
                    Error();
                }
            }
            else {
                Error();
            }
        }
        else {
            Error();
        }
    }
    else {
        Error();
    }
}

void Parser::stringList() {
    if (match(TokenType::COMMA)) {
        if (matchD(TokenType::STRING)) {
            AddParam();
            stringList();
        }
        else {
            Error();
        }
    }
}

void Parser::ruleList() {
    if (matchD(TokenType::ID)) {
        rule();
        ruleList();
    }
}

void Parser::rule() {
    headPredicate();
    if (match(TokenType::COLON_DASH)) {
        predicate();
        predicateList();
        if (!match(TokenType::PERIOD)) {
            Error();
        }
        else {
            program.AddRule(head, predicates);
        }
    }
    else {
        Error();
    }
}

void Parser::headPredicate() {
    if (matchD(TokenType::ID)) {
        SetId();
        if (match(TokenType::LEFT_PAREN)) {
            if (matchD(TokenType::ID)) {
                AddParam();
                idList();
                if (!match(TokenType::RIGHT_PAREN)) {
                    Error();
                }
                else {
                    head = Predicate(id, parameters);
                    parameters.clear();
                }
            }
            else {
                Error();
            }
        }
        else {
            Error();
        }
    }
    else {
        Error();
    }
}

void Parser::predicate() {
    if (matchD(TokenType::ID)) {
        SetId();
        if (match(TokenType::LEFT_PAREN)) {
            parameter();
            parameterList();
            if (!match(TokenType::RIGHT_PAREN)) {
                Error();
            }
            predicates.emplace_back(Predicate(id, parameters));
            parameters.clear();
        }
        else {
            Error();
        }
    }
    else {
        Error();
    }
}

void Parser::parameter() {
    if (!matchD(TokenType::STRING) || !matchD(TokenType::ID)) {
        AddParam();
    }
    else {
        Error();
    }
}

void Parser::parameterList() {
    if (match(TokenType::COMMA)) {
        parameter();
        parameterList();
    }
}

void Parser::predicateList() {
    if (match(TokenType::COMMA)) {
        predicate();
        predicateList();
    }
}

void Parser::query() {
    predicate();
    if (!match(TokenType::Q_MARK)) {
        Error();
    }
    else {
        program.AddQuery(Predicate(id, predicates.at(0).getParams()));
        predicates.erase(predicates.begin());
    }
}

void Parser::queryList() {
    if (matchD(TokenType::ID)) {
        query();
        queryList();
    }
}

bool Parser::match(TokenType compare) {
    if (tokens.at(0)->getTokenType() == compare) {
        tokens.erase(tokens.begin());
        return true;
    }
    else {
        return false;
    }
}

bool Parser::matchD(TokenType compare) {
    if (tokens.at(0)->getTokenType() == compare) {
        return true;
    }
    else {
        return false;
    }
}

void Parser::AddParam() {
    parameters.emplace_back(Parameter(tokens.at(0)->getTokenDescription()));
    tokens.erase(tokens.begin());
}

void Parser::Error() {
    throw *tokens.at(0);
}

void Parser::SetId() {
    id = tokens.at(0)->getTokenDescription();
    tokens.erase(tokens.begin());
}