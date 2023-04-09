
#include "PlayerObject.h"
#include "arrow.h"

PlayerObject :: PlayerObject()
{
    time_ = 0;
    frame_ = 0;
    x_pos_ = SCREEN_WIDTH/2 - 100;
    y_pos_ = SCREEN_HEIGHT/2 + 100;
    x_val_ = 0;
    y_val_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = 1;
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
    if(status_ == 0){
        weapon.LoadImg("img//bow_r.png",des);
        LoadImg("img//player_r.png", des);
    }
    else if(status_ == 1){
        weapon.LoadImg("img//bow_l.png",des);
        LoadImg("img//player_l.png", des);
    }

    if( (input_type_.left_ == 1 || input_type_.right_ == 1) || (input_type_.down_ == 1 || input_type_.up_ ==1) )
    {
        frame_ ++;
    }
    else
    {
        frame_ = 0;
    }

    if( frame_ >= 8*FRAMEDELAY)
    {
        frame_ = 0;
    }

    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect * current_clip;

    if(status_ == 0)
         current_clip = &frame_clip_[frame_/FRAMEDELAY];
    else
         current_clip = &frame_clip_[(8*FRAMEDELAY-frame_)/FRAMEDELAY];

    SDL_Rect renderQuad = {rect_.x, rect_.y , width_frame_*room, height_frame_*room};

    SDL_RenderCopy (des, p_object_, current_clip, &renderQuad);

    SDL_Rect renderQuad_bow = {rect_.x+width_frame_*room*0.33, rect_.y+height_frame_*room*0.63, width_frame_*room*0.55, height_frame_*room*0.4};
    SDL_RenderCopy (des, weapon.get_p_object(), NULL, &renderQuad_bow);

}

void PlayerObject :: Move(SDL_Event events, SDL_Renderer * screen)
{
    if(events.type == SDL_KEYDOWN)
    {
        if(events.key.keysym.sym == SDLK_RIGHT)
        {
            status_ = WALK_RIGHT;
            input_type_.right_ = 1;
            input_type_.left_ = 0;
        }
        if(events.key.keysym.sym == SDLK_LEFT)
        {
            status_ = WALK_LEFT;
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
            status_ = WALK_RIGHT;
            input_type_.right_ = 0;
        }
        if(events.key.keysym.sym == SDLK_LEFT)
        {
            status_ = WALK_LEFT;
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

    if(x_pos_ <= 0) x_pos_+= PLAYER_V;
    if(x_pos_ >= SCREEN_WIDTH - width_frame_ )  x_pos_ -= PLAYER_V;
    if(y_pos_ <= 0 + TILE_SIZE) y_pos_ += PLAYER_V;
    if(y_pos_ >= SCREEN_HEIGHT - TILE_SIZE - height_frame_) y_pos_ -= PLAYER_V;


}

void PlayerObject::Shoot(SDL_Renderer* des,SDL_Event events,int time)
{
    if(time-time_ >= 40){
    if(events.type == SDL_MOUSEBUTTONDOWN)
    {
        time_ = time;
        if( events.button.button == SDL_BUTTON_LEFT)
        {
            ArrowObject * p_arrow = new ArrowObject();

            if(status_ == WALK_LEFT)
            {
                p_arrow->set_arrow_dir(ArrowObject::DIR_LEFT);
                p_arrow->SetRect(this->rect_.x , rect_.y + height_frame_*0.5 );
                p_arrow->LoadImg("img//arrow1.png", des);
            }
            else if(status_ == WALK_RIGHT)
            {
                p_arrow->set_arrow_dir(ArrowObject::DIR_RIGHT);
                p_arrow->SetRect(this->rect_.x + width_frame_ - 10, rect_.y + height_frame_*0.5 );
                p_arrow->LoadImg("img//arrow.png", des);
            }

            p_arrow->SetRect(this->rect_.x + width_frame_ - 10, rect_.y + height_frame_*0.5 );
            p_arrow->set_x_val(arrow_v);
            p_arrow->set_is_move(1);

            p_arrow_list_.push_back(p_arrow);
        }
    }
    }

    for(int i=0; i < p_arrow_list_.size(); i++)
    {
        ArrowObject* p_arrow = p_arrow_list_.at(i);
        if(p_arrow != NULL)
        {
            if(p_arrow->get_is_move() == 1)
            {
                p_arrow->Move(SCREEN_WIDTH,SCREEN_HEIGHT);
                p_arrow->Render(des);
            }
            else
            {
                p_arrow_list_.erase(p_arrow_list_.begin() + i);
                if(p_arrow != NULL)
                {
                    delete p_arrow;
                    p_arrow = NULL;
                }
            }
        }
    }



}

void PlayerObject::RemoveArrow(const int & idx)
{
    int size_ = p_arrow_list_.size();
    if(size_ > 0 && idx <size_)
    {
        ArrowObject* p_arrow = p_arrow_list_.at(idx);
        p_arrow_list_.erase(p_arrow_list_.begin()+ idx);

        if(p_arrow)
        {
            delete p_arrow;
            p_arrow = NULL;
        }
    }
}

SDL_Rect PlayerObject::get_rect()
{
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = width_frame_;
    rect.h = height_frame_;

    return rect;

}
