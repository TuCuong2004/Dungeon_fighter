#ifndef THREATSOBJECT_H_INCLUDED
#define THREATSOBJECT_H_INCLUDED

#define Threats_frame 8


#include "CommonFunction.h"
#include "BaseObject.h"

class ThreatsObject : public BaseObject
{
public:
    ThreatsObject();
    ~ThreatsObject();

    void set_x_val(const float &xVal) {x_val_ = xVal;}
    void set_y_val(const float &yVal) {y_val_ = yVal;}

    void set_x_pos(const float &xPos) {x_pos_ = xPos;}
    void set_y_pos(const float &yPos) {y_pos_ = yPos;}

    float get_x_pos() const {return x_pos_;}
    float get_y_pos() const {return y_pos_;}

    void SetMapxy(const int &mp_x, const int &mp_y) {map_x_ = mp_x; map_y_ = mp_y;}

    void Set_clip();

    bool LoadImage(std::string path, SDL_Renderer* screen);

    void Render(SDL_Renderer* des);

    int get_width_frame() const {return width_frame_;}
    int get_height_frame() const {return height_frame_;}

    int Move(float x, float y,int time);

    void DoPlayer(const Map& gMap);
    void CheckToMap(const Map& gMap);

    float get_x_pos()  {return x_pos_;}
    float get_y_pos()  {return y_pos_;}

    void Set_hp(int hp) {hp_ = hp;}
    void get_damage()   {hp_--;}
    void set_hp_v();
    void set_v(int v) {THREATS_V = v;}
    void set_type(string type)    {type_ = type;}
    string get_type() {return type_;}
    int get_hp() {return hp_;}

private:
    string type_="1";
    double THREATS_V = 1;
    int hp_;
    int map_x_;
    int map_y_;
    float x_pos_;
    float y_pos_;
    float x_val_;
    float y_val_;
    SDL_Rect frame_clip_[Threats_frame];
    int width_frame_;
    int height_frame_;
    int frame_;

};

#endif // THREATSOBJECT_H_INCLUDED
