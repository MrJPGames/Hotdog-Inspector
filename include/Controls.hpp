#pragma once

#include <switch.h>

#include <SDL2/SDL.h>
#include "Math.hpp"
#include "Camera.hpp"

// Nice little package for LMB, RMB, MMB, and mouse pos
class Controls
{
public:
	Controls()
	:
	camera(nullptr),
	leftClick(false), 
	rightClick(false),
	middleClick(false),
	mouseWheelDelta(0)
		
	{
		//Initialize gyro
		u32 handles[4];
		hidGetSixAxisSensorHandles(&handles[0], 2, CONTROLLER_PLAYER_1, TYPE_JOYCON_PAIR);
		hidGetSixAxisSensorHandles(&handles[2], 1, CONTROLLER_PLAYER_1, TYPE_PROCONTROLLER);
		hidGetSixAxisSensorHandles(&handles[3], 1, CONTROLLER_HANDHELD, TYPE_HANDHELD);
		hidStartSixAxisSensor(handles[0]);
		hidStartSixAxisSensor(handles[1]);
		hidStartSixAxisSensor(handles[2]);
		hidStartSixAxisSensor(handles[3]);
	}

	void setCamera(const Camera* p_camera) { camera = p_camera; }

	const Vector2f* getWorldMousePos() const;
	const Vector2f* getScreenMousePos() const;
	bool isLeftClick();
	bool isRightClick();
	bool isMiddleClick();
	bool isExitButtonClick();

	void update(SDL_Event* p_event);
	void printState();

private:
	// Ptr to camera needed to gather the in-world mouse coords
	const Camera* camera;

	bool leftClick;
	bool rightClick;
	bool middleClick;
	bool quit = false;

	bool useGyro = true;

	Vector2f gyroDelta = {0, 0};

	// Amount of scrolling done in a set amout of time
	int mouseWheelDelta;

	Vector2f worldMousePos;
	Vector2f screenMousePos;

	SixAxisSensorValues sasv;
	touchPosition tp;
};