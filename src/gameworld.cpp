#include <iostream>
#include <algorithm>

#include "Conveyor.hpp"
#include "GameWorld.hpp"
#include "Sprite.hpp"
#include "Camera.hpp"
#include "Particle.hpp"
#include "Cursor.hpp"
#include "Splash.hpp"
#include "Menu.hpp"

extern int gWinWidth;
extern int gWinHeight;



bool CollisionInfo::contains(Sprite* p_sprite)
{
	if (p_sprite == a)
		return true;
	if (p_sprite == b)
		return true;

	return false;
}

bool operator ==(CollisionInfo& p_a, CollisionInfo& p_b)
{
	size_t hashA = (size_t)p_a.a + (size_t)p_a.b;
	size_t hashB = (size_t)p_b.a + (size_t)p_b.b;

	if (hashA == hashB)
		return true;

	return false;
}

GameWorld::GameWorld(Controls* p_controls)
: 
levelAt(1),
levelDelta(0.0f),
menu(true),
splashTime(100.f),
splashCounter(0.0f),
splashScreen(true),
controls(p_controls),
collisionFrames(2),
timer(100.f),
dawgs(0)
{
	allCollisions.resize(0);


	levels[0] = 100.f;
	levels[1] = 90.f;
	levels[2] = 80.f;
	levels[3] = 70.f;
	levels[4] = 60.f;
	levels[5] = 50.f;
	levels[6] = 40.f;
	levels[7] = 30.f;
	levels[8] = 20.f;
	levels[9] = 10.f;
}

GameWorld::~GameWorld()
{
	// Delete any sprites that haven't been deleted
	for (std::multimap<int, Sprite*>::iterator i = allSprites.begin(); i != allSprites.end(); ++i)
	{
		Sprite* s = i->second;

		std::cout << s->getName() << std::endl;
		delete s;
	}
}

