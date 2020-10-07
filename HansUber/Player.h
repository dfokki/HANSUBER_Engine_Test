
#ifndef PLAYER_H_
#define PLAYER_H_ 

#include <AnimatedSpriteGameObject.h>
#include <SpriteGameObject.h>
#include <Map.h>

using namespace yam2d;

class Player : public AnimatedSpriteGameObject
{
public:
	
	bool playerMoves;
	bool Moving;
	bool HasLammas;
	bool IsAlive;
	Player(int gameObjectType, SpriteSheet* spriteSheet, Map*map);
	virtual ~Player(void);


	virtual void update( float deltaTime );
	
private:
	
	Map* m_map;


};



#endif