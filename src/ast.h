//ABSTRACT SYNTAX TREE
#pragma once
#include <memory>
#include <string>

struct Expr{//base class 
    virtual ~Expr() = default;//in cpp, is we give default access, everyone can acces this struct publicly
    virtual std::string print() const=0;
};

struct LiteralExpr : Expr{//child class of Expr VARIABLES LIKE 5, 412, "HELLO"
    std::string value;
    LiteralExpr(std::string v) : value(std::move(v)){}//move() stands for string transformation, not copying but moving

    std::string print() const override{
        return value;
    }
};

struct BinaryExpr : Expr {
    //for instance: "1 + 2"
    //left is '1'
    //operator is '+'
    //right is '2'
    std::unique_ptr<Expr> left;
    std::string op;
    std::unique_ptr<Expr> right;

    BinaryExpr(std::unique_ptr<Expr> l, std::string o, std::unique_ptr<Expr> r) 
        : left(std::move(l)), op(std::move(o)), right(std::move(r)) {}

    std::string print() const override{
        return "(" + op  + " " + left->print() + " " + right->print() + ")";
    }
};

struct UnaryExpr : Expr{
    std::string op;
    std::unique_ptr<Expr> right;

    UnaryExpr(std::string o, std::unique_ptr<Expr> r) 
    : op(std::move(o)), right(std::move(r)){}

    std::string print() const override{
        return "(" + op + " " + right->print() + ")";
    }
};

struct Stmt {
    virtual ~Stmt() = default;
    virtual std::string print() const = 0;
};

struct ExprStmt : Stmt {
    std::unique_ptr<Expr> expr;

    ExprStmt(std::unique_ptr<Expr> e)
        : expr(std::move(e)) {}

    std::string print() const override {
        return expr->print() + ";";
    }
};

struct VarStmt : Stmt {
    std::string name;
    std::unique_ptr<Expr> initializer;

    VarStmt(std::string n, std::unique_ptr<Expr> init)
        : name(std::move(n)), initializer(std::move(init)) {}

    std::string print() const override {
        return "(let " + name + " " + initializer->print() + ")";
    }
};