void GameWorld::createClickableData(std::map<std::string, SDL_Texture*> p_textures)
{

	//Add all possible clickable structs
	//HOTDOG CLEAN
	{
		SpriteCreateInfo createInfo = {};
        createInfo.name = "Good Hotdog";

        createInfo.tex = p_textures["Hotdog 0"];
        createInfo.alpha = 255;
        createInfo.flip = SDL_FLIP_NONE;
        createInfo.pos = Vector2f(-33, -11);
        createInfo.origin = Vector2f(6.f, 12.5f);
        createInfo.frameSize = Vector2i(12, 25);
        createInfo.scale = Vector2f(1.0f, 1.0f);
        createInfo.depth = 0;
        createInfo.zoomModifier = 1.f;

        //It's a clickable!
        createInfo.clickable = true;
        createInfo.interactsWithCursor = true;
        createInfo.halfBounds = Vector2f(2.5f, 6.5f);
        clickables.push_back(createInfo);
    }
    //HOTDOG MOLDY
	{
		SpriteCreateInfo createInfo = {};
        createInfo.name = "Bad Hotdog";

        createInfo.tex = p_textures["Hotdog 1"];
        createInfo.alpha = 255;
        createInfo.flip = SDL_FLIP_NONE;
        createInfo.pos = Vector2f(-33, -11);
        createInfo.origin = Vector2f(6.f, 12.5f);
        createInfo.frameSize = Vector2i(12, 25);
        createInfo.scale = Vector2f(1.0f, 1.0f);
        createInfo.depth = 0;
        createInfo.zoomModifier = 1.f;

        //It's a clickable!
        createInfo.clickable = true;
        createInfo.interactsWithCursor = true;
        createInfo.halfBounds = Vector2f(2.5f, 6.5f);
        clickables.push_back(createInfo);
    }

   	//HOTDOG FINGER
	{
		SpriteCreateInfo createInfo = {};
        createInfo.name = "Hotdog Finger";

        createInfo.tex = p_textures["Finger"];
        createInfo.alpha = 255;
        createInfo.flip = SDL_FLIP_NONE;
        createInfo.pos = Vector2f(-33, -11);
        createInfo.origin = Vector2f(5.f, 12.5f);
        createInfo.frameSize = Vector2i(12, 25);
        createInfo.scale = Vector2f(1.0f, 1.0f);
        createInfo.depth = 0;
        createInfo.zoomModifier = 1.f;

        //It's a clickable!
        createInfo.clickable = true;
        createInfo.interactsWithCursor = true;
        createInfo.halfBounds = Vector2f(2.5f, 8.5f);
        clickables.push_back(createInfo);
    }

   	//HOTDOG FINGER
	{
		SpriteCreateInfo createInfo = {};
        createInfo.name = "Radioactive";

        createInfo.tex = p_textures["Radioactive Hotdog"];
        createInfo.alpha = 255;
        createInfo.flip = SDL_FLIP_NONE;
        createInfo.pos = Vector2f(-33, -11);
        createInfo.origin = Vector2f(5.f, 12.5f);
        createInfo.frameSize = Vector2i(12, 25);
        createInfo.scale = Vector2f(1.0f, 1.0f);
        createInfo.depth = 0;
        createInfo.zoomModifier = 1.f;

        createInfo.doesAnimate = true;
        createInfo.animationSet = loadAnimationFile("romfs:/clickable/radioactive.json");

        //It's a clickable!
        createInfo.clickable = true;
        createInfo.interactsWithCursor = true;
        createInfo.halfBounds = Vector2f(2.5f, 8.5f);
        clickables.push_back(createInfo);
    }
   	//Pig Foot
	{
		SpriteCreateInfo createInfo = {};
        createInfo.name = "Pig foot";

        createInfo.tex = p_textures["Pig Foot"];
        createInfo.alpha = 255;
        createInfo.flip = SDL_FLIP_NONE;
        createInfo.pos = Vector2f(-33, -11);
        createInfo.origin = Vector2f(6.f, 12.5f);
        createInfo.frameSize = Vector2i(12, 25);
        createInfo.scale = Vector2f(1.0f, 1.0f);
        createInfo.depth = 0;
        createInfo.zoomModifier = 1.f;

        //It's a clickable!
        createInfo.clickable = true;
        createInfo.interactsWithCursor = true;
        createInfo.halfBounds = Vector2f(2.5f, 8.5f);
        clickables.push_back(createInfo);
    }
   	//Rotten
	{
		SpriteCreateInfo createInfo = {};
        createInfo.name = "Rotten";

        createInfo.tex = p_textures["Rotten 0"];
        createInfo.alpha = 255;
        createInfo.flip = SDL_FLIP_NONE;
        createInfo.pos = Vector2f(-33, -11);
        createInfo.origin = Vector2f(6.f, 12.5f);
        createInfo.frameSize = Vector2i(12, 25);
        createInfo.scale = Vector2f(1.0f, 1.0f);
        createInfo.depth = 0;
        createInfo.zoomModifier = 1.f;

        //It's a clickable!
        createInfo.clickable = true;
        createInfo.interactsWithCursor = true;
        createInfo.halfBounds = Vector2f(2.5f, 8.5f);
        clickables.push_back(createInfo);
    }



   	//Eating rat
	{
		SpriteCreateInfo createInfo = {};
        createInfo.name = "Rat 0";

        createInfo.tex = p_textures["Rat 0"];
        createInfo.alpha = 255;
        createInfo.flip = SDL_FLIP_NONE;
        createInfo.pos = Vector2f(-33, -12);
        createInfo.origin = Vector2f(7.5f, 4.5f);
        createInfo.frameSize = Vector2i(15, 9);
        createInfo.scale = Vector2f(1.0f, 1.0f);
        createInfo.depth = 0;
        createInfo.zoomModifier = 1.f;

        createInfo.doesAnimate = true;
        createInfo.animationSet = loadAnimationFile("romfs:/clickable/rat.json");

        //It's a clickable!
        createInfo.clickable = true;
        createInfo.interactsWithCursor = true;
        createInfo.halfBounds = Vector2f(7.5f, 4.5f);
        clickables.push_back(createInfo);
    }

    //Rat 1
	{
		SpriteCreateInfo createInfo = {};
        createInfo.name = "Rat 1";

        createInfo.tex = p_textures["Rat 1"];
        createInfo.alpha = 255;
        createInfo.flip = SDL_FLIP_NONE;
        createInfo.pos = Vector2f(-33, -14);
        createInfo.origin = Vector2f(6.f, 8.f);
        createInfo.frameSize = Vector2i(12, 25);
        createInfo.scale = Vector2f(1.0f, 1.0f);
        createInfo.depth = 0;
        createInfo.zoomModifier = 1.f;

        //It's a clickable!
        createInfo.clickable = true;
        createInfo.interactsWithCursor = true;
        createInfo.halfBounds = Vector2f(2.5f, 6.5f);
        clickables.push_back(createInfo);
    }

}

// create the camera, pretty simple
Camera* GameWorld::createCamera(Vector2f p_pos, Vector2f p_size)
{
	CameraCreateInfo createInfo = {};
	createInfo.pos = p_pos;
	createInfo.size = p_size;
	createInfo.zoom = 8;
	createInfo.lag = 0.08f;
	camera = Camera(createInfo);
	return &camera;
}

