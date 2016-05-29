#include <iostream>
#include <tclap/CmdLine.h>

using namespace std;

int main(int argc, const char *argv[]) {
    TCLAP::CmdLine cmd("Command description message", ' ', "0.9");
    TCLAP::ValueArg<std::string> nameArg("e", "expr", "Function for interpolation", true, "x^2", "string", cmd);
    cmd.parse(argc, argv);

    cout << "Hello " << nameArg.getValue() << "!" << endl;

    return 0;
}