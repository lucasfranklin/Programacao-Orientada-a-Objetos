#include "../include/CWindowSingleton.h"

using namespace std;

CWindowingleton *CWindowingleton::instancePointer = NULL;

CWindowingleton* CWindowingleton::Instance(const int newX, const int newY, const int newCx, const int newCy){

    if(!instancePointer){
        instancePointer = new CWindowingleton(newX,newY,newCx,newCy);
    }

    return instancePointer;
}

CWindowingleton::CWindowingleton(const int newX, const int newY, const int newCx, const int newCy)
{
    x = newX;
    y = newY;
    cX = newCx;
    cY = newCy;
    my_canvas = new Canvas();
}

int CWindowingleton::setTextColor(const Color& color)
{
    my_canvas->setFontColor(color);
    return 0;
}

int CWindowingleton::show() const
{
    cout << "Janela desenhada na posicao (" << x << "," << y << ") com largura "<< cX << " e altura " << cY << endl;
    return 0;
}

int CWindowingleton::resize(const int newCx, const int newCy)
{
    cX = newCx;
    cY = newCy;
    show();
    return 0;
}

int CWindowingleton::move(const int newX, const int newY)
{
    x = newX;
    y = newY;
    show();
    return 0;
}

int CWindowingleton::textOut(const int positionX, const int positionY, char* text) const
{
    cout << text << " na posicao ("<< positionX << "," << positionY << ")";
    return 0;
}

bool CWindowingleton::writeAttributes(const string fileName) const
{

    ofstream outFile(fileName.c_str());

    if(!outFile) return false;

    //CWindowingleton DATA
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

bool CWindowingleton::readAttributes(const string fileName)
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


CWindowingleton::~CWindowingleton()
{
    delete my_canvas;
    //Destructor
}

//-----INICIO DOS METODOS DA CLASSE CANVAS-----

CWindowingleton::Canvas::Canvas(const Color newFontColor,const Color newFeatherColor,const Color newBrushColor,const int newFontSize,const string newFontType)
{
    fontColor = newFontColor;
    fontSize = newFontSize;
    fontType = newFontType;
    featherColor = newFeatherColor;
    brushColor = newBrushColor;
}

void CWindowingleton::Canvas::setFontColor(const Color& newFontColor)
{
    fontColor = newFontColor;
}
void CWindowingleton::Canvas::setFontSize(const int newFontSize)
{
    fontSize = newFontSize;
}
void CWindowingleton::Canvas::setFontType(const string newFontType)
{
    fontType = newFontType;
}
void CWindowingleton::Canvas::setFeatherColor(const Color& newFeatherColor)
{
    featherColor = newFeatherColor;
}
void CWindowingleton::Canvas::setBrushColor(const Color& newBrushColor)
{
    brushColor = newBrushColor;
}
Color CWindowingleton::Canvas::getFontColor() const
{
    return fontColor;
}
int CWindowingleton::Canvas::getFontSize() const
{
    return fontSize;
}
string CWindowingleton::Canvas::getFontType() const
{
    return fontType;
}
Color CWindowingleton::Canvas::getFeatherColor() const
{
    return featherColor;
}
Color CWindowingleton::Canvas::getBrushColor() const
{
    return brushColor;
}
CWindowingleton::Canvas::~Canvas()
{
    //Destructor
}
//-----FIM DOS METODOS DA CLASSE CANVAS-----

//-----PEGANDO ATRIBUTOS DE CANVAS A PARTIR DE CWindowingleton
Color CWindowingleton::getCanvasFontColor() const
{
    return my_canvas->getFontColor();
}
int CWindowingleton::getCanvasFontSize() const
{
    return my_canvas->getFontSize();
}
string CWindowingleton::getCanvasFontType() const
{
    return my_canvas->getFontType();
}
Color CWindowingleton::getCanvasFeatherColor() const
{
    return my_canvas->getFeatherColor();
}
Color CWindowingleton::getCanvasBrushColor() const
{
    return my_canvas->getBrushColor();
}
