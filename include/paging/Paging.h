//
// Created by abav on 22.05.2025.
//

#ifndef PAGING_H
#define PAGING_H
#include "referenceStringReader/ReferenceStringReader.h"
#include "PagingAlgorithm.h"
#include <string>

namespace Paging {
    PagingAlgorithm* instantiatePagingAlgorithm(std::string dllPath);
    void processReferenceString(Tiles& tiles, ReferenceStringReader& reader, PagingAlgorithm& pagingAlgorithm);
};
#endif //PAGING_H
