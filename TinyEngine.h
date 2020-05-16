#include <functional>
using Handle = std::function<void()>;
#include <initializer_list>
using slist = std::initializer_list<std::string>;

//Interface Dependencies (DearImGUI)
#include "include/imgui/imgui.h"
#include "include/imgui/imgui_impl_sdl.h"
#include "include/imgui/imgui_impl_opengl3.h"

//Drawing Dependencies
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

//File IO
#include <sstream>
#include <iostream>
#include <fstream>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

//Network
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <chrono>
#include <thread>

//Helpers
#include "include/helpers/input.h"
#include "include/helpers/log.h"
#include "include/helpers/parse.h"
#include "include/helpers/helper.h"
#include "include/helpers/ease.h"
#include "include/helpers/color.h"
#include "include/helpers/image.h"
#include "include/helpers/timer.h"

//Utility Classes for the Engine
#include "include/utility/texture.cpp"
#include "include/utility/shader.cpp"
#include "include/utility/sprite.cpp"
#include "include/utility/particle.cpp"
#include "include/utility/billboard.cpp"
#include "include/utility/model.cpp"

//Requires Models
#include "include/helpers/object.h"

//Utility Classes for Network
#include "include/network/buffer.cpp"
#include "include/network/socket.cpp"

#include "include/net.cpp"
#include "include/view.cpp"
#include "include/event.cpp"
#include "include/audio.cpp"

/* TINY ENGINE */

namespace Tiny {

//Main Engine Elements
static View view;       //Window and Interface
static Event event;     //Event Handler
static Audio audio;     //Audio Processor
static Net net;         //Network Handler

bool windowmode = false;

bool window(std::string windowName, int width, int height){
  windowmode = true;

  //Initialize SDL Core
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
    printf( "SDL could not initialize! Error: %s\n", SDL_GetError() );
    return false;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  //Initialize SDL_Image
  if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ){
    printf( "SDL_Image could not initialize! Error: %s\n", IMG_GetError() );
    return false;
  }

  //Initialize SDL_TTF
  TTF_Init();

  //Initialize the View
  if(!view.init(windowName, width, height)){
    std::cout<<"Failed to launch visual interface."<<std::endl;
    return false;
  }

  if(!audio.init()){
    std::cout<<"Failed to launch audio interface."<<std::endl;
		return false;
	}
  return true;
}

void quit(){
  if(windowmode){
    view.cleanup();
    audio.cleanup();
    TTF_Quit();
    SDL_Quit();
  }
  if(net.open)
    net.close();
};

template<typename F, typename... Args>
void loop(F function, Args&&... args){
  if(windowmode)
    while(!event.quit){
      event.input();        //Handle Input
      event.handle(view);

      if(net.open)
        net.handle();        //Handle Network Messages

      audio.process();      //Audio Processor

      function(args...);    //User-defined Game Loop

      view.render();        //Render View

    }
  else{
    while(net.open){
      net.handle();        //Handle Network Messages
    }
  }
};

//End of Namespace
};
