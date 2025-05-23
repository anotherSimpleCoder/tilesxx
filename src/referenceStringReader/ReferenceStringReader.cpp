//
// Created by abav on 21.05.2025.
//
#include "referenceStringReader/ReferenceStringReader.h"

#include <iostream>
#include <filesystem>
#include <fstream>

ReferenceStringReader::ReferenceStringReader(std::string referenceStringFileName) {
    if (!std::filesystem::exists(referenceStringFileName)) {
        std::cerr << "Reference string file " << referenceStringFileName << " not found!" << std::endl;
        return;
    }

    std::ifstream file(referenceStringFileName);
    std::string line;
    std::getline(file, line);

    std::cout << line << std::endl;
}
