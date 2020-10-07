
#include "Player.h" 
include 
#include <Layer.h>
#include "Input.h"
#include <Map.h>
#include <es_util.h>
#include "Lammas.h"
#include <SpriteGameObject.h>
#include <AnimatedSpriteGameObject.h>
#include <vector>

using namespace yam2d; 
bool hasCollision = false;
//since last update
float SLU  = 0.2f;
// Update interval
float UI = 0.4f;
vec2 lastPlayerPos;
//rotation before collision
float RbC;
bool HasCollision;


Player::Player(int gameObjectType, SpriteSheet* spriteSheet, Map*map)
	: AnimatedSpriteGameObject(gameObjectType,spriteSheet) 
{
	IsAlive = true;
	m_map = map;
	HasLammas = false;
	playerMoves = false;
	//for (int i = 0; i < map->getLayer("Lammas_Objects")->getGameObjects().size(); i++)
	//{
	//	Lammas* lammas2 = new Lammas(map->getLayer("Lammas_Objects")->getGameObjects()[i]->getPosition());
	//	lammas.push_back(lammas2);
	//	m_map->getLayer("lammas")->addGameObject(lammas[i]->lammas);
	//	
	//	
	//
	//}
}


Player::~Player(void)
{
}

void Player::update( float deltaTime )
{ 
	SLU += deltaTime;

	if(SLU >= UI && HasCollision == false)
	{
		 lastPlayerPos = getPosition();
		 RbC = getRotation();
		 HasCollision = false;
		SLU = 0.0f;
	}

	

	AnimatedSpriteGameObject::update(  deltaTime );

	

	

	float rotationSpeed = 2.0f;
	float moveSpeed = 8.0f; 

	

	float forward = float(getKeyState(KEY_W)-getKeyState(KEY_S));
	float right = float(getKeyState(KEY_D)-getKeyState(KEY_A));

	float rotate = float(getKeyState(KEY_RIGHT)-getKeyState(KEY_LEFT));

	if(forward > 0)
	{
	setRotation(getRotation() + deltaTime*rotate*rotationSpeed ); 
	}
	else if(forward==0)
	{
	setRotation(getRotation() + deltaTime*rotate*rotationSpeed* 3 );
	}
	//collider
Layer::GameObjectList& objectList =  m_map->getLayer("Collision")->getGameObjects();
		
		


for (int i = 0; i < objectList.size(); i++)
		{
			GameObject* otherObject = objectList[i];
			if(	collidesTo(otherObject))
			{
				HasCollision = true;
				setPosition(lastPlayerPos);
				setRotation(RbC);
				SLU = 0.0f;
				
				return;
			}
		}

	

		if( fabsf(right) > 0.1f   )
	{
		
		// Rotate forward direction according to game object rotation
		vec2 direction = rotateVector( vec2(0,right), getRotation() );

		direction.Normalize(); // Make sure that lenght of direction vector is 1

		// Update position (euler integration)
		setPosition(getPosition() + deltaTime*moveSpeed*direction );
		HasCollision = false;

	}
		if(fabsf(forward) > 0.1f)
		{
		
			
			vec2 direction = rotateVector( vec2(forward,0), getRotation() );
			direction.Normalize(); 
			setPosition(getPosition() + deltaTime*moveSpeed*direction );
			HasCollision = false;
		}
}


