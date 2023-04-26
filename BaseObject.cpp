
//#include "stdfix.h"
#include "BaseObject.h"

BaseObject::BaseObject()
{
    p_object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}

BaseObject::~BaseObject()
{


}

bool BaseObject::LoadImg(std::string path, SDL_Renderer * screen)
{
    SDL_Texture * new_texture = NULL;

    SDL_Surface * load_surface = IMG_Load(path.c_str());

    if(load_surface != NULL)
    {
      // SDL_SetColorKey(load_surface,SDL_TRUE, SDL_MapRGB(load_surface->format,COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);

        if(new_texture != NULL)
        {
            p_object_ = new_texture;
            if(p_object_ == NULL) cout << "loi load img" << endl;
            rect_.w = load_surface->w*zoom_m;
            rect_.h = load_surface->h*zoom_m;
        }

        SDL_FreeSurface(load_surface);

    }

  //  p_object_ = new_texture;

    if(p_object_ == NULL)
        std :: cout << "loi loadimg" << endl;


    // SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};  SDL_RenderCopy(screen, p_object_, NULL, &renderquad);

    // Render(screen,NULL);

    return p_object_ ;

}

void BaseObject::Render(SDL_Renderer * des, const SDL_Rect * clip )
{

    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(des, p_object_, clip, &renderquad);

}

void BaseObject::Free(){
    if(p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;
        rect_.h = 0;
        rect_.w = 0;
    }
}




