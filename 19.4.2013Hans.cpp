// Include OpenGL ES Engine utils
#include <es_util.h>
// Include map class
#include <Map.h>

#include <TextGameObject.h>
// Camera class
#include <ctime>
#include "Enemy.h"
#include <Camera.h>
#include <Tile.h>
#include <Layer.h>
#include <Input.h>
#include <AnimatedSpriteGameObject.h>
//#include <TextGameObject.h>
#include "Player.h"
#include "Lammas.h"

using namespace yam2d;

	int GAME = 0;
	int PlayerStatus = 0;

namespace
{
	
	std::vector<Enemy*> lammas1;
	std::vector<Enemy*> dog1;
	//AnimatedSpriteGameObject* lammas = 0;
	//AnimatedSpriteGameObject* dog = 0;
	GameObject*  Laiva = 0;
	// Pointer to TmxMap-object
	TmxMap* map = 0;
	TmxMap* menu = 0;
	Player* player = 0;
	Enemy* enemy = 0;	
	Enemy* enemydog = 0;
	Enemy* enemybag = 0;
	// We need to use Ref-class (autopointer), so that we dont lose our object references when explosion is destroyed from the map.
	Ref<Texture> texture = 0;
	Ref<SpriteSheet> spriteSheet = 0; 
	/*bool StartGame = false;*/
	/*int pressReturn = 0;*/
}
// Tapaus Jossa Pelaajalla ei ole lammasta
void PlayerNoSheep(ESContext *esContext)
{
	
		{
		
	Texture* playerTexture = new Texture("HanswalkEmpty.png");
	playerTexture->setTransparentColor(0xff,0x00,0xff);
		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
	
player = new Player(0,spriteSheet,map);
player -> setSize(64, 64);

	int numClipsPerAnimation = 8;

	float animationFrameRate = 8.0f;
	for( int i=0; i<4; ++i )
			{
		std::vector<int> indices;
		indices.resize(numClipsPerAnimation);
		for( size_t j=0; j<indices.size(); ++j )
				{
			indices[j] = numClipsPerAnimation*i + j;
				}

		
		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
			}
	
	player->setActiveAnimation(0);
	player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );
	
	
	map->getLayer("GameObjects")->addGameObject(player);
		}

	


}


//Tapaus Jossa pelaajalla on lammas.
void PlayerHasSheep(ESContext *esContext)
{
	
	Texture* playerTexture = new Texture("HanswalkFull.png");
		playerTexture->setTransparentColor(0xff,0x00,0xff);
		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
		

		player = new Player(0,spriteSheet,map);
		player -> setSize(64, 64);

		int numClipsPerAnimation = 8;

		float animationFrameRate = 8.0f;
	
		
	for( int i=0; i<4; ++i )
				
					{
		std::vector<int> indices;
		indices.resize(numClipsPerAnimation);
			for( size_t j=0; j<indices.size(); ++j )
			
						{
			
						indices[j] = numClipsPerAnimation*i + j;
						}

		
		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
				
					}
	player->setActiveAnimation(0);


	player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );
	
	
	map->getLayer("GameObjects")->addGameObject(player);

}


bool StartUp(ESContext *esContext)
{
	{
	menu = new TmxMap();
	
	// Load map file
	if( !menu->loadMapFile("MainMenu.tmx") )
		return false;
	// Move gameobject to middle of map.
	vec2 cameraPosM = vec2(menu->getWidth()/2.0f - 0.5f, menu->getHeight()/2.0f - 0.5f);
	menu->getCamera()->setPosition( cameraPosM );
	}
		return true;
}


