#include "game_map.h"
using namespace std;


void GameMap :: LoadMap(char *name)
{
    FILE *fp = NULL;
    fopen_s(&fp, name, "rb");
    if (fp == NULL)
    {
        std::cout << "loi load map";
        return;
    }

    game_map_.max_x_ = 0;
    game_map_.max_y_ = 0;

        for(int i = 0; i < MAX_MAP_Y; i++)
        {
            for(int j = 0; j < MAX_MAP_X; j++)
            {
                fscanf(fp,"%d",&game_map_.tile[i][j]);
                int val = game_map_.tile[i][j];

                if(val >= 0 && val < 10)
                {
                   // cout << val << " ";
                    if(j > game_map_.max_x_)    game_map_.max_x_ = j;
                    if(i > game_map_.max_y_)    game_map_.max_y_ = i;
                }
            }
            //cout << endl;
        }

        game_map_.max_x_++ ;
        game_map_.max_y_++;


        game_map_.file_name_ = name;
        fclose(fp);
}

void GameMap :: LoadTiles (SDL_Renderer * screen)
{
    /*char file_img[20];
    FILE * fp= NULL;

    for(int i = 0; i < MAX_TILES; i++)
    {
        sprintf_s(file_img, "map/%d.png", i);

        fopen_s(&fp, file_img, "rb");

        if(fp == NULL)
        {
             continue;
        }


        fclose(fp);*/

        Tile_mat[1].LoadImg("map/1.png",screen);
        Tile_mat[2].LoadImg("map/2.png",screen);
        Tile_mat[3].LoadImg("map/3.png",screen);
        Tile_mat[4].LoadImg("map/4.png",screen);


}

void GameMap :: DrawMap (SDL_Renderer * screen)
{
    int x1 = 0;
    int x2 = SCREEN_WIDTH;

    int y1 = 0;
    int y2 = SCREEN_HEIGHT;

    int map_x=0;
    int map_y=0;


    for(int i = 0; i < y2; i+= SCREEN_HEIGHT/game_map_.get_max_y())
    {
        map_x = 0;
        for(int j = 0; j <x2; j+= SCREEN_WIDTH/game_map_.get_max_x())
        {
            int val = game_map_.tile[map_y][map_x];
           // cout <<  val << " ";
            if(val > 0 && val < 10)
            {
               // std::cout << val << " " ;

                Tile_mat[val].SetRect(j,i);

                Tile_mat[val].Render(screen);

            }
            map_x++;
        }
       // cout << endl;
        map_y++;
    }

    return;
}
