// Copyright Juan Lopez [UMASS_Lowell] [10/2022]
#include "Sokoban.hpp"
Sokoban::Sokoban():\
xPlane(0), yPlane(0) {}

Sokoban::Sokoban(std::string image_filename) {
    if (!image.loadFromFile(image_filename)) {
        throw std::invalid_argument("Sokoban image file not found,"
        " exiting");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    xPlane = 0;
    yPlane = 0;
}

Sokoban::Sokoban(const Sokoban& cpyConstructor) {
    xPlane = cpyConstructor.xPlane;
    yPlane = cpyConstructor.yPlane;
    image = cpyConstructor.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

Sokoban::Sokoban(Sokoban&& mvConstructor) noexcept {
    xPlane = mvConstructor.xPlane;
    yPlane = mvConstructor.yPlane;
    image = mvConstructor.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    mvConstructor.xPlane = 0;
    mvConstructor.yPlane = 0;
}
int Sokoban::getXPlane(void) const {
    return xPlane;
}
int Sokoban::getYPlane(void) const {
    return yPlane;
}
sf::Image Sokoban::getImage(void) const {
    return image;
}


void Sokoban::setXPlane(int numOf) {
    xPlane = numOf;
}
void Sokoban::setYPlane(int iptY) {
    yPlane = iptY;
}
void Sokoban::setImage(std::string imageFileName) {
    if (!image.loadFromFile(imageFileName)) {
        throw std::invalid_argument("Sokoban image file not found, exiting.");
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

Sokoban:: ~Sokoban() {
    xPlane = 0;
    yPlane = 0;
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

std::ostream& operator<<(std::ostream& out, Sokoban& Sokoban) {
    std::cout << Sokoban.getXPlane() <<" "<< Sokoban.getYPlane();

    return out;
}



// overloaded insertion operator for file input through terminal
std::istream& operator>>(std::istream& in, Sokoban& Sokoban) {
    double dubVal;
    std::string image;
    std::string imageFileName;
    sf::Vector2u windowSize = Sokoban.getImage().getSize();


    // get data for each planet
    for (int i = 0; i < Sokoban.getNumOfPlanets(); i++) {
        CelestialBody* planet = new CelestialBody();

        // get xPos
        in >> dubVal;
        dubVal = (((dubVal / 2) / Sokoban.getRadius())\
         * windowSize.x) + (windowSize.x / 2);
        planet->setPosX(dubVal);

        // get yPos
        in >> dubVal;
        dubVal = (((dubVal / 2) / Sokoban.getRadius())\
         * windowSize.y) + (windowSize.y / 2);
        planet->setPosY(dubVal);

        //  planet->updatePosition();

        // get velocity, mass and image file
        in >> dubVal;
        planet->setVelocityX(dubVal);
        in >> dubVal;
        planet->setVelocityY(dubVal);
        in >> dubVal;
        planet->setMass(dubVal);
        in >> imageFileName;
        image = imageFileName;

        try {
            planet->setImage(image);
        }
        catch (std::invalid_argument& err) {
            std::cout << err.what() << std::endl;
            exit(-1);
        }
        Sokoban.planets.push_back(planet);
    }

    return in;
}

Sokoban& Sokoban::operator=(Sokoban& cpyInptVal) {
    if (this == &cpyInptVal) {
       return *this;
    }

    xPlane = cpyInptVal.xPlane;
    yPlane = cpyInptVal.yPlane;
    image = cpyInptVal.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    return *this;
}

Sokoban& Sokoban::operator=(Sokoban&& mvInptVal) noexcept {
    if (this == &mvInptVal) {
        return *this;
    }

    // copy
    xPlane = mvInptVal.xPlane;
    // delete
    mvInptVal.xPlane = 0;
    // copy
    yPlane = mvInptVal.yPlane;
    // delete
    mvInptVal.yPlane = 0;
    // copy
    image = mvInptVal.image;
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    // delete
    mvInptVal.setImage(nullptr);

    return *this;
}
