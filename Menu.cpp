#include<bits/stdc++.h>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Menu.h"
#include "game_map.h"
using namespace std;
SDL_Texture* bg=NULL;
SDL_Texture* start=NULL;
SDL_Texture* quit=NULL;
SDL_Rect button1,button2;
string text= "START";
string text2= "QUIT";
string text3= "Dungeon fighter";
void printText(SDL_Renderer* renderer,string text,int x, int y,TTF_Font* font,SDL_Color textColor)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(),textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = 21*text.size();
    dest.h = 45;
    SDL_RenderCopy(renderer, texture, NULL, &dest);
    SDL_DestroyTexture(texture);
 	SDL_FreeSurface(surface);
}
void draw_menu(SDL_Renderer* renderer,TTF_Font* font,SDL_Color textColor)
{
    button1 ={100,350,262,73};
    button2 ={140,500,180,73};
  //  bg=IMG_LoadTexture(renderer,"map//5.png");
   /* start=IMG_LoadTexture(renderer,"map/2.png");
    quit=IMG_LoadTexture(renderer,"map/2.png");*/
    SDL_RenderCopy(renderer,bg,NULL,NULL);
    SDL_RenderCopy(renderer,start,NULL,&button1);
    SDL_RenderCopy(renderer,quit,NULL,&button2);
    printText(renderer,text3,SCREEN_WIDTH/2-21*text3.size()/2 ,150,font,textColor);
    printText(renderer,text,SCREEN_WIDTH/2-21*text.size()/2 ,250,font,textColor);
    printText(renderer,text2,SCREEN_WIDTH/2-21*text2.size()/2 ,350,font,textColor);

}
void run_menu(SDL_Renderer* renderer,TTF_Font* font,SDL_Color textColor)
{

    int mouseX, mouseY;
    SDL_Event e;
    while(1)
    {
        SDL_PollEvent(&e);
        draw_menu(renderer,font,textColor);
        if(e.type == SDL_MOUSEBUTTONDOWN&&mouseX>=100&&mouseX<=362&&mouseY>=350&&mouseY<=423)
        {
            break;
        }
        if(e.type==SDL_QUIT||e.type == SDL_MOUSEBUTTONDOWN&&mouseX>=140&&mouseX<=320&&mouseY>=500&&mouseY<=573)
            exit(0);
        if(e.type == SDL_MOUSEMOTION)
        {
            mouseX = e.button.x;
            mouseY = e.button.y;
        }

        GameMap game_map0;
        game_map0.LoadMap("map/map0.o");
        game_map0.LoadTiles(g_screen);
        SDL_RenderPresent(g_screen);
    }
}
