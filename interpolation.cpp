#include <iostream>
#include <tclap/CmdLine.h>
//#include "CFunction.h"

using namespace std;

int main(int argc, const char *argv[]) {
    TCLAP::CmdLine cmd("Command description message", ' ', "0.9");

    // Interpolate existing function or use file as input
    TCLAP::ValueArg<std::string> expressionString("e", "expr", "Function for interpolation", false, "x^2", "string");
    TCLAP::ValueArg<std::string> inputFile("i", "input", "Input file", false, "", "string");
    cmd.xorAdd(expressionString, inputFile);

    // Choose interpolation type out of supported
    vector<string> allowedTypes;
    allowedTypes.push_back("lagrange");
    TCLAP::ValuesConstraint<string> constraint = TCLAP::ValuesConstraint<string>(allowedTypes);
    TCLAP::ValueArg<std::string> type("t", "type", "Interpolation type", true, "", &constraint, cmd);

    // Parse arguments
    cmd.parse(argc, argv);

    return EXIT_SUCCESS;
}