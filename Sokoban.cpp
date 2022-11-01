// Copyright Juan Lopez [UMASS_Lowell] [10/2022]
#include "Sokoban.hpp"
SokobanMap::SokobanMap():\
columnNumber(0), rowNumber(0),\
wall(0), nonWall(0) {}

int SokobanMap::getColumn(void) const {
    return columnNumber;
}
int SokobanMap::getRow(void) const {
    return rowNumber;
}
void SokobanMap::setTextureMap(std::string imageFileName) {
    if (!textureMap.loadFromFile(imageFileName)) {
        throw std::invalid_argument("texture image file not found, exiting.");
    }
    // textureMap.loadFromFile(image);
}

void SokobanMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(spriteMap, states);
}
void SokobanMap::drawMap(){

}


// overloaded insertion operator for file input through terminal
std::istream& operator>>(std::istream& in, SokobanMap& SokobanMap) {
    in >> SokobanMap.columnNumber;
    in >> SokobanMap.rowNumber;
    // Read in the grid information from the file. For now, only worry about wall vs non-wall tiles
    char _input = 'a';
    // while not the end of a string the loops separates wall from non wall.
    for(int i = 0; i <(SokobanMap.columnNumber*SokobanMap.rowNumber);i++){
        in >> _input;
        
        if(_input == '#'){
            SokobanMap.wall++;
        } else{
            SokobanMap.nonWall++;
        }

    }

    return in;
}
