#include <iostream>

using namespace std;
int potencia(int i, int j);

int main()
{
    int base, exponent, result;
    cout << "- Calculo de Potencia -" << endl << endl << "Entre com a base: ";
    cin >> base;
    cout << "Entre com o expoente: ";
    cin >> exponent;
    result = potencia(base, exponent);
    cout << "Resultado: " << result << endl;
    return 0;
}

int potencia(int i, int j){

    if(j==0) return 1;
    else return i*potencia(i, j-1);

}
