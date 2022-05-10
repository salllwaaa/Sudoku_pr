#include "menu1.h"


menu1::menu1(double width, double hight) {
	//play
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {}



	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Blue);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(75);
	mainMenu[0].setPosition(sf::Vector2f(width / 2, hight / (Max_main_menu1 + 1.0529)));


	//about 
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::Yellow);
	mainMenu[1].setString("About");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(sf::Vector2f(width / 2, hight / (Max_main_menu1 - 1.000075)));

	//exit

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::Yellow);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(53);
	mainMenu[2].setPosition(sf::Vector2f(width / 2, hight / (Max_main_menu1 - 1.6)));


	mainMenuSelected = 0;

}
menu1::~menu1()
{

}
//function to draw the main menu
void menu1::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}
//move down
void menu1::moveDown()
{
	if (mainMenuSelected + 1 <= Max_main_menu1) //check the items
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
		// go to the next item
		mainMenuSelected++;// go to the next item
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}

		mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);  //change the item's color

	}
}



//move up
void menu1::moveUp()
{
	if (mainMenuSelected - 1 >= -1) //check if not play
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);
	}

}