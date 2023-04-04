//#include "stdafx.h"
#include "CommonFunction.h"
#include "BaseObject.h"
#include "game_map.h"
#include<fstream>
#include "PlayerObject.h"
#include"ThreatsObject.h"
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


 //  vector<ThreatsObject*> threats_list = MakeThreatsList();
    vector<ThreatsObject*> threats_list ;
    for(int i=0; i<5; i++)
    {

        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats1.png",g_screen);
        p_threat->Set_clip();
        p_threat->set_x_pos(900);
        p_threat->set_y_pos(60+i*80);

        threats_list.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }


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

        p_player.Shoot(g_screen);
        p_player.Render(g_screen);

        for(int i=0; i<threats_list.size(); i++)
        {
            if(threats_list[i] != NULL){
            threats_list[i]->Render(g_screen);
            threats_list[i]->Move(p_player.get_x_pos(),p_player.get_y_pos());
            }
        }

      vector<ArrowObject*> arrow_list = p_player.get_arrow_list();
        for(int i = 0; i < arrow_list.size(); i++)
        {
            if(arrow_list[i] != NULL){
            for(int k = 0; k < threats_list.size(); k++)
            {
                if(threats_list[k] != NULL)
                {
                    SDL_Rect a_rect;
                    a_rect.x = threats_list[k]->GetRect().x;
                    a_rect.y = threats_list[k]->GetRect().y;
                    a_rect.w = threats_list[k]->get_width_frame();
                    a_rect.h = threats_list[k]->get_height_frame();

                    SDL_Rect b_rect = arrow_list[i]->GetRect();

                    bool bCol = CheckCollision(a_rect,b_rect);

                    if(bCol)
                    {
                        cout << k;
                        p_player.RemoveArrow(i);
                        threats_list[k]->Free();
                        threats_list.erase(threats_list.begin() + k);

                    }
                }

            }
            }
        }


        SDL_RenderPresent(g_screen);

        SDL_Delay(150);

    }

    close();

    return 0;
}
