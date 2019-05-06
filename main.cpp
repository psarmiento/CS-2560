/*
	TO DO: 
		- Update player lives 
		- Work on limited # of jumps 
		- Possibly adding in another box after certain speed 
			has been reached 
		
	Tweaks:
		- Speed of box? -> max speed of box 

*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

double boxSpeed = -0.03;
double jumpSpeed = -0.3;
double grav = 0.04;
int maxJump = 0;				// max jumps = 2
int playerLives = 3;
int playerScore = 0;
int main()
{
	// load font file to display text
	sf::Font font;
	if (!font.loadFromFile("Raleway-Black.ttf"))
	{
		std::cout << "Font folder cannot be loaded\n";
	}

	// Set text settings
	sf::Text text;
	text.setPosition(0, 0);
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);

	// Create Window frame 
	sf::RenderWindow window(sf::VideoMode(500, 500), "Jump Block");

	// Draw players rectangle 
	sf::RectangleShape player(sf::Vector2f(10, 50));
	player.setFillColor(sf::Color::White);

	// Draw squares player needs to jump over 
	sf::RectangleShape box(sf::Vector2f(20, 20));
	box.setFillColor(sf::Color::Red);

	// Set rectangle in a random place inside the window 
	// The very bottom of the window will be treated as the "ground"
	player.setPosition(150, 450);

	// Squares position initially offscreen and will be moved to the left towards the player 
	box.setPosition(550, 480);

	// while loop, where game code begins controlling the "physics" and other events happening 
	while (window.isOpen())
	{
		// Display the players current lives 
		std::stringstream s;
		s << "Lives left: " << playerLives;
		s << "\nScore: " << playerScore;
		text.setString(s.str());

		// If user decides to exit game 
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// If spacebar is pressed, jump up 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			player.move(0, jumpSpeed);
		}

		// Limit number of jumps
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.getPosition().y < 450 && maxJump != 1) {
			player.move(0, jumpSpeed);
			++maxJump;

		}

		//Gravity for when jumping up
		if (player.getPosition().y < 450)
			player.move(0, grav);


		else if (player.getPosition().y <= 0)
			player.setPosition(player.getPosition().x, 0);

		// Move box to left towards player 
		box.move(boxSpeed, 0);

		// Collision of player and box
		// Update player lives
		if (box.getGlobalBounds().intersects(player.getGlobalBounds())) {
			box.setPosition(550, 480);
			playerLives--;
		}

		//  Once box is out of bounds, move it back to original position and repeat 
		//  Also increment speed of box slowly 
		if (box.getPosition().x < 0) {
			box.setPosition(550, 480);
			playerScore++;

			// Limit max speed of box 
			if (boxSpeed > -0.07) {
				boxSpeed += -0.01;
				box.move(boxSpeed, 0);
			}
		}

		// Display window 
		window.clear();
		window.draw(player);
		window.draw(box);
		window.draw(text);		
		window.display();
	}

	return 0;
}
