#include <iostream>
#include <string>
#include "include/Color.h"
#include "include/CWindow.h"

using namespace std;

bool dataCWindow();
void dataCanvas(CWindow& window);

int main()
{
    CWindow window(20,20,40,40);

    cout << "- Dados em CWindow" << endl << endl;
    cout << window;

    ifstream file("newAtributtes.txt");
    file >> window;

    cout << endl << "- Dados em CWindow depois da leitura" << endl << endl;
    cout << window;

    cout << endl << "- Teste de copia de canvas" << endl << endl;

    window.testCanvasCopy();

    return 0;
}
