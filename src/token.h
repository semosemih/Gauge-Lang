#pragma once
#include <string>

enum class TokenType{
//single-character tokens
LEFT_PAREN, RIGHT_PAREN,
LEFT_BRACE, RIGHT_BRACE,
COMMA, SEMICOLON,

PLUS, MINUS, STAR, SLASH,
EQUAL,

//literals
IDENTIFIER, //variables like x, ymin, player_health
NUMBER,

//keywords
LET,
FUN,

EOF_TOKEN
};

struct Token{
    TokenType type;
    std::string lexeme;
    int line;
};