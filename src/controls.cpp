#include <SDL2/SDL.h>

#include "Math.hpp"
#include "Controls.hpp"
#include "Camera.hpp"

extern int gMouseWheelDelta;


const Vector2f* Controls::getWorldMousePos() const
{

	return &worldMousePos;
}

const Vector2f* Controls::getScreenMousePos() const
{
	return &screenMousePos;
}

bool Controls::isLeftClick()
{
	return leftClick;
}

bool Controls::isRightClick()
{
	return rightClick;
}

bool Controls::isMiddleClick()
{
	return middleClick;
}

bool Controls::isExitButtonClick(){
	return quit;
}

void Controls::update(SDL_Event* p_event)
{
	//Reset
	leftClick = false;


	Vector2i mouseCoords;

	mouseCoords = {0, 0};

	//Update inputs
	hidScanInput();
	u32 kHeld = hidKeysHeld(CONTROLLER_P1_AUTO);
	u32 touches = hidTouchCount();
	//Read gyro (and other sensors...)
	hidSixAxisSensorValuesRead(&sasv, CONTROLLER_P1_AUTO, 1);

	if (kHeld & KEY_X){
		useGyro = true;
		gyroDelta = {0, 0};
	}

	if (useGyro){
		gyroDelta.x -= sasv.gyroscope.z;
		gyroDelta.y -= sasv.gyroscope.x;

		//Transfor gyroDeltas into mouse coords
		mouseCoords.x = 150*gyroDelta.x+640;
		mouseCoords.y = 150*gyroDelta.y+360;
	}
	
	//Only single touch support
	if (touches >= 1){
		//Read only 'first' touch
		hidTouchRead(&tp, 0);
		mouseCoords = {tp.px, tp.py};
		leftClick = true;
		useGyro = false; //Turn off gyro when using touch

		mouseCoords.x = tp.px;
		mouseCoords.y = tp.py;
	}

	//update the world mouse position
	worldMousePos = toVector2f(mouseCoords);

	worldMousePos -= camera->getPos() + camera->getHalfSize();
	worldMousePos /= camera->getZoom();

	//update screen space position
	screenMousePos = toVector2f(mouseCoords);

	if (kHeld & KEY_A){
		leftClick = true;
	}

	if (kHeld & KEY_PLUS){
		quit = true;
	}

	// Update the mouse buttons and the mouse wheel
	mouseWheelDelta = 0;
}