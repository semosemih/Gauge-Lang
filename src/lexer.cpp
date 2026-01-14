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

void Lexer::scanToken(){//this function belongs to Lexer class and its name is scanToken
    char c = advance();

    switch(c){
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(TokenType::RIGHT_BRACE); break;
        case '+': addToken(TokenType::PLUS); break;
        case '-': addToken(TokenType::MINUS); break;
        case '*': addToken(TokenType::STAR); break;
        case '/': addToken(TokenType::SLASH); break;
        case '=': addToken(TokenType::EQUAL); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case ',': addToken(TokenType::COMMA); break;

        case ' ':
        case '\r':
        case '\t':
            break;

        case '\n':
            line++;
            break;

        default:
            break;
    }
}

char Lexer::advance(){
    return source[current++];
}

bool Lexer::isAtEnd() const{ //due to const reserved word, it cannot change any variable of Lexer object. 
    return current >= source.length();
}

void Lexer::addToken(TokenType type){
    std::string text = source.substr(start, current - start);
    tokens.push_back({type,text,line});
}

char Lexer::peek() const{
    if (isAtEnd()) return '\0';
    return source[current];
}

bool Lexer::isAlpha(char c) const{//alpha stands for alphabet letter
    return std::isalpha(static_cast<unsigned char>(c));
}

bool Lexer::isDigit(char c) const{
    return std::isdigit(static_cast<unsigned char>(c));
}