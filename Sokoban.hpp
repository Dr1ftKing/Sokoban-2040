// Copyright Juan Lopez [UMASS_Lowell] [10/2022]
#ifndef _HOME_OEM_DESKTOP_PROJECT_PROJECT_4_PS4A_SOKOBAN_HPP_
#define _HOME_OEM_DESKTOP_PROJECT_PROJECT_4_PS4A_SOKOBAN_HPP_

#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>


class Sokoban : public sf::Drawable {
 public:
    // constructors
    Sokoban();
    explicit Sokoban(std::string image_filename);
    explicit Sokoban(const Sokoban& copySokoban);
    explicit Sokoban(Sokoban&& moveSokoban) noexcept;
    ~Sokoban();

    // accessors and mutators
    int getXPlane(void) const;
    int getYPlane(void) const;
    sf::Image getImage(void) const;


    void setXPlane(int);
    void setYPlane(int);
    void setImage(std::string imageFileName);

    // overloaded assignment operators for Sokoban setup in main
    Sokoban& operator=(Sokoban& cpyInptVal);
    Sokoban& operator=(Sokoban&& mvInptVal) noexcept;


    // overloaded insertion operator for file input through terminal
 private:
    // override virtual draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    int xPlane;
    int yPlane;
    sf::Image image; // image data for Sokoban
    sf::Texture texture;
    sf::Sprite sprite;
};
std::istream& operator>>(std::istream& in, Sokoban& Sokoban);
std::ostream& operator<<(std::ostream& out, Sokoban& Sokoban);

#endif  // _HOME_OEM_DESKTOP_PROJECT_PROJECT_4_PS4A_SOKOBAN_HPP_
