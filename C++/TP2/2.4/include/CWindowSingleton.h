#ifndef CWindowSingleton_H
#define CWindowSingleton_H

#include <string>
#include <iostream>
#include <fstream>
#include "Color.h"

class CWindowingleton
{
    //---INICIO CLASSE CANVAS---
    class Canvas
    {
    private:
        Color fontColor;
        int fontSize;
        std::string fontType;
        Color featherColor; //Cor da pena
        Color brushColor; //cor do pincel

    public:
        Canvas(const Color newFontColor = Color(0,0,0),const Color newFeatherColor = Color(255,255,255),const Color newBrushColor = Color(128,128,128),const int newFontSize= 12,const std::string newFontType = "Arial");
        ~Canvas();
        Color getFontColor() const;
        int getFontSize() const;
        std::string getFontType() const;
        Color getFeatherColor() const;
        Color getBrushColor() const;
        void setFontColor(const Color& newFontColor);
        void setFontSize(const int newFontSize);
        void setFontType(const std::string newFontType);
        void setFeatherColor(const Color& newFeatherColor);
        void setBrushColor(const Color& newBrushColor);

    };
    //---FIM DA CLASSE CANVAS---

private:
    int x,y;
    int cX,cY;
    Canvas* my_canvas;
    static CWindowingleton *instancePointer;

public:
    static CWindowingleton *Instance(const int newX = 0,const int newY = 0,const int newCx = 0,const int newCy = 0);
    int show() const; //mostra tela
    int move(const int newX,const int newY);   //Move
    int resize(const int newCx, const int newCy);   //Redimensiona
    int setTextColor(const Color& color);
    int textOut(const int positionX, const int positionY, char* text) const;  //Texto em xy
    bool writeAttributes(const std::string fileName) const;
    bool readAttributes(const std::string fileName);
    //---PEGA ATRIBUTOS DE CANVAS A PARTIR DE CWindowingleton---
    Color getCanvasFontColor() const;
    int getCanvasFontSize() const;
    std::string getCanvasFontType() const;
    Color getCanvasFeatherColor() const;
    Color getCanvasBrushColor() const;
    ~CWindowingleton();

private:
    CWindowingleton(const int newX = 0, const int newY = 0, const int newCx = 0, const int newCy = 0);
    void setInstancePointer();

};

#endif // CWindowingleton_H
