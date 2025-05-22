//
// Created by abav on 21.05.2025.
//

#ifndef PAGINGALGORITHM_H
#define PAGINGALGORITHM_H

#include <string>
#include <vector>
#include "tile/Tiles.h"

class PagingAlgorithm {
public:
    virtual Tile* selectTileToReplace(
      Tiles& tiles,
      int pageNr,
      std::vector<int>& references
    ) = 0;
};
#endif //PAGINGALGORITHM_H
