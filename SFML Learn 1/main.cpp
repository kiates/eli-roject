#include <SFML\Graphics.hpp>
#include "Platform.h"
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1080,720), "Window", sf::Style::Close | sf::Style::Titlebar); //defining size, name, and stles of the window
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f)); // creates shape of 100 by 100
	Player player(0, 0);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));
	player.setFillColor(sf::Color::Green); //sets color of rectangle
	Platform plat(4, 1);
	Platform plat2(3, 1);
	Platform plat3(2, 1);
	Platform plat4(1, 1);
	Platform plat5(0, 1);
	Platform plat6(-1, 1);

	while (window.isOpen()) { //main game loop

		sf::Event evnt; //defines event
		while(window.pollEvent(evnt)) { //when the window gets an event
			
			if (evnt.type == evnt.Closed) { //when 'x' is pressed in the corner
				window.close(); //closes the window
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) { // moves the player left when 'A' is pressed
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) { // moves the play right when 'D' is pressed
			player.move(0.1f, 0.0f);
		}
		
		view.setCenter(player.getPosition().x, player.getPosition().y); // sets a view to follow the player

		window.clear(); // clears window

		window.setView(view); // set view on the the screen

		//drawing section
		window.draw(player); 
		plat.draw(window);
		plat2.draw(window);
		plat3.draw(window);
		plat4.draw(window);
		plat5.draw(window);
		plat6.draw(window);

		window.display(); // updates the screen with the buffer screen

	}

	return 0;
}