#include <iostream>
#include <string>

using namespace std;

void modifyString1(string* string1);
void modifyString2(string& string2);

int main()
{
    string string1, string2;
    string1 = "Valor String 1";
    string2 = "Valor String 2";

    cout << string1 << endl << string2 << endl << endl;

    modifyString1(&string1);
    modifyString2(string2);

    cout << string1 << endl << string2 << endl;

    return 0;
}

void modifyString1(string* string1)
{
    *string1 = "Valor String 1 [Modificado]";
    return;
}

void modifyString2(string& string2)
{
    string2 = "Valor String 2 [Modificado]";
    return;
}

