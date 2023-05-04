#ifndef PLAYEROBJECT_H_INCLUDED
#define PLAYEROBJECT_H_INCLUDED

#include "arrow.h"
#include <vector>
#include "CommonFunction.h"
#include "BaseObject.h"
#include "Thunder.h"
#define PLAYER_V 3


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
    void run() { run_ = 1;}

    void Shoot(SDL_Renderer* des,SDL_Event events,int time,float x_shoot, float y_shoot);

    void set_arrow_list(std::vector<ArrowObject*> arrow_list)
    {
        p_arrow_list_ = arrow_list;
    }

    vector <ArrowObject*> get_arrow_list() const {return p_arrow_list_;}
    vector <ThunderObject*> get_thunder_list() const {return p_thunder_list_;}
    void RemoveArrow(const int & idx);
    void set_status( int a) {status_ = a;}
    void set_pos(int x, int y) {x_pos_ = x, y_pos_ = y;}

    float get_x_pos() const {return x_pos_;}
    float get_y_pos() const {return y_pos_;}
    SDL_Rect get_rect();

private:

    vector <ArrowObject*> p_arrow_list_;
    vector <ThunderObject*> p_thunder_list_;
    BaseObject weapon;

    int time_=-40;
    int time1_=-100;
    float x_val_;
    float y_val_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[8];
    Input input_type_;
    int frame_;
    int run_ ;
};



#endif // PLAYEROBJECT_H_INCLUDED
