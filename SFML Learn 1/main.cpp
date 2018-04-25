#include <SFML\Graphics.hpp>
#include "Platform.h"
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1080,720), "Window", sf::Style::Close | sf::Style::Titlebar); //defining size, name, and stles of the window
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f)); // creates shape of 100 by 100
	Player player(0, 0);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));
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
		
		view.setCenter(player.getPosition() + sf::Vector2f(player.getHeight() / 2, player.getWidth() / 2)); // sets a view to follow the player

		window.clear(); // clears window
		window.setView(view); // set view on the the screen

		player.updatePlayer(window);

		//drawing section
		player.draw(window);
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