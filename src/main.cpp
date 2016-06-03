#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "MapGenerator.hpp"
#include "Drawing.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "Collisions.hpp"
#include "HiscoreLoader.hpp"
#include "GameStates.hpp"
#include "IconData.hpp"


int main()
{
	// Game init
	sf::RenderWindow window(sf::VideoMode(640, 480), "YellowSnake", sf::Style::Close);
	window.setIcon(sfml_icon.width, sfml_icon.height, sfml_icon.pixel_data);

	GameStates gameState = GameStates::GAME_LOGO;

	Map map;
	generateLevel1(map);

	Snake snake({ int(map.getWidth() / 2), int(map.getHeight() / 2) });

	Food food;
	food.setMapSize(map.getWidth(), map.getHeight());
	food.dislocate();

	sf::Clock clock;
	sf::Time time;

	sf::Font fontBricks;
	fontBricks.loadFromFile("Fonts/Bricks.otf");

	sf::Text scoreText;
	scoreText.setFont(fontBricks);
	scoreText.setString(L"SCORE:");
	scoreText.setCharacterSize(24);
	scoreText.setPosition(15, 450);

	sf::Text hiscoreText;
	hiscoreText.setFont(fontBricks);
	hiscoreText.setString(L"HISCORE:");
	hiscoreText.setCharacterSize(24);
	hiscoreText.setPosition(320, 450);

	sf::Text gameOver;
	gameOver.setFont(fontBricks);
	gameOver.setString(L"GAME OVER");
	gameOver.setCharacterSize(24);
	gameOver.setPosition((640 / 2) - gameOver.getGlobalBounds().width / 2, (480 / 2) - gameOver.getGlobalBounds().height / 2 - 32);

	sf::Text yourScore;
	yourScore.setFont(fontBricks);
	yourScore.setString(L"YOUR score: ");
	yourScore.setCharacterSize(24);
	yourScore.setPosition((640 / 2) - yourScore.getGlobalBounds().width / 2, (480 / 2) - yourScore.getGlobalBounds().height / 2 - 12);

	sf::Text playAgain;
	playAgain.setFont(fontBricks);
	playAgain.setString(L"PLAY AGAIN Y/N");
	playAgain.setCharacterSize(12);
	playAgain.setPosition((640 / 2) - playAgain.getGlobalBounds().width / 2, (480 / 2) - playAgain.getGlobalBounds().height / 2 + 12);

	sf::Text gameWin;
	gameWin.setFont(fontBricks);
	gameWin.setString(L"YOUR WINNER!!!");
	gameWin.setCharacterSize(24);
	gameWin.setPosition((640 / 2) - gameWin.getGlobalBounds().width / 2, (480 / 2) - gameWin.getGlobalBounds().height / 2 - 32);

	sf::Text gamePause;
	gamePause.setFont(fontBricks);
	gamePause.setString(L"PAUSE");
	gamePause.setCharacterSize(24);
	gamePause.setPosition((640 / 2) - gamePause.getGlobalBounds().width / 2, (480 / 2) - gamePause.getGlobalBounds().height / 2 - 24);

	sf::Text gamePauseKey;
	gamePauseKey.setFont(fontBricks);
	gamePauseKey.setString(L"PRESS SPACE TO CONTINUE");
	gamePauseKey.setCharacterSize(12);
	gamePauseKey.setPosition((640 / 2) - gamePauseKey.getGlobalBounds().width / 2, (480 / 2) - gamePauseKey.getGlobalBounds().height / 2);

	sf::Text logoGameNameText;
	logoGameNameText.setFont(fontBricks);
	logoGameNameText.setString(L"SNAKE CLASIC");
	logoGameNameText.setCharacterSize(36);
	logoGameNameText.setPosition((640 / 2) - logoGameNameText.getGlobalBounds().width / 2, (480 / 2) - logoGameNameText.getGlobalBounds().height / 2 - 96);

	sf::Text logoText;
	logoText.setFont(fontBricks);
	logoText.setString(L"GAME KEYS:\n"
					   L"\tUP ARROW - SNAKE GOES UP\n"
					   L"\tDOWN ARROW - SNAKE GOES DOWN\n"
					   L"\tLEFT ARROW - SNAKE GOES LEFT\n"
					   L"\tRIGHT ARROW - SNAKE GOES RIGHT\n"
					   L"\tSPACE - GAME PAUSE\n"
					   L"\tESCAPE - GAME EXIT\n"
					   L"PRESS SPACE TO PLAY\n"
					   );

	logoText.setCharacterSize(16);
	logoText.setPosition((640 / 2) - logoText.getGlobalBounds().width / 2, (480 / 2) - logoText.getGlobalBounds().height / 2 + 32);

	int hightscore = loadHiscore();

	// Game events
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {

					case sf::Keyboard::Up:
						snake.setDirectionUp();
						break;

					case sf::Keyboard::Down:
						snake.setDirectionDown();
						break;

					case sf::Keyboard::Left:
						snake.setDirectionLeft();
						break;

					case sf::Keyboard::Right:
						snake.setDirectionRight();
						break;

					case sf::Keyboard::Space:
						if (gameState == GameStates::GAME_RUN) {
							gameState = GameStates::GAME_PAUSE;
							clock.restart();
						}
						else if (gameState == GameStates::GAME_PAUSE) {
							gameState = GameStates::GAME_RUN;
							clock.restart();
						}

						if (gameState == GameStates::GAME_LOGO) {
							gameState = GameStates::GAME_RUN;
						}

						if (gameState == GameStates::GAME_WIN) {
							exit(0);
						}
						break;

					case sf::Keyboard::Y:
						if (gameState == GameStates::GAME_OVER) {
							if (snake.getFoodEaten() > hightscore) {
								saveHiscore(snake.getFoodEaten());
							}
							snake.reload({ int(map.getWidth() / 2), int(map.getHeight() / 2) });
							gameState = GameStates::GAME_RUN;
							clock.restart();
						}
						break;

					case sf::Keyboard::N:
						if (gameState == GameStates::GAME_OVER) {
							if (snake.getFoodEaten() > hightscore) {
								saveHiscore(snake.getFoodEaten());
							}
							exit(0);
						}
						break;

					case sf::Keyboard::Escape:
						exit(0);
						break;

					default:
						break;
				}
			}
		}
		

		// Game states
		window.clear(sf::Color(47, 83, 136));		

		switch (gameState) {

			case GameStates::GAME_RUN:
				time = clock.getElapsedTime();
				if (time.asMilliseconds() > 500) {
					snake.move();
					clock.restart();
				}

				checkCollisions(snake, food);
				if (checkCollisions(snake, map)) {
					gameState = GameStates::GAME_OVER;
				}
				if (checkCollisions(snake)) {
					gameState = GameStates::GAME_OVER;
				}

				if (snake.getFoodEaten() + 3 == map.getEmptyCount()) gameState = GameStates::GAME_WIN;

				scoreText.setString(L"SCORE: " + std::to_wstring(snake.getFoodEaten()));
				hiscoreText.setString(L"HISCORE: " + std::to_wstring(hightscore));

				drawMap(window, map.getCoords());
				drawFood(window, food.getCoords());
				drawSnake(window, snake);
				window.draw(scoreText);
				window.draw(hiscoreText);
				break;

			case GameStates::GAME_PAUSE:
				drawMap(window, map.getCoords());
				drawFood(window, food.getCoords());
				drawSnake(window, snake);
				window.draw(scoreText);
				window.draw(hiscoreText);

				window.draw(gamePause);
				window.draw(gamePauseKey);
				break;

			case GameStates::GAME_OVER:
				drawMap(window, map.getCoords());
				drawFood(window, food.getCoords());
				drawSnake(window, snake);
				window.draw(scoreText);
				window.draw(hiscoreText);

				window.draw(gameOver);
				yourScore.setString(L"YOUR SCORE: " + std::to_wstring(snake.getFoodEaten()));
				yourScore.setPosition((640 / 2) - yourScore.getGlobalBounds().width / 2, (480 / 2) - yourScore.getGlobalBounds().height / 2 - 12);
				window.draw(yourScore);
				window.draw(playAgain);
				break;

			case GameStates::GAME_WIN:
				window.draw(gameWin);
				break;

			case GameStates::GAME_LOGO:
				window.draw(logoGameNameText);
				window.draw(logoText);
				break;
		}


		window.display();
	}

	return 0;
}
