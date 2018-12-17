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
        Canvas(const Canvas& copyObject);
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

        ~Canvas();

    };
    //---FIM DA CLASSE CANVAS---

private:
    int x,y;
    int cX,cY;
    Canvas* my_canvas;

public:
    CWindow(const int newX,const int newY,const int newCx,const int newCy);
    CWindow(const CWindow& copyObject);
    ~CWindow();
    int show() const; //mostra tela
    int move(const int newX,const int newY);   //Move
    int resize(const int newCx,const int newCy);   //Redimensiona
    int setTextColor(const Color& color);
    int textOut(const int positionX,const int positionY, char* text) const;  //Texto em xy
    bool writeAttributes(const std::string fileName) const;
    bool readAttributes(const std::string fileName);
    CWindow operator= (const CWindow& attCWindow);
    friend std::istream& operator>>(std::istream& input, CWindow& flowIn);
    friend std::ostream& operator<<(std::ostream& output, const CWindow& flowOut);
    //---PEGA ATRIBUTOS DE CANVAS A PARTIR DE CWindow---
    Color getCanvasFontColor() const;
    int getCanvasFontSize() const;
    std::string getCanvasFontType() const;
    Color getCanvasFeatherColor() const;
    Color getCanvasBrushColor() const;
    void setCanvasFontColor(Color& fontColor);
    void setCanvasFontSize(int& fontSize);
    void setCanvasFontType(std::string& fontType);
    void setCanvasFeatherColor(Color& featherColor);
    void setCanvasBrushColor(Color& brushColor);
    //Metodos de Teste
    void copyCanvas(Canvas copyCanvas);
    void testCanvasCopy();
};

inline void CWindow::Canvas::setFontColor(const Color& newFontColor)
{
    fontColor = newFontColor;
}
inline void CWindow::Canvas::setFontSize(const int newFontSize)
{
    fontSize = newFontSize;
}
inline void CWindow::Canvas::setFontType(const std::string newFontType)
{
    fontType = newFontType;
}
inline void CWindow::Canvas::setFeatherColor(const Color& newFeatherColor)
{
    featherColor = newFeatherColor;
}
inline void CWindow::Canvas::setBrushColor(const Color& newBrushColor)
{
    brushColor = newBrushColor;
}
inline Color CWindow::Canvas::getFontColor() const
{
    return fontColor;
}
inline int CWindow::Canvas::getFontSize() const
{
    return fontSize;
}
inline std::string CWindow::Canvas::getFontType() const
{
    return fontType;
}
inline Color CWindow::Canvas::getFeatherColor() const
{
    return featherColor;
}
inline Color CWindow::Canvas::getBrushColor() const
{
    return brushColor;
}

//-----FIM DOS METODOS DA CLASSE CANVAS-----

//-----PEGANDO ATRIBUTOS DE CANVAS A PARTIR DE CWindow
inline Color CWindow::getCanvasFontColor() const
{
    return my_canvas->getFontColor();
}
inline int CWindow::getCanvasFontSize() const
{
    return my_canvas->getFontSize();
}
inline std::string CWindow::getCanvasFontType() const
{
    return my_canvas->getFontType();
}
inline Color CWindow::getCanvasFeatherColor() const
{
    return my_canvas->getFeatherColor();
}
inline Color CWindow::getCanvasBrushColor() const
{
    return my_canvas->getBrushColor();

}

//Metodos de set de canvas

inline void CWindow::setCanvasFontColor(Color& fontColor)
{
    my_canvas->setFontColor(fontColor);
}
inline void CWindow::setCanvasFontSize(int& fontSize)
{
    my_canvas->setFontSize(fontSize);
}
inline void CWindow::setCanvasFontType(std::string& fontType)
{
    my_canvas->setFontType(fontType);
}
inline void CWindow::setCanvasFeatherColor(Color& featherColor)
{
    my_canvas->setFeatherColor(featherColor);
}
inline void CWindow::setCanvasBrushColor(Color& brushColor)
{
    my_canvas->setBrushColor(brushColor);
}
#endif // CWindow_H
