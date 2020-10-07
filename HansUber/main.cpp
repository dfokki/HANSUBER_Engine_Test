//
//#include <es_util.h>
//#include <Map.h>
//#include <TextGameObject.h>
//#include <ctime>
//#include "Enemy.h"
//#include <Camera.h>
//#include <Tile.h>
//#include <Layer.h>
//#include <Input.h>
//#include <AnimatedSpriteGameObject.h>
//#include "Player.h"
//#include "Lammas.h"
//#include <irrKlang.h>
//
//
//#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
//
//using namespace irrklang;
//using namespace yam2d;
//int LampaitaLaivassa = 0;
//	int MontakoDogia = 0;
//	int numOfCollisions = 0;
//	int GAME = 4;
//	int PlayerStatus = 0;
//	int MontakoLammasta = 0;
//	 vec2 tempPosition();
//	int SheepAmount;
//	int SheepLeft = 12;
//namespace
//{
//		ISoundEngine* engine = 0;
//		std::vector<Enemy> SBag;
//	std::vector<Enemy*> lammas1;
//	std::vector<Enemy*> dog1;
//	//AnimatedSpriteGameObject* lammas = 0;
//	//AnimatedSpriteGameObject* dog = 0;
//	GameObject*  Laiva = 0;
//	// Pointer to TmxMap-object
//	TmxMap* win = 0;
//	TmxMap* how = 0;
//	TmxMap* death = 0;
//	TmxMap* Retry = 0;
//	TmxMap* map = 0;
//	TmxMap* menu = 0;
//	Player* player = 0;
//	Enemy* enemy = 0;	
//	Enemy* enemydog = 0;
//	Enemy* enemybag = 0;
//	// We need to use Ref-class (autopointer), so that we dont lose our object references when explosion is destroyed from the map.
//	Ref<Texture> texture = 0;
//	Ref<SpriteSheet> spriteSheet = 0; 
//	/*bool StartGame = false;*/
//	/*int pressReturn = 0;*/
//}
//// Tapaus Jossa Pelaajalla ei ole lammasta
//bool PlayerNoSheep(ESContext *esContext)
//{
//	
//	//map->deleteGameObject(player);
//	{
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
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
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
//	player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );
//	
//	
//	map->getLayer("GameObjects")->addGameObject(player);
//	return true;	}
//
//	
//	return true;
//
//}
//
//
//bool SheepSpawn (ESContext *esContext)
//{
//	for (int SheepAmount = 0; SheepAmount <12; SheepAmount++)
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
//	enemy->setPosition( map->getLayer("Lammas_Objects")->getGameObjects()[SheepAmount]->getPosition());
//		map->getLayer("GameObjects")->addGameObject(enemy);
//
//		// Add some waypoints for enemy.		if (GAME == 1)
//		{
//		std::vector<vec2> enemyWaypoints;
//	int index = 0;
//	for (index = 0; index < 100; index++)
//	{
//		
//		
//		enemyWaypoints.push_back( vec2((rand()%(40-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(40-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(40-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(40-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(40-1)+1),(rand()%(30-1)+1)) );
//	/*	esLogMessage("lammas waypoint locations");
//		for (int i = 0; i < enemyWaypoints.size(); ++i) {
//			esLogMessage("WP x: %f, y: %f", enemyWaypoints[i].x, enemyWaypoints[i].y);
//		}*/
//	}
//		enemy->setWayoints(enemyWaypoints);
//		}	
//
//	}
//	
//	lammas1.push_back(enemy);
//}
//	
//	return true;
//	}
//
//bool DogSpawn(ESContext* esContext)
//{
//	
//	{
//	{
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
//enemydog->setPosition( map->getLayer("susi")->getGameObjects()[MontakoDogia]->getPosition());
//	map->getLayer("susi")->addGameObject(enemydog);
//
//		std::vector<vec2> enemyWaypoints;
//	int index = 0;
//	for (index = 0; index < 100; index++)
//	{
//		
//		enemyWaypoints.push_back(player->getPosition());
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		/*enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );*/
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
//return true;
//
//}
//
//
//
////Tapaus Jossa pelaajalla on lammas.
//bool PlayerHasSheep(ESContext *esContext)
//{
//	vec2 tempPos = player->getPosition();
//	float tempRot = player->getRotation();
//	map->deleteGameObject(player);
//	{
//	
//	Texture* playerTexture = new Texture("HanswalkFull.png");
//		playerTexture->setTransparentColor(0xff,0x00,0xff);
//		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
//		
//
//		player = new Player(0,spriteSheet,map);
//		player->HasLammas = true;
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
//	player->setActiveAnimation(0);
//
//
//	player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );
//	
//	
//	player->setPosition(tempPos);
//	return true;
//
//	}
//return true;
//}
//
//
//bool StartUp(ESContext *esContext)
//{
//	{
//	menu = new TmxMap();
//	
//	// Load map file
//	if( !menu->loadMapFile("MainMenu.tmx") )
//		return false;
//	// Move gameobject to middle of map.
//	vec2 cameraPosM = vec2(menu->getWidth()/2.0f - 0.5f, menu->getHeight()/2.0f - 0.5f);
//	menu->getCamera()->setPosition( cameraPosM );
//
//	
//
//	return true;
//	}
//		
//}
//bool howTo(ESContext* esContext)
//{
//	{
//	how = new TmxMap();
//	
//	// Load map file
//	if( !how->loadMapFile("HowTo.tmx") )
//		return false;
//	// Move gameobject to middle of map.
//	vec2 cameraPosM = vec2(how->getWidth()/2.0f - 0.5f, how->getHeight()/2.0f - 0.5f);
//	how->getCamera()->setPosition( cameraPosM );
//
//	
//
//	return true;
//	}
//}
////bool GameSound(ESContext* esContext)
////{
////
////
////	return true;
////}
//
//bool GameOn(ESContext *esContext)
//{
//	
//		{
//	// Create new TmxMap object
//			map = new TmxMap();
//	
//	// Load map file
//			if( !map->loadMapFile("MapOne.tmx") )
//			return false;
//	// Move gameobject to middle of map.
//			vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//			map->getCamera()->setPosition( cameraPos );
//
//	//Luodaan laivan collision layeri johon hans tyhjent‰‰ pussinsa
//		Laiva = new GameObject(1, map->getLayer("Laiva")->getGameObjects()[3]->getPosition(), map->getLayer("Laiva")->getGameObjects()[0]->getSize());
//
//			assert(PlayerStatus >= 0 && PlayerStatus <= 3);
//
//	switch (PlayerStatus)
//		{	
//	case 0:
//
//
//			PlayerNoSheep( esContext);
//	
//			break;
//
//	case 1:
//		if (player->HasLammas == false)
//			{
//				PlayerNoSheep( esContext);
//		
//			}
//				break;
//			
//	case 2:
//	
//			esLogMessage ("On LAMMAS ASADSDASDA");
//			PlayerHasSheep( esContext);
//		
//			break;
//		
//
//	default:
//
//			esLogMessage ("Jokin kusee");
//			break;
//
//		}
//
//
//	// LIS‰t‰‰ Peliin Lampaat.
//	switch (MontakoLammasta)
//	{
//case 0:
//
//	SheepSpawn(esContext);
//	DogSpawn(esContext);
//	break;
//	
//case 1:
//	SheepSpawn(esContext);
//	DogSpawn(esContext);
//		
//break;
//
//default: 
//	esLogMessage("taas joku kusee");
//		break;
//	}
//
//		engine = createIrrKlangDevice();
//	
//	engine->play2D("oceanferry.wav", true);
//	
//	engine->play2D("Ireland.mp3", true);
//	
//	
//
//	return true;
//	}
//}
//
//bool Win(ESContext *esContext)
//{
//	{
//	
//		win = new TmxMap();
//	
//	// Load map file
//	if( !win->loadMapFile("Winner.tmx") )
//		return false;
//	// Move gameobject to middle of map.
//	vec2 cameraPosD = vec2(win->getWidth()/2.0f - 0.5f, win->getHeight()/2.0f - 0.5f);
//	win->getCamera()->setPosition( cameraPosD );
//
//	
//
//	return true;
//	}
//
//}
//bool Restart(ESContext *esContext)
//{
//	{
//	Retry = new TmxMap();
//	
//	// Load map file
//	if( !Retry->loadMapFile("EndScreen.tmx") )
//		return false;
//	// Move gameobject to middle of map.
//	vec2 cameraPosM = vec2(Retry->getWidth()/2.0f - 0.5f, Retry->getHeight()/2.0f - 0.5f);
//	Retry->getCamera()->setPosition( cameraPosM );
//
//	
//
//	return true;
//	}
//		
//}
//
//
//bool Death(ESContext *esContext)
//{
//	
//	{
//	
//		death = new TmxMap();
//	
//	// Load map file
//	if( !death->loadMapFile("YOUDIED.tmx") )
//		return false;
//	// Move gameobject to middle of map.
//	vec2 cameraPosD = vec2(death->getWidth()/2.0f - 0.5f, death->getHeight()/2.0f - 0.5f);
//	death->getCamera()->setPosition( cameraPosD );
//
//	
//
//	return true;
//	}
//}
//
//
//
//bool init ( ESContext *esContext )
//{
//	
//
//	StartUp(esContext);
//	
//		GameOn(esContext);
//		
//			Restart(esContext);
//
//				Death(esContext);
//
//					howTo(esContext);
//	return true;
//	
//}
//
//
//void deinit ( ESContext *esContext )
//{
//	
//	delete  Laiva;
//	texture = 0;
//	spriteSheet = 0; 
//	delete player;
//	delete enemybag;
//	delete enemydog;
//	delete enemy;
//	/*delete enemydog;
//	delete enemy;*/
//	// Delete map.
//	delete win;
//	delete how;
//	delete death;
//	delete map;
//	delete menu;
//	delete Retry;
//}
////
////
////UPDATE OSIO
////
//
//void HansUpdate(ESContext* ctx, float deltaTime)
//{
//	for (int i = 0; i <= MontakoDogia ;i++ )
//	{
//
//		if(player->IsAlive)
//		{
//			if(player->collidesTo(dog1[i]))
//			{
//		
//		
//			for(int Shit = 0; Shit <= SheepLeft; Shit++)
//				{
//				map->deleteGameObject(lammas1[Shit]);
//		
//				}
//		
//			for(int DogsLeft = 0; DogsLeft <= MontakoDogia; DogsLeft++)
//				{
//				map->deleteGameObject(dog1[DogsLeft]);
//		
//				}
//
//			map->deleteGameObject(player);
//			player->HasLammas = false;
//			player->IsAlive = false;
//			GAME = 2;
//			
//			return;
//			}
//		}
//	}
// 
//	if (player->HasLammas==false)
//		{
//	
//		//niin kauan kuin lampaita ritt‰‰
//		for (int i = 0;i < 12 ;i++ )
//			{
//				if (player->collidesTo(lammas1[i]) )
//				{
//					MontakoDogia = MontakoDogia + 1;
//					numOfCollisions += numOfCollisions + 1 ;
//					SheepLeft = SheepLeft - 1;
//					esLogMessage("NOC = %d", numOfCollisions );
//						//poistaa lammas objektin
//					
//					
//						//jotta 
//					player->HasLammas = true;
//					map->deleteGameObject(lammas1[i]);
//			
//				engine->play2D("dogpack.wav");
//				engine->play2D("manlaughshort.wav");
//				
//					/*PlayerStatus = 2;*/
//	
//				}
//
//
//			if(numOfCollisions == 1)
//				{	
//					
//				DogSpawn(ctx);
//				esLogMessage("montakoDogia  %d ", MontakoDogia);
//				numOfCollisions = numOfCollisions - 1;
//											
//				}		
//			
//			}
//	
//		}
//
//
//	if(player->collidesTo(Laiva)&&player->HasLammas == true )
//				{
//					esLogMessage("OSUU LAIVAAN " );
//					esLogMessage("haslammas on false " );
//					engine->play2D("manlaugh.wav");
//					engine->play2D("farmHerd.wav");
//				
//					
//						
//	/* Add enemy to map layer named "GameObjects".*/
//			if (SheepLeft != 0)
//			{
//				for (int i = 11; i >= SheepLeft ;i-- )
//				{
//		Texture* enemyTexture = new Texture("sheepBag.png");
//		enemyTexture->setTransparentColor(0xff,0x00,0xff);
//		spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,256,0,0);
//		
//		/*Create new player.*/
//		enemybag = new Enemy(0,spriteSheet,player);
//		enemybag -> setSize(64,64 );
//		int numClipsPerAnimation = 4;
//
//		float animationFrameRate =10.0f;
//
//		for( int i=0; i<4; ++i )
//				{
//					std::vector<int> indices;
//					indices.resize(numClipsPerAnimation);
//		
//		for( size_t j=0; j<indices.size(); ++j )
//					{
//			
//						indices[j] = numClipsPerAnimation*i + j;
//				
//					}
//	
//		// Add looping animation.
//					enemybag->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//				}	
//
//
//				enemybag->setActiveAnimation(0);
//
//				enemybag->setPosition( map->getLayer("LammasPussi")->getGameObjects()[i]->getPosition());
//				map->getLayer("GameObjects")->addGameObject(enemybag);
//		
//				player->HasLammas = false;
//		esLogMessage("montako pussia %d", SheepLeft);
//				}
//			}
//	}
//	if(SheepLeft == 0 && player->collidesTo(Laiva))
//	{
//	GAME = 5;
//	engine->play2D("manlaugh.wav");
//	engine->play2D("farmHerd.wav");
//	
//	}
//		
//
//}
//
//
//
//void menuUpdate(ESContext* ctx, float deltaTime)
//{
//	vec2 cameraPos =  vec2(menu->getWidth()/2.0f - 0.5f, menu->getHeight()/2.0f - 0.5f);
//	
//	menu->getCamera()->setPosition( cameraPos );
//	// Update map. this will update all GameObjects inside a map layers.
//	menu->update(deltaTime);
//
//	
//
//	if( getKeyState(KEY_RETURN)&&GAME == 0 )
//	{
//		esLogMessage("painettutut ");
//		GAME = 1;
//	
//	}
//
//	if(getKeyState(KEY_ESCAPE))
//	{
//		exit(0);
//	}
//	
//}
//
//void mapUpdate(ESContext* ctx, float deltaTime)
//{
//
//	vec2 cameraPos =  vec2(player->getPosition());
//	
//	map->getCamera()->setPosition( cameraPos );
//	// Update map. this will update all GameObjects inside a map layers.
//	map->update(deltaTime);
//
//	HansUpdate(ctx,deltaTime);
//	//GameSound(ctx);
//		if(getKeyState(KEY_ESCAPE))
//	{
//		exit(0);
//	}
//	
//	}
//
//void RestartUpdate(ESContext* ctx, float deltaTime)
//{
//
//	vec2 cameraPos =  vec2(Retry->getWidth()/2.0f - 0.5f, Retry->getHeight()/2.0f - 0.5f);
//	
//	Retry->getCamera()->setPosition( cameraPos );
//	// Update map. this will update all GameObjects inside a map layers.
//	Retry->update(deltaTime);
//
//
//	if( getKeyState(KEY_R)&& GAME == 2 )
//	{
//		esLogMessage("painettutut ");
//		
//		
//		
//			for(int Shit = 0; Shit <= SheepLeft; Shit++)
//				{
//				map->deleteGameObject(lammas1[Shit]);
//		
//				}
//		
//			for(int DogsLeft = 0; DogsLeft <= MontakoDogia; DogsLeft++)
//				{
//				map->deleteGameObject(dog1[DogsLeft]);
//		
//				}
//
//		/**player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );*/
//			
//			map->deleteGameObject(player);
//
//for(int i = 0; i <= 2; i++)
//{
//			map->update(deltaTime);
//}
//		/*PlayerStatus = 0;*/
//		
//		MontakoDogia = 0;
//		numOfCollisions = 0;
//		SheepAmount = 0;
//		SheepLeft = 12;
//		GAME = 3;
//	
//	}
//
//	if(getKeyState(KEY_ESCAPE))
//	{
//		exit(0);
//	}
//	
//	}
//
////void  GameSoundUp(ESContext* ctx, float deltaTime)
////{float interval = 1.5f;
////float counter = 0.0f;
////
////counter += deltaTime;
////
////	if (counter>=interval){
////	GameSound(ctx);
////	counter = 0;
////	}
////	return;
////}
//void howToUpdate(ESContext* ctx, float deltaTime)
//{
//vec2 cameraPos =  vec2(how->getWidth()/2.0f - 0.5f, how->getHeight()/2.0f - 0.5f);
//	
//	how->getCamera()->setPosition( cameraPos );
//	// Update map. this will update all GameObjects inside a map layers.
//	how->update(deltaTime);
//	if(getKeyState(KEY_SPACE))
//	{
//	GAME = 0;
//	
//	}
//	if(getKeyState(KEY_ESCAPE))
//	{
//	exit(0);
//	}
//}
//
//void deathUpdate(ESContext* ctx, float deltaTime)
//{
//	vec2 cameraPos =  vec2(death->getWidth()/2.0f - 0.5f, death->getHeight()/2.0f - 0.5f);
//	
//	death->getCamera()->setPosition( cameraPos );
//	// Update map. this will update all GameObjects inside a map layers.
//	death->update(deltaTime);
//
//	engine->drop();
//
//	if(getKeyState(KEY_ESCAPE))
//	{
//		exit(0);
//	}
//}
//void winUpdate(ESContext* ctx, float deltaTime)
//{
//	int count1 = 0;
//		count1 += deltaTime;
//	vec2 cameraPos =  vec2(win->getWidth()/2.0f - 0.5f, win->getHeight()/2.0f - 0.5f);
//	
//	win->getCamera()->setPosition( cameraPos );
//	// Update map. this will update all GameObjects inside a map layers.
//	win->update(deltaTime);
//
//	
//
//	if(count1 == 9)
//	{
//		exit(0);
//	}
//
//}
//
//
//void update( ESContext* ctx, float deltaTime )
//{
//	
//
//	assert(GAME >= 0 && GAME <= 5);
//	switch (GAME)
//	{
//	case 0:
//	menuUpdate(ctx,deltaTime);
//	break;
//
//
//	case 1:
//
//	mapUpdate(ctx,deltaTime);
//
//	
//	player->IsAlive;
//
//	case 2:
//		RestartUpdate(ctx,deltaTime);
//		break;
//	
//	case 3:
//		deathUpdate(ctx,deltaTime);
//		break;
//
//	case 4:
//
//		howToUpdate(ctx,deltaTime);
//
//		break;
//	case 5:
//
//		winUpdate(ctx, deltaTime);
//
//		break;
//
//	default:
//		break;
//	}
//
//
//
//}
//
//void draw ( ESContext *esContext )
//{
//	if(GAME == 0)
//	{
//	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );
//
//	// Clear the color buffer
//	glClear ( GL_COLOR_BUFFER_BIT );
//		menu->getCamera()->setScreenSize(esContext->width,esContext->height); 
//
//	// Render map and all of its layers containing GameObjects to screen.
//		menu->render();
//	}
//
//		
//else if (GAME == 1)
//	{
//		
//
//	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );
//
//	// Clear the color buffer
//	glClear ( GL_COLOR_BUFFER_BIT );
//		map->getCamera()->setScreenSize(esContext->width ,esContext->height); 
//
//	// Render map and all of its layers containing GameObjects to screen.
//	map->render();
//	}
//
// else if(GAME == 2)
//	{
//	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );
//
//	// Clear the color buffer
//	glClear ( GL_COLOR_BUFFER_BIT );
//		Retry->getCamera()->setScreenSize(esContext->width,esContext->height); 
//
//	// Render map and all of its layers containing GameObjects to screen.
//	Retry->render();
//	}
//
//else if(GAME == 3)
//	{
//	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );
//
//	// Clear the color buffer
//	glClear ( GL_COLOR_BUFFER_BIT );
//		death->getCamera()->setScreenSize(esContext->width,esContext->height); 
//
//	// Render map and all of its layers containing GameObjects to screen.
//death->render();
//	}
// else if(GAME == 4)
//	{
//	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );
//
//	// Clear the color buffer
//	glClear ( GL_COLOR_BUFFER_BIT );
//		how->getCamera()->setScreenSize(esContext->width,esContext->height); 
//
//	// Render map and all of its layers containing GameObjects to screen.
//	how->render();
//	}
//}
//
//
//int main ( int argc, char *argv[] )
//{
//	ESContext esContext;
//	esInitContext ( &esContext );
//
//	esCreateWindow( &esContext, "HANS UBER The SHEEP THIEF", 1920, 1080, ES_WINDOW_DEFAULT );
//	
//	if ( !init ( &esContext ) )
//		return 0;
//	
// 
//
//	esRegisterDrawFunc( &esContext, draw );
//	esRegisterUpdateFunc( &esContext, update );
//	esRegisterDeinitFunc( &esContext, deinit);
//
//	esMainLoop ( &esContext );
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
////// Include OpenGL ES Engine utils
////#include <es_util.h>
////// Include map class
////#include <Map.h>
////
////#include <TextGameObject.h>
////// Camera class
////#include <ctime>
////#include "Enemy.h"
////#include <Camera.h>
////#include <Tile.h>
////#include <Layer.h>
////#include <Input.h>
////#include <AnimatedSpriteGameObject.h>
//////#include <TextGameObject.h>
////#include "Player.h"
////#include "Lammas.h"
////
////using namespace yam2d;
////
////	int GAME = 0;
////	int PlayerStatus = 0;
////
////namespace
////{
////	
////	std::vector<Enemy*> lammas1;
////	std::vector<Enemy*> dog1;
////	//AnimatedSpriteGameObject* lammas = 0;
////	//AnimatedSpriteGameObject* dog = 0;
////	GameObject*  Laiva = 0;
////	// Pointer to TmxMap-object
////	TmxMap* map = 0;
////	TmxMap* menu = 0;
////	Player* player = 0;
////	Enemy* enemy = 0;	
////	Enemy* enemydog = 0;
////	Enemy* enemybag = 0;
////	// We need to use Ref-class (autopointer), so that we dont lose our object references when explosion is destroyed from the map.
////	Ref<Texture> texture = 0;
////	Ref<SpriteSheet> spriteSheet = 0; 
////	/*bool StartGame = false;*/
////	/*int pressReturn = 0;*/
////}
////// Tapaus Jossa Pelaajalla ei ole lammasta
////bool PlayerNoSheep(ESContext *esContext)
////{
////	{
////		{
////		
////	Texture* playerTexture = new Texture("HanswalkEmpty.png");
////	playerTexture->setTransparentColor(0xff,0x00,0xff);
////		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
////	
////player = new Player(0,spriteSheet,map);
////player -> setSize(64, 64);
////
////	int numClipsPerAnimation = 8;
////
////	float animationFrameRate = 8.0f;
////	for( int i=0; i<4; ++i )
////			{
////		std::vector<int> indices;
////		indices.resize(numClipsPerAnimation);
////		for( size_t j=0; j<indices.size(); ++j )
////				{
////			indices[j] = numClipsPerAnimation*i + j;
////				}
////
////		
////		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
////			}
////	
////	player->setActiveAnimation(0);
////		}
////	return true;
////	}	
////	player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );
////	
////	
////	map->getLayer("GameObjects")->addGameObject(player);
////
////}
////
////
//////Tapaus Jossa pelaajalla on lammas.
////bool PlayerHasSheep(ESContext *esContext)
////{
////	{
////	Texture* playerTexture = new Texture("HanswalkFull.png");
////		playerTexture->setTransparentColor(0xff,0x00,0xff);
////		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
////		
////
////		player = new Player(0,spriteSheet,map);
////		player -> setSize(64, 64);
////
////		int numClipsPerAnimation = 8;
////
////		float animationFrameRate = 8.0f;
////	
////		
////	for( int i=0; i<4; ++i )
////				
////					{
////		std::vector<int> indices;
////		indices.resize(numClipsPerAnimation);
////			for( size_t j=0; j<indices.size(); ++j )
////			
////						{
////			
////						indices[j] = numClipsPerAnimation*i + j;
////						}
////
////		
////		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
////				
////					}
////	return true;
////}
////	player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );
////	
////	
////	map->getLayer("GameObjects")->addGameObject(player);
////
////}
////
////
////bool StartUp(ESContext *esContext)
////{
////	{
////	menu = new TmxMap();
////	
////	// Load map file
////	if( !menu->loadMapFile("MainMenu.tmx") )
////		return false;
////	// Move gameobject to middle of map.
////	vec2 cameraPosM = vec2(menu->getWidth()/2.0f - 0.5f, menu->getHeight()/2.0f - 0.5f);
////	menu->getCamera()->setPosition( cameraPosM );
////	}
////		return true;
////}
////
////
////bool GameOn(ESContext *esContext)
////{
////	{
////		{
////	// Create new TmxMap object
////	map = new TmxMap();
////	
////	// Load map file
////	if( !map->loadMapFile("MapOne.tmx") )
////		return false;
////	// Move gameobject to middle of map.
////	vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
////	map->getCamera()->setPosition( cameraPos );
////
////
////	
////	
////	Laiva = new GameObject(1, map->getLayer("Laiva")->getGameObjects()[0]->getPosition(), map->getLayer("Laiva")->getGameObjects()[0]->getSize());
////	
////	
////
////	
////
////
////		
////	
//// //Luodaan Koira 
//
//// 
//// 
////
////
////
////
////	 //luodaan kaksitoista lammasta jotka saavat satunnaiset waypointit.
////	
////for (int i = 0; i <12; i++)
////{
////	/* Add enemy to map layer named "GameObjects".*/
////	{
////
////		Texture* enemyTexture = new Texture("sheep.png");
////		enemyTexture->setTransparentColor(0xff,0x00,0xff);
////		spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,256,0,0);
////		
////		/*Create new player.*/
////		enemy = new Enemy(0,spriteSheet,player);
////		enemy -> setSize(64,64 );
////		int numClipsPerAnimation = 4;
////
////		float animationFrameRate =4.0f;
////
////		for( int i=0; i<4; ++i )
////	{
////		std::vector<int> indices;
////		indices.resize(numClipsPerAnimation);
////		for( size_t j=0; j<indices.size(); ++j )
////		{
////			indices[j] = numClipsPerAnimation*i + j;
////		}
////
////		// Add looping animation.
////		enemy->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
////	}
////
////
////	enemy->setActiveAnimation(0);
////
////	enemy->setPosition( map->getLayer("Lammas_Objects")->getGameObjects()[i]->getPosition());
////		map->getLayer("GameObjects")->addGameObject(enemy);
////		
////		// Add some waypoints for enemy.
////		std::vector<vec2> enemyWaypoints;
////	int index = 0;
////	for (index = 0; index < 100; index++)
////	{
////		
////		
////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
////	/*	esLogMessage("lammas waypoint locations");
////		for (int i = 0; i < enemyWaypoints.size(); ++i) {
////			esLogMessage("WP x: %f, y: %f", enemyWaypoints[i].x, enemyWaypoints[i].y);
////		}*/
////	}
////		enemy->setWayoints(enemyWaypoints);
////		
////	}
////
////	lammas1.push_back(enemy);
////}
////	}
////
////	return true;
////	
////}
////
//////// Initialize the game
//////bool init ( ESContext *esContext )
//////{
//////	//
//////	//if (!StartGame)
//////	//{
//////	//// Create new TmxMap object
//////	//map = new TmxMap();
//////	//
//////	//// Load map file
//////	//if( !map->loadMapFile("MainMenu.tmx") )
//////	//	return false;
//////	//// Move gameobject to middle of map.
//////	//vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//////	//map->getCamera()->setPosition( cameraPos );
//////
//////	//}
//////	
//////	else	if(StartGame)
//////{	
//////
//////	{
//////		delete map;
//////	// Create new TmxMap object
//////	map = new TmxMap();
//////	
//////	// Load map file
//////	if( !map->loadMapFile("MapOne.tmx") )
//////		return false;
//////	// Move gameobject to middle of map.
//////	vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//////	map->getCamera()->setPosition( cameraPos );
//////
//////
//////	
//////	
//////	Laiva = new GameObject(1, map->getLayer("Laiva")->getGameObjects()[0]->getPosition(), map->getLayer("Laiva")->getGameObjects()[0]->getSize());
//////	
//////	{
//////
//////		
//////	Texture* playerTexture = new Texture("HanswalkEmpty.png");
//////	playerTexture->setTransparentColor(0xff,0x00,0xff);
//////		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
//////		
//////player = new Player(0,spriteSheet,map);
//////player -> setSize(64, 64);
//////
//////	int numClipsPerAnimation = 8;
//////
//////	float animationFrameRate = 8.0f;
//////	for( int i=0; i<4; ++i )
//////	{
//////		std::vector<int> indices;
//////		indices.resize(numClipsPerAnimation);
//////		for( size_t j=0; j<indices.size(); ++j )
//////		{
//////			indices[j] = numClipsPerAnimation*i + j;
//////		}
//////
//////		
//////		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//////	}
//////	
//////	player->setActiveAnimation(0);
//////	
//////	player->setPosition(map->getLayer("player.object")->getGameObjects()[0]->getPosition() );
//////	
//////	
//////	map->getLayer("GameObjects")->addGameObject(player);
//////
//////
//////
//////		
//////	}
////// //Luodaan Koira 
////// {
////// Texture* enemyTexture = new Texture("dogrun1.png");
//////	enemyTexture->setTransparentColor(0xff,0x00,0xff);
//////	spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,128,0,0);
//////	
//////	/*Create new player.*/
//////	enemydog = new Enemy(0,spriteSheet,player);
//////	enemydog -> setSize(64,64 );
//////	int numClipsPerAnimation = 4;
//////
//////	float animationFrameRate =8.0f;
//////
//////	for( int i=0; i<4; ++i )
//////{
//////	std::vector<int> indices;
//////	indices.resize(numClipsPerAnimation);
//////	for( size_t j=0; j<indices.size(); ++j )
//////	{
//////		indices[j] = numClipsPerAnimation*i + j;
//////	}
//////
//////	// Add looping animation.
//////	enemydog->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//////}
//////
//////
//////enemydog->setActiveAnimation(0);
//////
//////enemydog->setPosition( map->getLayer("susi")->getGameObjects()[0]->getPosition());
//////	map->getLayer("susi")->addGameObject(enemydog);
//////
//////		std::vector<vec2> enemyWaypoints;
//////	int index = 0;
//////	for (index = 0; index < 100; index++)
//////	{
//////		
//////		
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//////	/*	esLogMessage("lammas waypoint locations");
//////		for (int i = 0; i < enemyWaypoints.size(); ++i) {
//////			esLogMessage("WP x: %f, y: %f", enemyWaypoints[i].x, enemyWaypoints[i].y);
//////		}*/
//////	}
//////		enemydog->setWayoints(enemyWaypoints);
//////		
//////	}
//////
//////	dog1.push_back(enemydog);
//////}
////// 
////// 
//////
//////
//////
//////
//////	 //luodaan kaksitoista lammasta jotka saavat satunnaiset waypointit.
//////	
//////for (int i = 0; i <12; i++)
//////{
//////	/* Add enemy to map layer named "GameObjects".*/
//////	{
//////
//////		Texture* enemyTexture = new Texture("sheep.png");
//////		enemyTexture->setTransparentColor(0xff,0x00,0xff);
//////		spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,256,0,0);
//////		
//////		/*Create new player.*/
//////		enemy = new Enemy(0,spriteSheet,player);
//////		enemy -> setSize(64,64 );
//////		int numClipsPerAnimation = 4;
//////
//////		float animationFrameRate =4.0f;
//////
//////		for( int i=0; i<4; ++i )
//////	{
//////		std::vector<int> indices;
//////		indices.resize(numClipsPerAnimation);
//////		for( size_t j=0; j<indices.size(); ++j )
//////		{
//////			indices[j] = numClipsPerAnimation*i + j;
//////		}
//////
//////		// Add looping animation.
//////		enemy->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//////	}
//////
//////
//////	enemy->setActiveAnimation(0);
//////
//////	enemy->setPosition( map->getLayer("Lammas_Objects")->getGameObjects()[i]->getPosition());
//////		map->getLayer("GameObjects")->addGameObject(enemy);
//////		
//////		// Add some waypoints for enemy.
//////		std::vector<vec2> enemyWaypoints;
//////	int index = 0;
//////	for (index = 0; index < 100; index++)
//////	{
//////		
//////		
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) ); 
//////		enemyWaypoints.push_back( vec2((rand()%(50-1)+1),(rand()%(30-1)+1)) );
//////	/*	esLogMessage("lammas waypoint locations");
//////		for (int i = 0; i < enemyWaypoints.size(); ++i) {
//////			esLogMessage("WP x: %f, y: %f", enemyWaypoints[i].x, enemyWaypoints[i].y);
//////		}*/
//////	}
//////		enemy->setWayoints(enemyWaypoints);
//////		
//////	}
//////
//////	lammas1.push_back(enemy);
//////}
//////	}
//////
//////	return true;
//////	
//////
//////	}
////
////
////// Deinitialize the game
////
////
////void deinit ( ESContext *esContext )
////{/*
////	GameObject*  Laiva = 0;*/
////	texture = 0;
////	spriteSheet = 0; 
////	/*delete enemydog;
////	delete enemy;*/
////	// Delete map.
////	delete map;
////	delete menu;
////}
////
////void update( ESContext* ctx, float deltaTime )
////{
////	
////	vec2 cameraPosM =  vec2(menu->getWidth()/2.0f - 0.5f, menu->getHeight()/2.0f - 0.5f);
////	
////	menu->getCamera()->setPosition( cameraPosM );
////	// Update map. this will update all GameObjects inside a map layers.
////	menu->update(deltaTime);
////	
////	vec2 cameraPos =  vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
////	
////	map->getCamera()->setPosition( cameraPos );
////	// Update map. this will update all GameObjects inside a map layers.
////	map->update(deltaTime);
////
////
////
////	if( getKeyState(KEY_RETURN) )
////	{
////	
////	GAME = 1;
////	
////	}
////}
////// Update game
//////void update( ESContext* ctx, float deltaTime )
//////{
//////	float painettu = ((pressReturn == 0) &&getKeyState(KEY_RETURN));
//////
//////		if (float pelinalku = painettu)
//////	{
//////		StartGame = true;
//////		
//////	}
//////
//////	
//////	/*vec2 cameraPos = player->getPosition();*/
//////	vec2 cameraPos =  vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//////	
//////	map->getCamera()->setPosition( cameraPos );
//////	// Update map. this will update all GameObjects inside a map layers.
//////	map->update(deltaTime);
//////
//////
//////	//pelitilan tarkastus
//////	 if(StartGame)
//////	{
//////		
//////	//tˆrm‰ystarkistu laivalle jossa Haslammas arvo muuttuu falseksi
//////		if (player->HasLammas &&player->collidesTo(Laiva))
//////		{
//////
//////			
//////			vec2 tempPosition =  player->getPosition();
//////			float tempRotation = player->getRotation();
//////			map->deleteGameObject(player);
//////
//////	Texture* playerTexture = new Texture("HanswalkEmpty.png");
//////	playerTexture->setTransparentColor(0xff,0x00,0xff);
//////		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
//////		
//////player = new Player(0,spriteSheet,map);
//////player -> setSize(64, 64);
//////
//////	int numClipsPerAnimation = 8;
//////
//////	float animationFrameRate = 8.0f;
//////	for( int i=0; i<4; ++i )
//////			{
//////		
//////		std::vector<int> indices;
//////		indices.resize(numClipsPerAnimation);
//////		
//////		for( size_t j=0; j<indices.size(); ++j )
//////				{
//////			indices[j] = numClipsPerAnimation*i + j;
//////				}
//////
//////		
//////		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//////			}
//////	
//////	player->setActiveAnimation(0);
//////	player->setRotation(tempRotation);
//////	player->setPosition(tempPosition);
//////	
//////	
//////	map->getLayer("GameObjects")->addGameObject(player);
//////
//////
//////	for (int i = 0; i <12; ++i)
//////		{
//////	
//////			if	(player->HasLammas && player->collidesTo(Laiva) )
//////	/* Add enemy to map layer named "GameObjects".*/
//////			{
//////				player->HasLammas = false;
//////		Texture* enemyTexture = new Texture("sheepBag.png");
//////		enemyTexture->setTransparentColor(0xff,0x00,0xff);
//////		spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture,256,256,0,0);
//////		
//////		/*Create new player.*/
//////		enemybag = new Enemy(0,spriteSheet,player);
//////		enemybag -> setSize(32,32 );
//////		int numClipsPerAnimation = 4;
//////
//////		float animationFrameRate =8.0f;
//////
//////		for( int i=0; i<4; ++i )
//////				{
//////		std::vector<int> indices;
//////		indices.resize(numClipsPerAnimation);
//////		
//////		for( size_t j=0; j<indices.size(); ++j )
//////					{
//////			
//////						indices[j] = numClipsPerAnimation*i + j;
//////				
//////					}
//////	
//////		// Add looping animation.
//////		enemy->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//////				}	
//////
//////
//////	enemy->setActiveAnimation(0);
//////
//////	enemy->setPosition( map->getLayer("LammasPussi")->getGameObjects()[i]->getPosition());
//////		map->getLayer("GameObjects")->addGameObject(enemy);
//////		
//////			}
//////
//////		}
//////
//////	}
//////
//////	//tˆrm‰ystarkistus koiralle ja pelaajalle jos pelaaja tˆrm‰‰ koiraan pelaaja IsAlive muuttuu falseksi
//////	if (player->collidesTo(enemydog))
//////	{
//////
//////		map->deleteGameObject(player);
//////		player->IsAlive = false;
//////		{
//////	
//////		// Create new TmxMap object
//////	
//////			map = new TmxMap();
//////	
//////	// Load map file
//////			map->loadMapFile("DIE.tmx") ;		
//////	// Move gameobject to middle of map.
//////			vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
//////			map->getCamera()->setPosition( cameraPos );
//////	
//////		}
//////	}
//////
//////	//tapahtuu jos haslammas on false
//////	if (player->HasLammas==false)
//////		{
//////	
//////		//niin kauan kuin lampaita ritt‰‰
//////		for (int i = 0;i < 12 ;i++ )
//////			{
//////		if (player->collidesTo(lammas1[i]) )
//////				{
//////		
//////			//poistaa lammas objektin
//////		map->deleteGameObject(lammas1[i]);
//////		map->deleteGameObject(player);
//////		// arvo muuttuu todeksi
//////		player->HasLammas = true;
//////
//////		
//////		Texture* playerTexture = new Texture("HanswalkFull.png");
//////		playerTexture->setTransparentColor(0xff,0x00,0xff);
//////		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture,128,128,0,0); 
//////		
//////
//////		player = new Player(0,spriteSheet,map);
//////		player -> setSize(64, 64);
//////
//////		int numClipsPerAnimation = 8;
//////
//////		float animationFrameRate = 8.0f;
//////	
//////		
//////	for( int i=0; i<4; ++i )
//////				
//////					{
//////		std::vector<int> indices;
//////		indices.resize(numClipsPerAnimation);
//////			for( size_t j=0; j<indices.size(); ++j )
//////			
//////						{
//////			
//////						indices[j] = numClipsPerAnimation*i + j;
//////						}
//////
//////		
//////		player->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//////				
//////					}
//////	
//////	player->setActiveAnimation(0);
//////	player->setPosition(map->getLayer("GameObjects")->getGameObjects()[0]->getPosition() );
//////	
//////
//////	map->getLayer("GameObjects")->addGameObject(player);
//////
//////
//////				}
//////			}
//////		}
//////	}
//////}
////
////
////// Draw game
////void draw ( ESContext *esContext )
////{
////
////
////
////
////	
////	assert(PlayerStatus >= 0 && PlayerStatus <= 2);
////
////	switch (PlayerStatus)
////		{	
////	
////	case 1:
////		if (player->HasLammas == false)
////		{
////		PlayerNoSheep(esContext);
////		
////
////		break;
////		}
////	case 2:
////		if(player->HasLammas == true)
////		{
////		PlayerHasSheep(esContext);
////
////		break;
////		}
////
////	default:
////
////		break;
////		}
////
////
////
////	assert(GAME >= 0 && GAME <= 2);
////	
////	switch (GAME)
////		{
////	case 0:
////		
////		StartUp(esContext);
////			// Set OpenGL clear color (dark gray)
////	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );
////
////	// Clear the color buffer
////	glClear ( GL_COLOR_BUFFER_BIT );
////		menu->getCamera()->setScreenSize(esContext->width,esContext->height); 
////
////	// Render map and all of its layers containing GameObjects to screen.
////		menu->render();
////		break;
////		
////	case 1:
////		
////		GameOn(esContext);
////			// Set OpenGL clear color (dark gray)
////	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );
////
////	// Clear the color buffer
////	glClear ( GL_COLOR_BUFFER_BIT );
////		map->getCamera()->setScreenSize(esContext->width,esContext->height); 
////
////	// Render map and all of its layers containing GameObjects to screen.
////	map->render();
////		break;
////
////	
////	default:
////	
////		
////		break;
////	}
////	// Set OpenGL clear color (dark gray)
////	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );
////
////	// Clear the color buffer
////	glClear ( GL_COLOR_BUFFER_BIT );
////
////	
////}
////
////
////int main ( int argc, char *argv[] )
////{
////	ESContext esContext;
////	esInitContext ( &esContext );
////	esCreateWindow( &esContext, "HANS UBER The SHEEP THIEF", 1920, 1080, ES_WINDOW_DEFAULT );
////
////	//if ( !init ( &esContext ) )
////	//	return 0;
////	
////	if ( !StartUp ( &esContext ) )
////		return 0;
////
////	if ( !GameOn ( &esContext ) )
////		return 0;
////
////	esRegisterDrawFunc( &esContext, draw );
////	esRegisterUpdateFunc( &esContext, update );
////	esRegisterDeinitFunc( &esContext, deinit);
////
////	esMainLoop ( &esContext );
////	return 0;
////}
//
//
//
//
//
//
//
