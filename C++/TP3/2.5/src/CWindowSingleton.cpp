#include "../include/CWindowSingleton.h"

using namespace std;

CWindowSingleton *CWindowSingleton::instancePointer = NULL;

CWindowSingleton* CWindowSingleton::Instance(const int newX, const int newY, const int newCx, const int newCy)
{

    if(!instancePointer)
    {
        instancePointer = new CWindowSingleton(newX,newY,newCx,newCy);
    }

    return instancePointer;
}

CWindowSingleton::CWindowSingleton(const int newX, const int newY, const int newCx, const int newCy)
{
    x = newX;
    y = newY;
    cX = newCx;
    cY = newCy;
    my_canvas = new Canvas();
}

CWindowSingleton::CWindowSingleton(const CWindowSingleton& copyObject)
{

    x = copyObject.x;
    y = copyObject.y;
    cX = copyObject.cX;
    cY = copyObject.cY;

    Color fontColor = copyObject.my_canvas->getFontColor();
    Color featherColor = copyObject.my_canvas->getFeatherColor();
    int fontSize = copyObject.my_canvas->getFontSize();
    string fontType = copyObject.my_canvas->getFontType();

    setCanvasFontColor(fontColor);
    setCanvasFeatherColor(featherColor);
    setCanvasFontSize(fontSize);
    setCanvasFontType(fontType);
}

CWindowSingleton CWindowSingleton::operator= (const CWindowSingleton& attCWindow)
{

    if(this==&attCWindow) return *this;

    x = attCWindow.x;
    y = attCWindow.y;
    cX = attCWindow.cX;
    cY = attCWindow.cY;

    Color fontColor = attCWindow.my_canvas->getFontColor();
    Color featherColor = attCWindow.my_canvas->getFeatherColor();
    int fontSize = attCWindow.my_canvas->getFontSize();
    string fontType = attCWindow.my_canvas->getFontType();

    setCanvasFontColor(fontColor);
    setCanvasFeatherColor(featherColor);
    setCanvasFontSize(fontSize);
    setCanvasFontType(fontType);

    return *this;

}

int CWindowSingleton::setTextColor(const Color& color)
{
    my_canvas->setFontColor(color);
    return 0;
}

int CWindowSingleton::show() const
{
    cout << "Janela desenhada na posicao (" << x << "," << y << ") com largura "<< cX << " e altura " << cY << endl;
    return 0;
}

int CWindowSingleton::resize(const int newCx, const int newCy)
{
    cX = newCx;
    cY = newCy;
    show();
    return 0;
}

int CWindowSingleton::move(const int newX, const int newY)
{
    x = newX;
    y = newY;
    show();
    return 0;
}

int CWindowSingleton::textOut(const int positionX, const int positionY, char* text) const
{
    cout << text << " na posicao ("<< positionX << "," << positionY << ")";
    return 0;
}

bool CWindowSingleton::writeAttributes(const string fileName) const
{

    ofstream outFile(fileName.c_str());

    if(!outFile) return false;

    //CWindowSingleton DATA
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

bool CWindowSingleton::readAttributes(const string fileName)
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

istream& operator>>(istream& input, CWindowSingleton& flowIn)
{

    int red,green,blue, fontSize;
    string fontType;


    input >> flowIn.x >> flowIn.y;
    input >> flowIn.cX >> flowIn.cY;

    input >> red >> green >> blue;
    Color fontColor(red,green,blue);
    flowIn.my_canvas->setFontColor(fontColor);

    input >> fontType;
    flowIn.my_canvas->setFontType(fontType);

    input >> fontSize;
    flowIn.my_canvas->setFontSize(fontSize);

    input >> red >> green >> blue;
    Color featherColor(red,green,blue);
    flowIn.my_canvas->setFeatherColor(featherColor);

    input >> red >> green >> blue;
    Color brushColor(red,green,blue);
    flowIn.my_canvas->setBrushColor(brushColor);

    return input;

}

ostream& operator<<(ostream& output, const CWindowSingleton& flowOut)
{
//CWindow DATA
    output << flowOut.x << " " << flowOut.y << endl;
    output << flowOut.cX << " " << flowOut.cY << endl << endl;

    Color fontColor = flowOut.my_canvas->getFontColor();
    Color featherColor = flowOut.my_canvas->getFeatherColor();
    Color brushColor = flowOut.my_canvas->getBrushColor();

    //CANVAS DATA
    output << fontColor.getRGBstr() << endl;
    output << flowOut.my_canvas->getFontType() << endl;
    output << flowOut.my_canvas->getFontSize() << endl;
    output << flowOut.my_canvas->getFeatherColor().getRGBstr() << endl;
    output << brushColor.getRGBstr() << endl;

    return output;
}

CWindowSingleton::~CWindowSingleton()
{
    delete my_canvas;
    //Destructor
}



//-----INICIO DOS METODOS DA CLASSE CANVAS-----

CWindowSingleton::Canvas::Canvas(const Color newFontColor,const Color newFeatherColor,const Color newBrushColor,const int newFontSize,const string newFontType)
{
    fontColor = newFontColor;
    fontSize = newFontSize;
    fontType = newFontType;
    featherColor = newFeatherColor;
    brushColor = newBrushColor;
}

CWindowSingleton::Canvas::Canvas(const Canvas& copyCanvas)
{
    fontColor = copyCanvas.fontColor;
    fontSize = copyCanvas.fontSize;
    fontType = copyCanvas.fontType;
    featherColor = copyCanvas.featherColor; //Cor da pena
    brushColor = copyCanvas.brushColor; //cor do pincel
}

CWindowSingleton::Canvas CWindowSingleton::Canvas::operator= (const Canvas& attObject)
{

    if(this==&attObject) return *this;

    fontColor = attObject.fontColor;
    fontSize = attObject.fontSize;
    fontType = attObject.fontType;
    featherColor = attObject.featherColor; //Cor da pena
    brushColor = attObject.brushColor; //cor do pincel

    return *this;
}


CWindowSingleton::Canvas::~Canvas()
{
    //Destructor
}

