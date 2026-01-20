#include <iostream>
#include "lexer.h"
#include "parser.h"
int main(){
    std::string source = "let x = 5 + 3 * 2;";

    Lexer lexer(source);

    auto tokens = lexer.scanTokens();
    // for(const auto& token : tokens){
    //     std::cout << static_cast<int>(token.type)
    //         << " : " << token.lexeme << std::endl;
    // }

    Parser parser(tokens);
    auto stmt = parser.parseStatement();

    if (stmt) {
        std::cout << stmt->print() << std::endl;
    } else {
        std::cout << "Parsing failed." << std::endl;
    }
    return 0;
}