#ifndef PLAYEROBJECT_H_INCLUDED
#define PLAYEROBJECT_H_INCLUDED

#include "CommonFunction.h"
#include "BaseObject.h"
#define PLAYER_V 10

class PlayerObject : public BaseObject
{
public:
    PlayerObject();
    ~PlayerObject();


    bool LoadImg(string path,SDL_Renderer * screen);
    void Render(SDL_Renderer * des);
    void Move(SDL_Event events, SDL_Renderer * screen);
    void Set_clips();

private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[9];
    Input input_type_;
    int frame_;
    int status_;
};



#endif // PLAYEROBJECT_H_INCLUDED
