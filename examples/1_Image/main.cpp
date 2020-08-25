#include "../../TinyEngine.h"
#include "../../include/helpers/image.h"
#include "../../include/helpers/color.h"

#include "effects.h"
#include "helpers/common.h"

int main( int argc, char* args[] ) {

	Tiny::window("Shader Effects Example", 1200, 800);

	Tiny::event.handler = [](){ /* ... */ };

	Tiny::view.interface = interfaceFunc;

	Texture tex(image::load(full_path("canyon.png").c_str()));		//Load Texture with Image
	Square2D flat;														//Create Primitive Model
	Shader effect({full_path("shader/effect.vs").c_str(), full_path("shader/effect.fs").c_str()}, {"in_Quad", "in_Tex"});

	Tiny::view.pipeline = [&](){

		Tiny::view.target(color::black);				//Target Main Screen

		effect.use();														//Use Effect Shader
		effect.uniform("index", ind);						//Define Uniforms
		effect.uniform("res", res);
		effect.uniform("bits", bits);
		effect.texture("imageTexture", tex);		//Load Texture
		effect.uniform("model", flat.model);		//Add Model Matrix
		flat.render();													//Render Primitive

	};

	Tiny::loop([&](){
		/* Absolutely Nothing! */
	});

	Tiny::quit();

	return 0;
}
