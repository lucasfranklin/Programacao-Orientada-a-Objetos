#include "../include/Color.h"

using namespace std;

Color::Color(const int newRed,const int newGreen,const int newBlue)
{
    red = newRed;
    green = newGreen;
    blue = newBlue;
}

Color::Color(const Color& copyObject)
{
    red = copyObject.red;
    green = copyObject.green;
    blue = copyObject.blue;
}

void Color::setRed(const int newRed)
{
    red = newRed;
}

void Color::setGreen(const int newGreen)
{
    green = newGreen;
}

void Color::setBlue(const int newBlue)
{
    blue = newBlue;
}

void Color::setRGB(const int newRed, int newGreen, int newBlue)
{
    setRed(newRed);
    setGreen(newGreen);
    setBlue(newBlue);
}

int Color::getRed() const
{
    return red;
}

int Color::getGreen() const
{
    return green;
}

int Color::getBlue() const
{
    return blue;
}

string Color::getRGBstr() const
{
    stringstream myString;  //Classe Strem para operações com string
    myString << red << " " << green << " " << blue;
    return myString.str();
}

Color Color::operator=(const Color& attColor)
{
    if(this==&attColor) return *this;
    red = attColor.red;
    green = attColor.green;
    blue = attColor.blue;
    return *this;
}



Color::~Color()
{
    //destructor
}