// create audio manager
AudioManager* GameWorld::createAudioManager()
{
	audioManager = AudioManager();
	audioManager.play("track_0", -1);
	return &audioManager;
}

// p_drawOrder is the drawing heiarchy
Crate* GameWorld::createCrate(SpriteCreateInfo& p_info, int p_drawOrder)
{
	Crate* c = new Crate(p_info);
	crates.push_back(c);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, c));

	return c;
}

// p_drawOrder is the drawing heiarchy
Furnace* GameWorld::createFurnace(SpriteCreateInfo& p_info, int p_drawOrder)
{
	Furnace* c = new Furnace(p_info);
	furnaces.push_back(c);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, c));

	return c;
}


// p_drawOrder is the drawing heiarchy
Conveyor* GameWorld::createConveyor(SpriteCreateInfo& p_info, int p_drawOrder)
{
	Conveyor* c = new Conveyor(p_info);
	conveyors.push_back(c);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, c));

	return c;
}


Sprite* GameWorld::createSprite(SpriteCreateInfo& p_info, int p_drawOrder)
{
	
	Sprite* s = new Sprite(p_info);
	sprites.push_back(s);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, s));

	return s;
}

Text* GameWorld::createText(SpriteCreateInfo& p_info, const char* p_string, TTF_Font* p_font, SDL_Color p_color, int p_drawOrder)
{
	
	Text* s = new Text(p_info, p_string, p_font, p_color);
	texts.push_back(s);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, s));

	return s;
}

// Create a particle on the heap
Particle* GameWorld::createParticle(SpriteCreateInfo& p_info, int p_drawOrder)
{
	Particle* p = new Particle(p_info);

	particles.push_back(p);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, particles.back()));

	return p;
}

Cursor* GameWorld::createCursor(SpriteCreateInfo& p_info, int p_drawOrder)
{
	cursor = new Cursor(p_info);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, cursor));

	return cursor;
}

Splash* GameWorld::createSplash(SpriteCreateInfo& p_info, int p_drawOrder)
{
	
	Splash* s = new Splash(p_info);
	splashScreens.push_back(s);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, s));

	return s;
}


Menu* GameWorld::createMenu(SpriteCreateInfo& p_info, int p_drawOrder)
{
	
	Menu* m = new Menu(p_info);
	menus.push_back(m);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, m));

	return m;
}

Lives* GameWorld::createLives(SpriteCreateInfo& p_info, Uint8 p_lives, int p_drawOrder)
{



	Lives c(p_info, p_lives);


	lifeCounters.push_back(c);

	for (int i = 0; i < c.getLives(); i++)
	{
		allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, &lifeCounters.back().getSprite(i)));
	}

	return &lifeCounters.back();

}

Hotdog* GameWorld::createHotdog(SpriteCreateInfo& p_info, Lives& p_lifeCounter, AudioManager& p_audioManager, int p_drawOrder)
{
	Hotdog* h = new Hotdog(p_info, &p_lifeCounter, &p_audioManager);
	hotdogs.push_back(h);

	allSprites.insert(std::pair<int, Sprite*>(p_drawOrder, h));

	return h;
}

