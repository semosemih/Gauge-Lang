#pragma once
#include "lexer.h"
#include "ast.h"
#include <vector>

class Parser{
public:
    Parser(const std::vector<Token>& tokens);

    std::unique_ptr<Expr> parseExpression();

private:
    const std::vector<Token>& tokens;
    size_t current = 0;

    const Token& advance();
    bool match(TokenType type);
    const Token& previous();
    bool isAtEnd() const;
};