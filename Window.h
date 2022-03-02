#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

extern sf::RenderWindow w;
extern sf::Event e;

class window_methods {
public:
	void close_window();
};

extern window_methods mw;
