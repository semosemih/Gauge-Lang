#pragma once
#include <memory>
#include <string>

struct Expr{
    virtual ~Expr() = default;
};

struct LiteralExpr : Expr{
    std::string value;
    LiteralExpr(std::string v) : value(std::move(v)){}
};

struct BinaryExpr : Expr {
    std::unique_ptr<Expr> left;
    std::string op;
    std::unique_ptr<Expr> right;

    BinaryExpr(std::unique_ptr<Expr> l, std::string o, std::unique_ptr<Expr> r) 
        : left(std::move(l)), op(std::move(o)), right(std::move(r)) {}
};

