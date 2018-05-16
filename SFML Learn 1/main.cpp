#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Platform.h"
#include "Player.h"
#include "Level.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280,720), "Window", sf::Style::Close | sf::Style::Titlebar); //defining size, name, and stles of the window
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f)); // creates shape of 100 by 100
	Player player(2, 7);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280.0f, 720.0f));
	Level *startingScreen = new Level(&homeScreen, STARTY, STARTX);
	Level *level = new Level(&level1, dimX, dimY);
	sf::Clock clock;
	sf::Time refreshRate = sf::microseconds(1500);

	//start buttons
	sf::RectangleShape startButton(sf::Vector2f(1006.0f, 156.0f));
	sf::RectangleShape optoinButton(sf::Vector2f(1006.0f, 156.0f));
	sf::RectangleShape exitButton(sf::Vector2f(1006.0f, 156.0f));

	sf::Texture t_startButton;
	sf::Texture t_optoinButton;
	sf::Texture t_exitButton;

	sf::Texture t_startButtonHovered;
	sf::Texture t_optoinButtonHovered;
	sf::Texture t_exitButtonHovered;

	t_startButton.loadFromFile("Assets/Start Button.png");
	t_optoinButton.loadFromFile("Assets/Option Button.png");
	t_exitButton.loadFromFile("Assets/Exit Button.png");

	t_startButtonHovered.loadFromFile("Assets/Start Button Hovered.png");
	t_optoinButtonHovered.loadFromFile("Assets/Option Button Hovered.png");
	t_exitButtonHovered.loadFromFile("Assets/Exit Button Hovered.png");

	startButton.setTexture(&t_startButton);
	startButton.setPosition(sf::Vector2f(100.0f, 100.0f));

	bool startScreen = false;

	while (window.isOpen()) { //main game loop
		clock.restart();
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
		if (startScreen == false) {
			view.setCenter(player.getPosition() + sf::Vector2f(player.getHeight() / 2, player.getWidth() / 2));
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



			//drawing section
			player.draw(window);
			for (int i = 0; i < level->plats.size(); i++) {
				level->plats[i].draw(window);

			}
			player.drawHealthBar(window, view);

			
			window.display(); // updates the screen with the buffer screen
			sf::Time elapsed = clock.getElapsedTime();
			while (elapsed < refreshRate) {
				elapsed = clock.getElapsedTime();
			}

			window.clear(); // clears window
		}
		else {
			window.draw(startButton);
			window.display();
			window.clear();
		}
	}

	delete level;

	return 0;
}