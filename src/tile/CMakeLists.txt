add_library(Tile
    Tile.cpp
)

add_library(Tiles
    Tiles.cpp
)

target_link_libraries(Tiles
    Tile
)