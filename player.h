/*
	Player class Header File
*/

#ifndef PLAYER_H
#define PLAYER_H




class Player{

public:
	Player();
	
	void init();
	void animate(float dt);
	void draw();
};

#endif