void GameWorld::deleteSprite(Sprite* sprite)
{
	// Check if it's in the cursor slot
	if (sprite == cursor->getSlot())
		cursor->setSlot(nullptr);

	// If this sprite is part of a CollisionInfo, delete that collision info
	
	// Dum dum move right here. Create a vector of all of the collisions that must be removed
	std::vector<std::list<CollisionInfo>::iterator> badCollisions = {};

	for (std::list<CollisionInfo>::iterator c = allCollisions.begin(); c != allCollisions.end(); c++)
	{
		if (c->contains(sprite))
		{
			badCollisions.push_back(c);
		}
		
	}

	// And now delete all of the bad collisions
	for (auto& c : badCollisions)
		allCollisions.erase(c);


	// Reinterpret the pointer to test what it is

	// Determine what data type this is
	Cursor* cursorTest = dynamic_cast<Cursor*>(sprite);

	if (cursorTest)
	{

		//std::cout << "Deleted " << cursorTest->getName() << std::endl;
		delete cursor;

		// Has been deleted, so carry on to the next sprite
		return;
	}

	Crate* crateTest = dynamic_cast<Crate*>(sprite);

	if (crateTest)
	{	
		//std::cout << "Deleted " << conveyorTest->getName() << std::endl;

		// Find the this conveyor from the conveyors, and remove it from the list
		std::vector<Crate*>::iterator crateIndex = std::find(crates.begin(), crates.end(), crateTest);
		crates.erase(crateIndex);

		delete crateTest;
		return;
	}


	Conveyor* conveyorTest = dynamic_cast<Conveyor*>(sprite);

	if (conveyorTest)
	{	
		//std::cout << "Deleted " << conveyorTest->getName() << std::endl;

		// Find the this conveyor from the conveyors, and remove it from the list
		std::vector<Conveyor*>::iterator conveyorIndex = std::find(conveyors.begin(), conveyors.end(), conveyorTest);
		conveyors.erase(conveyorIndex);

		delete conveyorTest;
		return;
	}

	Splash* splashTest = dynamic_cast<Splash*>(sprite);

	if (splashTest)
	{	
		//std::cout << "Deleted " << conveyorTest->getName() << std::endl;

		// Find the this conveyor from the conveyors, and remove it from the list
		std::vector<Splash*>::iterator splashIndex = std::find(splashScreens.begin(), splashScreens.end(), splashTest);
		splashScreens.erase(splashIndex);

		delete splashTest;
		splashScreen = false;
		return;
	}

	Menu* menuTest = dynamic_cast<Menu*>(sprite);

	if (menuTest)
	{	
		//std::cout << "Deleted " << conveyorTest->getName() << std::endl;

		// Find the this conveyor from the conveyors, and remove it from the list
		std::vector<Menu*>::iterator menuIndex = std::find(menus.begin(), menus.end(), menuTest);
		menus.erase(menuIndex);

		delete menuTest;
		menu = false;
		return;
	}

	Hotdog* hotdogTest = dynamic_cast<Hotdog*>(sprite);

	if (hotdogTest)
	{	
		//std::cout << "Deleted " << hotdogTest->getName() << std::endl;

		// Find the this conveyor from the conveyors, and remove it from the list
		std::vector<Hotdog*>::iterator hotdogIndex = std::find(hotdogs.begin(), hotdogs.end(), hotdogTest);
		hotdogs.erase(hotdogIndex);

		delete hotdogTest;
		return;
	}

	Particle* particleTest = dynamic_cast<Particle*>(sprite);

	if (particleTest)
	{	

		//std::cout << "Deleted " << particleTest->getName() << std::endl;
		// Find the this conveyor from the conveyors, and remove it from the list
		std::vector<Particle*>::iterator particleIndex = std::find(particles.begin(), particles.end(), particleTest);

		particles.erase(particleIndex);


		delete particleTest;
		return;
	}

	Sprite* spriteTest = dynamic_cast<Sprite*>(sprite);

	if (spriteTest)
	{	
		//std::cout << "Deleted " << spriteTest->getName() << std::endl;

		// Find the this conveyor from the conveyors, and remove it from the list
		std::vector<Sprite*>::iterator index = std::find(sprites.begin(), sprites.end(), spriteTest);
		sprites.erase(index);


		delete spriteTest;

		return;
	}
}

const std::multimap<int, Sprite*>& GameWorld::getAllSprites()
{
	return allSprites;
}

const Camera& GameWorld::getCamera()
{
	return camera;
}

// Method to determine if two clickables are colliding
bool GameWorld::SpriteVsSprite(Sprite* p_a, Sprite* p_b)
{

	Vector2f delta = p_b->getPos() - p_a->getPos();
	Vector2f totalSize = p_b->getHalfBounds() + p_a->getHalfBounds();

	if (abs(delta.x) < totalSize.x &&
		abs(delta.y) < totalSize.y)
	{	

		return true;
	}

	return false;
}

void GameWorld::collisionTest()
{

	std::multimap<int, Sprite*>::iterator first = allSprites.begin();
	std::multimap<int, Sprite*>::iterator last = allSprites.end();

	for (auto a = first; a != last; ++a)
	{
		for (auto b = std::next(a, 1); b != last; ++b)
		{	
			Sprite* x = a->second;
			Sprite* y = b->second;
			if (&x == &y)
			{
				continue;
			}

			if (x->isClickable() != true)
			{
				continue;
			}

			if (y->isClickable() != true)
			{
				continue;
			}

			if (SpriteVsSprite(x, y))
			{
				CollisionInfo collision = {x, y};

				collision.freshCollision = true;
				collision.framesLeft = collisionFrames;

				bool duplicate = false;
				for (CollisionInfo& otherCollision : allCollisions)
				{
					if (collision == otherCollision)
					{
						duplicate = true;
						otherCollision.freshCollision = false;
						otherCollision.framesLeft = collisionFrames;

					}
				}
				if (!duplicate) 
				{
					allCollisions.push_back(collision);
				}


				resolveCollision(x, y);
			}
		}
	}	
	


}

