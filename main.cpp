//#include "stdafx.h"
#include "CommonFunction.h"
#include "BaseObject.h"
#include "game_map.h"
#include<fstream>
#include "PlayerObject.h"
#include"ThreatsObject.h"
#include"Menu.h"
using namespace std;

BaseObject g_background;
TTF_Font* font=NULL;
SDL_Color textColor = {255, 255, 255};


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
    TTF_Init();

    font = TTF_OpenFont("m5x7.ttf",50);
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
            threats_list[i]->Render_hp(g_screen);

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

   for(int i=0; i<5; i++)
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
    }
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

     for(int i=0; i<5; i++)
    {
        ThreatsObject* p_threat = new ThreatsObject;
        p_threat->LoadImageA("img//threats1_r.png",g_screen);
        p_threat->set_type("3");
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
        p_threat->set_type("3");
        p_threat->set_hp_v();
        p_threat->Set_clip();
        p_threat->set_x_pos(50);
        p_threat->set_y_pos(60+i*80);

        threats_list1.push_back(p_threat);
        p_threat = nullptr;
        delete p_threat;
    }
    return threats_list1;
}

int main( int argc, char* args[] )
{
    int score=0;
    int kill=0;
    int time[10];
    for(int i=0; i<10; i++)
    {
        time[i] = 0;
    }

    if(InitData()==0)
        return -1;

  if(LoadBacground() == 0)
        return -1;
/////////////////game start///////////////////////////////////////////////////////////////////////////////////////


  // run_menu(g_screen,font,textColor);
        BaseObject intro_back_ground;
        intro_back_ground.LoadImg("map//back_ground.png",g_screen);
        int mouseX, mouseY;
        PlayerObject intro_player1 ;
        intro_player1.LoadImg("img//player_l.png",g_screen);
        intro_player1.Set_clips();

        PlayerObject intro_player2 ;
        intro_player2.LoadImg("img//player_l.png",g_screen);
        intro_player2.Set_clips();

        ThreatsObject intro_threats1;
        intro_threats1.LoadImageA("img//threats4_r.png",g_screen);
        intro_threats1.Set_clip();

        ThreatsObject intro_threats2;
        intro_threats2.LoadImageA("img//threats4_l.png",g_screen);
        intro_threats2.Set_clip();

    while(1)
    {
//        game_map0.DrawMap(g_screen);
        intro_back_ground.Render(g_screen);
        SDL_PollEvent(&g_event);
        draw_menu(g_screen,font,textColor);
        if(g_event.type == SDL_MOUSEBUTTONDOWN&&mouseX>=458&&mouseX<=563&&mouseY>=250&&mouseY<=295)
        {
            break;
        }
        if(g_event.type==SDL_QUIT||g_event.type == SDL_MOUSEBUTTONDOWN&&mouseX>=468&&mouseX<=552&&mouseY>=350&&mouseY<=395)
            exit(0);
        if(g_event.type == SDL_MOUSEMOTION)
        {
            mouseX = g_event.button.x;
            mouseY = g_event.button.y;
        }
        if(mouseX>=458&&mouseX<=563&&mouseY>=250&&mouseY<=295)
        {
            intro_player1.set_pos(350 , 260);
            intro_player1.set_status(0);
            intro_player1.run();
            intro_player1.Render(g_screen);

            intro_threats1.set_x_pos(390);
            intro_threats1.set_y_pos(250);
            intro_threats1.Render(g_screen);

        }

        if(mouseX>=468&&mouseX<=552&&mouseY>=350&&mouseY<=395)
        {
            intro_player1.set_pos(350 , 360);
            intro_player1.set_status(1);
            intro_player1.run();
            intro_player1.Render(g_screen);

            intro_threats2.set_x_pos(390);
            intro_threats2.set_y_pos(350);
            intro_threats2.Render(g_screen);
        }
        SDL_Delay(10);
        SDL_RenderPresent(g_screen);
    }
/////////////////game start//////////////////////////////////////////////////////////////////////////////////////

    GameMap game_map;
    game_map.LoadMap("map/map1.o");
    game_map.LoadTiles(g_screen);

    PlayerObject p_player ;
    p_player.LoadImg("img//player_r.png",g_screen);
    p_player.Set_clips();

    vector<ThreatsObject*> threats_list1 = MakeThreats1();
    vector<ThreatsObject*> threats_list2 = MakeThreats2();

    bool is_menu = 0;
    bool is_quit = 0;
    while(!is_quit)
    {
        if(SDL_PollEvent(&g_event) != 0)
        {
            if(g_event.type == SDL_QUIT)
                is_quit = 1;

        }
    /////////////////menu /////////////////////////////////////////
        if(g_event.key.keysym.sym == SDLK_ESCAPE)   is_menu = 1;
        while(is_menu!=0)
        {

            GameMap menu_map;
            menu_map.LoadMap("map/map0.o");
            menu_map.LoadTiles(g_screen);
            menu_map.DrawMap(g_screen);


            string s1 = "Kill " + to_string(kill);
            printText(g_screen,s1,100 ,270,font,textColor, 15, 30);
            string s2 = "Score " + to_string(score);
            printText(g_screen,s2,400 ,270,font,textColor, 15, 30);
            string s3 = "Round " + to_string(Check_round(threats_list1,threats_list2));
            printText(g_screen,s3,700 ,270,font,textColor, 15, 30);

            SDL_RenderPresent(g_screen);
            if ( SDL_WaitEvent(&g_event) != 0 &&(g_event.type == SDL_KEYDOWN || g_event.type == SDL_QUIT) )  is_menu = 0;

        }
        /////////////////menu /////////////////////////////////////////

        SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen,NULL);
        game_map.DrawMap(g_screen);

        p_player.Move(g_event,g_screen);
        p_player.Shoot(g_screen,g_event,time[0],g_event.button.x,g_event.button.y);
        p_player.Render(g_screen);


        if( 1 )  ///// round1 /////
        {
            if(time[1] - 0 <= 300) {printText(g_screen,"Round 1",SCREEN_WIDTH/2 -100 ,150,font,textColor, 21, 45);}
            ThreatsControl(threats_list1,p_player,time[1]);
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
                                score+=10;
                                kill++;
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

                        vector<ThunderObject*> thungder_list = p_player.get_thunder_list();
                for(int i = 0; i < thungder_list.size(); i++)
                {
                    if(thungder_list[0] != NULL)
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

                                SDL_Rect b_rect = thungder_list[0]->get_dame_rect();
                              //  cout <<thungder_list[0]->get_dame_rect().x << endl;
                                bool bCol = CheckCollision(a_rect,b_rect);
                              //  cout << bCol << " "<<thungder_list[0]->frame_  << " ";

                                 if(bCol && thungder_list[0]->frame_ >= 31 /* FRAMEDELAY->THUNDEROBJECT*/)
                                {

                                   // p_player.RemoveArrow(i);
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
                        time[1]++;

        }


       if(time[0] >=500)  ///// round2 /////
        {
          //  p_player.x_pos_ = SCREEN_WIDTH/2;
          //  p_player.y_pos_ = SCREEN_HEIGHT/2;
            if(time[2] <= 300) {printText(g_screen,"Round 2",SCREEN_WIDTH/2 -100 ,150,font,textColor, 21, 45);}
                ThreatsControl(threats_list2,p_player,time[2]);
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


                vector<ThunderObject*> thungder_list = p_player.get_thunder_list();
                for(int i = 0; i < thungder_list.size(); i++)
                {
                    if(thungder_list[0] != NULL)
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

                                SDL_Rect b_rect = thungder_list[0]->get_dame_rect();
                              //  cout <<thungder_list[0]->get_dame_rect().x << endl;
                                bool bCol = CheckCollision(a_rect,b_rect);
                              //  cout << bCol << " "<<thungder_list[0]->frame_  << " ";

                                 if(bCol && thungder_list[0]->frame_ >= 31 /* FRAMEDELAY->THUNDEROBJECT*/)
                                {

                                   // p_player.RemoveArrow(i);
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


                        time[2]++;
        }


           if(Check_round(threats_list1,threats_list2) == 3)   is_quit = 1;

        time[0]++;
        SDL_RenderPresent(g_screen);

        SDL_Delay(10);

    }

    close();

    return 0;
}
