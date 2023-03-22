#ifndef GAME_MAP_H_INCLUDED
#define GAME_MAP_H_INCLUDED

#include "CommonFunction.h"
#include "BaseObject.h"

#define MAX_TILES 5

class TileMat : public BaseObject
{
public:
    TileMat(){;}
    ~TileMat(){;}

};

class GameMap
{
public:
    GameMap(){;}
    ~GameMap(){;}

    void LoadMap(char* name);
    void LoadTiles(SDL_Renderer * screen);
    void DrawMap (SDL_Renderer * screen);


private:
    Map game_map_;
    TileMat Tile_mat[MAX_TILES];
};

#endif // GAME_MAP_H_INCLUDED
