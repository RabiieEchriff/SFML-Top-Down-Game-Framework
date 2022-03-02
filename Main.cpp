#include "Window/Window.h"
#include "Animator.h"
#include "Timer.h"
#include <iostream>
#include <sstream>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	//handle events here

	ImGui::SFML::Init(w);

	char path[100] = { "res/mech.png" };
	float display_width = -220;
	float display_height = 188;
	int rect_left = 0;
	int rect_top = 0;
	int rect_width = 220;
	int rect_height = 188;
	int rows = 2;
	int columns = 3;
	float frame_duration = 0.09;
	float position_x = 680;
	float position_y = 100;

	std::vector<animation>animations;
	std::vector<sf::Texture>textures;
	animation anim1("res/explosion.png", { 150,150 }, { 0,0,64,64 }, { 5,5 }, 0.03);
	animations.push_back(anim1);
	textures.push_back(animations[0].m_tx);
	animations[0].m_sprite.setPosition(sf::Vector2f(100, 100));
	animation anim2("res/rockman.png", { 143,-137 }, { 0,0,143,137 }, { 3,2 }, 0.1);
	anim2.m_sprite.rotate(90);
	animations.push_back(anim2);
	textures.push_back(animations[1].m_tx);
	animations[1].m_sprite.setPosition(sf::Vector2f(300, 100));
	animation anim3("res/fire.png", { 64,128 }, { 0,0,64,128 }, { 8,4 }, 0.01);
	animations.push_back(anim3);
	textures.push_back(animations[2].m_tx);
	animations[2].m_sprite.setPosition(sf::Vector2f(500, 100));

	animation anim4;

	//handle events here
	sf::Clock deltaClock;
	while (w.isOpen()) {

		mw.close_window();

		ImGui::SFML::Update(w, deltaClock.restart());

		//update game logic here
		ImGui::Begin("Add Animation");

		ImGui::InputText("File Path", path, IM_ARRAYSIZE(path));
		ImGui::InputFloat("Display Width", &display_width);
		ImGui::InputFloat("Display Height", &display_height);
		ImGui::InputInt("First Frame X", &rect_left);
		ImGui::InputInt("First Frame Y", &rect_top);
		ImGui::InputInt("First Frame Width", &rect_width);
		ImGui::InputInt("First Frame Height", &rect_height);
		ImGui::InputInt("Rows", &rows);
		ImGui::InputInt("Columns", &columns);
		ImGui::InputFloat("Frame Duration", &frame_duration);
		ImGui::InputFloat("Position X", &position_x);
		ImGui::InputFloat("Position Y", &position_y);
		if (ImGui::Button("Add", { 40,20 })) {
			std::string p;
			std::stringstream pp;
			pp << path;
			pp >> p;
			anim4 = animation(p, { display_width,display_height }, { rect_left,rect_top,rect_width,rect_height }, { rows,columns }, frame_duration);
			
			animations.push_back(anim4);
			animations[animations.size() - 1].m_sprite.setPosition(sf::Vector2f(position_x, position_y));

			for (int i = 0; i < textures.size(); i++) {
				animations[i].m_tx = textures[i];
				animations[i].m_sprite.setTexture(animations[i].m_tx);
			}textures.push_back(animations[animations.size() - 1].m_tx);

		}
		ImGui::Text("NOTE: If the wrong texture is displayed, hit 'Add' again.");
		ImGui::End();
		
		for (int i = 0; i < animations.size(); i++) { animations[i].animate(); }
		//update game logic here

		w.clear();

		//draw objects here
		for (int i = 0; i < animations.size(); i++) { w.draw(animations[i].m_sprite); }
		//draw objects here

		ImGui::SFML::Render(w);
		w.display();
	}
	ImGui::SFML::Shutdown();
}





