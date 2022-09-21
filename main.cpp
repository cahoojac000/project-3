#include "Lexer.h"
#include "Parser.h"
#include <fstream>
#include <string>
#include "DatalogProgram.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    // open file
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

    auto* lexer = new Lexer();
    lexer->Run(inputString);

    auto* parser = new Parser(lexer->getTokens());
    DatalogProgram program = parser->parse();
    if (!parser->Failed()) std::cout << program.toString();

    delete lexer;
    //delete parser;

    return 0;
}