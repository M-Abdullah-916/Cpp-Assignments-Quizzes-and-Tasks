#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;
using namespace sf;

struct Piece
{
	Sprite b1;
	Sprite b2;
	Sprite b3;
	Sprite b4;
};

struct roll {
	Sprite one;
	Sprite two;
	Sprite three;
	Sprite four;
	Sprite five;
	Sprite six;
	Sprite fordefault;
};

void check(int num, RenderWindow& thatWindow)
{
	struct roll dicee;
	Texture z2, z3, z4, z5, z6, z7;
	z2.loadFromFile("d1.png");
	z3.loadFromFile("d2.png");
	z4.loadFromFile("d3.png");
	z5.loadFromFile("d4.png");
	z6.loadFromFile("d5.png");
	z7.loadFromFile("d6.png");

	dicee.one.setTexture(z2);
	dicee.two.setTexture(z3);
	dicee.three.setTexture(z4);
	dicee.four.setTexture(z5);
	dicee.five.setTexture(z6);
	dicee.six.setTexture(z7);
	dicee.fordefault.setTexture(z7);

	if (num == 6) {
		dicee.six.setPosition(1060, 200);
		thatWindow.draw(dicee.six);
		
	}
	else if (num == 5) {
		dicee.six.setPosition(1060, 200);
		thatWindow.draw(dicee.five);
		
	}
	else if (num == 4) {
		dicee.six.setPosition(1060, 200);
		thatWindow.draw(dicee.four);
		
	}
	else if (num == 3) {
		dicee.six.setPosition(1060, 200);
		thatWindow.draw(dicee.three);
		
	}
	else if (num == 2) {
		dicee.six.setPosition(1060, 200);
		thatWindow.draw(dicee.two);
		
	}
	else{
		dicee.one.setPosition(1060, 200);
		thatWindow.draw(dicee.one);
		
	}
}




