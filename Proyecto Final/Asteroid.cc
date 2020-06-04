#include "Asteroid.h"

Asteroid::Asteroid(int vY){
    _x = 400;
    _y = 200; //Posicion en y alzar

	_velX = 0;
    _velY = vY;
}

XLDisplay& Asteroid::render(){
    XLDisplay& disp = XLDisplay::display();
    disp.set_color(XLDisplay::BROWN);
    disp.circle(_x, _y, 10);
    return disp;
}

void Asteroid::move()
{
	_x += _velX;
	_y += _velY;
}

void bulletCollision(int nPlayer, int vX)
{
	if(nPlayer == 1)
        _velX = vX;
    else if(nPlayer == 2)
        _velX = -vX;
}