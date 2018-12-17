#include "../include/Color.h"

using namespace std;

Color::Color(const int newRed,const int newGreen,const int newBlue)
{
    setRed(newRed);
    setGreen(newGreen);
    setBlue(newBlue);
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

void Color::setRGB(const int newRed,const int newGreen,const int newBlue)
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
    //Classe para trabalhar com opeçaões com String
    stringstream myString;
    //myStreng recebe uma nova string a partir dos atributos, do tipo int da classe
    myString << red << " " << green << " " << blue;
    return myString.str();
}

Color::~Color()
{
    //destructor
}
