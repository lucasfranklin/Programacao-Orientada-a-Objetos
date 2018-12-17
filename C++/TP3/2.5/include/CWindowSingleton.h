#ifndef CWindowSingleton_H
#define CWindowSingleton_H

#include <string>
#include <iostream>
#include <fstream>
#include "Color.h"

class CWindowSingleton
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
        Canvas(const Canvas& copyCanvas);
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
        Canvas operator= (const Canvas& attObject);

    };
    //---FIM DA CLASSE CANVAS---

private:
    int x,y;
    int cX,cY;
    Canvas* my_canvas;
    static CWindowSingleton *instancePointer;

public:
    static CWindowSingleton *Instance(const int newX = 0,const int newY = 0,const int newCx = 0,const int newCy = 0);
    int show() const; //mostra tela
    int move(const int newX,const int newY);   //Move
    int resize(const int newCx, const int newCy);   //Redimensiona
    int setTextColor(const Color& color);
    int textOut(const int positionX, const int positionY, char* text) const;  //Texto em xy
    bool writeAttributes(const std::string fileName) const;
    bool readAttributes(const std::string fileName);
    //---PEGA ATRIBUTOS DE CANVAS A PARTIR DE CWindowSingleton---
    Color getCanvasFontColor() const;
    int getCanvasFontSize() const;
    std::string getCanvasFontType() const;
    Color getCanvasFeatherColor() const;
    Color getCanvasBrushColor() const;
    ~CWindowSingleton();
    friend std::istream& operator>>(std::istream& input, CWindowSingleton& flowIn);
    friend std::ostream& operator<<(std::ostream& output, const CWindowSingleton& flowOut);
    void setCanvasFontColor(Color& fontColor);
    void setCanvasFontSize(int& fontSize);
    void setCanvasFontType(std::string& fontType);
    void setCanvasFeatherColor(Color& featherColor);
    void setCanvasBrushColor(Color& brushColor);

private:
    CWindowSingleton(const int newX = 0, const int newY = 0, const int newCx = 0, const int newCy = 0);
    void setInstancePointer();
    CWindowSingleton(const CWindowSingleton& copyObject);
    CWindowSingleton operator= (const CWindowSingleton& attCWindow);


};

inline void CWindowSingleton::Canvas::setFontColor(const Color& newFontColor)
{
    fontColor = newFontColor;
}
inline void CWindowSingleton::Canvas::setFontSize(const int newFontSize)
{
    fontSize = newFontSize;
}
inline void CWindowSingleton::Canvas::setFontType(const std::string newFontType)
{
    fontType = newFontType;
}
inline void CWindowSingleton::Canvas::setFeatherColor(const Color& newFeatherColor)
{
    featherColor = newFeatherColor;
}
inline void CWindowSingleton::Canvas::setBrushColor(const Color& newBrushColor)
{
    brushColor = newBrushColor;
}
inline Color CWindowSingleton::Canvas::getFontColor() const
{
    return fontColor;
}
inline int CWindowSingleton::Canvas::getFontSize() const
{
    return fontSize;
}
inline std::string CWindowSingleton::Canvas::getFontType() const
{
    return fontType;
}
inline Color CWindowSingleton::Canvas::getFeatherColor() const
{
    return featherColor;
}
inline Color CWindowSingleton::Canvas::getBrushColor() const
{
    return brushColor;
}

//-----PEGANDO ATRIBUTOS DE CANVAS A PARTIR DE CWindowSingleton
inline Color CWindowSingleton::getCanvasFontColor() const
{
    return my_canvas->getFontColor();
}
inline int CWindowSingleton::getCanvasFontSize() const
{
    return my_canvas->getFontSize();
}
inline std::string CWindowSingleton::getCanvasFontType() const
{
    return my_canvas->getFontType();
}
inline Color CWindowSingleton::getCanvasFeatherColor() const
{
    return my_canvas->getFeatherColor();
}
inline Color CWindowSingleton::getCanvasBrushColor() const
{
    return my_canvas->getBrushColor();
}

//Metodos de set de canvas

inline void CWindowSingleton::setCanvasFontColor(Color& fontColor)
{
    my_canvas->setFontColor(fontColor);
}
inline void CWindowSingleton::setCanvasFontSize(int& fontSize)
{
    my_canvas->setFontSize(fontSize);
}
inline void CWindowSingleton::setCanvasFontType(std::string& fontType)
{
    my_canvas->setFontType(fontType);
}
inline void CWindowSingleton::setCanvasFeatherColor(Color& featherColor)
{
    my_canvas->setFeatherColor(featherColor);
}
inline void CWindowSingleton::setCanvasBrushColor(Color& brushColor)
{
    my_canvas->setBrushColor(brushColor);
}
#endif // CWindowSingleton_H
