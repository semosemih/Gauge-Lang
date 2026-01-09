#include "lexer.h"
#include <cctype>

//bu ne abi
Lexer::Lexer(const std::string& source)
: source(source){}

std::vector<Token> Lexer::scanTokens(){
    while (!isAtEnd()){
        start = current;
        scanToken();
    }

    tokens.push_back({TokenType::EOF_TOKEN, "", line});
    return tokens;
}

//keep going!