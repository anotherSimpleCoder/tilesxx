//
// Created by abav on 21.05.2025.
//
#include "referenceStringReader/ReferenceStringReader.h"

#include <fstream>

ReferenceStringReader::ReferenceStringReader(std::string referenceStringFileName) {
    std::ifstream file(referenceStringFileName);
    std::string line;
    std::getline(file, line);
}
