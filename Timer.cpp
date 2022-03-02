#include "Timer.h"

float timer::accumulate_time() {
	sf::Time elapsed_time;
	sf::Time delta_time;

	float dt_seconds;

	delta_time = clock0.restart();
	elapsed_time += delta_time;

	dt_seconds = delta_time.asSeconds();



	return dt_seconds;
}