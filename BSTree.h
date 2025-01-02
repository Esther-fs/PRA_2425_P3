#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include <exception>
#include "BSNode.h"

using namespace std;

template <typename T> 
class BSTree {
    private:
        int nelem;
        BSNode<T>* root;
        //busca el elemnto deseado
        BSNode<T>* search(BSNode<T>* n, T e) const{
            if (n==nullptr){
                throw runtime_erro("Elemento no encontrado");
                return nullptr;
            }else if(n->elem<e){
                return search(n->right,e);
            }else if(n->elem>e){
                return search(n->left,e);
            }else{
                return n;
            }
        }
        BSNode<T>* insert(BSNode<T>* n, T e){
            if (n==nullptr){//añade elemento
                nelem++;
                return new BSNode<T>(e);
            }else if(n->elem==e){//Ya exixte el elmento a insertar
                throw runtime_erro("Elemento ya exixtente");
            //busca posible posicion
            }else if(n->elem<e){
                n->right=insert(n->right,e);
            }else{
                n->left=insert(n->left,e);
            }
            return n;
        }
        void print_inorder(ostream &out, BSNode<T>* n) const{
            if(n != nullptr){
                print_inorder(out,n->left);
                out<<" "<<n->elem<<" ";
                print_inorder(out,n->right);
            }
        }
        BSNode<T>*remove(BSNode<T>* n,T e){
            if (n==nullptr){
                throw runtime_erro("Elemento no encontrado");
                return nullptr;
            }else if(n->elem<e){
                n->right=remove(n->right,e);
            }else if(n->elem>e){
                n->left=remove(n->left,e);
            }else{
                if((n->left != nullptr)&&(n->right != nullptr)){
                    n->elem=max(n->left);
                    n->left=remove_max(n->left);
                }else{
                    if(n->left != nullptr){
                        n=n->left;
                    }else{
                        n=n->right;
                    }
                    nelem--;
                }
            }
            return n;
        }
        T max(BSNode<T>* n) const{
            if(n==nullptr){
                throw runtime_erro("Elemento no encontrado");
            }else if(n->right != nullptr){
                return max(n->right);
            }else{
                return n->elem;
            }
        }

        BSNode<T>* remove_max(BSNode<T>* n){
            if (n->right == nullptr){
                return n->left;
            }else{
                n->right=remove_max(n->right);
                return n;
            }
        }
        void delete_cascada(BSNode<T>* n){
            if(n==nullptr);
            else if((n->left != nullptr) &&(n->right != nullptr)){
                delete_cascada(n->left);
                delete_cascada(n->right);
            }else if((n->left == nullptr) &&(n->right != nullptr)){
                delete_cascada(n->right);
            }else if((n->left != nullptr) &&(n->right != nullptr)){
                delete_cascada(n->left);
            }
            nelem--;
            return delete n;
        }
    public:
        BSTree(){
            nelem=0;
            root=nullptr;
        }
        int size() const{
            return nelem;
        }
        //llama a la funcion que busca el elemto y lo debuelve
        T search(T e) const{
            BSNode<T>* nodo =search(root,e);
            return nodo->elem;
        }
        //llama a la fucion que llama a la busqueda de elemto
        T operator[](T e) const{
            return search(e);
        }
        void insert(T e){
            root=insert(root,e);
        }
        friend ostream& operator<<(ostream &out, const BSTree<T> &bst){
            bst.print_inorder(out,bst.root);
            return out;
        }
        void remove(T e){
            root=remove(root, e);
        }
        ~BSTree(){
            delete_cascada(root);
        }
	T max() const{
		return (max(root));
	}	
};
