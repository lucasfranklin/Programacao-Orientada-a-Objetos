#include <iostream>

using namespace std;

int main()
{
    string frase1, frase2;
    int i,j = 0;
    cout << "Entre com uma frase: ";
    cin >> frase1;
    for(i=0; i < frase1.size(); i++){
        if((int)frase1[i] > 65 && (int)frase1[i] < 123){
            j++;
           // cout << (int)frase1[i] << endl;
            frase2.replace(i,1,(char)frase1[i]);
            cout << frase2[j] << endl;
        }
 while(frase1>> frase2)
 frase += frase2;
    }

  //  cout << endl << frase2 << endl;
    return 0;
}
