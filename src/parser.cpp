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

std::unique_ptr<Expr> Parser::parseExpression() {
    std::unique_ptr<Expr> expr =
        std::make_unique<LiteralExpr>(advance().lexeme);

    while (match(TokenType::PLUS)) {
        std::string op = previous().lexeme;

        std::unique_ptr<Expr> right =
            std::make_unique<LiteralExpr>(advance().lexeme);

        expr = std::make_unique<BinaryExpr>(
            std::move(expr),
            op,
            std::move(right)
        );
    }

    return expr;
}
