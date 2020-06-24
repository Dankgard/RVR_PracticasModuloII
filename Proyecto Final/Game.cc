#include "Game.h"
#include <string>

Game::Game(int16_t x1,int16_t y1, int16_t x2, int16_t y2){
    player1 = new Player(x1,y1,1);
    player2 = new Player(x2,y2,2);
}

void Game::to_bin(){
    size_t bSize= bullets.size() * sizeof(int16_t) * 3;
    size_t aSize= asteroids.size() * sizeof(int16_t) * 3;
    alloc_data(SIZE + bSize + aSize);
    char * d = _data;
    
    memcpy(d, &player1->_x, sizeof(int16_t));                                          
    d += sizeof(int16_t);
    memcpy(d, &player1->_y, sizeof(int16_t));                                          
    d += sizeof(int16_t);
    memcpy(d, &player1->_lives, sizeof(int16_t));                                          
    d += sizeof(int16_t);

    memcpy(d, &player2->_x, sizeof(int16_t));                                          
    d += sizeof(int16_t);
    memcpy(d, &player2->_y, sizeof(int16_t));                                          
    d += sizeof(int16_t);
    memcpy(d, &player2->_lives, sizeof(int16_t));                                          
    d += sizeof(int16_t);

    int16_t tamBullet = bullets.size();
    memcpy(d, &tamBullet, sizeof(int16_t));	

    for (int i = 0; i < bullets.size(); i++) {
        d += sizeof(int16_t); 
        memcpy(d, &bullets[i]._x, sizeof(int16_t));
        d += sizeof(int16_t); 
        memcpy(d, &bullets[i]._y, sizeof(int16_t));
        d += sizeof(int16_t); 
        memcpy(d, &bullets[i]._nPlayer, sizeof(int16_t));
    }

    d += sizeof(int16_t);
    int16_t tamAsteroid = asteroids.size();
    memcpy(d, &tamAsteroid, sizeof(int16_t));

    for (int i = 0; i < asteroids.size(); i++) {
        d += sizeof(int16_t); 
        memcpy(d, &asteroids[i]._x, sizeof(int16_t));
        d += sizeof(int16_t); 
        memcpy(d, &asteroids[i]._y, sizeof(int16_t));
        d += sizeof(int16_t); 
        memcpy(d, &asteroids[i]._velY, sizeof(int16_t));
    }
}

int Game::from_bin(char * bobj){
    memcpy(&player1->_x, bobj, sizeof(int16_t));
    bobj += sizeof(int16_t);
    memcpy(&player1->_y, bobj, sizeof(int16_t));
    bobj += sizeof(int16_t);
    memcpy(&player1->_lives, bobj, sizeof(int16_t));
    bobj += sizeof(int16_t);
    memcpy(&player2->_x, bobj, sizeof(int16_t));
    bobj += sizeof(int16_t);
    memcpy(&player2->_y, bobj, sizeof(int16_t));
    bobj += sizeof(int16_t);
    memcpy(&player2->_lives, bobj, sizeof(int16_t));
    bobj += sizeof(int16_t);

    int16_t t;
    memcpy(&t, bobj, sizeof(int16_t));	
    bullets.clear();
    for (int i = 0; i < t; i++) {
        int16_t _x;
        int16_t _y;
        int16_t _nPlayer;
        bobj += sizeof(int16_t); 
        memcpy(&_x, bobj, sizeof(int16_t));
        bobj += sizeof(int16_t); 
        memcpy(&_y, bobj, sizeof(int16_t));
        bobj += sizeof(int16_t); 
        memcpy(&_nPlayer, bobj, sizeof(int16_t));
        Bullet bull(_x, _y, _nPlayer);
        bullets.push_back(bull);
    }

    bobj += sizeof(int16_t); 
    int16_t tamAsteroid;
    memcpy(&tamAsteroid, bobj, sizeof(int16_t));
    asteroids.clear();

    for (int i = 0; i < tamAsteroid; i++) {
        int16_t _x;
        int16_t _y;
        int16_t _velY;
        bobj += sizeof(int16_t); 
        memcpy(&_x, bobj, sizeof(int16_t));
        bobj += sizeof(int16_t); 
        memcpy(&_y, bobj, sizeof(int16_t));
        bobj += sizeof(int16_t); 
        memcpy(&_velY, bobj, sizeof(int16_t));
        Asteroid ast(_x, _y ,_velY);
        asteroids.push_back(ast);
    }

    return 0;
}

void Game::createBullet(int16_t nPlayer)
{
	if (nPlayer == 1){
		Bullet bullet(player1->_x + 50, player1->_y + 30, nPlayer);
        bullets.push_back(bullet);
    }
	else{
        Bullet bullet2(player2->_x, player2->_y + 30, nPlayer);
        bullets.push_back(bullet2);
    }	
}

void Game::createAsteroid()
{
	Asteroid asteroid (400, 200, 1);
	asteroids.push_back(asteroid);
}

