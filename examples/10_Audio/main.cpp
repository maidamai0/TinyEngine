#include "../../TinyEngine.h"
#include "helpers/common.h"

int main( int argc, char* args[] ) {

	Tiny::audio.init();
	Tiny::audio.load({full_path("acoustic.wav").c_str()});
	Tiny::audio.play(full_path("acoustic.wav").c_str());

	Tiny::loop([&](){
		//This waits until the program quits...
	});

	Tiny::quit();

	return 0;
}
