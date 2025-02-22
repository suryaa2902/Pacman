// /*
// Author: Suryaa Senthilkumar Shanthi
// Class: ECE6122 A
// Last Date Modified: 31 October, 2022
// Description: Lab3 - Make a Pacman game as given in the instructions
// */

#include<iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
	bool End = false;
	bool Start = false;
	bool Up = false;
	bool Down = false;
	bool Left = false;
	bool Right = false;
	bool PowerUpsEat = false;


	VideoMode vm(641, 728);
	RenderWindow window(vm, "PACMAN GAME");
	window.setFramerateLimit(50);

	//Background
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/maze.bmp");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	//Start
	Texture textureStart;
	textureStart.loadFromFile("graphics/pac-man.bmp");
	Sprite spriteStart;
	spriteStart.setTexture(textureStart);

	//Pacman
	Texture texturePacman;
	texturePacman.loadFromFile("graphics/pacman.bmp");
	Sprite spritePacman;
	spritePacman.setTexture(texturePacman);
	spritePacman.setPosition(Vector2f(305.f, 490.f));

	//Ghosts
	vector <Sprite> Ghosts;
	Sprite Ghost;

	//Orange Ghost
	Texture textureorange;
	textureorange.loadFromFile("graphics/orange_ghost.bmp");
	Ghost.setTexture(textureorange);
	Ghosts.push_back(Ghost);

	//Pink Ghost
	Texture texturepink;
	texturepink.loadFromFile("graphics/pink_ghost.bmp");
	Ghost.setTexture(texturepink);
	Ghosts.push_back(Ghost);

	//Red Ghost
	Texture texturered;
	texturered.loadFromFile("graphics/red_ghosts.bmp");
	Ghost.setTexture(texturered);
	Ghosts.push_back(Ghost);

	//Blue Ghost
	Texture textureblue;
	textureblue.loadFromFile("graphics/blue_ghost.bmp");
	Ghost.setTexture(textureblue);
	Ghosts.push_back(Ghost);

	for (auto& ghost : Ghosts)
	{
		ghost.setPosition(303,244);
	}

	//Creation of Recatangles
	vector<RectangleShape>walls;
	RectangleShape Wall;
	Wall.setFillColor(Color::Transparent);
	Wall.setSize(Vector2f(633.f, 18.f));
	Wall.setPosition(0, 20);
	walls.push_back(Wall);
	Wall.setPosition(0, 650);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(16.f, 227.f));
	Wall.setPosition(27, 6);
	walls.push_back(Wall);
	Wall.setPosition(595, 6);
	walls.push_back(Wall);
	Wall.setPosition(595, 426);
	walls.push_back(Wall);
	Wall.setPosition(26, 426);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(18.f, 84.f));
	Wall.setPosition(127, 220);
	walls.push_back(Wall);
	Wall.setPosition(493, 220);
	walls.push_back(Wall);
	Wall.setPosition(493, 344);
	walls.push_back(Wall);
	Wall.setPosition(127, 344);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(121.f, 17.f));
	Wall.setPosition(493, 220);
	walls.push_back(Wall);
	Wall.setPosition(493, 288);
	walls.push_back(Wall);
	Wall.setPosition(493, 344);
	walls.push_back(Wall);
	Wall.setPosition(493, 412);
	walls.push_back(Wall);
	Wall.setPosition(24, 220);
	walls.push_back(Wall);
	Wall.setPosition(24, 288);
	walls.push_back(Wall);
	Wall.setPosition(24, 344);
	walls.push_back(Wall);
	Wall.setPosition(24, 412);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(64.f, 46.f));
	Wall.setPosition(81, 76);
	walls.push_back(Wall);
	Wall.setPosition(493, 76);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(64.f, 24.f));
	Wall.setPosition(81, 158);
	walls.push_back(Wall);
	Wall.setPosition(493, 158);
	walls.push_back(Wall);
	Wall.setPosition(81, 464);
	walls.push_back(Wall);
	Wall.setPosition(493, 464);
	walls.push_back(Wall);
	Wall.setPosition(493, 158);
	walls.push_back(Wall);
	Wall.setPosition(493, 158);
	walls.push_back(Wall);
	Wall.setPosition(17, 527);
	walls.push_back(Wall);
	Wall.setPosition(557, 527);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(85.f, 46.f));
	Wall.setPosition(184, 76);
	walls.push_back(Wall);
	Wall.setPosition(367, 76);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(24.f, 85.f));
	Wall.setPosition(307, 34);
	walls.push_back(Wall);
	Wall.setPosition(184, 343);
	walls.push_back(Wall);
	Wall.setPosition(429, 343);
	walls.push_back(Wall);
	Wall.setPosition(121, 464);
	walls.push_back(Wall);
	Wall.setPosition(493, 464);
	walls.push_back(Wall);
	Wall.setPosition(184, 527);
	walls.push_back(Wall);
	Wall.setPosition(307, 527);
	walls.push_back(Wall);
	Wall.setPosition(429, 527);
	walls.push_back(Wall);
	Wall.setPosition(307, 158);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(24.f, 83.f));
	Wall.setPosition(307, 405);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(24.f, 147.f));
	Wall.setPosition(184, 158);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(24.f, 146.f));
	Wall.setPosition(429, 158);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(85.f, 24.f));
	Wall.setPosition(184, 464);
	walls.push_back(Wall);
	Wall.setPosition(368, 464);
	walls.push_back(Wall);
	Wall.setPosition(184, 220);
	walls.push_back(Wall);
	Wall.setPosition(368, 220);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(130.f, 24.f));
	Wall.setPosition(257, 527);
	walls.push_back(Wall);
	Wall.setPosition(257, 405);
	walls.push_back(Wall);
	Wall.setPosition(257, 158);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(187.f, 24.f));
	Wall.setPosition(81, 589);
	walls.push_back(Wall);
	Wall.setPosition(368, 589);
	walls.push_back(Wall);
	Wall.setSize(Vector2f(146.f, 84.f));
	Wall.setPosition(246, 282);
	walls.push_back(Wall);

	//Arranging the Coins
	vector<CircleShape>coins;
	CircleShape coin;
	coin.setRadius(2);
	coin.setPosition(60, 629);
	coins.push_back(coin);
	for (int i = 0; i < 25; i++)
	{
		coin.setPosition(60 + 21 * i, 629);
		coins.push_back(coin);
		coin.setPosition(60 + 21 * i, 137);
		coins.push_back(coin);
		if (!(i == 12 || i == 13))
		{
			coin.setPosition(60 + 21 * i, 55);
			coins.push_back(coin);
			coin.setPosition(60 + 21 * i, 444);
			coins.push_back(coin);
			if (!(i == 6 || i == 7 || i == 18 || i == 19))
			{
				coin.setPosition(60 + 21 * i, 568);
				coins.push_back(coin);
				coin.setPosition(60 + 21 * i, 199);
				coins.push_back(coin);
			}
			if ((i == 0 || i == 5 || i == 11 || i == 14 || i == 20 || i == 24))
			{
				coin.setPosition(60 + 21 * i, 76);
				coins.push_back(coin);
				coin.setPosition(60 + 21 * i, 116);
				coins.push_back(coin);
				coin.setPosition(60 + 21 * i, 465);
				coins.push_back(coin);
				coin.setPosition(60 + 21 * i, 485);
				coins.push_back(coin);
				if (!(i == 5 || i == 20))
				{
					coin.setPosition(60 + 21 * i, 588);
					coins.push_back(coin);
					coin.setPosition(60 + 21 * i, 608);
					coins.push_back(coin);
				}
				if (!(i == 0 || i == 24))
				{
					coin.setPosition(60 + 21 * i, 96);
					coins.push_back(coin);
				}
			}
			if ((i == 0 || i == 5 || i == 8 || i == 17 || i == 20 || i == 24))
			{
				coin.setPosition(60 + 21 * i, 158);
				coins.push_back(coin);
				coin.setPosition(60 + 21 * i, 178);
				coins.push_back(coin);
			}

		}

	}

	for (int j = 0; j < 10; j++)
	{
		coin.setPosition(480, 224 + 22 * j);
		coins.push_back(coin);
	}
	for (int j = 0; j < 10; j++)
	{
		coin.setPosition(165, 224 + 22 * j);
		coins.push_back(coin);
	}
	for (int j = 0; j < 16; j++)
	{
		coin.setPosition(165 + 21 * j, 507);
		coins.push_back(coin);
	}

	coin.setPosition(530, 507);
	coins.push_back(coin);
	coin.setPosition(530, 529);
	coins.push_back(coin);
	coin.setPosition(530, 551);
	coins.push_back(coin);
	coin.setPosition(81, 507);
	coins.push_back(coin);
	coin.setPosition(480, 551);
	coins.push_back(coin);
	coin.setPosition(165, 529);
	coins.push_back(coin);
	coin.setPosition(165, 551);
	coins.push_back(coin);
	coin.setPosition(228, 529);
	coins.push_back(coin);
	coin.setPosition(228, 551);
	coins.push_back(coin);
	coin.setPosition(102, 507);
	coins.push_back(coin);
	coin.setPosition(102, 529);
	coins.push_back(coin);
	coin.setPosition(102, 551);
	coins.push_back(coin);
	coin.setPosition(551, 507);
	coins.push_back(coin);
	coin.setPosition(417, 529);
	coins.push_back(coin);
	coin.setPosition(480, 529);
	coins.push_back(coin);
	coin.setPosition(417, 551);
	coins.push_back(coin);


	//Arranging the PowerUps
	vector<CircleShape>PowerUPS;
	CircleShape PowerUps;
	PowerUps.setRadius(5);
	PowerUps.setPosition(55, 93);
	PowerUPS.push_back(PowerUps);
	PowerUps.setPosition(55, 502);
	PowerUPS.push_back(PowerUps);
	PowerUps.setPosition(567, 93);
	PowerUPS.push_back(PowerUps);
	PowerUps.setPosition(567, 502);
	PowerUPS.push_back(PowerUps);


	sf::Text messageText;
	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	messageText.setFont(font);
	messageText.setString("PRESS ENTER TO START");
	messageText.setCharacterSize(50);
	messageText.setFillColor(Color::White);
	messageText.setPosition(30, 300);


	const float movement_Speed = 2.5f;
	Vector2f velocity;
	FloatRect pacmanNxtpos;
	const float ghost_speed = 2.f;
	Vector2f Ghost_velocity[4];
	vector<int> direction_ghost(4);


	Clock timer;

	//Ghost Movements
	srand((unsigned)time(0));
	for (int i = 0; i < Ghosts.size(); i++)
	{

		// Ghost direction 
		// 0 - up,1 - down,2 - right,3 - left
		direction_ghost[i] = 1 + (rand() * (int)(3 - 1) / RAND_MAX);

	}
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{

				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();

		}
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			Start = true;
		}

		//Pacman movement

		velocity.x = 0.f; // X coordinate are moved 
		velocity.y = 0.f; // Y coordinate are moved 
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Left = false;
			Right = false;
			Up = true;
			Down = false;

		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			Left = false;
			Right = false;
			Up = false;
			Down = true;

		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			Left = true;
			Right = false;
			Up = false;
			Down = false;

		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			Left = false;
			Right = true;
			Up = false;
			Down = false;

		}

		for (size_t i = 0; i < Ghosts.size(); i++)
		{
			for (auto& wall : walls)
			{

				// Ghost should move randomly after hiting the wall
				FloatRect ghost_bounds = Ghosts[i].getGlobalBounds();
				FloatRect wall_bounds = wall.getGlobalBounds();


				if (wall_bounds.intersects(ghost_bounds))
				{

					if (ghost_bounds.left < wall_bounds.left && ghost_bounds.left + ghost_bounds.width < wall_bounds.left + wall_bounds.width && ghost_bounds.top < wall_bounds.top + wall_bounds.height && ghost_bounds.top + ghost_bounds.height  > wall_bounds.top)
					{
						direction_ghost[i] = 1 + (rand() * (int)(5 - 1) / RAND_MAX);
						Ghosts[i].setPosition(wall_bounds.left - ghost_bounds.width, ghost_bounds.top);
					}

					if (ghost_bounds.left > wall_bounds.left && ghost_bounds.left + ghost_bounds.width > wall_bounds.left + wall_bounds.width && ghost_bounds.top < wall_bounds.top + wall_bounds.height && ghost_bounds.top + ghost_bounds.height  > wall_bounds.top)
					{
						direction_ghost[i] = 1 + (rand() * (int)(5 - 1) / RAND_MAX);
						Ghosts[i].setPosition(wall_bounds.left + wall_bounds.width, ghost_bounds.top);
					}

					if (ghost_bounds.top < wall_bounds.top && ghost_bounds.top + ghost_bounds.height < wall_bounds.top + wall_bounds.height && ghost_bounds.left < wall_bounds.left + wall_bounds.width && ghost_bounds.left + ghost_bounds.width  > wall_bounds.left)
					{
						direction_ghost[i] = 1 + (rand() * (int)(5 - 1) / RAND_MAX);
						Ghosts[i].setPosition(ghost_bounds.left, wall_bounds.top - ghost_bounds.height);
					}

					if (ghost_bounds.top > wall_bounds.top && ghost_bounds.top + ghost_bounds.height > wall_bounds.top + wall_bounds.height && ghost_bounds.left < wall_bounds.left + wall_bounds.width && ghost_bounds.left + ghost_bounds.width  > wall_bounds.left)
					{
						direction_ghost[i] = 1 + (rand() * (int)(5 - 1) / RAND_MAX);
						Ghosts[i].setPosition(ghost_bounds.left, wall_bounds.top + wall_bounds.height);
					}
				}
			}
		}

		for (int i = 0; i < direction_ghost.size(); i++)
		{
			Ghost_velocity[i].x = 0.f;
			Ghost_velocity[i].y = 0.f;

			if (direction_ghost[i] == 1)
			{
				Ghost_velocity[i].x += ghost_speed;

			}

			if (direction_ghost[i] == 2)
			{
				Ghost_velocity[i].x += -ghost_speed;

			}

			if (direction_ghost[i] == 3)
			{
				Ghost_velocity[i].y += -ghost_speed;
			}
			if (direction_ghost[i] == 4)
			{
				Ghost_velocity[i].y += ghost_speed;
			}
		}

		for (int i = 0; i < Ghosts.size(); i++)
		{
			if (Start)
			{
				Ghosts[i].move(Ghost_velocity[i]);
			}
		}


		// Eating Coins 

		for (size_t i = 0; i < coins.size(); i++)
		{
			if (spritePacman.getGlobalBounds().intersects(coins[i].getGlobalBounds()))
			{
				coins.erase(coins.begin() + i);

			}

		}

		//PowerUps
		for (size_t i = 0; i < PowerUPS.size(); i++)
		{
			if (spritePacman.getGlobalBounds().intersects(PowerUPS[i].getGlobalBounds()))
			{
				PowerUPS.erase(PowerUPS.begin() + i);
				timer.restart();
				PowerUpsEat = true;
			}
		}

		if (timer.getElapsedTime() < seconds(5) && PowerUpsEat)
		{
			for (size_t j = 0; j < Ghosts.size(); j++)
			{
				if (spritePacman.getGlobalBounds().intersects(Ghosts[j].getGlobalBounds()))
				{
					Ghosts.erase(Ghosts.begin() + j);

				}
			}
		}
		else
		{
			PowerUpsEat = false;
		}
		for (auto& wall : walls)
		{
			FloatRect pacman_bounds = spritePacman.getGlobalBounds();
			FloatRect wall_bounds = wall.getGlobalBounds();

			pacmanNxtpos = pacman_bounds;
			pacmanNxtpos.left += velocity.x;
			pacmanNxtpos.top += velocity.y;

			if (wall_bounds.intersects(pacmanNxtpos))
			{


				if (pacman_bounds.left < wall_bounds.left && pacman_bounds.left + pacman_bounds.width < wall_bounds.left + wall_bounds.width && pacman_bounds.top < wall_bounds.top + wall_bounds.height && pacman_bounds.top + pacman_bounds.height  > wall_bounds.top)
				{
					velocity.x = 0.f;
					spritePacman.setPosition(wall_bounds.left - pacman_bounds.width, pacman_bounds.top);
				}

				if (pacman_bounds.left > wall_bounds.left && pacman_bounds.left + pacman_bounds.width > wall_bounds.left + wall_bounds.width && pacman_bounds.top < wall_bounds.top + wall_bounds.height && pacman_bounds.top + pacman_bounds.height  > wall_bounds.top)
				{
					velocity.x = 0.f;
					spritePacman.setPosition(wall_bounds.left + wall_bounds.width, pacman_bounds.top);
				}

				if (pacman_bounds.top < wall_bounds.top && pacman_bounds.top + pacman_bounds.height < wall_bounds.top + wall_bounds.height && pacman_bounds.left < wall_bounds.left + wall_bounds.width && pacman_bounds.left + pacman_bounds.width  > wall_bounds.left)
				{
					velocity.y = 0.f;
					spritePacman.setPosition(pacman_bounds.left, wall_bounds.top - pacman_bounds.height);
				}

				if (pacman_bounds.top > wall_bounds.top && pacman_bounds.top + pacman_bounds.height > wall_bounds.top + wall_bounds.height && pacman_bounds.left < wall_bounds.left + wall_bounds.width && pacman_bounds.left + pacman_bounds.width  > wall_bounds.left)
				{
					velocity.y = 0.f;
					spritePacman.setPosition(pacman_bounds.left, wall_bounds.top + wall_bounds.height);
				}
			}
		}

		if (spritePacman.getPosition().x < 27)
		{
			spritePacman.setPosition(607, spritePacman.getPosition().y);
		}


		if (spritePacman.getPosition().x > 607)
		{
			spritePacman.setPosition(27, spritePacman.getPosition().y);
		}

		for (auto& ghost : Ghosts)
		{
			if (ghost.getPosition().x < 27)
			{
				ghost.setPosition(607, ghost.getPosition().y);
			}
			if (ghost.getPosition().x > 607)
			{
				ghost.setPosition(27, ghost.getPosition().y);
			}
		}

		if (Up)
		{
			velocity.y += -movement_Speed;
		}

		if (Down)
		{
			velocity.y += movement_Speed;
		}

		if (Left)
		{
			velocity.x += -movement_Speed;
		}

		if (Right)
		{
			velocity.x += movement_Speed;
		}
		spritePacman.move(velocity);

		// If all ghost are eaten then the game ends 
		for (auto& ghost : Ghosts)
		{
			if ((spritePacman.getGlobalBounds().intersects(ghost.getGlobalBounds()) && !PowerUpsEat))// all ghost die 
			{

				End = true;
				window.close();
			}
		}
		if ((Ghosts.size() == 0) || (coins.size() == 0 && PowerUPS.size() == 0)) // all coins eaten 
		{
			End = true;
			window.close();

		}
		window.clear();
		window.draw(spriteBackground);
		if (!Start)
		{
			window.draw(spriteStart);
			window.draw(messageText);
		}
		if (Start)
		{
			for (auto& ghost : Ghosts)
			{
				window.draw(ghost);
			}
			for (auto& coin : coins)
			{
				window.draw(coin);
			}
			for (auto& PowerUps : PowerUPS)
			{
				window.draw(PowerUps);
			}
			window.draw(spritePacman);
			for (auto& wall : walls)
			{
				window.draw(wall);
			}
			for (auto& coin : coins)
			{
				window.draw(coin);
			}
		}
		window.display();
	}
	return 0;
}