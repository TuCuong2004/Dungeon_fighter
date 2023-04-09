#ifndef COMMONFUNCTION_H_INCLUDED
#define COMMONFUNCTION_H_INCLUDED

#include <iostream>
#include<bits/stdc++.h>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <fstream>

#define THREATS_ROUND_1 5
#define FRAMEDELAY 7

using namespace std;

static SDL_Window * g_window = NULL;
static SDL_Renderer * g_screen = NULL;
static SDL_Event  g_event;

// screen
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;
const int SCREEN_BPP = 32;

const int  COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 255;
const double room = 1.5;

#define TILE_SIZE 30


#define MAX_MAP_X 32
#define MAX_MAP_Y 18

typedef struct Input
{
  int left_;
  int right_;
  int up_;
  int down_;
};

 struct Map
{
  int max_x_;
  int max_y_;

  int tile[MAX_MAP_Y][MAX_MAP_X] = {0};
  string file_name_;

  int get_max_x () {return max_x_;}
  int get_max_y () {return max_y_;}

};

bool CheckCollision (const SDL_Rect& object1 , const SDL_Rect& objecct2);



#endif // COMMONFUNCTION_H_INCLUDED


