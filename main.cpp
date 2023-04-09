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


    g_window = SDL_CreateWindow("Dungeon fighter",
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if(g_window == NULL)
            succes = 0;
    else
    {
        g_screen = SDL_CreateRenderer(g_window,-1,SDL_RENDERER_ACCELERATED);

        if(g_screen == NULL)
            succes = 0;

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

void ThreatsControl(vector<ThreatsObject*> threats_list, PlayerObject p_player,int time)
{

    for(int i=0; i<threats_list.size(); i++)
        {
            string s1 = "img//threats" + threats_list[i]->get_type() + "_l" + ".png";
            string s2 = "img//threats" + threats_list[i]->get_type() + "_r" + ".png";
            if(threats_list[i] != NULL){
            threats_list[i]->Render(g_screen);
            if(threats_list[i]->Move(p_player.get_x_pos(),p_player.get_y_pos(),time) == 1)
            {
                threats_list[i]->LoadImageA(s1,g_screen);
                threats_list[i]->Set_clip();
            }
            else
            {
                threats_list[i]->LoadImageA(s2,g_screen);
                threats_list[i]->Set_clip();
            }
            }
        }
}

int Check_round(vector<ThreatsObject*> threats_list1,vector<ThreatsObject*> threats_list2)
{

    if(threats_list2.size() == 0)   return 3;
    if(threats_list1.size() == 0)   return 2;

    return 1;
}

vector<ThreatsObject*> MakeThreats1()
{
    vector<ThreatsObject*> threats_list1;
     for(int i=0; i<5; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats1_r.png",g_screen);
        p_threat->set_type("1");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(900);
        p_threat->set_y_pos(60+i*80);

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }

    for(int i=0; i<5; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats1_r.png",g_screen);
        p_threat->set_type("1");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(50);
        p_threat->set_y_pos(60+i*80);

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }

    for(int i=0; i<2; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats2_r.png",g_screen);
        p_threat->set_type("2");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(900);
        p_threat->set_y_pos(60+i*(SCREEN_HEIGHT-240));

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }

    for(int i=0; i<2; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats2_r.png",g_screen);
        p_threat->set_type("2");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(50);
        p_threat->set_y_pos(60+i*(SCREEN_HEIGHT-240));

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }

  /*  for(int i=0; i<5; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats2_r.png",g_screen);
        p_threat->set_type("1");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(270 +i*100);
        p_threat->set_y_pos(60);

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }

    for(int i=0; i<5; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats2_r.png",g_screen);
        p_threat->set_type("1");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(270 +i*100);
        p_threat->set_y_pos(SCREEN_HEIGHT-100);

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }*/
    return threats_list1;
}

vector<ThreatsObject*> MakeThreats2()
{
    vector<ThreatsObject*> threats_list1;
     for(int i=0; i<2; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats2_r.png",g_screen);
        p_threat->set_type("4");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(900);
        p_threat->set_y_pos(60+i*(SCREEN_HEIGHT-240));

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }

    for(int i=0; i<2; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats2_r.png",g_screen);
        p_threat->set_type("4");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(50);
        p_threat->set_y_pos(60+i*(SCREEN_HEIGHT-240));

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }

    return threats_list1;
}

int main( int argc, char* args[] )
{
    int time=0;

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

    vector<ThreatsObject*> threats_list1 = MakeThreats1();
    vector<ThreatsObject*> threats_list2 = MakeThreats2();
    bool is_quit = 0;

    while(!is_quit)
    {
        if(SDL_PollEvent(&g_event) != 0)
        {
            if(g_event.type == SDL_QUIT)
                is_quit = 1;

        }

        SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen,NULL);
        game_map.DrawMap(g_screen);

        p_player.Move(g_event,g_screen);
        p_player.Shoot(g_screen,g_event,time);
        p_player.Render(g_screen);



        if(Check_round(threats_list1,threats_list2) == 1)  ///// round1 /////
        {

            ThreatsControl(threats_list1,p_player,time);
                  vector<ArrowObject*> arrow_list = p_player.get_arrow_list();
                for(int i = 0; i < arrow_list.size(); i++)
                {
                    if(arrow_list[i] != NULL)
                    {
                        for(int k = 0; k < threats_list1.size(); k++)
                        {
                            if(threats_list1[k] != NULL)
                            {
                                SDL_Rect a_rect;
                                a_rect.x = threats_list1[k]->GetRect().x;
                                a_rect.y = threats_list1[k]->GetRect().y;
                                a_rect.w = threats_list1[k]->get_width_frame();
                                a_rect.h = threats_list1[k]->get_height_frame();

                                SDL_Rect b_rect = arrow_list[i]->GetRect();

                                bool bCol = CheckCollision(a_rect,b_rect);

                                if(bCol)
                                {
                                    p_player.RemoveArrow(i);
                                    threats_list1[k]->get_damage();
                                }
                                if(threats_list1[k]->get_hp() == 0 )
                                {
                                threats_list1[k]->Free();
                                threats_list1.erase(threats_list1.begin() + k);
                                }

                            }

                        }

                    }

                }

                                for(int k = 0; k < threats_list1.size(); k++)
                        {
                            if(threats_list1[k] != NULL)
                            {
                                SDL_Rect a_rect;
                                a_rect.x = threats_list1[k]->GetRect().x;
                                a_rect.y = threats_list1[k]->GetRect().y;
                                a_rect.w = threats_list1[k]->get_width_frame();
                                a_rect.h = threats_list1[k]->get_height_frame();

                                SDL_Rect b_rect = p_player.get_rect();

                                bool cCol = CheckCollision(a_rect,b_rect);

                                if(cCol)
                                {
                                    is_quit = 1;
                                    threats_list1[k]->Free();
                                    threats_list1.erase(threats_list1.begin() + k);
                                }
                            }

                        }
        }

       if(Check_round(threats_list1,threats_list2) == 2)  ///// round2 /////
        {
                ThreatsControl(threats_list2,p_player,time);
                vector<ArrowObject*> arrow_list = p_player.get_arrow_list();
                for(int i = 0; i < arrow_list.size(); i++)
                {
                    if(arrow_list[i] != NULL)
                    {
                        for(int k = 0; k < threats_list2.size(); k++)
                        {
                            if(threats_list2[k] != NULL)
                            {
                                SDL_Rect a_rect;
                                a_rect.x = threats_list2[k]->GetRect().x;
                                a_rect.y = threats_list2[k]->GetRect().y;
                                a_rect.w = threats_list2[k]->get_width_frame();
                                a_rect.h = threats_list2[k]->get_height_frame();

                                SDL_Rect b_rect = arrow_list[i]->GetRect();

                                bool bCol = CheckCollision(a_rect,b_rect);

                                 if(bCol)
                                {
                                    p_player.RemoveArrow(i);
                                    threats_list2[k]->get_damage();
                                }
                                if(threats_list2[k]->get_hp() == 0 )
                                {
                                threats_list2[k]->Free();
                                threats_list2.erase(threats_list2.begin() + k);
                                }

                            }

                        }

                    }

                }


                            for(int k = 0; k < threats_list2.size(); k++)
                        {

                            if(threats_list2[k] != NULL)
                            {
                                SDL_Rect a_rect;
                                a_rect.x = threats_list2[k]->GetRect().x;
                                a_rect.y = threats_list2[k]->GetRect().y;
                                a_rect.w = threats_list2[k]->get_width_frame();
                                a_rect.h = threats_list2[k]->get_height_frame();

                                SDL_Rect b_rect = p_player.get_rect();

                                bool cCol = CheckCollision(b_rect,a_rect);

                                if(cCol)
                                {
                                    is_quit = 1;
                                    threats_list2[k]->Free();
                                    threats_list2.erase(threats_list2.begin() + k);
                                }
                            }

                        }
        }


           if(Check_round(threats_list1,threats_list2) == 3)   is_quit = 1;

        time++;
        SDL_RenderPresent(g_screen);

        SDL_Delay(10);

    }

    close();

    return 0;
}
