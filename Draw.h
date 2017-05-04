#ifndef DRAW_H
#define DRAW_H

class Draw {
private:
	sf::RenderWindow m_window*;
public:
	Draw(sf::RenderWindow window*);
	~Draw();
	Step();
};

#endif