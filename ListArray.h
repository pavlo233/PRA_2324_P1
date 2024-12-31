#include <iostream>
#include "List.h"
#include <stdexcept>


template <typename T>
class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
	public:
		
		
		ListArray(){
		
			arr = new T[MINSIZE];
	        	max= MINSIZE;
			int n=0;	
		}
	 	~ListArray(){
			delete[] arr;
		}
		T operator[](int pos){
			if(pos-1<=max && pos>=0){
			    return arr[pos];
			}
			else{
				throw std::out_of_range("posicion inexistente");
			}
		}
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			int tam = list.n;
			out<<"List => [";
			for(int i=0;i<tam;i++){
				out<<std::endl<<list.arr[i];
			}
			out<<"]";
			return out;
		}
	       	void resize(int new_size){
			T* aux = new T[new_size];
			for(int i=0;i<max;i++){
				aux[i]=arr[i];
		
			}
		       	delete[] arr;
			arr=aux;
			max=new_size;
                        	
		}
		void insert(int pos, T e) override{
		    if(n>=max){
		        resize(max+10);
		        

		    }
		    if(pos > size() || pos<0 ){
		                
		        throw std::out_of_range("posicion invalida");    		
		       
		    }  
		    else {
		    
		        for(int i = n-1;i>pos-1;i--){
			    arr[i+1]=arr[i];
			}
		        arr[pos]=e;
		    }	
		    
		    n++;
		}
	        void append(T e) override{
	            insert((n),e);
				
		
		
		
		
		}
		void prepend(T e) override{
		    insert(0,e);    
		}
		T remove(int pos) override{
		  if(pos >= size() || pos<0 ){
		                
		       throw std::out_of_range("posicion invalida");    		
		       
		   }  
		   else{
		       T x = arr[pos];
	               n--;
		       
	               for(int i=pos;i<size();i++){
		           arr[i]=arr[i+1];
			   
		       }	       
		       return x;
		
		}}
		T get(int pos) override{
		    if(pos >=  size() || pos<0 ){
		                
		        throw std::out_of_range("posicion invalida");    		
		       
		    }  
	            else{
		        return arr[pos];
		    }
		
		
		}
		int search(T e) override{
			int pos =  -1;
			for(int i=0;i<size();i++){
				if(arr[i]==e){
					
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