int main()
{

	RenderWindow window(VideoMode(600, 600), "SFML Tutorial", Style::Fullscreen);
	


	RectangleShape box[6][3];
	RectangleShape box1[6][3];
	RectangleShape box2[3][6];
	RectangleShape box3[3][6];
	RectangleShape tiles;
	RectangleShape green;
	RectangleShape red;
	RectangleShape yellow;
	RectangleShape tilesbdr;
	RectangleShape greenbdr;
	RectangleShape redbdr;
	RectangleShape yellowbdr;
	RectangleShape rainbow;



	struct Piece b;
	struct Piece g;
	struct Piece r;
	struct Piece y;


	//Background File
	Texture text;
	text.loadFromFile("wood.png");
	if (!text.loadFromFile("wood.png"))
		cout << "FILE NOT FOUND";
	text.setSmooth(true);
	Sprite bg;
	bg.setTexture(text);


	//------------------------------------------------
	Font font;
	font.loadFromFile("Arial.ttf");
	if (!font.loadFromFile("Arial.ttf"))
		cout << "File not found";

	Text z1;
	z1.setFont(font);
	z1.setString("ROLL THE DICE");
	z1.setCharacterSize(50);
	z1.setFillColor(Color::Black);
	z1.setStyle(Text::Bold | Text::Underlined);
	z1.setPosition(950, 20);



	//--------------------------------------------------------------------
	//Drawing Blue House
	tiles.setFillColor(Color::Blue);
	tiles.setSize(Vector2f(300, 300));
	tiles.setPosition(0, 0);
	tiles.setOutlineColor(Color::Black);
	tiles.setOutlineThickness(4);

	//Drawing Green House
	green.setFillColor(Color::Green);
	green.setSize(Vector2f(300, 300));
	green.setPosition(500, 0);
	green.setOutlineColor(Color::Black);
	green.setOutlineThickness(4);

	//Drawing Red House
	red.setFillColor(Color::Red);
	red.setSize(Vector2f(300, 300));
	red.setPosition(0, 465);
	red.setOutlineColor(Color::Black);
	red.setOutlineThickness(4);

	//Drawing Yellow House
	yellow.setFillColor(Color::Yellow);
	yellow.setSize(Vector2f(300, 300));
	yellow.setPosition(500, 465);
	yellow.setOutlineColor(Color::Black);
	yellow.setOutlineThickness(4);


	//---------------------------------------------------------------
	yellowbdr.setFillColor(Color::Yellow);
	yellowbdr.setSize(Vector2f(200, 200));
	yellowbdr.setPosition(550, 515);
	yellowbdr.setOutlineColor(Color::White);
	yellowbdr.setOutlineThickness(20);

	redbdr.setFillColor(Color::Red);
	redbdr.setSize(Vector2f(200, 200));
	redbdr.setPosition(50, 515);
	redbdr.setOutlineColor(Color::White);
	redbdr.setOutlineThickness(20);

	greenbdr.setFillColor(Color::Green);
	greenbdr.setSize(Vector2f(200, 200));
	greenbdr.setPosition(550, 50);
	greenbdr.setOutlineColor(Color::White);
	greenbdr.setOutlineThickness(20);

	tilesbdr.setFillColor(Color::Blue);
	tilesbdr.setSize(Vector2f(200, 200));
	tilesbdr.setPosition(50, 50);
	tilesbdr.setOutlineColor(Color::White);
	tilesbdr.setOutlineThickness(20);

	rainbow.setFillColor(Color::White);
	rainbow.setSize(Vector2f(200, 165));
	rainbow.setPosition(300, 300);

	//-----------------------------------------------------------------------------
	CircleShape triangle3(67, 3);
	triangle3.setFillColor(Color::Red);
	triangle3.setPosition(332, 380);



	CircleShape triangle2(67, 3);
	triangle2.setFillColor(Color::Yellow);
	triangle2.setPosition(442, 292);
	triangle2.rotate(30.0f);

	CircleShape triangle1(70, 3);
	triangle1.setFillColor(Color::Green);
	triangle1.setPosition(424, 220);
	triangle1.rotate(60.0f);
	triangle1.setScale(1.0f, 1.0f);

	CircleShape triangle(67, 3);
	triangle.setFillColor(Color::Blue);
	triangle.setPosition(240, 360);
	triangle.rotate(-30.0f);

	Texture fordice;
	fordice.loadFromFile("white.jpg");
	Sprite bg1;
	bg1.setTexture(fordice);
	bg1.setPosition(850, 0);

	


	//-----------------------------------------------------------------------
	int l = 50, m = 54;
	//Path Yellow
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if ((i == 1 && j <= 4) || (i == 2 && j == 4) || (i == 0 && j == 3))
			{
				box3[i][j].setFillColor(Color::Yellow);
				box3[i][j].setSize(Vector2f(50, 54));
				box3[i][j].setPosition(500 + (l * j), 300 + (m * i));
				box3[i][j].setOutlineThickness(2);
				box3[i][j].setOutlineColor(Color::Black);
			}
			else
			{
				box3[i][j].setFillColor(Color::White);
				box3[i][j].setSize(Vector2f(50, 54));
				box3[i][j].setPosition(500 + (l * j), 300 + (m * i));
				box3[i][j].setOutlineThickness(2);
				box3[i][j].setOutlineColor(Color::Black);
			}
		}
	}

	//Path Blue
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if ((i == 1 && j >= 1) || (i == 0 && j == 1) || (i == 2 && j == 2))
			{
				box2[i][j].setFillColor(Color::Blue);
				box2[i][j].setSize(Vector2f(50, 54));
				box2[i][j].setPosition(0 + (l * j), 300 + (m * i));
				box2[i][j].setOutlineThickness(2);
				box2[i][j].setOutlineColor(Color::Black);
			}
			else
			{
				box2[i][j].setFillColor(Color::White);
				box2[i][j].setSize(Vector2f(50, 54));
				box2[i][j].setPosition(0 + (l * j), 300 + (m * i));
				box2[i][j].setOutlineThickness(2);
				box2[i][j].setOutlineColor(Color::Black);
			}
		}
	}

	//Path Red and Green
	int z = 66;
	int k = 50;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((i <= 4 && j == 1) || (i == 4 && j == 0) || (i == 3 && j == 2))
			{
				box1[i][j].setFillColor(Color::Red);
				box1[i][j].setSize(Vector2f(66.6, 50));
				box1[i][j].setPosition(300 + (z * j), 465 + (k * i));
				box1[i][j].setOutlineThickness(2);
				box1[i][j].setOutlineColor(Color::Black);
			}
			else
			{
				box1[i][j].setFillColor(Color::White);
				box1[i][j].setSize(Vector2f(66.6, 50));
				box1[i][j].setPosition(300 + (z * j), 465 + (k * i));
				box1[i][j].setOutlineThickness(2);
				box1[i][j].setOutlineColor(Color::Black);
			}
		}
	}


		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((i >= 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 0))
				{
					box[i][j].setFillColor(Color::Green);
					box[i][j].setSize(Vector2f(66.6, 50));
					box[i][j].setPosition(300 + (z * j), 0 + (k * i));
					box[i][j].setOutlineThickness(2);
					box[i][j].setOutlineColor(Color::Black);
				}
				else
				{
					box[i][j].setFillColor(Color::White);
					box[i][j].setSize(Vector2f(66.6, 50));
					box[i][j].setPosition(300 + (z * j), 0 + (k * i));
					box[i][j].setOutlineThickness(2);
					box[i][j].setOutlineColor(Color::Black);
				}
			}
		}


		//Blue pieces
		Texture t1;
		t1.loadFromFile("blue.png");
		if (!t1.loadFromFile("blue.png"))
			cout << "FILE NOT FOUND";
		t1.setSmooth(true);
		b.b1.setTexture(t1);
		b.b2.setTexture(t1);
		b.b3.setTexture(t1);
		b.b4.setTexture(t1);
		b.b1.setPosition(100, 100);
		b.b2.setPosition(150, 100);
		b.b3.setPosition(100, 150);
		b.b4.setPosition(150, 150);

		//Green Pieces
		Texture t2;
		t2.loadFromFile("green.png");
		if (!t2.loadFromFile("green.png"))
			cout << "FILE NOT FOUND";
		t2.setSmooth(true);
		g.b1.setTexture(t2);
		g.b2.setTexture(t2);
		g.b3.setTexture(t2);
		g.b4.setTexture(t2);
		g.b1.setPosition(600, 100);
		g.b2.setPosition(650, 100);
		g.b3.setPosition(600, 150);
		g.b4.setPosition(650, 150);

		//Red Pieces
		Texture t3;
		t3.loadFromFile("red.png");
		if (!t3.loadFromFile("red.png"))
			cout << "FILE NOT FOUND";
		t3.setSmooth(true);
		r.b1.setTexture(t3);
		r.b2.setTexture(t3);
		r.b3.setTexture(t3);
		r.b4.setTexture(t3);
		r.b1.setPosition(100, 550);
		r.b2.setPosition(150, 550);
		r.b3.setPosition(100, 600);
		r.b4.setPosition(150, 600);

		//Yellow Pieces
		Texture t4;
		t4.loadFromFile("y.png");
		if (!t4.loadFromFile("y.png"))
			cout << "FILE NOT FOUND";
		t4.setSmooth(true);
		y.b1.setTexture(t4);
		y.b2.setTexture(t4);
		y.b3.setTexture(t4);
		y.b4.setTexture(t4);
		y.b1.setPosition(480, 465);
		y.b2.setPosition(540, 465);
		y.b3.setPosition(480, 550);
		y.b4.setPosition(540, 550);


		//------------------------------------


		struct roll dice;

		Texture z2, z3, z4, z5, z6, z7;
		z2.loadFromFile("d1.png");
		z3.loadFromFile("d2.png");
		z4.loadFromFile("d3.png");
		z5.loadFromFile("d4.png");
		z6.loadFromFile("d5.png");
		z7.loadFromFile("d6.png");
	
		dice.one.setTexture(z2);
		dice.two.setTexture(z3);
		dice.three.setTexture(z4);
		dice.four.setTexture(z5);
		dice.five.setTexture(z6);
		dice.six.setTexture(z7);
		dice.fordefault.setTexture(z7);

		dice.fordefault.setPosition(1060, 150);
		dice.fordefault.setScale(2.5f, 2.0f);

		int num;

	while (window.isOpen())
	{
		Event event;


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (dice.fordefault.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
			{
				//srand(time(NULL));
				//num=rand() % 6 + 1;
				dice.fordefault.setColor(Color::Red);
				check(num, window);

			}
		}
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.key.code == Keyboard::Escape)
					window.close();
				

			}
			window.draw(bg);

			window.draw(yellow);
			window.draw(red);
			window.draw(green);
			window.draw(tiles);

			window.draw(tilesbdr);
			window.draw(greenbdr);
			window.draw(redbdr);
			window.draw(yellowbdr);
			window.draw(rainbow);
			window.draw(triangle3);
			window.draw(triangle2);
			window.draw(triangle1);
			window.draw(triangle);




			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 6; j++)
				{
					window.draw(box2[i][j]);
					window.draw(box3[i][j]);
				}

			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++)
				{
					window.draw(box[i][j]);
					window.draw(box1[i][j]);
				}






			//Blue Pieces
			window.draw(b.b1);
			window.draw(b.b2);
			window.draw(b.b3);
			window.draw(b.b4);

			//Green Pieces
			window.draw(g.b1);
			window.draw(g.b2);
			window.draw(g.b3);
			window.draw(g.b4);

			//Red Pieces
			window.draw(r.b1);
			window.draw(r.b2);
			window.draw(r.b3);
			window.draw(r.b4);

			//Yellow Pieces

			window.draw(y.b1);
			window.draw(y.b2);
			window.draw(y.b3);
			window.draw(y.b4);

			window.draw(bg1);
			window.draw(z1);

			/*window.draw(dice.one);
			window.draw(dice.two);
			window.draw(dice.three);
			window.draw(dice.four);
			window.draw(dice.five);
			window.draw(dice.six);*/
			window.draw(dice.fordefault);


		
			
			window.display();


	}
}
