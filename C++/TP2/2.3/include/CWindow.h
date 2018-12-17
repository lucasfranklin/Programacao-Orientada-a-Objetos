#ifndef CWindow_H
#define CWindow_H

#include <iostream>
#include <fstream>
#include <string>
#include "Color.h"

class CWindow
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
        ~Canvas();

    };
    //---FIM DA CLASSE CANVAS---

private:
    int x,y;
    int cX,cY;
    Canvas* my_canvas;

public:
    CWindow(const int newX,const int newY,const int newCx,const int newCy);
    ~CWindow();
    int show() const; //mostra tela
    int move(const int newX,const int newY);   //Move
    int resize(const int newCx,const int newCy);   //Redimensiona
    int setTextColor(const Color& color);
    int textOut(const int positionX,const int positionY, char* text) const;  //Texto em xy
    bool writeAttributes(const std::string fileName) const;
    bool readAttributes(const std::string fileName);
    //---PEGA ATRIBUTOS DE CANVAS A PARTIR DE CWindow---
    Color getCanvasFontColor() const;
    int getCanvasFontSize() const;
    std::string getCanvasFontType() const;
    Color getCanvasFeatherColor() const;
    Color getCanvasBrushColor() const;
};

#endif // CWindow_H
