#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {
    private:
        int n;
        int max;
        ListLinked<TableEntry>>* table;//puntero a la lista de elemntos
        int h(std::string key){
            int acum =0;
            for(int i=0;i<key.length();i++){
                acum +=int(key.at(i));
            }
        return acum% max;
        }
    public:
        HashTable(int size){
            n=0;
            max=size;
            table=new ListLinked<TableEntry<V>>[size];
        }
        ~HashTable(){
            delete[] table;
        }
        int capacity(){
            return max;
        }
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
            out << "HashTable( entries: " << th.n << " Capacidad: " << th.max << ")" << std::endl;
            for (int i = 0; i < th.max; i++){
                out << "cubeta " << i << "elementos ["<< std::endl;
                for (int j = 0; j < th.table[i].size(); j++) {
                    out << "(" << th.table[i].get(j) << ")" << std::endl;
                }
                out << "]" << std::endl;
            }
            return out;
        }
        V operator[](std::string key){
            if (key > max){
                throw std::runtime_error();
            }else{
                return search(key);
            }
        }
        void insert(std::string key, V value)override{
            TableEntry<V> i(key, value);
            if(table[h(key)].search(key) != -1){
                throw std::runtime_error();
            }else{
                table[h(key)].prepend(i);
            }
            n++;
        }
        V search(std::string key)override{
            V aux = table[h(key)].search(key);
            if(aux == -1){
                throw std::runtime_error("Elemento no encotrado");
            }
            TableEntry<V> valor =table[h(key)].get(aux);
            return valor.value;
        }
        V remove(std::string key)override{
            V aux =table[h(key)].search(key);
            if(aux == -1){
                throw std::runtime_error("Elemento no encotrado");
            }
            TableEntry<V> valor =table[h(key)].remove(aux);
            n--;
            return valor.value;
        }
        int entries() override{
            return n;
        }
};
