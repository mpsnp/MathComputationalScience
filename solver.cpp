//
// Created by mpsnp on 29.05.16.
//

#include <tclap/CmdLine.h>

int main(int argc, const char *argv[]) {
    TCLAP::CmdLine cmd("Command description message", ' ', "0.9");
    TCLAP::ValueArg<std::string> inputPath("i", "input", "Input file", false, "", "string", cmd);
    TCLAP::ValueArg<std::string> outputpath("o", "output", "Output file", false, "", "string", cmd);
    cmd.parse(argc, argv);


    return EXIT_SUCCESS;
}