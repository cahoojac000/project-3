#include "Token.h"

#include <utility>

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    // TODO: delete test values
    this->type = type;
    this->description = std::move(description); // TODO: Maybe remove move if bugs occur
    this->line = line;
}

std::string Token::toString() {
    std::stringstream ss;
    std::string typeString = tokenTypeToString(type);
    ss << "(" << typeString << ",\"" << description << "\"," << line << ")" << std::endl;
    return ss.str();
}

std::string Token::tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::COLON: return "COLON";
        case TokenType::COLON_DASH: return "COLON_DASH";
        case TokenType::COMMA: return "COMMA";
        case TokenType::PERIOD: return "PERIOD";
        case TokenType::Q_MARK: return "Q_MARK";
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::MULTIPLY: return "MULTIPLY";
        case TokenType::ADD: return "ADD";
        case TokenType::SCHEMES: return "SCHEMES";
        case TokenType::FACTS: return "FACTS";
        case TokenType::RULES: return "RULES";
        case TokenType::QUERIES: return "QUERIES";
        case TokenType::ID: return "ID";
        case TokenType::STRING: return "STRING";
        case TokenType::COMMENT: return "COMMENT";
        case TokenType::UNDEFINED: return "UNDEFINED";
        case TokenType::END_OF_FILE: return "EOF";
    }
    return "ERROR";
}
