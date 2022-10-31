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
    int _inputXPlane;
    int _inputYPlane;
    std::cin >> _inputXPlane;
    std::cin >> _inputYPlane;

    int _windowX = (_inputXPlane*100)/3;
    int _windowY = (_inputYPlane*100)/3;

    Sokoban Sokoban;
    try {
        //  Sokoban = Sokoban("nbody/starfield.jpg");
        std::cin >> Sokoban;
    }
    catch (std::invalid_argument& err) {
        std::cout << err.what() << std::endl;
        exit(-1);
    }

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
