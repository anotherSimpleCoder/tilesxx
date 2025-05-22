//
// Created by abav on 21.05.2025.
//

#ifndef TILES_H
#define TILES_H

#include <vector>

#include "Tile.h"

class Tiles {
private:
    std::vector<Tile*> tiles;
public:
    explicit Tiles(int nrOfTiles);
    int getNrOfTiles() const;
    Tile* getTile(int i) const;
    Tile* getFreeTile();
    Tile* locate(int pageNr);
    void print() const;
};
#endif //TILES_H