void GameWorld::resolveCollision(Sprite* p_a, Sprite* p_b)
{	
	// Vector2f posA = p_a->getPos();
	// Vector2f posB = p_b->getPos();

	// Vector2f delta = posB - posA;

	// float deltaLength = delta.length();
	// Vector2f normal = normalise(delta);

	// Vector2f correction = normal * deltaLength;

	p_a->duringCollision(p_b);
	p_b->duringCollision(p_a);
	if (controls->isLeftClick())
	{
		// Check if p_a is a Cursor
		// Turn the Sprite ptr into a Cursor ptr
		Cursor* cursorTest = dynamic_cast<Cursor*>(p_a);

		// Check to make sure the the Sprite ptr converted back to a Cursor ptr
		if(cursorTest)
		{
			// If the cursor slot isn't full, set it to be this slot
			if (!cursorTest->isSlotFull())
			{
				if (p_b->isInteractsWithCursor())
					cursorTest->setSlot(p_b);
			}
		}

		// Check if p_a is a Cursor
		cursorTest = dynamic_cast<Cursor*>(p_b);

		// Check to make sure the the Sprite ptr converted back to a Cursor ptr
		if (cursorTest)
		{	
			// If the cursor slot isn't full, set it to be this slot
			if (!cursorTest->isSlotFull())
				if (p_a->isInteractsWithCursor())
					cursorTest->setSlot(p_a);
		}

		
	}
}
void GameWorld::updateCollisions()
{	

	// Iterate through a list of all collisions
	for (std::list<CollisionInfo>::iterator i = allCollisions.begin(); i != allCollisions.end(); )
	{
		// If the collision just happened, call the onCollisionBegin methods for the sprites
		if ((*i).freshCollision == true)
		{
			i->a->onCollisionBegin(i->b);
			i->b->onCollisionBegin(i->a);
		}

		// Reduce the frames left that the collision will be active for
		(*i).framesLeft = (*i).framesLeft - 1;

		// If there are no more collision frames left,
		// remove the collision from the list and call the onCollisionEnd method for the sprites
		if ((*i).framesLeft < 0)
		{
			i->a->onCollisionEnd(i->b);
			i->b->onCollisionEnd(i->a);

			i = allCollisions.erase(i);
		}

		++i;

	}
}

void GameWorld::update(const double& dt, std::map<std::string, SDL_Texture*> p_textures)
{
	camera.updatePrev();
	camera.update(Vector2f(0.0f, 0.0f));
	if (splashScreen)
	{

		for (std::multimap<int, Sprite*>::iterator i = allSprites.begin(); i != allSprites.end(); ++i)
		{
			Sprite* sprite = i->second;

			if (sprite->shouldDelete())
			{
				deleteSprite(sprite);
				allSprites.erase(i);
				continue;
			}
			if (sprite->getName()  == "Splash")
			{	
				sprite->updatePrev();
				sprite->update(dt);
			}
			//sprite->clamp();
		}

	}

	if (!splashScreen && menu)
	{
		

		for (std::multimap<int, Sprite*>::iterator i = allSprites.begin(); i != allSprites.end(); ++i)
		{
			Sprite* sprite = i->second;

			if (controls->isLeftClick() && sprite->getName()  == "Menu")
			{
				sprite->mustDelete(true);
			}

			if (sprite->shouldDelete())
			{
				deleteSprite(sprite);
				allSprites.erase(i);
				continue;
			}
			if (sprite->getName()  == "Menu")
			{	
				sprite->updatePrev();
				sprite->update(dt);
			}
			//sprite->clamp();
		}
	}
	if (!splashScreen && !menu)
	{
			// Iterate through all of the sprites and update them
		// NOTE: Should have an Entity class and then only update Entities
		for (std::multimap<int, Sprite*>::iterator i = allSprites.begin(); i != allSprites.end(); ++i)
		{
			Sprite* sprite = i->second;

			if (sprite->shouldDelete())
			{
				deleteSprite(sprite);
				allSprites.erase(i);
				continue;
			}

			sprite->updatePrev();
			sprite->update(dt);
			//sprite->clamp();
		}
		//Check for collisions
		collisionTest();
		
		// Delete old collisions
		updateCollisions();	

		levelDelta += 0.1f;

		if (levelDelta > 100 && levelAt < 9)
		{
			levelAt++;
			levelDelta = 0.0f;
		}
		timer+= 0.3f;
		if (timer > levels[levelAt])
		{
	    	timer = 0.0f;
	    	{
	    		audioManager.play("spawn", 0);
	        	createHotdog(clickables.at(rand() % 8), lifeCounters.front(), audioManager, 9);
	        	dawgs++;
	   
	    	}

		}
	}
}
