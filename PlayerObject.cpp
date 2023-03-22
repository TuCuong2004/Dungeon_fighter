
#include "PlayerObject.h"

PlayerObject :: PlayerObject()
{
    frame_ = 0;
    x_pos_ = 50;
    y_pos_ = 50;
    x_val_ = 0;
    y_val_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = -1;
    input_type_.left_ = 0;
    input_type_.right_ = 0;
    input_type_.down_ = 0;
    input_type_.up_ = 0;
}

PlayerObject :: ~PlayerObject()
{

}

bool PlayerObject :: LoadImg (string path,SDL_Renderer * screen)
{
    bool ret = BaseObject :: LoadImg(path,screen);

    if (ret == 1)
    {
        width_frame_ = rect_.w/9;
        height_frame_ = rect_.h;
    }

    return ret;
}

void PlayerObject :: Set_clips()
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

        frame_clip_[8].x = 8*width_frame_;
        frame_clip_[8].y = 0;
        frame_clip_[8].w = width_frame_;
        frame_clip_[8].h = height_frame_;
    }

}

void PlayerObject :: Render (SDL_Renderer * des)
{
    if(status_ == 0)
        LoadImg("img//player_r.png", des);
    else if(status_ == 1)
        LoadImg("img//player_l.png", des);

    if( (input_type_.left_ == 1 || input_type_.right_ == 1) || (input_type_.down_ == 1 || input_type_.up_ ==1))
    {
        frame_ ++;
    }
    else
    {
        frame_ = 0;
    }

    if( frame_ >= 8)
    {
        frame_ = 0;
    }

    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect * current_clip = &frame_clip_[frame_];

    SDL_Rect renderQuad = {rect_.x, rect_.y , width_frame_, height_frame_};

    SDL_RenderCopy (des, p_object_, current_clip, &renderQuad);
}

void PlayerObject :: Move(SDL_Event events, SDL_Renderer * screen)
{
    if(events.type == SDL_KEYDOWN)
    {
        if(events.key.keysym.sym == SDLK_RIGHT)
        {
            status_ = 0;
            input_type_.right_ = 1;
            input_type_.left_ = 0;
        }
        if(events.key.keysym.sym == SDLK_LEFT)
        {
            status_ = 1;
            input_type_.left_ = 1;
            input_type_.right_ = 0;
        }
        if(events.key.keysym.sym == SDLK_DOWN)
        {
            input_type_.down_ = 1;
        }
        if(events.key.keysym.sym == SDLK_UP)
        {
            input_type_.up_ = 1;
        }

    }
    else if (events.type == SDL_KEYUP)
    {
        if(events.key.keysym.sym == SDLK_RIGHT)
        {
            status_ = 0;
            input_type_.right_ = 0;
        }
        if(events.key.keysym.sym == SDLK_LEFT)
        {
            status_ = 0;
            input_type_.left_ = 0;
        }
        if(events.key.keysym.sym == SDLK_DOWN)
        {
            input_type_.down_ = 0;
        }
        if(events.key.keysym.sym == SDLK_UP)
        {
            input_type_.up_ = 0;
        }
    }


    if(input_type_.right_ == 1)
    {
        x_pos_ += PLAYER_V;
    }
    if(input_type_.left_ == 1)
    {
        x_pos_ -= PLAYER_V;
    }
    if( input_type_.down_ == 1)
    {
        y_pos_ += PLAYER_V;
    }
    if( input_type_.up_ == 1)
    {
        y_pos_ -= PLAYER_V;
    }


}

