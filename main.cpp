#include <SFML/Graphics.hpp>

int main()
{
	// Create Window frame 
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	// Draw players rectangle 
	sf::RectangleShape rect(sf::Vector2f(10,50));
	rect.setFillColor(sf::Color::White);

	// Draw squares player needs to jump over 
	sf::RectangleShape box(sf::Vector2f(20, 20));
	box.setFillColor(sf::Color::Red);

	// Set rectangle in a random place inside the window 
	// The very bottom of the window will be treated as the "ground"
	rect.setPosition(150, 450);

	// Squares position initially offscreen and will be moved to the left towards the player 
	box.setPosition(550, 480);

	// while loop, where game code begins controlling the "physics" and other events happening 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// If spacebar is pressed, jump up 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			rect.move(0, -0.2);
		}

		//Gravity for when jumping up
		if (rect.getPosition().y < 450)
			rect.move(0, 0.05);
		

		else if (rect.getPosition().y <= 0)
			rect.setPosition(rect.getPosition().x, 0);

		// Move box to left towards player 
		box.move(-0.03, 0);

		if (box.getPosition().x < 0) {
			box.setPosition(550, 480);
		}

		window.clear();
		window.draw(rect);
		window.draw(box);
		window.display();
	}

	return 0;
}
