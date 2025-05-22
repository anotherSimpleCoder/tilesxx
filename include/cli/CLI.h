//
// Created by abav on 21.05.2025.
//

#ifndef CLI_H
#define CLI_H
#include "tile/Tiles.h"

class CLI {
private:
    int usage();
public:
    int run(int argc, char** argv);
};
#endif //CLI_H
