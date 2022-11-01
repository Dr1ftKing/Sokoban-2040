// Copyright Juan Lopez [UMASS_Lowell] [10/2022]
#include <cmath>
#include "Sokoban.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr <<\
         "Incorrect usage. Usage:./Sokoban level1.txt"\
          << std::endl;
        exit(-1);
    }
    SokobanMap levelLayout;
    try {
        std::ifstream fin (argv[1]);
        fin >> levelLayout;
    }
    catch(std::invalid_argument& err) {
        std::cout << err.what()<<std::endl;
        exit(-1);
    }

    int _windowX = (levelLayout.getColumn()*100)/3;
    int _windowY = (levelLayout.getRow()*100)/3;

    // window size should be getsize of one image then * by perimeter size
    sf::RenderWindow window(sf::VideoMode\
    (_windowX, _windowY), "Sokoban");
    window.setFramerateLimit(60);




// SFML display loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        window.draw(levelLayout);
        window.display();
    }
}
