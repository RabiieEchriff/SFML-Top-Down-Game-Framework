#include "Animator.h"

void animation::animate() {
	m_time1 = m_timer.accumulate_time();
	m_time2 = m_time2 + m_time1;

	frame_selector = m_time2 / m_frame_duration;

	m_sprite.setTextureRect(sf::IntRect(m_rect.width * frame_selector, m_rect.height * row, m_rect.width, m_rect.height));
	if (m_time2 > full_duration / m_rows_and_columns.y && row != m_rows_and_columns.y - 1) {
		m_time2 = 0;
		row++;
	}
	if (m_time2 > full_duration / m_rows_and_columns.y && row == m_rows_and_columns.y - 1) {
		m_time2 = 0;
		row = 0;
	}
	
}

void animation::animate_once() {
	m_time1 = m_timer.accumulate_time();
	m_time2 = m_time2 + m_time1;

	frame_selector = m_time2 / m_frame_duration;

	m_sprite.setTextureRect(sf::IntRect(m_rect.width * frame_selector, m_rect.height * row, m_rect.width, m_rect.height));
	if (m_time2 > full_duration / m_rows_and_columns.y && row != m_rows_and_columns.y - 1) {
		m_time2 = 0;
		row++;
	}
}

