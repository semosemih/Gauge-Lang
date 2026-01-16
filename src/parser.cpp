#include "parser.h"
Parser::Parser(const std::vector<Token>& t) : tokens(t) {}

const Token& Parser::advance(){
    if (!isAtEnd()) current++;
    return previous();
}

bool Parser::match(TokenType type){
   if(!isAtEnd() && tokens[current].type == type){
    advance();
    return true;
   } 
   return false;
}

const Token& Parser::previous(){
    return tokens[current - 1];
}

bool Parser::isAtEnd() const {
    return tokens[current].type == TokenType::EOF_TOKEN;
}

std::unique_ptr<Expr> Parser::parseExpression() {//whole expression
    return parseTerm();
}

std::unique_ptr<Expr> Parser::parseTerm(){//plus and minus
    auto expr = parseFactor();

    while(match(TokenType::PLUS)){
        std::string op = previous().lexeme;
        auto right = parseFactor();
        expr = std::make_unique<BinaryExpr>(
            std::move(expr), op, std::move(right)
        );
    }
    return expr;
}

std::unique_ptr<Expr> Parser::parseFactor(){//for star and slash operator
    auto expr = parsePrimary();

    while (match(TokenType::STAR)){
        std::string op = previous().lexeme;
        auto right = parsePrimary();
        expr = std::make_unique<BinaryExpr>(
            std::move(expr), op, std::move(right)
        );
    }
    return expr;
}

std::unique_ptr<Expr> Parser::parsePrimary(){//paranthesis and literal 
    if(match(TokenType::NUMBER)|| match(TokenType::IDENTIFIER)){
        return std::make_unique<LiteralExpr>(previous().lexeme);
    }

    if(match(TokenType::LEFT_PAREN)){
        auto expr = parseExpression();
        match(TokenType::RIGHT_PAREN);
        return expr;
    }
    return nullptr;
}