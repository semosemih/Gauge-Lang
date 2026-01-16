#include <iostream>
#include "lexer.h"
#include "parser.h"
int main(){
    std::string source = 
    "5 + 3 + 2";
    Lexer lexer(source);

    auto tokens = lexer.scanTokens();
    for(const auto& token : tokens){
        std::cout << static_cast<int>(token.type)
            << " : " << token.lexeme << std::endl;
    }

    Parser parser(tokens);
    auto ast = parser.parseExpression();

    std::cout << ast->print() << std::endl;
    return 0;
}