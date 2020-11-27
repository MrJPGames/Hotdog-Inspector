#include "Game.hpp"
#include "Animation.hpp"

extern int gWinWidth;
extern int gWinHeight;

Game::Game(RenderWindow* p_window)
:
window(p_window),
world(&controls)
{
	//disable the nasty looking cursor to make way for ours
	SDL_ShowCursor(SDL_DISABLE);

	loadTextures();
	loadWorld();

}

Game::~Game()
{

	// Destroys all textures that haven't been destroyed when we quit the game
	for (std::map<std::string, SDL_Texture*>::iterator i = textures.begin(); i != textures.end(); ++i)
	{
		SDL_DestroyTexture(i->second);
		std::cout << "Destroyed texture " << i->first << std::endl;
	}
}

std::map<std::string, SDL_Texture*>& Game::getTextures()
{
    return textures;
}

void Game::loadTextures()
{
	// Load our textures, and give each one a name

	SDL_Texture* t0 = window->loadTexture("romfs:/floor_0.png");
	textures.insert(std::pair<std::string, SDL_Texture*>("Floor 0", t0));

	SDL_Texture* t1 = window->loadTexture("romfs:/cursor_0.png");
	textures.insert(std::pair<std::string, SDL_Texture*>("Cursor 0", t1));

	SDL_Texture* t2 = window->loadTexture("romfs:/conveyor_belt_0.png");
	textures.insert(std::pair<std::string, SDL_Texture*>("Conveyor 0", t2));

	SDL_Texture* t3 = window->loadTexture("romfs:/frame_0.png");
	textures.insert(std::pair<std::string, SDL_Texture*>("Frame 0", t3));

	SDL_Texture* t4 = window->loadTexture("romfs:/font.png");
	textures.insert(std::pair<std::string, SDL_Texture*>("Font 0", t4));

	SDL_Texture* t5 = window->loadTexture("romfs:/clickable/normal.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Hotdog 0", t5));

    SDL_Texture* t6 = window->loadTexture("romfs:/clickable/moldy.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Hotdog 1", t6));

    SDL_Texture* t7 = window->loadTexture("romfs:/clickable/finger.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Finger", t7));

    SDL_Texture* t8 = window->loadTexture("romfs:/trash_can.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Trash Can 0", t8));

    SDL_Texture* t9 = window->loadTexture("romfs:/UI/X.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Lives 0", t9));

    SDL_Texture* t10 = window->loadTexture("romfs:/crate_0.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Crate 0", t10));

    SDL_Texture* t11 = window->loadTexture("romfs:/clickable/radioactive.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Radioactive Hotdog", t11));

    SDL_Texture* t12 = window->loadTexture("romfs:/clickable/pig_foot.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Pig Foot", t12));

    SDL_Texture* t13 = window->loadTexture("romfs:/clickable/rotten.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Rotten 0", t13));

    SDL_Texture* t14 = window->loadTexture("romfs:/clickable/rat.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Rat 0", t14));


	SDL_Texture* t15 = window->loadTexture("romfs:/clickable/rat 2.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Rat 1", t15));


	SDL_Texture* t16 = window->loadTexture("romfs:/furnace_0.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Furnace 0", t16));

	SDL_Texture* t17 = window->loadTexture("romfs:/spash.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Splash 0", t17));


   	SDL_Texture* t18 = window->loadTexture("romfs:/title.png");
    textures.insert(std::pair<std::string, SDL_Texture*>("Menu 0", t18));

}



