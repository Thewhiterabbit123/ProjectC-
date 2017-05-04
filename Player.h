#ifndef PLAYER_H
#define PLAYER_H

class Player {
	private:
		Car* m_car;
		std::vector<int> m_score;
	public:
		Player();
		~Player();
	
};

#endif