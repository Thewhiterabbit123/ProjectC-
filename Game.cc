#include "Game.h"
#include <iostream>
#include "Globals.h"


FooDraw::FooDraw() {

}

FooDraw::~FooDraw() {}

void FooDraw::setWindow (sf::RenderWindow *window) {
	this->window = window;
	std::cout << "SET\n";
}

void FooDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	sf::ConvexShape polygon;
	polygon.setPointCount(vertexCount);
	for (int32 i=0; i<vertexCount; i++) {
		b2Vec2 vertex = vertices[i];
		polygon.setPoint(i, sf::Vector2f(vertex.x*RATIO, vertex.y*RATIO));
	}
	//polygon.SetOutlineWidth(1.0f);
	//polygon.EnableFill(false);
	this->window->draw(polygon);
	std::cout << "DrawPolygon";

}


void FooDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	sf::ConvexShape polygon;
	polygon.setPointCount(vertexCount);
	for (int32 i=0; i<vertexCount; i++) {
		b2Vec2 vertex = vertices[i];
		polygon.setPoint(i, sf::Vector2f(vertex.x*RATIO, vertex.y*RATIO));
	}

	//polygon.SetOutlineWidth(1.0f);
	//polygon.EnableFill(false);
	this->window->draw(polygon);
	//std::cout << "DrawPolygon";

}

sf::Color FooDraw::B2SFColor(const b2Color &color, int alpha) {
	sf::Color result((sf::Uint8)(color.r*255), (sf::Uint8)(color.g*255), (sf::Uint8)(color.b*255), (sf::Uint8) alpha);
	return result;
}

void Game::setWall(float x, float y, float w, float h, float angle){
	b2BodyDef bodyDef;
	bodyDef.position.Set(0, 0);
	m_groundBody = m_world->CreateBody( &bodyDef );

	b2PolygonShape polygonShape;
	b2FixtureDef fixtureDef;
  	fixtureDef.shape = &polygonShape;
   	fixtureDef.isSensor = false;

   	polygonShape.SetAsBox( w/2/RATIO, h/2/RATIO, b2Vec2((x+w/2)/RATIO, (y+h/2)/RATIO), angle);
	m_groundBody->CreateFixture(&fixtureDef);

}

void Game::setWalls() {

   	setWall(88,232,32,1368,0);
   	setWall(204,298,33,1261,0);

   	setWall(192,154,461,13,0);
   	setWall(253,259,370,16,0);

   	setWall(629,288,12,965,0);
   	setWall(735,248,11,968,0);

   	setWall(738,1343,193,16,0);
   	setWall(768,1235,134,13,0);

   	setWall(902,841,18,399,0);
   	setWall(1014,726,215,18,0);

   	setWall(1005,869,30,394,0);
   	setWall(1055,833,145,15,0);

   	setWall(1323,846,31,680,0);
   	setWall(1232,875,6,609,0);

   	setWall(198,1700,949,27,0);
   	setWall(257,1569,859,35,0);

   	//diagonal
   	b2BodyDef bodyDef;
	bodyDef.position.Set(0, 0);
	m_groundBody = m_world->CreateBody( &bodyDef );

	b2PolygonShape polygonShape;
	b2FixtureDef fixtureDef;
  	fixtureDef.shape = &polygonShape;
   	fixtureDef.isSensor = false;

   	std::cout << "****" << DIST(88,232,192,154) << "*****\n" ;

   	polygonShape.SetAsBox( DIST(88,232,192,154)/2/RATIO, 5/RATIO,  b2Vec2((MID(88,192)+20)/RATIO, MID(232,154)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(204,298,253,259)/2/RATIO, 5/RATIO,  b2Vec2((MID(204,253)+10)/RATIO, (MID(298,259)+5)/RATIO), -45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(653,141,735,248)/2/RATIO, 5/RATIO,  b2Vec2((MID(653,735))/RATIO, (MID(141,248)+5)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(623,259,629,288)/2/RATIO, 5/RATIO,  b2Vec2((MID(623,629)+2)/RATIO, (MID(259,288)+5)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( DIST(629,1594,738,1343)/2/RATIO, 5/RATIO,  b2Vec2((MID(629,738)+2)/RATIO, (MID(1594,1343)+5)/RATIO), 45*DEGTORAD);
	m_groundBody->CreateFixture(&fixtureDef);
   //	setWall(88,170,130,2,-45*DEGTORAD);
   //	setWall(257,1569,859,35);



	/*polygonShape.SetAsBox( 5.0f/RATIO, 150.0f/RATIO, b2Vec2(130.0f/RATIO,400.0f/RATIO), 0 );
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( 2000/RATIO, 10.0f/RATIO, b2Vec2(350.0f/RATIO,600.0f/RATIO), 0 );
	m_groundBody->CreateFixture(&fixtureDef);

	polygonShape.SetAsBox( 2000/RATIO, 100.0f/RATIO );
	m_groundBody->CreateFixture(&fixtureDef);*/
}

Game::Game(sf::RenderWindow* window): m_window(window) {
	m_world = new b2World(b2Vec2(0,0));
	m_world->SetGravity( b2Vec2(0,0) );

	player.setCar(m_world);
	
	m_tBackGround.loadFromFile("./Staff/background.png");
	m_tBackGround.setSmooth(true);
	m_sBackGround.setTexture(m_tBackGround);
	//m_sBackGround.setTextureRect( IntRect())
	m_sBackGround.scale(1,1);
	m_controlState = 0;

   // if (!buffer.loadFromFile("./Staff/lol.ogg"))
        ;//обработать

    sound.setBuffer(buffer);

  //  if (!music.openFromFile("./Staff/skyrim.ogg"))
        ;//o,hf,fnfnm
    //    music.play();

    m_debugDraw.SetFlags(b2Draw::e_shapeBit);
    m_debugDraw.setWindow(m_window);
    m_world->SetDebugDraw(&m_debugDraw);
    setWalls();

}

void Game::keyPressed() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->keyboard('A');
    } else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (m_controlState & LEFT)) {
    		this->keyboardUp('A');
	 	}
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  {
        this->keyboard('D');
    } else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (m_controlState & RIGHT))  {
    		this->keyboardUp('D');
		}
    }
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  { 
        this->keyboard('W'); 
        sound.play();
    } else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (m_controlState & UP))  { 
    		this->keyboardUp('W'); 
            //sound.stop();
		}
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  { 
        this->keyboard('S');
    } else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (m_controlState & DOWN))  { 
    		this->keyboardUp('S');
		}
    }    
}

