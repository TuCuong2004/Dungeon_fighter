#ifndef THUNDER_H_INCLUDED
#define THUNDER_H_INCLUDED


#include "CommonFunction.h"
#include "BaseObject.h"
#define FRAMEDELAY_ 5



class ThunderObject : public BaseObject
{
public:
    void Render(SDL_Renderer* des);
    void Set_clip();
    SDL_Rect get_dame_rect() {return are_dame;}
    void set_rect(float a, float b) {rect_.x = a-50; rect_.y = b-height_frame_-50;are_dame.x= a-50; are_dame.y=b-50;}
    bool LoadImg(string path,SDL_Renderer * screen);
    int get_frame() {return frame_;}
    ThunderObject();
    int  frame_ = 0;
    //void set_dame_rect(float a, float b)    {are_dame.x= a; are_dame.y=b}

private:
    SDL_Rect are_dame{100,100,100,100};
    SDL_Rect frame_clip_[7];
    int dame_frame;
    int width_frame_;
    int height_frame_;
};

#endif // THUNDER_H_INCLUDED
