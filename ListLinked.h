#include <iostream>
#include "List.h"
#include "Node.h"
#include <stdexcept>
template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;
	int n;
        // ...

    public:
        ListLinked(){
	
	    this->first = nullptr;
            this->n = 0;
	
	}
	~ListLinked(){
	    while(1){
	        Node<T>* aux = first->next;
                delete first;
	        if(aux==nullptr){
	            break;
	        }
	        else{
	            first=aux;
                }

	    }
	}
        T operator[](int pos){
	    if(pos < 0 || pos >= size()){
	    
	        throw std::out_of_range("posicion invalida p");
	    
	    }
	    else{
	        Node<T>* aux = first;
	      
	        for(int i = 0;i<pos;i++){
		
		   aux = aux->next;
		}
		return aux->data;
	    }
	
	
	}
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
	    Node<T>* aux = list.first;
            
            out<<"List => [";
            for(int i=0;i<list.n;i++){
                out<<std::endl<<aux->data;
		aux = aux->next;
            }
		    out<<"]";
		    return out;
		}

		void insert(int pos, T e) override {
		
		    if(pos < 0 || pos > size() ){
			throw std::out_of_range("posicion invalida");
		    
		    }
		    else if(pos == 0){
			Node<T>* aux = first;
			first = new Node(e,aux);
			n++;
		    }
		
		    else{
			Node<T>* aux = first;
			Node<T>* aux2;

			for(int i=0;i<pos-1;i++){
			    aux=aux->next;
			}
			aux2=aux->next;
			aux->next = new Node(e,aux2);
	                n++;
	    
	    }
	    
	    
	
	}
	void append(T e) override{
	
	    insert(size(),e);
	
	
	}
	void prepend(T e) override{

	
	    insert(0,e);
	
	}
	T remove(int pos) override{
	    if(pos < 0 || pos >= size() ){
	        throw std::out_of_range("posicion invalida r");
	    
	    }
	    else if(pos == 0){
		T value = first->data;   
	        	
		Node<T>* aux = first->next;    
	        delete first;
	        first = aux;
	        n--;
		return value;
	    }
	    else{
		T value;    
	        Node<T>* aux = first;
	        Node<T>* aux2;

	        for(int i=0;i<pos-1;i++){
		    aux=aux->next;
		}
	        aux2=aux->next;
		aux->next=aux2->next;
		value=aux2->data;
		delete aux2;
	        n--;
		return value;
           	    
	    }
	 }
	 T get(int pos) override{
	     return (*this)[pos];
	 
	 }
         int search(T e) override{
             int pos =  -1;
             for(int i=0;i<size();i++){
                 if((*this)[i]==e){

                     pos = i;
                     break;
                 }
             }
             return pos;

         }
         bool empty() override{
             bool a=1;
             if( n>0){
                 a=0;
             }

             return a;
          }

          int size() override{
             return n;
          }




};
