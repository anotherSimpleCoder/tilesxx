//
// Created by abav on 21.05.2025.
//
#include "tile/Tile.h"

#include <chrono>

using namespace std::chrono;

Tile::Tile() {
    this->inUse = false;
    this->pageNr = -1;
    this->nrOfAccesses = 0;
    this->ticksLastAccessed = this->ticksLoaded = duration_cast<milliseconds>(
        steady_clock::now().time_since_epoch()
    ).count();
}

bool Tile::isInUse() const {
    return this->inUse;
}

int Tile::getPageNr() const {
    return this->pageNr;
}

int Tile::getNrOfAccesses() const {
    return this->nrOfAccesses;
}

long long Tile::getTicksLastAccessed() const{
    return this->ticksLastAccessed;
}

long long Tile::getTicksLoaded() const {
    return this->ticksLoaded;
}

void Tile::loadPage(int pageNr) {
    this->pageNr = pageNr;
    inUse = true;
    this->ticksLastAccessed = this->ticksLoaded = duration_cast<milliseconds>(
        steady_clock::now().time_since_epoch()
    ).count();
    nrOfAccesses = 0;
}

void Tile::access() {
    ++nrOfAccesses;
    ticksLastAccessed = duration_cast<milliseconds>(
        steady_clock::now().time_since_epoch()
    ).count();
}
