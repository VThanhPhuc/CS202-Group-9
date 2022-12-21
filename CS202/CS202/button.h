#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Button
{
public:
	Button() {};
	Button(std::string t, sf::Vector2f size,int CharSize, sf::Color bgColor, sf::Color textColor)
	{
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(CharSize);
		text.setOutlineThickness(0.5);

		button.setSize(size);
		button.setFillColor(bgColor);
		button.setOutlineColor(sf::Color::Black);
		button.setOutlineThickness(10);
	}
	Button& operator = (Button a)
	{
		this->button = a.button;
		this->text = a.text;
		return *this;
	}
	void setFont(sf::Font& font)
	{
		text.setFont(font);
	}

	void setBackColor(sf::Color color)
	{
		button.setFillColor(color);
	}

	void setTextColor(sf::Color color)
	{
		text.setFillColor(color);
	}

	void setPosition(sf::Vector2f pos)
	{
		button.setPosition(pos);

		//float xPos = (pos.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
		//float yPos = (pos.y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
		text.setPosition(pos.x + 40 , pos.y + 10);
	}
	void SetText(std::string t)
	{
		this->text.setString(t);
	}
	void drawTo(sf::RenderWindow& window)
	{
		window.draw(button);
		window.draw(text);
	}

	bool isMouseOver(sf::RenderWindow& window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnPosX = button.getPosition().x;
		float btnPosY = button.getPosition().y;

		float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;


		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
		{
			return true;
		}
		return false;
	}
private:
	sf::RectangleShape button;
	sf::Text text;
};