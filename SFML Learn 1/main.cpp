#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Platform.h"
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1080,720), "Window", sf::Style::Close | sf::Style::Titlebar); //defining size, name, and stles of the window
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f)); // creates shape of 100 by 100
	Player player(2, 0);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));
	Platform plat(4, 1);
	Platform plat2(3, 1);
	Platform plat3(2, 1);
	Platform plat4(1, 1);
	Platform plat5(0, 1);
	Platform plat6(-1, 1);
	Platform plat7(2, 0);
	std::vector <Platform> plats;
	plats.push_back(plat);
	plats.push_back(plat2);
	plats.push_back(plat3);
	plats.push_back(plat4);
	plats.push_back(plat5);
	plats.push_back(plat6);
	plats.push_back(plat7);
	bool detectCollision = false;

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

		for (int i = 0; i < plats.size(); i++) {
			bool isColliding;
			isColliding = plats[i].detectCollisionTop(player);
			if (isColliding == true) {
				player.updatePlayer(window, true);
				detectCollision = true;
			}

		}

		if (!detectCollision) {
			player.updatePlayer(window, false);
		}
		//player.updatePlayer(window, plat.detectCollisionTop(player));
		//player.updatePlayer(window, plat2.detectCollisionTop(player));
		//player.updatePlayer(window, plat2.detectCollisionTop(player));
		//player.updatePlayer(window, plat3.detectCollisionTop(player));
		//player.updatePlayer(window, plat5.detectCollisionTop(player));
		//player.updatePlayer(window, plat6.detectCollisionTop(player));
		//player.updatePlayer(window, plat7.detectCollisionTop(player));

		//drawing section
		player.draw(window);
		plat.draw(window);
		plat2.draw(window);
		plat3.draw(window);
		plat4.draw(window);
		plat5.draw(window);
		plat6.draw(window);
		plat7.draw(window);
		plat7.detectCollision(player);


		window.display(); // updates the screen with the buffer screen

		detectCollision = false;
	}

	return 0;
}