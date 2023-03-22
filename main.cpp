//#include "stdafx.h"
#include "CommonFunction.h"
#include "BaseObject.h"
#include "game_map.h"
#include<fstream>
#include "PlayerObject.h"
using namespace std;


BaseObject g_background;

bool InitData()
{
    bool succes = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)    return 0;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");

    g_window = SDL_CreateWindow("Dungeon fighter",
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if(g_window == NULL)
            succes = 0;
    else
    {
        g_screen = SDL_CreateRenderer(g_window,-1,SDL_RENDERER_ACCELERATED);

        if(g_screen == NULL)
            succes = 0;
        else
        {
            SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;

            if (!(IMG_Init(imgFlags))&&imgFlags)     succes = 0;

        }
    }

    return succes;

}

bool LoadBacground()
{

    bool ret = g_background.LoadImg("img/background.png",g_screen);

    if(ret == 0)
        return false;


    return 1;
}


void close()
{
    g_background.Free();

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit;
    SDL_Quit;
}

int main( int argc, char* args[] )
{
    if(InitData()==0)
        return -1;

  if(LoadBacground() == 0)
        return -1;

    GameMap game_map;
    game_map.LoadMap("map/map.o");
    game_map.LoadTiles(g_screen);

    PlayerObject p_player ;
    p_player.LoadImg("img//player_r.png",g_screen);
    p_player.Set_clips();


    bool is_quit = 0;

    while(!is_quit)
    {
        while(SDL_PollEvent(&g_event) != 0)
        {
            if(g_event.type == SDL_QUIT)
                is_quit = 1;

            p_player.Move(g_event,g_screen);
        }

        SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen,NULL);

        game_map.DrawMap(g_screen);

        p_player.Render(g_screen);

        SDL_RenderPresent(g_screen);

    }

    close();

    return 0;
}
