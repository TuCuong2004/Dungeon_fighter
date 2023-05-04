#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "CommonFunction.h"
void printText(SDL_Renderer* renderer,string text,int x, int y,TTF_Font* font,SDL_Color textColor, float w, float h);
void run_menu(SDL_Renderer* renderer,TTF_Font* font,SDL_Color textColor);
void draw_menu(SDL_Renderer* renderer,TTF_Font* font,SDL_Color textColor);
//void printText(SDL_Renderer* renderer,string text,int x, int y);

#endif // MENU_H_INCLUDED
