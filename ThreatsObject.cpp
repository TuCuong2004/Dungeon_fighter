#include "ThreatsObject.h"

ThreatsObject::ThreatsObject()
{
    width_frame_ = 0;
    height_frame_ = 0;
    x_val_ = 0.0;
    y_val_ = 0.0;
    x_pos_ = 50;
    y_pos_ = 50;
    frame_ = 0;
}

ThreatsObject::~ThreatsObject()
{

}

bool ThreatsObject::LoadImage(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path,screen);
    if(ret)
    {
        width_frame_ = rect_.w/Threats_frame;
        height_frame_ = rect_.h;
    }
    return ret;
}

void ThreatsObject::Set_clip()
{

    if(width_frame_ > 0 && height_frame_ > 0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;

        frame_clip_[1].x = width_frame_;
        frame_clip_[1].y = 0;
        frame_clip_[1].w = width_frame_;
        frame_clip_[1].h = height_frame_;

        frame_clip_[2].x = 2*width_frame_;
        frame_clip_[2].y = 0;
        frame_clip_[2].w = width_frame_;
        frame_clip_[2].h = height_frame_;

        frame_clip_[3].x = 3*width_frame_;
        frame_clip_[3].y = 0;
        frame_clip_[3].w = width_frame_;
        frame_clip_[3].h = height_frame_;

        frame_clip_[4].x = 4*width_frame_;
        frame_clip_[4].y = 0;
        frame_clip_[4].w = width_frame_;
        frame_clip_[4].h = height_frame_;

        frame_clip_[5].x = 5*width_frame_;
        frame_clip_[5].y = 0;
        frame_clip_[5].w = width_frame_;
        frame_clip_[5].h = height_frame_;

        frame_clip_[6].x = 6*width_frame_;
        frame_clip_[6].y = 0;
        frame_clip_[6].w = width_frame_;
        frame_clip_[6].h = height_frame_;

        frame_clip_[7].x = 7*width_frame_;
        frame_clip_[7].y = 0;
        frame_clip_[7].w = width_frame_;
        frame_clip_[7].h = height_frame_;

     /*   frame_clip_[8].x = 8*width_frame_;
        frame_clip_[8].y = 0;
        frame_clip_[8].w = width_frame_;
        frame_clip_[8].h = height_frame_;*/
    }
}

void ThreatsObject::Render(SDL_Renderer* des)
{
    frame_++;

     if( frame_ >= 7)
    {
        frame_ = 0;
    }

    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect * current_clip = &frame_clip_[frame_];

    SDL_Rect renderQuad = {rect_.x, rect_.y , width_frame_, height_frame_};

    SDL_RenderCopy (des, p_object_, current_clip, &renderQuad);

}

 void ThreatsObject::Move(float x, float y)
 {
    if (x_pos_ > x){x_pos_-=THREATS_V;}
    if (x_pos_ < x){x_pos_+=THREATS_V;}
    if (y_pos_ > y){y_pos_-=THREATS_V;}
    if (y_pos_ < y){y_pos_+=THREATS_V;}
 }
