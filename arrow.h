#ifndef ARROW_H_INCLUDED
#define ARROW_H_INCLUDED

#include "CommonFunction.h"
#include "BaseObject.h"

#define arrow_v 6

class ArrowObject : public BaseObject
{
public:
    ArrowObject();
    ~ArrowObject();

    enum ArrowDir
    {
        DIR_RIGHT =20,
        DIR_LEFT = 21,
    };

    void set_x_val(const int& xVal) {x_val_ = xVal;}
    void set_y_val (const int& yVal) {y_val_ = yVal;}
    int get_x_val() {return x_val_;}
    int get_y_val() {return y_val_;}

    void set_is_move(const bool & isMove) {is_move_ = isMove;}
    bool get_is_move() const {return is_move_;}

    void Move(const int& x_border, const int & y_border);

    void set_arrow_dir(const unsigned int & arrowdir){arrow_dir_ = arrowdir;}
    unsigned int get_arrow_dir() const{return arrow_dir_;}

private:
    int x_val_;
    int y_val_;
    bool is_move_;
    unsigned int arrow_dir_;

};

#endif // ARROW_H_INCLUDED