void Game::loadWorld()
{	

	world.createClickableData(textures);
	// create the world

	// The camera. First param is the position of cam, second is the view port of the camera
	world.createCamera(Vector2f(0, 0), Vector2f(gWinWidth, gWinHeight));

	// The controls need a ptr to the camera, so that we can calculate the
	// in game coordinates of the mouse
	controls.setCamera(&world.getCamera());
	world.createAudioManager();
	// The floor
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Floor";
		createInfo.tex = textures["Floor 0"];
		createInfo.alpha = 255;
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(1, 2);
		createInfo.origin = Vector2f(32, 32);
		createInfo.frameSize = Vector2i(64, 64);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;

		//createInfo.clickable = true;
		createInfo.clickable = false;
		createInfo.halfBounds = Vector2f(32.f, 32.f);
		world.createSprite(createInfo, 0);	
	
	}

	// Trash can
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Trash Can";
		createInfo.tex = textures["Trash Can 0"];
		createInfo.alpha = 255;
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(24, 22);
		createInfo.origin = Vector2f(12, 6);
		createInfo.frameSize = Vector2i(24, 43);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;

		//createInfo.clickable = true;
		createInfo.clickable = true;
		createInfo.halfBounds = Vector2f(12, 6);
		world.createSprite(createInfo, 1);	
	
	}

	//cursor
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Cursor";
		createInfo.tex = textures["Cursor 0"];
		createInfo.alpha = 255;
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(0, 0);
		createInfo.origin = Vector2f(2.5f, 1.5f);
		createInfo.frameSize = Vector2i(5, 5);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;

		// It's a clickable!
		createInfo.clickable = true;
		//createInfo.clickable = false;
		createInfo.halfBounds = Vector2f(0.5f, 0.5f);

		Cursor* c = world.createCursor(createInfo, 19);
		c->init();
		c->setControls(&controls, world.getAudioManager());
	}

	// The crate
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Crate";
		createInfo.tex = textures["Crate 0"];
		createInfo.alpha = 255;
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(-12, 17);
		createInfo.angle = 0.0f;
		createInfo.origin = Vector2f(14, 4);
		createInfo.frameSize = Vector2i(28, 21);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;

		// it animates
		createInfo.doesAnimate = true;
		createInfo.animationSet = loadAnimationFile("romfs:/crate_0.json");
		// it's a clickable
		//createInfo.clickable = true;
		createInfo.clickable = true;
		createInfo.halfBounds = Vector2f(11.f, 4.5f);

	    world.createCrate(createInfo, 1);
	}

	// The furnace
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Furnace";
		createInfo.tex = textures["Furnace 0"];
		createInfo.alpha = 255;
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(32, -7);
		createInfo.angle = 0.0f;
		createInfo.origin = Vector2f(7.5f, 13);
		createInfo.frameSize = Vector2i(15, 35);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;

		// it animates (well not yet but maybe eventually)
		createInfo.doesAnimate = true;
		createInfo.animationSet = loadAnimationFile("romfs:/furnace_0.json");
		// it's a clickable
		//createInfo.clickable = true;
		createInfo.clickable = true;
		createInfo.halfBounds = Vector2f(7.5f, 13.f);

	    world.createFurnace(createInfo, 7);
	}


	// The Conveyor
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Conveyor";
		createInfo.tex = textures["Conveyor 0"];
		createInfo.alpha = 255;
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(-7, -10);
		createInfo.angle = 0.0f;
		createInfo.origin = Vector2f(31, 12);
		createInfo.frameSize = Vector2i(62, 38);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;

		createInfo.doesAnimate = true;
		createInfo.animationSet = loadAnimationFile("romfs:/conveyor_belt_0.json");

		// it's a clickable
		//createInfo.clickable = true;
		createInfo.clickable = true;
		createInfo.halfBounds = Vector2f(31.f, 12.f);

	    world.createConveyor(createInfo, 0);
	}


	// UI Lives
	 {
	 	SpriteCreateInfo createInfo = {};
	 	createInfo.name = "Life Counter";
	 	createInfo.tex = textures["Lives 0"];
	 	createInfo.alpha = 255;
	 	createInfo.color = Color(255, 255, 255);
	 	createInfo.flip = SDL_FLIP_NONE;
	 	createInfo.pos = Vector2f(8, -29);
	 	createInfo.origin = Vector2f(0, 0);
	 	createInfo.frameSize = Vector2i(7, 7);
	 	createInfo.scale = Vector2f(1.0f, 1.0f);
	 	createInfo.depth = 0;
	 	createInfo.zoomModifier = 1.f;
	 	world.createLives(createInfo, 4, 10);	
	 }

	// Frame to clip off anything outside the 64x64 playpen
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Frame";
		createInfo.tex = textures["Frame 0"];
		createInfo.alpha = 255;
		createInfo.color = Color(0, 0, 0);
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(0, 0);
		createInfo.origin = Vector2f(114, 64);
		createInfo.frameSize = Vector2i(228, 128);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;
		world.createSprite(createInfo, 31);	

		world.createSprite(createInfo, 100);	
	}

	// Splash
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Splash";
		createInfo.tex = textures["Splash 0"];
		createInfo.alpha = 255;
		createInfo.color = Color(0, 0, 0);
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(0, 0);
		createInfo.origin = Vector2f(36, 36);
		createInfo.frameSize = Vector2i(72, 72);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;
		world.createSplash(createInfo, 300);	
	}

	// TTF_Font* font = TTF_OpenFont("romfs:/font.ttf", 4);
	// // Text 
	// {
	// 	SpriteCreateInfo createInfo = {};
	// 	createInfo.name = "Text";
	// 	createInfo.alpha = 255;
	// 	createInfo.color = Color(0, 0, 0);
	// 	createInfo.flip = SDL_FLIP_NONE;
	// 	createInfo.pos = Vector2f(0, 0);
	// 	createInfo.origin = Vector2f(36, 36);
	// 	createInfo.frameSize = Vector2i(72, 72);
	// 	createInfo.scale = Vector2f(1.0f, 1.0f);
	// 	createInfo.depth = 0;
	// 	createInfo.zoomModifier = 1.f;
	
	// 	SDL_Color color = {255, 255, 255};
	// 	world.createText(createInfo, "Round 1", font, color, 8);	
	// }


	// Menu
	{
		SpriteCreateInfo createInfo = {};
		createInfo.name = "Menu";
		createInfo.tex = textures["Menu 0"];
		createInfo.alpha = 255;
		createInfo.flip = SDL_FLIP_NONE;
		createInfo.pos = Vector2f(0, 0);
		createInfo.angle = 0;
		createInfo.origin = Vector2f(36, 36);
		createInfo.frameSize = Vector2i(72, 72);
		createInfo.scale = Vector2f(1.0f, 1.0f);
		createInfo.depth = 0;
		createInfo.zoomModifier = 1.f;

		createInfo.doesAnimate = true;
		createInfo.animationSet = loadAnimationFile("romfs:/title.json");

		world.createMenu(createInfo, 20);	
	}
}

// Should the game quit?
bool Game::shouldQuit()
{
	return quit;
}

bool Game::isUserExitReq(){
	return controls.isExitButtonClick();
}

// Main loop for the game
void Game::mainLoop(const float& p_dt)
{
	//while (SDL_PollEvent(&event)){
		// Update the state of the controls
		controls.update(&event);
	//}
	
	// Update the game based on the deltaTime(p_dt)
	world.update(p_dt, textures);
}