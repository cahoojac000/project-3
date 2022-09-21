#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (static_cast<long unsigned int>(index) > input.size() - 1) {
        this->type = TokenType::UNDEFINED;
    }
    else {
        if (input[index] == '|') {
            inputRead++;
            index++;
            S4(input);
        }
        else {
            if (input[index] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S2(input);
        }
    }
}

void CommentAutomaton::S3(const std::string &input) {
    if (static_cast<long unsigned int>(index) > input.size() - 1) {
        inputRead++;
        index++;
    }
    else {
        if (input[index] != '\n') {
            inputRead++;
            index++;
            S3(input);
        }
    }
}

void CommentAutomaton::S4(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
    }
    else {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}
