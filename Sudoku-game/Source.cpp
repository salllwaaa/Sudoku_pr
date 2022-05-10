#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio.hpp>
#include "menu1.h"
#include <SFML/Audio/Sound.hpp>
#include <iostream>
using namespace std;

int  page_number = -1;

void random();
void lockFun();
int deleteButton(int x);
int numpad(int x);
bool check(int x, int y, int& value);


//data arrays (3 games with answers)
int boarddata1[9][9] = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0}
};

int answer1[9][9] = {
  {4, 3, 5, 2, 6, 9, 7, 8, 1},
  {6, 8, 2, 5, 7, 1, 4, 9, 3},
  {1, 9, 7, 8, 3, 4, 5, 6, 2},
  {8, 2, 6, 1, 9, 5, 3, 4, 7},
  {3, 7, 4, 6, 8, 2, 9, 1, 5},
  {9, 5, 1, 7, 4, 3, 6, 2, 8},
  {5, 1, 9, 3, 2, 6, 8, 7, 4},
  {2, 4, 8, 9, 5, 7, 1, 3, 6},
  {7, 6, 3, 4, 1, 8, 2, 5, 9}
};

int boardData2[9][9] = {

    {2, 0, 0, 0, 0, 1, 0, 0, 7},
    {0, 0, 0, 8, 0, 9, 4, 2, 0},
    {0, 0, 3, 6, 0, 0, 0, 0, 0},
    {0, 7, 2, 0, 3, 0, 0, 0, 0},
    {9, 3, 0, 0, 0, 2, 1, 5, 0},
    {8, 6, 0, 0, 9, 0, 7, 0, 0},
    {5, 0, 0, 9, 0, 0, 0, 0, 0},
    {0, 1, 0, 2, 0, 3, 6, 0, 8},
    {0, 8, 0, 0, 6, 7, 2, 0, 0}
};

int answer2[9][9] = {

{2, 9, 8, 3, 4, 1, 5, 6, 7},
{6, 5, 1, 8, 7, 9, 4, 2, 3},
{7, 4, 3, 6, 2, 5, 9, 8, 1},
{1, 7, 2, 5, 3, 6, 8, 4, 9},
{9, 3, 4, 7, 8, 2, 1, 5, 6},
{8, 6, 5, 1, 9, 4, 7, 3, 2},
{5, 2, 6, 9, 1, 8, 3, 7, 4},
{4, 1, 7, 2, 5, 3, 6, 9, 8},
{3, 8, 9, 4, 6, 7, 2, 1, 5}
};

int boardData3[9][9] = {
{8, 0, 1, 0, 0, 0, 0, 0, 4},
{4, 5, 0, 3, 0, 2, 6, 0, 7},
{3, 0, 0, 0, 0, 0, 5, 9, 1},
{0, 3, 0, 0, 0, 0, 0, 0, 8},
{6, 1, 2, 9, 8, 0, 0, 0, 0},
{0, 0, 5, 1, 6, 0, 0, 2, 3},
{0, 4, 0, 5, 0, 0, 8, 7, 0},
{0, 6, 0, 2, 4, 0, 0, 5, 0},
{0, 9, 0, 8, 0, 0, 0, 1, 2}
};

int answer3[9][9] = {

{8, 7, 1, 6, 5, 9, 2, 3, 4},
{4, 5, 9, 3, 1, 2, 6, 8, 7},
{3, 2, 6, 4, 7, 8, 5, 9, 1},
{9, 3, 4, 7, 2, 5, 1, 6, 8},
{6, 1, 2, 9, 8, 3, 7, 4, 5},
{7, 8, 5, 1, 6, 4, 9, 2, 3},
{2, 4, 3, 5, 9, 1, 8, 7, 6},
{1, 6, 8, 2, 4, 7, 3, 5, 9},
{5, 9, 7, 8, 3, 6, 4, 1, 2}
};

int usedarray[9][9];
int answer[9][9];
bool lock[9][9];


int X, Y;
int counter = -1;
int variable = 0;
sf::Text boardtext[9][9];
sf::RenderWindow window(sf::VideoMode(1067, 715), "Sudoku!");
sf::SoundBuffer wrongAnswer;
sf::Sound explosionWrong;
sf::SoundBuffer youWin;
sf::Sound explosionWin;
sf::Text text3;



int raw, column;


