#include <iostream>
#include <tclap/CmdLine.h>
#include "CFunction.h"

using namespace std;

int main(int argc, const char *argv[]) {
    TCLAP::CmdLine cmd("Command description message", ' ', "0.9");
    TCLAP::ValueArg<std::string> expressionString("e", "expr", "Function for interpolation", false, "x^2", "string", cmd);
    cmd.parse(argc, argv);

    CFunction *func = CFunction::instance();
    func->setExpressionString(expressionString.getValue());

    cout << "value = " << func->value(4) << "!" << endl;

    return 0;
}