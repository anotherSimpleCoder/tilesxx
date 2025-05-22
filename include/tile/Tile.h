//
// Created by abav on 21.05.2025.
//

#ifndef TILE_H
#define TILE_H
class Tile {
private:
    bool inUse;
    int pageNr;
    long long ticksLoaded;
    long long ticksLastAccessed;
    int nrOfAccesses;
public:
    Tile();
    bool isInUse() const;
    int getPageNr() const;
    int getNrOfAccesses() const;
    long long getTicksLastAccessed() const;
    long long getTicksLoaded() const;
    void loadPage(int pageNr);
    void access();
};
#endif //TILE_H
