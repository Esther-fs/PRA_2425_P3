#include <iostream>
#include <ostream>
#include <stdexcept>
#using namespace std
#include "List.h"

template <typename T>//Creacion de variable generica
class ListArray : public List<T>{ //Crear subclase
    private:
    T* arr;//puntero inicial
    int max;//Tamaño array
    int n;//longitud lista
    static const int MINSIZE = 2;//crear costante gloval de la clase
    void resize(int new_sice){
        T* aux = new T[new_sice];
        
        for(int i=0;i<max;i++){
            aux[i]=arr[i];
        }
        delete arr;
        this->arr=aux;
        this->max=new_sice;
    }

    public:
    ListArray(){
    	arr = new T [MINSICE];
    	max = 2;
    	n=0;
    }
    ~ListArray(){
    	delate[] arr;
    }
    T operator[](int pos){
        if ((pos>(max-1))||(pos<=0)){
            throw(out_of_range);
    	}else{
    		return get(pos);
    	}
    }
    
    friend ostram& operator<<(ostream &out,const ListArray<T> &list){
    	cout<<"Lista: -> ["<< endl;
    	for (int i=0;i<list.n;i++){
    		out<<" "<<list.arr[i]<<endl;
    	}
    	cout<<"]"<<endl;
    	return out;
    }
}
