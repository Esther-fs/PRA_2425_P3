#include <ostream>
#include "List.h"
#include "Node.h"

template<typename T>
class ListLinked : public List<T>{
	private:
		Node<T>* first;
		int n;
	piblic:
		ListLinked(){
			first=nullptr;
			n=0;
		}
		~ ListLinked(){
			Node<T>* aux =first;
			while(aux != nullptr){
				Node<T> aux2=aux-> next;
				delete aux;
				aux =aux2;
			}
		}
		T operator[](int pos){
			if(pos<0||pos>size()-1){
				throw std::out_of_range("Fuera de rango");
				else{
					Node<T>* aux=first;
					for(int i=0;i<pos;i++){
					aux=aux->next;
					}
					return aux->data;
				}
			}
		}
		friend std::ostream& operator << (std::ostream &out, const ListLinked<T> &list){
		out<<"Lista : [";
		Node<T>* aux=list.first;
		while(aux != nullptr){
			out<<aux->data<<" ";
			aux=aux->next;
		}
		out<<"]";
		return out;
