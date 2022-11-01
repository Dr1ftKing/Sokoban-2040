// Copyright Juan Lopez [UMASS_Lowell] [10/2022]
#ifndef _HOME_OEM_DESKTOP_PROJECT_PROJECT_4_PS4A_SOKOBAN_HPP_
#define _HOME_OEM_DESKTOP_PROJECT_PROJECT_4_PS4A_SOKOBAN_HPP_

#include <exception>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/*
The Sokoban class should have the following features:

It must be sf::Drawable, with a private virtual void method named draw (as required of sf::Drawable subclasses).

A movePlayer() method that takes an enumeration corresponding to one of the car- dinal directions that changes the player's location.
For this part, movePlayer() is allowed to do nothing. You will complete this for part (b).

It may contain a sf::Sprite object (as well as the sf::Texture object needed to hold the Sprite's image).

A >> operator which reads the level from a stream. You may want to add a << operator that writes the level back to a stream.
*/

class Sokoban : public sf::Drawable {
 public:
    // constructors
    Sokoban();


    // overloaded insertion operator for file input through terminal
 private:
    // override virtual draw function
    friend std::istream& operator>>(std::istream& in, Sokoban& Sokoban);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

class SokobanMap : public sf::Drawable {
 public:
    // constructors
    SokobanMap();
    // accessors and mutators
    int getColumn(void) const;
    int getRow(void) const;

 private:
    // override virtual draw function
    friend std::istream& operator>>(std::istream& in, SokobanMap& SokobanMap);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    int columnNumber;
    int rowNumber;
    std::string wall;
    std::string nonWall;
    sf::Texture textureMap;
    sf::Sprite spriteMap;
    // create helper class
    // bare bones means nothing in it, maybe default construcotr.
    // then create istream operator, that reads in data. From level file. Col number and row number. add these fields to sokoban
    //  have draw function just draw, havent read data in level, just dimensions
    // at this point should have correct dimensions
    // determine how to represent map,(helper class?)
    // concern should be whether its a wall or non wall
    // then modify draw to do wall or floor

    // should I store all 5 things together or wall.floor in one conatainer and the other three in another
};

// std::ostream& operator<<(std::ostream& out, Sokoban& Sokoban);

#endif  // _HOME_OEM_DESKTOP_PROJECT_PROJECT_4_PS4A_SOKOBAN_HPP_
