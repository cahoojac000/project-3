#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <sstream>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    PERIOD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END_OF_FILE
};

class Token
{
private:
    std::string tokenTypeToString(TokenType type);
    TokenType type;
    std::string description;
    int line;

public:
    Token(TokenType type, std::string description, int line);
    std::string toString();
    TokenType getTokenType() { return type; }
    std::string getTokenDescription() { return description; }
};

#endif // TOKEN_H

