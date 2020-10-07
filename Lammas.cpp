//#include "Lammas.h"
//#include <stdlib.h>
////#include <Map.h>
////#include <vector>
// 
//using namespace yam2d;
//
//Lammas::Lammas(vec2 LammasXY/*,int gameObjectType*//*, GameObject* doorObject*//*, int gameObjectType*/)
//	:LammasXY(LammasXY), IsAlive(false)
//	
//{
//	
//
//	Texture* LammasTexture = new Texture("sheep.png");
//	SpriteSheet* spriteSheet = SpriteSheet::generateSpriteSheet(LammasTexture,256,256,0,0); 
//
//	lammas = new AnimatedSpriteGameObject  (0, spriteSheet);
//	lammas->setSize(64,64);
//	
//	int numClipsPerAnimation = 4;
//
//		float animationFrameRate = 2.0f;
//
//		for( int i=0; i<4; ++i )
//	{
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
//		for( size_t j=0; j<indices.size(); ++j )
//		{
//			indices[j] = numClipsPerAnimation*i + j;
//		}
//			lammas->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//		}
//	
//	lammas->setActiveAnimation(0);
//	lammas->setPosition(LammasXY.x, LammasXY.y-1.0f);
//
//	
//}
//void Lammas::update( float deltaTime )
//{
//	IsAlive = true;
//	
//
//}

//
//
//void Lammas::setWayoints(const std::vector<vec2>& waypoints )
//{
//	m_waypoints = waypoints;
//
//}
//
//
//
//
//bool Lammas::checkDistance(vec2 playerDistance)
//{
//	/*printf("%f %f \n", playerDistance.y-DoorXY.y, playerDistance.x-DoorXY.x);*/
//
//	if( ( ( (playerDistance.y - LammasXY.y) > 0.6f   || ((playerDistance.y - LammasXY.y) < -1.5f) /*|| (playerDistance.y - DoorXY.y) > -0.1f*/) ) )
//	{	
//		return false;
//	}
//	if(((playerDistance.x - LammasXY.x) > 0.9f) || ((playerDistance.x - LammasXY.x) < -0.9f))
//	{
//		return false;
//	}
//	return true;
//}
