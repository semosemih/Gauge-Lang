#pragma once
#include <string>
#include <vector>
#include "token.h"

class Lexer{
public:
    explicit Lexer(const std::string& source);

    std::vector<Token> scanTokens();
private:
    const std::string source;
    std::vector<Token> tokens;

    int start = 0 ;
    int current = 0;
    int line = 1;

    void scanToken();
    char advance();
    bool isAtEnd() const;

    void addToken(TokenType type);

    char peek() const;
    bool isAlpha(char c) const;
    bool isDigit(char c) const;

    void identifier();
    void number();
};
