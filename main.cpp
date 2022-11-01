// Copyright Juan Lopez [UMASS_Lowell] [06/06/2022]
#include <cmath>
#include "Sokoban.hpp"

int main(int argc, char* argv[]) {
        if (argc != 1) {
        std::cerr <<\
         "Incorrect usage. Usage:./Sokoban level1.txt"\
          << std::endl;
        exit(-1);
    }
    SokobanMap levelLayout;
    std::cin >> levelLayout;

    int _windowX = (levelLayout.getColumn()*100)/3;
    int _windowY = (levelLayout.getRow()*100)/3;


    sf::RenderWindow window(sf::VideoMode\
    (_windowX, _windowY), "Sokoban");
    window.setFramerateLimit(60);

    // get Sokoban data from file input
    // std::cin >> Sokoban;

// SFML display loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        window.display();
    }
}
