#include <functional>
#include <array>

#include "../../TinyEngine.h"

//Data
constexpr auto size = 100;
constexpr auto wind_width = 1200;
constexpr auto wind_height = 800;
std::array<bool, wind_width*wind_height> data = {false};
bool paused = true;

//Setup of Data
void setup(){
  //Generate Random Data!
  srand(time(nullptr));
  for(int i = 0; i < wind_width*wind_height; i++){
    data[i] = (rand()%2 == 0)?1:0;
  }
};

// Event Handler
std::function<void()> eventHandler = [](){

  // Pause and Unpause
  if(!Tiny::event.press.empty())
    if(Tiny::event.press.back() == SDLK_p)
      paused = !paused;

};