int main()
{


    menu1 Menu(500, 500);
    //select random array form 3 arrays
    random();
    //lock correct items from changing
    lockFun();

    //sfml images-sounds-fonts
    sf::Texture texture;
    texture.loadFromFile("sudoku-test.png");
    sf::Sprite background(texture);
    background.setScale(1, 1);

    sf::Texture texture1;
    texture1.loadFromFile("about_window.png");
    sf::Sprite About(texture1);
    About.setScale(1, 1);

    sf::Texture texture2;
    texture2.loadFromFile("YOU_WIN.png");
    sf::Sprite youwin(texture2);
    youwin.setScale(1, 1);
    youwin.setPosition(sf::Vector2f(65, 70));

    sf::Texture texture3;
    texture3.loadFromFile("menu.png");
    sf::Sprite menu(texture3);
    menu.setScale(1.4, 1.6);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text space;
    space.setString(" ");

    wrongAnswer.loadFromFile("wrong answer.wav");

    youWin.loadFromFile("clapping.wav");


    if (!font.loadFromFile("arial.ttf")) {}



    text3.setFont(font);
    text3.setFillColor(sf::Color::Black);
    text3.setString("$UDOKU");
    text3.setCharacterSize(50);
    text3.setPosition(sf::Vector2f(window.getSize().x - 270, window.getSize().y - 680));


    // make the data appear on the window
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            boardtext[i][j] = sf::Text();
            boardtext[i][j].setCharacterSize(30);
            boardtext[i][j].setFont(font);
            boardtext[i][j].setFillColor(sf::Color::Blue);
            boardtext[i][j].setString(std::to_string(usedarray[i][j]));
            boardtext[i][j].setPosition(sf::Vector2f((window.getSize().x - 337) / 9 * i + 35, window.getSize().y / 9 * j + 25));
        }
    }


    //mouse event

    if (page_number == 0) //game window
    {

        random();

        lockFun();

    }


    while (window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (page_number == -1) //menu window
            {

                if (event.type == sf::Event::KeyReleased)
                {

                    if (event.key.code == sf::Keyboard::Up)
                    {
                        Menu.moveUp();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        Menu.moveDown();
                        break;

                    }
                    //choose window
                    if (event.key.code == sf::Keyboard::Return) //enter
                    {

                        if (Menu.mainMenuPressed() == 0)
                        {

                            page_number = 0;
                            cout << "play window\n";

                        }
                        if (Menu.mainMenuPressed() == 1)
                        {

                            page_number = 1;
                            cout << "about window\n";
                        }
                        if (Menu.mainMenuPressed() == 2)
                        {

                            page_number = 2;
                            cout << "exit window\n";
                        }
                    }

                }




            }

            if (page_number == 0) //play window
            {

                if (event.type == sf::Event::KeyReleased)
                {

                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        page_number = -1;
                        break;
                    }
                }

                switch (event.type)
                {
                case sf::Event::MouseButtonPressed:
                    X = sf::Mouse::getPosition(window).x;
                    Y = sf::Mouse::getPosition(window).y;
                    cout << X << " " << Y << endl;
                    // get raw & column number from position
                    raw = X / 80;
                    column = Y / 80;
                    cout << "i" << raw << " j " << column << endl;

                    deleteButton(X);

                    numpad(X);

                    if (X < 720) check(raw, column, variable);




                    break;
                }





                window.clear();

                window.draw(background);

                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (usedarray[i][j] == 0)
                            window.draw(space);
                        else
                            window.draw(boardtext[i][j]);


                    }
                }

                window.draw(text3);

                if (counter == 0) { window.draw(youwin); }

                window.display();

            }

            if (page_number == 1) // about window
            {

                if (event.type == sf::Event::KeyReleased)
                {

                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        page_number = -1;
                        break;
                    }
                }
                window.clear();
                window.draw(About);
                window.display();

            }

            if (page_number == 2) //exit 
                window.close();

        }
        if (page_number == -1)// menu window
        {
            window.clear();
            window.draw(menu);
            Menu.draw(window);


            window.display();
        }

    }

    return 0;
}






void random()//choose random array 
{
    srand(time(0));
    int randomnumber = rand() % 3 + 1;
    cout << "array number:" << randomnumber << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {


            if (randomnumber == 1)
            {

                usedarray[i][j] = boarddata1[i][j];
                answer[i][j] = answer1[i][j];

            }
            else if (randomnumber == 2)
            {
                usedarray[i][j] = boardData2[i][j];
                answer[i][j] = answer2[i][j];
            }
            else
            {
                usedarray[i][j] = boardData3[i][j];
                answer[i][j] = answer3[i][j];

            }


        }
    }
}


void lockFun()
{
    counter = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (usedarray[i][j] != 0)

                lock[i][j] = 1;
            else
                counter++;
        }
    }
}


int deleteButton(int x)
{
    if ((X < 861) && (X > 758))
    {
        if ((Y > 529) && (Y < 587))
        {
            variable = 0;
        }
    }
    return variable;
}


int numpad(int x) // value from number pad 
{
    if (x > 720 && X < 1020)
    {
        if ((Y > 160) && (Y <= 260)) {
            variable = (((X - 780) / 74) + 1);
        }
        else if ((Y > 260) && (Y <= 369)) {
            variable = (((X - 780) / 74) + 4);
        }
        else if ((Y > 369) && (Y <= 478)) {
            variable = (((X - 780) / 74) + 7);
        }

        std::cout << "number is" << variable << endl;

        return variable;
    }
}



bool check(int i, int j, int& value)
{
    if (lock[i][j] == 0)// empty or wrong value
    {
        i = raw;
        j = column;
        cout << "correct answer is" << answer[i][j] << endl;
        if (value == answer[i][j]) // correct value
        {
            usedarray[i][j] = value;
            lock[i][j] = 1;
            counter--;
            boardtext[i][j].setFillColor(sf::Color::Green);
            cout << usedarray[i][j] << " correct\n";
            boardtext[i][j].setString(std::to_string(usedarray[i][j]));


            if (counter == 0) // finished 
            {
                cout << "you winned !!!!!";


                explosionWin.setBuffer(youWin);
                explosionWin.setVolume(1000);

                explosionWin.play();
            }

            return 1;
        }
        else // wrong value or delete
        {
            usedarray[i][j] = value;
            boardtext[i][j].setFillColor(sf::Color::Red);
            cout << boarddata1[i][j] << " wrong\n";
            boardtext[i][j].setString(std::to_string(usedarray[i][j]));

            if (value != 0) // wrong value only
            {
                explosionWrong.setBuffer(wrongAnswer);
                explosionWrong.setVolume(1000);

                explosionWrong.play();
            }
            return 0;

        }
    }


}