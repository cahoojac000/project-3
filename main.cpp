#include <string>
#include <fstream>
#include "Lexer.h"
#include "Parser.h"
#include "DatalogProgram.h"
#include "Database.h"
#include "Interpreter.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::ifstream input(fileName);
    if (!input.is_open()) {
        std::cout << "File " << fileName << " could not be found or opened." << std::endl;
        return 1;
    }

    std::string inputString;
    if (input.is_open()) {
        while (input.peek() != EOF) {
            inputString.push_back(char(input.get()));
        }
    }

    auto* lexer = new Lexer(inputString);

    auto* parser = new Parser(lexer->getTokens());
    DatalogProgram program = parser->parse();

    auto* interpreter = new Interpreter(program);

    delete lexer;
    delete parser;
    delete interpreter;

    return 0;
}