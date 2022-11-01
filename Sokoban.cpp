// Copyright Juan Lopez [UMASS_Lowell] [10/2022]
#include "Sokoban.hpp"
SokobanMap::SokobanMap():\
columnNumber(0), rowNumber(0) {}

int SokobanMap::getColumn(void) const {
    return columnNumber;
}
int SokobanMap::getRow(void) const {
    return rowNumber;
}

void SokobanMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(spriteMap, states);
}


// overloaded insertion operator for file input through terminal
std::istream& operator>>(std::istream& in, SokobanMap& SokobanMap) {
    in >> SokobanMap.columnNumber;
    in >> SokobanMap.rowNumber;
    // Read in the grid information from the file. For now, only worry about wall vs non-wall tiles
    char _input;
    // while not the end of a string the loops separates wall from non wall.
    while(_input != '\0'){
        in >> _input;
        
        if(_input == '#'){
            SokobanMap.wall.push_back(_input);
        } else{
            SokobanMap.nonWall.push_back(_input);
        }

    }

    return in;
}
