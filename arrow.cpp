#include "arrow.h"

ArrowObject :: ArrowObject()
{
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
}


ArrowObject :: ~ArrowObject()
{

}

void ArrowObject :: Move(const int& x_border, const int & y_border)
{
  /*  if(arrow_dir_ == DIR_RIGHT)
    {
        rect_.x +=x_val_;
        if(rect_.x > x_border)
        {
            is_move_ = 0;
            Free();
        }
    }
    else if(arrow_dir_ == DIR_LEFT)
    {
        rect_.x -= x_val_;
        if(rect_.x < 0)
        {
            is_move_ = 0;
            Free();
        }
    } */

    float d = sqrt((x_player - x_shoot)*(x_player - x_shoot) + (y_player - y_shoot)*(y_player - y_shoot));

    rect_.x+=arrow_v*(x_shoot - x_player)*1.00/d;
    rect_.y+=arrow_v*(y_shoot - y_player)*1.00/d;



    if(rect_.x>SCREEN_WIDTH||rect_.x<0||rect_.y>SCREEN_HEIGHT||rect_.y<0)
    {
        is_move_ = 0;
        Free();
    }
}

