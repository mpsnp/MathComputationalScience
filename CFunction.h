//
// Created by mpsnp on 29.05.16.
//

#ifndef COMPUTATIONALSCIENCE_CFUNCTION_H
#define COMPUTATIONALSCIENCE_CFUNCTION_H

#include <string>

class CFunction {
public:

    static CFunction *instance();
    virtual void setExpressionString(std::string exprString) = 0;
    virtual double value(double x) = 0;
};


#endif //COMPUTATIONALSCIENCE_CFUNCTION_H
