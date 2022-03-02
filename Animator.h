#pragma once
#include <SFML/Graphics.hpp>
#include "Timer.h"

class animation {
public:
	sf::Sprite m_sprite;
	sf::Texture m_tx;
	std::string m_path;

	sf::IntRect m_rect;
	sf::Vector2i m_rows_and_columns;
	float m_frame_duration;
	float m_scale;

	timer m_timer;
	float m_time1;
	float m_time2=0;

	int row = 0;

	float frame_number = m_rows_and_columns.x * m_rows_and_columns.y;
	float full_duration = m_frame_duration * frame_number;
	int frame_selector;

	sf::Vector2f sprite_scale;
	sf::Vector2u original_size;
	sf::Vector2f texture_size;

	sf::Vector2f m_size;

	animation(sf::Texture tx, sf::Vector2f size, sf::IntRect rect, sf::Vector2i rows_and_columns, float frame_duration) :m_tx(tx), m_rect(rect), m_rows_and_columns(rows_and_columns), m_frame_duration(frame_duration) {
		m_sprite.setTexture(m_tx);

		m_sprite.setTextureRect(rect);

		original_size.x = m_sprite.getTextureRect().width;
		original_size.y = m_sprite.getTextureRect().height;
		texture_size.x = static_cast<float>(original_size.x);
		texture_size.y = static_cast<float>(original_size.y);
		sprite_scale.x = size.x / texture_size.x;
		sprite_scale.y = size.y / texture_size.y;

		m_sprite.setScale(sf::Vector2f(sprite_scale.x, sprite_scale.y));
		m_sprite.setOrigin(sf::Vector2f(original_size.x / 2, original_size.y / 2));

	}

	animation(std::string path, sf::Vector2f size, sf::IntRect rect, sf::Vector2i rows_and_columns, float frame_duration) :m_size(size), m_rect(rect), m_rows_and_columns(rows_and_columns), m_frame_duration(frame_duration) {
		m_tx.loadFromFile(path);
		m_sprite.setTexture(m_tx);

		m_sprite.setTextureRect(rect);

		original_size.x = m_sprite.getTextureRect().width;
		original_size.y = m_sprite.getTextureRect().height;
		texture_size.x = static_cast<float>(original_size.x);
		texture_size.y = static_cast<float>(original_size.y);
		sprite_scale.x = size.x / texture_size.x;
		sprite_scale.y = size.y / texture_size.y;

		m_sprite.setScale(sf::Vector2f(sprite_scale.x, sprite_scale.y));
		m_sprite.setOrigin(sf::Vector2f(original_size.x / 2, original_size.y / 2));

	}
	
	animation() {}
	

	void animate();
	void animate_once();

};