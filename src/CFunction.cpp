//
// Created by mpsnp on 29.05.16.
//

#include "CFunction.h"
#include "exprtk.hpp"

class CFunctionImpl: public CFunction {
private:
    double x;
    exprtk::symbol_table<double> table;
    exprtk::expression<double> expr;
public:
    CFunctionImpl();
    virtual double value(double x) override;
    virtual void setExpressionString(std::string exprString) override;
};

CFunction *CFunction::instance() {
    return new CFunctionImpl();
}

void CFunctionImpl::setExpressionString(std::string exprString) {
    exprtk::parser<double> exprParser;
    exprParser.compile(exprString, expr);
}

double CFunctionImpl::value(double x) {
    this->x = x;
    return expr.value();
}

CFunctionImpl::CFunctionImpl() {
    table.add_variable("x", x);
    table.add_constants();
    expr.register_symbol_table(table);
}
