#include "midi.hh"
#include "breakpoints.hh"
#include "exp.hh"
#include "sin.hh"
#include "test.hh"

#include <iostream>
#include <string>
#include <filesystem>

using namespace test;

int main(int argc, char** argv) {
    std::string prefix;

    if (argc == 2) {
        prefix = std::string(argv[1]);
    }
    
    Test::run(prefix);

    return 0;
}