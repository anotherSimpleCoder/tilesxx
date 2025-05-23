//
// Created by abav on 21.05.2025.
//
#include <iostream>
#include <string>
#include <filesystem>

#include "cli/CLI.h"
#include "referenceStringReader/ReferenceStringReader.h"
#include "paging/Paging.h"

int CLI::usage() {
    std::cout << "Usage\n";
    std::cout << "Paging <nrOfTiles> <referenceStringFile> <algorithmDLLFile>" << std::endl;
    return 1;
}


int CLI::run(int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);

    if (args.size() != 4) {
        return this->usage();
    }

    auto tiles = Tiles(std::stoi(args[1]));
    std::cout << std::filesystem::current_path() << std::endl;
    ReferenceStringReader referenceStringReader(args[2]);
    auto* pagingAlgorithm = Paging::instantiatePagingAlgorithm(args[3]);

    Paging::processReferenceString(tiles, referenceStringReader, *pagingAlgorithm);
    return 0;
}