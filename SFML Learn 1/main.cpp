#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Platform.h"
#include "Player.h"
#include "Level.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280,720), "Window", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen); //defining size, name, and stles of the window
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f)); // creates shape of 100 by 100
	Player player(2, 7);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280.0f, 720.0f));
	Level *startingScreen = new Level(&homeScreen, STARTY, STARTX);
	Level *level = new Level(&level1, dimX, dimY);
	sf::Clock clock;
	sf::Time refreshRate = sf::microseconds(1500);
	sf::Mouse mouse;
	sf::Vector2i mousePos = mouse.getPosition();

	//start buttons
	sf::RectangleShape startButton(sf::Vector2f(1006.0f, 156.0f));
	sf::RectangleShape optoinButton(sf::Vector2f(1006.0f, 156.0f));
	sf::RectangleShape exitButton(sf::Vector2f(1006.0f, 156.0f));

	sf::IntRect startButtonInt(137, 64, 1006, 156);
	sf::IntRect optoinButtonInt(137, 282, 1006, 156);
	sf::IntRect exitButtonInt(137, 500, 1006, 156);

	sf::Texture t_startButton;
	sf::Texture t_optoinButton;
	sf::Texture t_exitButton;

	sf::Texture t_startButtonHovered;
	sf::Texture t_optoinButtonHovered;
	sf::Texture t_exitButtonHovered;

	t_startButton.loadFromFile("Assets/Play Button.png");
	t_optoinButton.loadFromFile("Assets/Options Button.png");
	t_exitButton.loadFromFile("Assets/Exit Button.png");

	t_startButtonHovered.loadFromFile("Assets/Play Button Hovered.png");
	t_optoinButtonHovered.loadFromFile("Assets/Options Button Hovered.png");
	t_exitButtonHovered.loadFromFile("Assets/Exit Button Hovered.png");

	startButton.setPosition(sf::Vector2f(137.0f, 64.0f));
	startButton.setTexture(&t_startButton);

	optoinButton.setPosition(sf::Vector2f(137.0f, 282.0f));
	optoinButton.setTexture(&t_optoinButton);

	exitButton.setPosition(sf::Vector2f(137.0f, 500.0f));
	exitButton.setTexture(&t_exitButton);
	

	bool startScreen = true;

	while (window.isOpen()) { //main game loop
		mousePos = mouse.getPosition();
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
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.close();
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
			if (startButtonInt.contains(mousePos)) {
				startButton.setTexture(&t_startButtonHovered);
				if (mouse.isButtonPressed(sf::Mouse::Button::Left)) {
					startScreen = false;
				}
			}
			else {
				startButton.setTexture(&t_startButton);
			}

			if (optoinButtonInt.contains(mousePos)) {
				optoinButton.setTexture(&t_optoinButtonHovered);
			}
			else {
				optoinButton.setTexture(&t_optoinButton);
			}

			if (exitButtonInt.contains(mousePos)) {
				exitButton.setTexture(&t_exitButtonHovered);
				if (mouse.isButtonPressed(sf::Mouse::Button::Left)) {
					window.close();
				}
			}
			else {
				exitButton.setTexture(&t_exitButton);
			}
			window.draw(startButton);
			window.draw(optoinButton);
			window.draw(exitButton);
			window.display();
			window.clear(sf::Color::Red);
		}
	}

	delete level;

	return 0;
}