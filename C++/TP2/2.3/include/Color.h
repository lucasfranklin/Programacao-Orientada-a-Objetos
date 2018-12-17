#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <iostream>
#include <sstream>

class Color
{
private:
    int red;
    int green;
    int blue;

public:
    Color(const int newRed = 0,const int newGreen = 0,const int newBlue = 0);
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    std::string getRGBstr() const;
    ~Color();

private:
    void setRed(const int newRed);
    void setGreen(const int newGreen);
    void setBlue(const int newBlue);
    void setRGB(const int newRed, int newGreen, int newBlue);

};

#endif // COLOR_H
