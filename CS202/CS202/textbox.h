#pragma once
#include "Constants.h"
#include "Background.h"
#include "string"
#include "sstream"
#include "iostream"
class TextBox
{
public:
	TextBox()
	{

	}

	TextBox(int size, sf::Color color, bool sel)
	{
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		IsSelected = sel;
		if (sel)
		{
			textbox.setString("_");
		}
		else
		{
			textbox.setString("");
		}
	}

	void setFont(sf::Font& font) {
		textbox.setFont(font);
	}

	void setPosition(sf::Vector2f pos)
	{
		textbox.setPosition(pos);
	}

	void setLimit(bool ToF,int lim)
	{
		hasLimit = ToF;
		limit = lim - 1;
	}

	void setSelected(bool sel)
	{
		IsSelected = sel;
		if (!sel)
		{
			std::string t = text.str();
			std::string newT = "";
			for (int i = 0; i < t.length() ; i++){
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}

	std::string getText()
	{
		return text.str();
	}

	void drawTo(sf::RenderWindow& window)
	{
		window.draw(textbox);
	}

	void typeOn(sf::Event input) {
		if (IsSelected)
		{
			int charTyped = input.text.unicode;
			if (charTyped < 128)
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						inputlogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY)
					{
						deleteLastChar();
					}
				}
				else {
					inputlogic(charTyped);
				}
			}
		}
	}
private:
	sf::Text textbox;
	std::ostringstream text;
	bool IsSelected = false;
	bool hasLimit = false;
	int limit;

	void inputlogic(int charTyped)
	{
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
			text << static_cast<char>(charTyped);
		else if (charTyped == DELETE_KEY)
		{
			if (text.str().length() > 0)
			{
				deleteLastChar();
			}
		}
		textbox.setString(text.str() + "_");
	}

	void deleteLastChar()
	{
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}
		text.str("");
		text << newT;

		textbox.setString(text.str());
	}
};