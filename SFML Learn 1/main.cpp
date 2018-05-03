#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Platform.h"
#include "Player.h"
#include "Level.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1080,720), "Window", sf::Style::Close | sf::Style::Titlebar); //defining size, name, and stles of the window
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f)); // creates shape of 100 by 100
	Player player(2, 7);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));
	Level *level = new Level(&level1, dimX, dimY);
	

	while (window.isOpen()) { //main game loop
		if (player.getPlayerHealth() <= 0.0f) {
			delete level;
			level = new Level(&level1, dimX, dimY);
			player.Reset(2, 7);
		}
		sf::Event evnt; //defines event
		while(window.pollEvent(evnt)) { //when the window gets an event
			
			if (evnt.type == evnt.Closed) { //when 'x' is pressed in the corner
				window.close(); //closes the window
			}

		}
		
		 // sets a view to follow the player

		
		window.setView(view); // set view on the the screen

		bool detectCollision = false;
		
		for (int i = 0; i < level->plats.size(); i++) {
			level->plats[i].detectCollision(player);
			level->plats[i].hurtPlayer(player);

		}
		for (int i = 0; i < level->plats.size(); i++) {
			bool isColliding;
			isColliding = level->plats[i].detectCollisionTop(player);
			
			if (isColliding == true) {

				detectCollision = true;
				std::cout << "touching";
				break;
			}

		}

		player.updatePlayer(window, detectCollision);
	
	
		view.setCenter(player.getPosition() + sf::Vector2f(player.getHeight() / 2, player.getWidth() / 2));
		//drawing section
		player.draw(window);
		for (int i = 0; i < level->plats.size(); i++) {
			level->plats[i].draw(window);

		}
		
		
		player.drawHealthBar(window, view);
		window.display(); // updates the screen with the buffer screen
		window.clear(); // clears window
	}

	delete level;

	return 0;
}