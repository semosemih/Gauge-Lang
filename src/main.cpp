#include <iostream>
#include "lexer.h"

int main(){
    std::string source = 
    "let x = 5 + 3;"
    "fun add(a, b) { return a + b; }";
    Lexer lexer(source);

    auto tokens = lexer.scanTokens();
    for(const auto& token : tokens){
        std::cout << static_cast<int>(token.type)
            << " : " << token.lexeme << std::endl;
    }

    return 0;
}