#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>

class my_vector{
    protected:
        T* data;
        int size;
    public:
        my_vector(int newTamanho = 0, const T& content = T()) : size(newTamanho), data((T *)malloc(sizeof(T)*newTamanho)){
            for(int i = 0; i<size; i++) data[i] = content;
        }
        ~my_vector(){
            delete data;
        }

        void getAll(){
        for(int i = 0; i<size; i++){
            cout << data[i] << " ";
        }
        }

        void insert(int i, int j){
            if(i>=j) throw;
            else data[i] = j;
        }

        inline int tamanho(){
            return size;
        }

        inline const T& operator[](int i) const{
            if(i>=size) throw;
            else return data[i];
        }



};

int main()
{
    my_vector<int> vetor(5);
    vetor.insert(0,1);
    vetor.insert(1,2);
    vetor.insert(2,3);
    vetor.insert(3,4);
    vetor.insert(4,5);

    vetor.getAll();

    return 0;
}
