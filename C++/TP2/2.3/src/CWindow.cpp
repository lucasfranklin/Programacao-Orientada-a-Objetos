#include "../include/CWindow.h"

using namespace std;

CWindow::CWindow(const int newX,const int newY,const int newCx,const int newCy)
{
    x = newX;
    y = newY;
    cX = newCx;
    cY = newCy;
    my_canvas = new Canvas();
}

int CWindow::setTextColor(const Color& color)
{
    my_canvas->setFontColor(color);
}

int CWindow::show() const
{
    cout << "Janela desenhada na posicao (" << x << "," << y << ") com largura "<< cX << " e altura " << cY << endl;
}

int CWindow::resize(const int newCx,const int newCy)
{
    cX = newCx;
    cY = newCy;
    show();
    return 0;
}

int CWindow::move(const int newX,const int newY)
{
    x = newX;
    y = newY;
    show();
    return 0;
}

int CWindow::textOut(const int positionX,const int positionY, char* text) const
{
    cout << text << " na posicao ("<< positionX << "," << positionY << ")";
    return 1;
}

bool CWindow::writeAttributes(const string fileName) const
{

    ofstream outFile(fileName.c_str());

    if(!outFile) return false;

    //CWindow DATA
    outFile << x << " " << y << endl;
    outFile << cX << " " << cY << endl << endl;

    Color fontColor = my_canvas->getFontColor();
    Color featherColor = my_canvas->getFeatherColor();
    Color brushColor = my_canvas->getBrushColor();

    //CANVAS DATA
    outFile << fontColor.getRGBstr() << endl;
    outFile << my_canvas->getFontType() << endl;
    outFile << my_canvas->getFontSize() << endl;
    outFile << featherColor.getRGBstr() << endl;
    outFile << brushColor.getRGBstr() << endl;

    return true;
}

bool CWindow::readAttributes(const string fileName)
{

    ifstream inFile(fileName.c_str());
    int red,green,blue, fontSize;
    string fontType;

    if(!inFile) return false;

    inFile >> x >> y;
    inFile >> cX >> cY;

    inFile >> red >> green >> blue;
    Color fontColor(red,green,blue);
    my_canvas->setFontColor(fontColor);

    inFile >> fontType;
    my_canvas->setFontType(fontType);

    inFile >> fontSize;
    my_canvas->setFontSize(fontSize);

    inFile >> red >> green >> blue;
    Color featherColor(red,green,blue);
    my_canvas->setFeatherColor(featherColor);

    inFile >> red >> green >> blue;
    Color brushColor(red,green,blue);
    my_canvas->setBrushColor(brushColor);

    return true;
}


CWindow::~CWindow()
{
    delete my_canvas;
    //Destructor
}

//-----INICIO DOS METODOS DA CLASSE CANVAS-----

CWindow::Canvas::Canvas(const Color newFontColor,const Color newFeatherColor,const Color newBrushColor,const int newFontSize,const string newFontType)
{
    fontColor = newFontColor;
    fontSize = newFontSize;
    fontType = newFontType;
    featherColor = newFeatherColor;
    brushColor = newBrushColor;
}

void CWindow::Canvas::setFontColor(const Color& newFontColor)
{
    fontColor = newFontColor;
}
void CWindow::Canvas::setFontSize(const int newFontSize)
{
    fontSize = newFontSize;
}
void CWindow::Canvas::setFontType(const string newFontType)
{
    fontType = newFontType;
}
void CWindow::Canvas::setFeatherColor(const Color& newFeatherColor)
{
    featherColor = newFeatherColor;
}
void CWindow::Canvas::setBrushColor(const Color& newBrushColor)
{
    brushColor = newBrushColor;
}
Color CWindow::Canvas::getFontColor() const
{
    return fontColor;
}
int CWindow::Canvas::getFontSize() const
{
    return fontSize;
}
string CWindow::Canvas::getFontType() const
{
    return fontType;
}
Color CWindow::Canvas::getFeatherColor() const
{
    return featherColor;
}
Color CWindow::Canvas::getBrushColor() const
{
    return brushColor;
}
CWindow::Canvas::~Canvas()
{
    //Destructor
}
//-----FIM DOS METODOS DA CLASSE CANVAS-----

//-----PEGANDO ATRIBUTOS DE CANVAS A PARTIR DE CWindow
Color CWindow::getCanvasFontColor() const
{
    return my_canvas->getFontColor();
}
int CWindow::getCanvasFontSize() const
{
    return my_canvas->getFontSize();
}
string CWindow::getCanvasFontType() const
{
    return my_canvas->getFontType();
}
Color CWindow::getCanvasFeatherColor() const
{
    return my_canvas->getFeatherColor();
}
Color CWindow::getCanvasBrushColor() const
{
    return my_canvas->getBrushColor();
}
