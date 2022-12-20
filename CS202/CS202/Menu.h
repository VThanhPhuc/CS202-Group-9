#pragma once
#include "Background.h"
#include "People.h"
#include "CCAR.h"
//class TextBox
//{
//public:
//	TextBox()
//	{
//
//	}
//
//	TextBox(int size, sf::Color color, bool sel) {
//		textbox.setCharacterSize(size);
//		textbox.setColor(color);
//		IsSelected = sel;
//		if (sel)
//		{
//			textbox.setString("_");
//		}
//		else
//		{
//			textbox.setString("");
//		}
//	}
//
//	void setFont(sf::Font& font) {
//		textbox.setFont(font);
//	}
//
//	void setPosition(sf::Vector2f pos)
//	{
//		textbox.setPosition(pos);
//	}
//
//	void setLimit(bool ToF,int lim)
//	{
//		hasLimit = ToF;
//		limit = lim;
//	}
//
//	void setSelected(bool sel)
//	{
//		IsSelected = sel;
//		if (!sel)
//		{
//			std::string t = text.str();
//			std::string newT = "";
//			for (int i = 0; i < t.length() - 1; i++){
//				newT += t[i];
//			}
//			textbox.setString(newT);
//		}
//	}
//
//	string getText()
//	{
//		return text.str();
//	}
//
//	void drawTo(sf::RenderWindow& window)
//	{
//		window.draw(textbox);
//	}
//
//	void typeOn(sf::Event input) {
//		if (IsSelected)
//		{
//			int charTyped = input.text.unicode;
//			if (charTyped < 128)
//			{
//				if (hasLimit)
//				{
//					if (text.str().length() <= limit)
//					{
//						inputlogic(charTyped);
//					}
//					else if (text.str().length() > limit && charTyped == DELETE_KEY)
//					{
//						deleteLastChar();
//					}
//				}
//				else {
//					inputlogic(charTyped);
//				}
//			}
//		}
//	}
//private:
//	sf::Text textbox;
//	std::ostringstream text;
//	bool IsSelected = false;
//	bool hasLimit = false;
//	int limit;
//
//	void inputlogic(int charTyped)
//	{
//		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
//			text << static_cast<char>(charTyped);
//		else if (charTyped == DELETE_KEY)
//		{
//			if (text.str().length() > 0)
//			{
//				deleteLastChar();
//			}
//		}
//		textbox.setString(text.str() + "_");
//	}
//
//	void deleteLastChar()
//	{
//		std::string t = text.str();
//		std::string newT = "";
//		for (int i = 0; i < t.length() - 1; i++)
//		{
//			newT += t[i];
//		}
//		text.str("");
//		text << newT;
//
//		textbox.setString(text.str());
//	}
//};
class Menu
{
private:
	sf::Sprite MenuBackground;
	sf::RectangleShape button_start; // begin the game
	sf::RectangleShape button_exit; // quit the game
	sf::RectangleShape button_back; //get back to the menu
	sf::RectangleShape menu_in_game; // menu
	sf::RectangleShape button_resume;

	sf::RectangleShape continue_button;
	sf::RectangleShape button_back1;
	sf::RectangleShape you_lose1;

	sf::Texture t;
	sf::Texture exit_button;
	sf::Texture s_button;
	sf::Texture b_button;
	sf::Texture menu_;
	sf::Texture resume;
	sf::Texture continue_p;
	sf::Texture b1_button;
	sf::Texture you_lose;
public:
	void InnitMenuBackground();
	void draw_menu(sf::RenderWindow& window);
	int Start_Play(sf::RenderWindow& window);
	int CheckMouseGamePlay(sf::RenderWindow& window);
	void Draw_Menu_In_game(sf::RenderWindow& window);
	void Menu_control(sf::RenderWindow& window, sf::Event event, Background d);
	void LoseGame(sf::RenderWindow& window);
	int ChoiceLoseGame(sf::RenderWindow& window);
	void Begin();
	void PlayGame(sf::RenderWindow& window, Background d, int& return1);
};