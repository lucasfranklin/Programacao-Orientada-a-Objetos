/*
    string::rbegin() -> Aponta para o fim da string (inicio reverso)
    string::rend() -> Aponta para o inicio da string (fim reverso)
    O "espa�o" entre rbegin e rend cont�m a string em ordem inversa
*/

#include <iostream>

using namespace std;

int main()
{
    string text;
    cout << "Entre com uma palavra ou frase para a verificacao de palindromo: ";
    cin >> text;

    if (text == string(text.rbegin(), text.rend())) cout << "Palindromo!";
    else cout << "Nao e palindromo!";

    return 0;
}


