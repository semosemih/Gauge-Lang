//.h (header) file is an API. Header files only declare that I have "bla bla" you can use that, the implementation is in another file.
#pragma once
#include "lexer.h"
#include "ast.h"
#include <vector>

class Parser{
public:
    Parser(const std::vector<Token>& tokens);

    std::unique_ptr<Expr> parseExpression();
    std::unique_ptr<Expr> parseTerm();
    std::unique_ptr<Expr> parseFactor();
    std::unique_ptr<Expr> parsePrimary();

private:
    const std::vector<Token>& tokens;
    size_t current = 0;

    const Token& advance();
    bool match(TokenType type);
    const Token& previous();
    bool isAtEnd() const;
};