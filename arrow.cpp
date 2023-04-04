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
    if(arrow_dir_ == DIR_RIGHT)
    {
        rect_.x +=x_val_;
        if(rect_.x > x_border)
        {
            is_move_ = 0;
        }
    }
    else if(arrow_dir_ == DIR_LEFT)
    {
        rect_.x -= x_val_;
        if(rect_.x < 0)
        {
            is_move_ = 0;
        }
    }


}

