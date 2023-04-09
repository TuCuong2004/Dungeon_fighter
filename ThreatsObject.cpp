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

     if( frame_ >= 49)
    {
        frame_ = 0;
    }

    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect * current_clip = &frame_clip_[frame_/7];

    SDL_Rect renderQuad = {rect_.x, rect_.y , width_frame_*room, height_frame_*room};

    SDL_RenderCopy (des, p_object_, current_clip, &renderQuad);

}

int ThreatsObject::Move(float x, float y, int time)
 {
    int dem = 1;
    int status=0;
    if(time%2==0)
    {
        if (x_pos_ > x && dem == 1){
            x_pos_-=THREATS_V;
            status =1;
            dem--;
        }

        if (x_pos_ < x && dem == 1){
            x_pos_+=THREATS_V;
            status = 0;
            dem--;
        }


        if (y_pos_ > y && dem == 1){y_pos_-=THREATS_V; dem--;}
        if (y_pos_ < y && dem == 1){y_pos_+=THREATS_V; dem--;}
    }
    if(time%2==1)
    {
        if (y_pos_ > y && dem == 1){y_pos_-=THREATS_V; dem--;}
        if (y_pos_ < y && dem == 1){y_pos_+=THREATS_V; dem--;}

        if (x_pos_ > x ){
            status =1;
        if(dem == 1){
            x_pos_-=THREATS_V;
            dem--;
        }
        }

        if (x_pos_ < x){
            status = 0;
        if(dem == 1){
            dem--;
            x_pos_+=THREATS_V;
        }
        }
    }

    return status;
 }

void ThreatsObject::set_hp_v()
{
    if(type_ == "1")   {hp_ = 1; THREATS_V = 1;}
    if(type_ == "2")   {hp_ = 3; THREATS_V = 1;}
    if(type_ == "3")   {hp_ = 1; THREATS_V = 1.5;}
    if(type_ == "4")   {hp_ = 5; THREATS_V = 1.5;}
}
