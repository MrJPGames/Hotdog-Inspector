#include "Hotdog.hpp"

#include "Conveyor.hpp"

Hotdog::Hotdog()
{

}

Hotdog::Hotdog(const SpriteCreateInfo& p_info, Lives* p_lifeCounter, AudioManager* p_audioManager)
:Sprite(p_info), 
atLastTarget(false),
canKill(true),
isDying(false),
fAlpha(255),
scaleLifeTime(1.f),
alphaLifeTime(300.f),
lifeCounter(p_lifeCounter),
targetPos(nullptr),
lastTargetPos(pos),
lag(0.1f),
audioManager(p_audioManager)

{
	lastTargetPos = pos;
}

void Hotdog::update(const float& p_dt)
{
	if (isDying)
	{


		scale -= scaleLifeTime * p_dt;


		if (alpha > 0)
		{
			fAlpha -= alphaLifeTime * p_dt;
			alpha = roundToInt(fAlpha);
		}
		else
		{
			//pleaseDelete = true;
		}
	}

	if(targetPos)
	{
		Vector2f dis = *targetPos - pos;
		Vector2f vel = dis * lag;

		move(vel);	
	}

	if (!clicked && !targetPos)
	{
		Vector2f dis = lastTargetPos - pos;
		Vector2f vel = dis * lag;
		move(vel);		
	}

	if (!clicked && !targetPos)
		canKill = false;

	if (doesAnimate)
		animate(p_dt);

	if (abs(lastTargetPos.x - pos.x) < 4.f && abs(lastTargetPos.y - pos.y) < 4.f)
		atLastTarget = true;
	else
		atLastTarget = false;

	if (atLastTarget)
		canKill = true;
}

void Hotdog::onCollisionBegin(Sprite* p_sprite)
{

}

void Hotdog::duringCollision(Sprite* p_sprite)
{

	Conveyor* conveyor = dynamic_cast<Conveyor*>(p_sprite);
	if (conveyor)
	{
		//std::cout << "lol" << std::endl;
		//targetPos = &p_sprite->getPos();
		if (!clicked)
		{
			move(Vector2f(conveyor->getSpeed()));
			lastTargetPos += conveyor->getSpeed();
		}

	}

	if (p_sprite->getName() == "Trash Can" && !clicked && canKill)
	{
		isDying = true;
		clickable = false;
		targetPos = &p_sprite->getPos();
		if (name == "Good Hotdog")
		{
			audioManager->play("wrong", 0);
			if (!lifeCounter->removeLife())
			{
				quit = true;
			}
		}
		//else
		//{
			//audioManager->play("correct", 0);
		//}
		targetPos = &p_sprite->getPos();
	}

	if (p_sprite->getName() == "Crate" && !clicked && canKill)
	{
		isDying = true;
		clickable = false;
		targetPos = &p_sprite->getPos();
		if (name == "Bad Hotdog" || name == "Hotdog Finger" || name == "Pig foot" || name == "Radioactive" || name == "Rotten" || name == "Rat 0" || name == "Rat 1")
		{
			audioManager->play("wrong", 0);
			if (!lifeCounter->removeLife())
			{
				quit = true;
			}
		}
		else
		{
			audioManager->play("correct", 0);
		}
		targetPos = &p_sprite->getPos();
	}

	if (p_sprite->getName() == "Furnace" && !clicked && canKill)
	{
		isDying = true;
		clickable = false;
		targetPos = &p_sprite->getPos();
		audioManager->play("wrong", 0);
		if (!lifeCounter->removeLife())
		{
			quit = true;
		}
		targetPos = &p_sprite->getPos();
	}
}

void Hotdog::onCollisionEnd(Sprite* p_sprite)
{

}

void Hotdog::animate(const float& p_dt)
{
	play(animationSet["main"]);

}