bool GameOn(ESContext *esContext)
{
	{
		{
	// Create new TmxMap object
	map = new TmxMap();
	
	// Load map file
	if( !map->loadMapFile("MapOne.tmx") )
		return false;
	// Move gameobject to middle of map.
	vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
	map->getCamera()->setPosition( cameraPos );


	
	
	/*Laiva = new GameObject(1, map->getLayer("Laiva")->getGameObjects()[0]->getPosition(), map->getLayer("Laiva")->getGameObjects()[0]->getSize());*/
	
	

	


		
	
// //Luodaan Koira 
// {
// Texture* enemyTexture = new Texture("dogrun1.png");
//	enemyTexture->setTransparentColor(0xff,0x00,0xff);
//	spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,128,0,0);
//	
//	/*Create new player.*/
//	enemydog = new Enemy(0,spriteSheet,player);
//	enemydog -> setSize(64,64 );
//	int numClipsPerAnimation = 4;
//
//	float animationFrameRate =8.0f;
//
//	for( int i=0; i<4; ++i )
//{
//	std::vector<int> indices;
//	indices.resize(numClipsPerAnimation);
//	for( size_t j=0; j<indices.size(); ++j )
//	{
//		indices[j] = numClipsPerAnimation*i + j;
//	}
//
//	// Add looping animation.
//	enemydog->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//}
//
//
//enemydog->setActiveAnimation(0);
//
//enemydog->setPosition( map->getLayer("susi")->getGameObjects()[0]->getPosition());
//	map->getLayer("susi")->addGameObject(enemydog);
//
//		std::vector<vec2> enemyWaypoints;
//	int index = 0;
//	for (index = 0; index < 100; index++)
//	{
//		
//		
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//	/*	esLogMessage("lammas waypoint locations");
//		for (int i = 0; i < enemyWaypoints.size(); ++i) {
//			esLogMessage("WP x: %f, y: %f", enemyWaypoints[i].x, enemyWaypoints[i].y);
//		}*/
//	}
//		enemydog->setWayoints(enemyWaypoints);
//		
//	}
//
//	dog1.push_back(enemydog);
//}
// 
// 
//
//
//
//
//	 //luodaan kaksitoista lammasta jotka saavat satunnaiset waypointit.
//	
//for (int i = 0; i <12; i++)
//{
//	/* Add enemy to map layer named "GameObjects".*/
//	{
//
//		Texture* enemyTexture = new Texture("sheep.png");
//		enemyTexture->setTransparentColor(0xff,0x00,0xff);
//		spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,256,0,0);
//		
//		/*Create new player.*/
//		enemy = new Enemy(0,spriteSheet,player);
//		enemy -> setSize(64,64 );
//		int numClipsPerAnimation = 4;
//
//		float animationFrameRate =4.0f;
//
//		for( int i=0; i<4; ++i )
//	{
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
//		for( size_t j=0; j<indices.size(); ++j )
//		{
//			indices[j] = numClipsPerAnimation*i + j;
//		}
//
//		// Add looping animation.
//		enemy->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//	}
//
//
//	enemy->setActiveAnimation(0);
//
//	enemy->setPosition( map->getLayer("Lammas_Objects")->getGameObjects()[i]->getPosition());
//		map->getLayer("GameObjects")->addGameObject(enemy);
//		
//		// Add some waypoints for enemy.
//		std::vector<vec2> enemyWaypoints;
//	int index = 0;
//	for (index = 0; index < 100; index++)
//	{
//		
//		
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//	/*	esLogMessage("lammas waypoint locations");
//		for (int i = 0; i < enemyWaypoints.size(); ++i) {
//			esLogMessage("WP x: %f, y: %f", enemyWaypoints[i].x, enemyWaypoints[i].y);
//		}*/
//	}
//		enemy->setWayoints(enemyWaypoints);
//		
//	}
//
//	lammas1.push_back(enemy);
//}
//	}

	return true;
	
}

//// Initialize the game
//bool init ( ESContext *esContext )
//{
//	//
//	//if (!StartGame)
//	//{
//	//// Create new TmxMap object
//	//map = new TmxMap();
//	//
//	//// Load map file
//	//if( !map->loadMapFile("MainMenu.tmx") )
//	//	return false;
//	//// Move gameobject to middle of map.
//	//vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//	//map->getCamera()->setPosition( cameraPos );
//
//	//}
//	
//	else	if(StartGame)
//{	
//
//	{
//		delete map;
//	// Create new TmxMap object
//	map = new TmxMap();
//	
//	// Load map file
//	if( !map->loadMapFile("MapOne.tmx") )
//		return false;
//	// Move gameobject to middle of map.
//	vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//	map->getCamera()->setPosition( cameraPos );
//
//
//	
//	
//	Laiva = new GameObject(1, map->getLayer("Laiva")->getGameObjects()[0]->getPosition(), map->getLayer("Laiva")->getGameObjects()[0]->getSize());
//	
//	{
//
//		
//	Texture* playerTexture = new Texture("HanswalkEmpty.png");
//	playerTexture->setTransparentColor(0xff,0x00,0xff);
//		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
//		
//player = new Player(0,spriteSheet,map);
//player -> setSize(64, 64);
//
//	int numClipsPerAnimation = 8;
//
//	float animationFrameRate = 8.0f;
//	for( int i=0; i<4; ++i )
//	{
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
//		for( size_t j=0; j<indices.size(); ++j )
//		{
//			indices[j] = numClipsPerAnimation*i + j;
//		}
//
//		
//		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//	}
//	
//	player->setActiveAnimation(0);
//	
//	player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );
//	
//	
//	map->getLayer("GameObjects")->addGameObject(player);
//
//
//
//		
//	}
// //Luodaan Koira 
// {
// Texture* enemyTexture = new Texture("dogrun1.png");
//	enemyTexture->setTransparentColor(0xff,0x00,0xff);
//	spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,128,0,0);
//	
//	/*Create new player.*/
//	enemydog = new Enemy(0,spriteSheet,player);
//	enemydog -> setSize(64,64 );
//	int numClipsPerAnimation = 4;
//
//	float animationFrameRate =8.0f;
//
//	for( int i=0; i<4; ++i )
//{
//	std::vector<int> indices;
//	indices.resize(numClipsPerAnimation);
//	for( size_t j=0; j<indices.size(); ++j )
//	{
//		indices[j] = numClipsPerAnimation*i + j;
//	}
//
//	// Add looping animation.
//	enemydog->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//}
//
//
//enemydog->setActiveAnimation(0);
//
//enemydog->setPosition( map->getLayer("susi")->getGameObjects()[0]->getPosition());
//	map->getLayer("susi")->addGameObject(enemydog);
//
//		std::vector<vec2> enemyWaypoints;
//	int index = 0;
//	for (index = 0; index < 100; index++)
//	{
//		
//		
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//	/*	esLogMessage("lammas waypoint locations");
//		for (int i = 0; i < enemyWaypoints.size(); ++i) {
//			esLogMessage("WP x: %f, y: %f", enemyWaypoints[i].x, enemyWaypoints[i].y);
//		}*/
//	}
//		enemydog->setWayoints(enemyWaypoints);
//		
//	}
//
//	dog1.push_back(enemydog);
//}
// 
// 
//
//
//
//
//	 //luodaan kaksitoista lammasta jotka saavat satunnaiset waypointit.
//	
//for (int i = 0; i <12; i++)
//{
//	/* Add enemy to map layer named "GameObjects".*/
//	{
//
//		Texture* enemyTexture = new Texture("sheep.png");
//		enemyTexture->setTransparentColor(0xff,0x00,0xff);
//		spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,256,0,0);
//		
//		/*Create new player.*/
//		enemy = new Enemy(0,spriteSheet,player);
//		enemy -> setSize(64,64 );
//		int numClipsPerAnimation = 4;
//
//		float animationFrameRate =4.0f;
//
//		for( int i=0; i<4; ++i )
//	{
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
//		for( size_t j=0; j<indices.size(); ++j )
//		{
//			indices[j] = numClipsPerAnimation*i + j;
//		}
//
//		// Add looping animation.
//		enemy->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//	}
//
//
//	enemy->setActiveAnimation(0);
//
//	enemy->setPosition( map->getLayer("Lammas_Objects")->getGameObjects()[i]->getPosition());
//		map->getLayer("GameObjects")->addGameObject(enemy);
//		
//		// Add some waypoints for enemy.
//		std::vector<vec2> enemyWaypoints;
//	int index = 0;
//	for (index = 0; index < 100; index++)
//	{
//		
//		
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//	/*	esLogMessage("lammas waypoint locations");
//		for (int i = 0; i < enemyWaypoints.size(); ++i) {
//			esLogMessage("WP x: %f, y: %f", enemyWaypoints[i].x, enemyWaypoints[i].y);
//		}*/
//	}
//		enemy->setWayoints(enemyWaypoints);
//		
//	}
//
//	lammas1.push_back(enemy);
//}
//	}
//
//	return true;
//	
//
//	}


// Deinitialize the game


void deinit ( ESContext *esContext )
{/*
	GameObject*  Laiva = 0;*/
	texture = 0;
	spriteSheet = 0; 
	/*delete enemydog;
	delete enemy;*/
	// Delete map.
	delete map;
	delete menu;
}

void update( ESContext* ctx, float deltaTime )
{
	
	vec2 cameraPosM =  vec2(menu->getWidth()/2.0f - 0.5f, menu->getHeight()/2.0f - 0.5f);
	
	menu->getCamera()->setPosition( cameraPosM );
	// Update map. this will update all GameObjects inside a map layers.
	menu->update(deltaTime);
	
	vec2 cameraPos =  vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
	
	map->getCamera()->setPosition( cameraPos );
	// Update map. this will update all GameObjects inside a map layers.
	map->update(deltaTime);



	assert(PlayerStatus >= 0 && PlayerStatus <= 2);

	switch (PlayerStatus)
		{	
	
	case 1:
		if (player->HasLammas == false)
		{
		PlayerNoSheep(esContext);
		

		break;
		}
	case 2:
		if(player->HasLammas == true)
		{
		PlayerHasSheep(esContext);

		break;
		}

	default:

		break;
		}

	if( getKeyState(KEY_RETURN) )
	{
	
	GAME = 1;
	
	}
}
// Update game
//void update( ESContext* ctx, float deltaTime )
//{
//	float painettu = ((pressReturn == 0) &&getKeyState(KEY_RETURN));
//
//		if (float pelinalku = painettu)
//	{
//		StartGame = true;
//		
//	}
//
//	
//	/*vec2 cameraPos = player->getPosition();*/
//	vec2 cameraPos =  vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//	
//	map->getCamera()->setPosition( cameraPos );
//	// Update map. this will update all GameObjects inside a map layers.
//	map->update(deltaTime);
//
//
//	//pelitilan tarkastus
//	 if(StartGame)
//	{
//		
//	//tˆrm‰ystarkistu laivalle jossa Haslammas arvo muuttuu falseksi
//		if (player->HasLammas &&player->collidesTo(Laiva))
//		{
//
//			
//			vec2 tempPosition =  player->getPosition();
//			float tempRotation = player->getRotation();
//			map->deleteGameObject(player);
//
//	Texture* playerTexture = new Texture("HanswalkEmpty.png");
//	playerTexture->setTransparentColor(0xff,0x00,0xff);
//		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
//		
//player = new Player(0,spriteSheet,map);
//player -> setSize(64, 64);
//
//	int numClipsPerAnimation = 8;
//
//	float animationFrameRate = 8.0f;
//	for( int i=0; i<4; ++i )
//			{
//		
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
//		
//		for( size_t j=0; j<indices.size(); ++j )
//				{
//			indices[j] = numClipsPerAnimation*i + j;
//				}
//
//		
//		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//			}
//	
//	player->setActiveAnimation(0);
//	player->setRotation(tempRotation);
//	player->setPosition(tempPosition);
//	
//	
//	map->getLayer("GameObjects")->addGameObject(player);
//
//
//	for (int i = 0; i <12; ++i)
//		{
//	
//			if	(player->HasLammas, player->collidesTo(Laiva) )
//	/* Add enemy to map layer named "GameObjects".*/
//			{
//				player->HasLammas = false;
//		Texture* enemyTexture = new Texture("sheepBag.png");
//		enemyTexture->setTransparentColor(0xff,0x00,0xff);
//		spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,256,0,0);
//		
//		/*Create new player.*/
//		enemybag = new Enemy(0,spriteSheet,player);
//		enemybag -> setSize(32,32 );
//		int numClipsPerAnimation = 4;
//
//		float animationFrameRate =8.0f;
//
//		for( int i=0; i<4; ++i )
//				{
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
//		
//		for( size_t j=0; j<indices.size(); ++j )
//					{
//			
//						indices[j] = numClipsPerAnimation*i + j;
//				
//					}
//	
//		// Add looping animation.
//		enemy->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//				}	
//
//
//	enemy->setActiveAnimation(0);
//
//	enemy->setPosition( map->getLayer("LammasPussi")->getGameObjects()[i]->getPosition());
//		map->getLayer("GameObjects")->addGameObject(enemy);
//		
//			}
//
//		}
//
//	}
//
//	//tˆrm‰ystarkistus koiralle ja pelaajalle jos pelaaja tˆrm‰‰ koiraan pelaaja IsAlive muuttuu falseksi
//	if (player->collidesTo(enemydog))
//	{
//
//		map->deleteGameObject(player);
//		player->IsAlive = false;
//		{
//	
//		// Create new TmxMap object
//	
//			map = new TmxMap();
//	
//	// Load map file
//			map->loadMapFile("DIE.tmx") ;		
//	// Move gameobject to middle of map.
//			vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//			map->getCamera()->setPosition( cameraPos );
//	
//		}
//	}
//
//	//tapahtuu jos haslammas on false
//	if (player->HasLammas==false)
//		{
//	
//		//niin kauan kuin lampaita ritt‰‰
//		for (int i = 0;i < 12 ;i++ )
//			{
//		if (player->collidesTo(lammas1[i]) )
//				{
//		
//			//poistaa lammas objektin
//		map->deleteGameObject(lammas1[i]);
//		map->deleteGameObject(player);
//		// arvo muuttuu todeksi
//		player->HasLammas = true;
//
//		
//		Texture* playerTexture = new Texture("HanswalkFull.png");
//		playerTexture->setTransparentColor(0xff,0x00,0xff);
//		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
//		
//
//		player = new Player(0,spriteSheet,map);
//		player -> setSize(64, 64);
//
//		int numClipsPerAnimation = 8;
//
//		float animationFrameRate = 8.0f;
//	
//		
//	for( int i=0; i<4; ++i )
//				
//					{
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
//			for( size_t j=0; j<indices.size(); ++j )
//			
//						{
//			
//						indices[j] = numClipsPerAnimation*i + j;
//						}
//
//		
//		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//				
//					}
//	
//	player->setActiveAnimation(0);
//	player->setPosition(map->getLayer("GameObjects")->getGameObjects()[0]->getPosition() );
//	
//
//	map->getLayer("GameObjects")->addGameObject(player);
//
//
//				}
//			}
//		}
//	}
//}


// Draw game
void draw ( ESContext *esContext )
{
	assert(GAME >= 0 && GAME <= 2);
	
	switch (GAME)
		{
	case 0:
		
		StartUp(esContext);
			// Set OpenGL clear color (dark gray)
	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );

	// Clear the color buffer
	glClear ( GL_COLOR_BUFFER_BIT );
		menu->getCamera()->setScreenSize(esContext->width,esContext->height); 

	// Render map and all of its layers containing GameObjects to screen.
		menu->render();
		break;
		
	case 1:
		
		GameOn(esContext);
			// Set OpenGL clear color (dark gray)
	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );

	// Clear the color buffer
	glClear ( GL_COLOR_BUFFER_BIT );
		map->getCamera()->setScreenSize(esContext->width,esContext->height); 

	// Render map and all of its layers containing GameObjects to screen.
	map->render();
		break;

	
	default:
	
		
		break;
	}
	// Set OpenGL clear color (dark gray)
	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );

	// Clear the color buffer
	glClear ( GL_COLOR_BUFFER_BIT );

	
}


int main ( int argc, char *argv[] )
{
	ESContext esContext;
	esInitContext ( &esContext );
	esCreateWindow( &esContext, "HANS UBER The SHEEP THIEF", 1920, 1080, ES_WINDOW_DEFAULT );

	//if ( !init ( &esContext ) )
	//	return 0;
	
	if ( !StartUp ( &esContext ) )
		return 0;

	if ( !GameOn ( &esContext ) )
		return 0;

	esRegisterDrawFunc( &esContext, draw );
	esRegisterUpdateFunc( &esContext, update );
	esRegisterDeinitFunc( &esContext, deinit);

	esMainLoop ( &esContext );
	return 0;
}
