#include "lexer.h"
#include <cctype>

//here is our constructor for the source code like "let x = 5;"
Lexer::Lexer(const std::string& source)
: source(source){}

std::vector<Token> Lexer::scanTokens(){
    while (!isAtEnd()){
        start = current;//after each token adding, start should updated!
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
            line++;//in token struct, remember we have line. by the help of this, we increment line by one for each row
            break;

        default:
        if (isDigit(c)){
            number();
        } else if (isAlpha(c)){
            identifier();
        }
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

char Lexer::peek() const{//look for the next char to check if it is a number or letter
    if (isAtEnd()) return '\0';
    return source[current];
}

bool Lexer::isAlpha(char c) const{//alpha stands for alphabet letter
    return std::isalpha(static_cast<unsigned char>(c));
}

bool Lexer::isDigit(char c) const{
    return std::isdigit(static_cast<unsigned char>(c));
}

void Lexer::number(){
    while (isDigit(peek())) advance();

    addToken(TokenType::NUMBER);
}

void Lexer::identifier(){
    while (isAlpha(peek()) || isDigit(peek())) advance();

    std::string text = source.substr(start, current - start);

    if(text == "let"){
        tokens.push_back({TokenType::LET, text, line});
    } else if (text == "fun"){
        tokens.push_back({TokenType::FUN, text, line});
    } else if (text =="return"){
        tokens.push_back({TokenType::RETURN, text, line});
    } else {
        tokens.push_back({TokenType::IDENTIFIER, text, line});
    }
}