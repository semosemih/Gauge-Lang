#include <iostream>
#include "lexer.h"

int main(){
    //henuz buranin ne yaptigini bilmiyorum.
    std::string source = "let x = 5 + 3;";
    Lexer lexer(source);

    auto tokens = lexer.scanTokens();
    for(const auto& token : tokens){
        std::cout << static_cast<int>(token.type)
            << " : " << token.lexeme << std::endl;
    }

    return 0;
}