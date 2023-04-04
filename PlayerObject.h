#ifndef PLAYEROBJECT_H_INCLUDED
#define PLAYEROBJECT_H_INCLUDED

#include "arrow.h"
#include <vector>
#include "CommonFunction.h"
#include "BaseObject.h"
#define PLAYER_V 5

class PlayerObject : public BaseObject
{
public:
    PlayerObject();
    ~PlayerObject();

    enum Walk
    {
        WALK_LEFT = 1,
        WALK_RIGHT = 0,
    };

    float x_pos_;
    float y_pos_;


    bool LoadImg(string path,SDL_Renderer * screen);
    void Render(SDL_Renderer * des);
    void Move(SDL_Event events, SDL_Renderer * screen);
    void Set_clips();
    int status_;

    void Shoot(SDL_Renderer* des);

    void set_arrow_list(std::vector<ArrowObject*> arrow_list)
    {
        p_arrow_list_ = arrow_list;
    }

    vector <ArrowObject*> get_arrow_list() const {return p_arrow_list_;}
    void RemoveArrow(const int & idx);

    float get_x_pos() const {return x_pos_;}
    float get_y_pos() const {return y_pos_;}

private:

    vector <ArrowObject*> p_arrow_list_;

    float x_val_;
    float y_val_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[9];
    Input input_type_;
    int frame_;
};



#endif // PLAYEROBJECT_H_INCLUDED
