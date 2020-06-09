#include "Player.h"

Player::Player(int16_t x, int16_t y, int16_t nPlayer){
    _x = x;
    _y = y;
	_nPlayer = nPlayer;
}

XLDisplay& Player::render(){
    XLDisplay& disp = XLDisplay::display();
    if(_nPlayer==1)
        disp.set_color(XLDisplay::BLUE);
    else
        disp.set_color(XLDisplay::RED);

    disp.rectangle(_x, _y, 50, 75);
    return disp;
}

void Player::shoot(){
    if(_nPlayer == 1)
        std::cout << "Disparo: " << _x << " " << _y << " speed: " << "5" "\n";
    else if(_nPlayer == 2)
        std::cout << "Disparo: " << _x << " " << _y << " speed: " << "-5" "\n";
}

void Player::move(int16_t y){
    if(_y > 0 && _y < 400)
        _y += y;    
}