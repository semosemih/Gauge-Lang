#include <iostream>
#include "lexer.h"
#include "parser.h"
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

    Parser parser(tokens);
    auto ast = parser.parseExpression();

    std::cout << "AST built successfully\n";
    return 0;
}