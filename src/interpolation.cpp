#include <iostream>
#include <map>
#include <vector>
#include <tclap/CmdLine.h>
#include "CInerpolator.h"
//#include "CFunction.h"

using namespace std;
using namespace TCLAP;

vector <Point> getInputArray(ValueArg<string> &expression, ValueArg<string> &inputPath);

void interpolate(ValueArg<string> &type, vector <Point> &input);

map<string, CInerpolator *> initializeInterpolators();

void drawLine(const string &name, vector <Point> &data);

void interpolateAndDraw(const string &name, CInerpolator *interpolator, vector <Point> &input);

int main(int argc, const char *argv[]) {
    CmdLine cmd("Command description message", ' ', "0.9");

    // Interpolate existing function or use file as input
    ValueArg<string> expressionString("e", "expr", "Function for interpolation", false, "x^2", "string");
    ValueArg<string> inputFile("i", "input", "Input file", false, "", "string");
    cmd.xorAdd(expressionString, inputFile);

    // Choose interpolation type out of supported
    vector<string> allowedTypes;
    allowedTypes.push_back("lagrange");
    ValuesConstraint<string> constraint = ValuesConstraint<string>(allowedTypes);
    ValueArg<string> type("t", "type", "Interpolation type", false, "", &constraint, cmd);

    // Parse arguments
    cmd.parse(argc, argv);

    // Read from file or generate input
    vector<Point> input = getInputArray(expressionString, inputFile);

    // Actual interpolation
    interpolate(type, input);

    return EXIT_SUCCESS;
}

void interpolate(ValueArg<string> &type, vector<Point> &input) {
    map<string, CInerpolator *> interpolators = initializeInterpolators();

    if (type.isSet()) {
        interpolateAndDraw(type.getValue(), interpolators[type.getValue()], input);
    } else {
        for (auto interpolator: interpolators) {
            interpolateAndDraw(interpolator.first, interpolator.second, input);
        }
    }
}

void interpolateAndDraw(const string &name, CInerpolator *interpolator, vector<Point> &input) {
    interpolator->Interpolate(input);
    vector<Point> output = interpolator->CalculateValues(0, 4, 0.02);
    drawLine(name, output);
}

void drawLine(const string &name, vector<Point> &data) {
    // TODO: Finish
}

map<string, CInerpolator *> initializeInterpolators() {
    // TODO: add new ones
    map<string, CInerpolator *> interMap;
    return interMap;
}

vector<Point> getInputArray(ValueArg<string> &expression, ValueArg<string> &inputPath) {
    // TODO: Finish
    vector<Point> input;
    input.push_back(Point(0, 0));
    input.push_back(Point(1, 1));
    input.push_back(Point(2, 4));
    input.push_back(Point(3, 9));
    input.push_back(Point(4, 16));
    return input;
}
