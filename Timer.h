#pragma once
#include <SFML/Graphics.hpp>

class timer {
public:
	sf::Clock clock0;

	float accumulate_time();

};