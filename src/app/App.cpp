#include <iostream>
#include "cli/CLI.h"

int main(int argc, char** argv) {
    CLI cli;
    return cli.run(argc, argv);
}