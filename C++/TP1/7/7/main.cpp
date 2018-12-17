#include <iostream>

using namespace std;

int parseInt(double var);

int main()
{
    int(*pFunction)(double) = parseInt;

    cout << pFunction(2.2) << endl;
    return 0;
}

int parseInt(double var){
    return (int)var;
}