b2World* Game::getWorld() {
	return m_world;
}

Player Game::getPlayer() {
	return player; 
}

void Game::checkBorders(float x, float y) {
	sf::View view(sf::FloatRect(0, 450, 1280, 720));
	m_window->setView(view);

	if (x*RATIO <=160 && y*RATIO <= 446) {
		view.move(0, -446);
		m_window->setView(view);
		std::cerr << "1\n";
		return;
	}

	if (x*RATIO >= 320 && y*RATIO <= 446) {
 		view.move(320-160,-446);
 		m_window->setView(view);
 		std::cerr << "2\n";
 		return;
 	}

 	if (y*RATIO >= 1550 && x*RATIO >= 320) {
		view.move(320-160, 654);
		m_window->setView(view);
		std::cerr << "3";
		return;
	}

	if (x*RATIO <= 160 && y*RATIO >= 1550 ) {
		view.move(0, 654);
		m_window->setView(view);
		std::cerr << "4\n";
		return;
	}

	if (y*RATIO <= 446) {
		view.move(x*RATIO-XPOS,-446);
		m_window->setView(view);
		std::cerr << "5\n";
		return;
	}


	if (x*RATIO >= 320 && y*RATIO<1550) {
		view.move(320-160,y*RATIO-YPOS);
		m_window->setView(view);
		std::cerr << "6\n";
		return;
	}


	if (y*RATIO >= 1550) {
		view.move(x*RATIO-XPOS,654);
		m_window->setView(view);
		std::cerr << "7";
		return;
	}

	if (x*RATIO <= 160) {
		view.move(0, y*RATIO-YPOS);
		m_window->setView(view);
		std::cerr << "8";
		return;
	}


	view.move(x*RATIO-XPOS,y*RATIO-YPOS);
	m_window->setView(view);


}

void Game::step() {

	Car* Car = player.getCar();
	
	sf::Sprite sCar = Car->getSprite();
	sCar.setOrigin(CAR_WIDTH/2, CAR_HEIGHT/2);
	
	b2Vec2 vec = Car->getBody()->GetPosition();
	float angle = Car->getBody()->GetAngle();
 

 	//std::cout << vec.x*RATIO << " " << vec.y*RATIO << std::endl;

 	checkBorders(vec.x, vec.y); //проверяет на выход за границы карты (белые полосы по краям убирает)

	m_window->draw(m_sBackGround);
	m_world->DrawDebugData();

	keyPressed();
	Car->update(m_controlState);

	sCar.setRotation(angle*RADTODEG);
	sCar.setPosition(vec.x*RATIO, vec.y*RATIO);

	m_window->draw(sCar);
	std::vector<Tire*> tires = Car->getTires();
	for(int i = 0; i < tires.size(); i++) {
		sf::Sprite sTire = tires[i]->getSprite();
		sTire.setOrigin(TIRE_WIDTH/2, TIRE_HEIGHT/2);
		vec = tires[i]->getBody()->GetPosition();
		angle = tires[i]->getBody()->GetAngle();
		sTire.setRotation(angle*RADTODEG);
		sTire.setPosition(vec.x*RATIO,vec.y*RATIO);
		m_window->draw(sTire);
	}
}

void Game::keyboard(const char key) {
    switch (key) {
        case 'A' : m_controlState |= LEFT; break;
        case 'D' : m_controlState |= RIGHT; break;
        case 'W' : m_controlState |= UP; break;
        case 'S' : m_controlState |= DOWN; break;
    }
}

void Game::keyboardUp(const char key) {
    switch (key) {
        case 'A' : m_controlState &= ~LEFT; break;
        case 'D' : m_controlState &= ~RIGHT; break;
        case 'W' : m_controlState &= ~UP; break;
        case 'S' : m_controlState &= ~DOWN; break;
    }
}