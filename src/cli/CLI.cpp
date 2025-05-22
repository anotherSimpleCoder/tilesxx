//
// Created by abav on 21.05.2025.
//
#include <iostream>
#include <string>

#include "cli/CLI.h"
#include "referenceStringReader/ReferenceStringReader.h"
#include "paging/PagingAlgorithm.h"

int CLI::usage() {
    std::cout << "Usage\n";
    std::cout << "Paging <nrOfTiles> <referenceStringFile> <algorithmDLLFile>" << std::endl;
    return 1;
}


int CLI::run(int argc, char** argv) {
    if (argc != 3) {
        return this->usage();
    }

    auto* tiles = new Tiles(std::stoi(argv[0]));
    ReferenceStringReader referenceStringReader(argv[1]);

    return 0;
}