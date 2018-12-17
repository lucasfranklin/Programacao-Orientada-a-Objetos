#include <iostream>
#include <string>
#include "include/Color.h"
#include "include/CWindow.h"

using namespace std;

bool dataCWindow();
void dataCanvas(CWindow& window);

int main()
{
    bool status;

    //Metodos da Classe CWindow
    status = dataCWindow();

    if(!status) cout << endl << "Erro ao carregar o arquivo";

    return 0;
}

bool dataCWindow()
{

    CWindow window(20,20,40,40);

    //Invoca o metodo show()
    cout << "Show(): ";
    window.show();

    //invoca o metodo move() que seta as coordenadas X e Y
    cout << "Move(): ";
    window.move(10,20);

    //Invoca o metodo resize() para redimensionar a largura e a altura
    cout << "Resize(): ";
    window.resize(35,45);

    //Invoca metodo setTextColor() para setar a cor do textp
    Color color(0,0,0); //Cor preta
    window.setTextColor(color);

    //Invoca o metodo textOut que posiciona o texto nas coordenadas X e Y
    char *text = "Texto";
    window.textOut(5, 5, text);

    //Carrega do arquivo valores para os atributos de CWindow e Canvas
    dataCanvas(window);

    //Escreve todos os atributos de CWindow e Canvas em arquivo
    window.writeAttributes("atributtes.txt");

    bool status = window.readAttributes("newAtributtes.txt");

    if(status)
    {
        cout << endl << endl << "+Atributos carregados do arquivo: " << endl << endl;
        window.show();
        dataCanvas(window);
    }

    else return false;

    return status;
}

void dataCanvas(CWindow& window)
{
    Color color;
    //-----Metodos da classe CWindow que retornam os atributos da classe Canvas
    cout << endl << endl << "+CANVAS: " << endl;
    color = window.getCanvasFontColor();
    cout << "Cor da fonte: " << color.getRGBstr() << endl;
    cout << "Tamanho da fonte: " << window.getCanvasFontSize() << endl;
    cout << "Tipo de fonte: " << window.getCanvasFontType() << endl;
    color = window.getCanvasFeatherColor();
    cout << "Cor da pena: " << color.getRGBstr() << endl;
    color =  window.getCanvasBrushColor();
    cout << "Cor do pincel: " << color.getRGBstr() << endl;
}
