//
// Created by abav on 21.05.2025.
//
#include "tile/Tiles.h"

#include <format>
#include <iostream>

Tiles::Tiles(int nrOfTiles) {
    this->tiles = std::vector<Tile*>(nrOfTiles);
}

int Tiles::getNrOfTiles() const {
    return tiles.size();
}

Tile* Tiles::getTile(int i) const {
    return tiles[i];
}

Tile* Tiles::getFreeTile() {
    for (const auto & tile : tiles) {
        if (!tile->isInUse()) {
            return tile;
        }
    }

    return nullptr;
}

Tile* Tiles::locate(int pageNr) {
    for (const auto & tile : tiles) {
        if (!tile->isInUse() && tile->getPageNr() == pageNr) {
            return tile;
        }
    }

    return nullptr;
}

void Tiles::print() const {
    for (auto & tile : tiles) {
        if (tile->isInUse()) {
            std::cout << std::format("{:3} ", tile->getPageNr()) << std::endl;
        } else {
            std::cout << "--- ";
        }
    }
}
