#include "Thunder.h"

ThunderObject :: ThunderObject()
{
    rect_.x= 50;
    rect_.y= 50;
    dame_frame = 8;
    width_frame_ = 0;
    height_frame_ = 0;
}


bool ThunderObject :: LoadImg (string path,SDL_Renderer * screen)
{
    bool ret = BaseObject :: LoadImg(path,screen);
    if (ret == 1)
    {
        width_frame_ = rect_.w/7;
        height_frame_ = rect_.h;
    }

    return ret;

  /*  are_dame.x = rect_.x;
    are_dame.y = rect_.y+height_frame_*7/8; */
    are_dame.w = 100;
    are_dame.h = 100;
}

void ThunderObject :: Set_clip()
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

     /*   frame_clip_[7].x = 7*width_frame_;
        frame_clip_[7].y = 0;
        frame_clip_[7].w = width_frame_;
        frame_clip_[7].h = height_frame_;

        frame_clip_[8].x = 8*width_frame_;
        frame_clip_[8].y = 0;
        frame_clip_[8].w = width_frame_;
        frame_clip_[8].h = height_frame_; */
    }
}

void ThunderObject :: Render(SDL_Renderer *des)
{

    frame_++;

    SDL_Rect * current_clip = &frame_clip_[frame_/FRAMEDELAY];

    SDL_Rect renderQuad = {rect_.x, rect_.y , width_frame_*zoom, height_frame_*zoom};
    SDL_RenderCopy (des, p_object_, current_clip, &renderQuad);

  /*  SDL_SetRenderDrawColor(des, 200, 0, 0, 255);
    SDL_RenderFillRect(des, &are_dame); */
   // cout << frame_;
}



