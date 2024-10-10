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
		
			T* arr[MINSIZE];
	        	max= 2;
			int n=0;	
		}
	 	~ListArray(){
			delete arr;
		}
		T operator[](int pos){
			if(pos-1<=max && pos>=0){
				std::cout<<arr[pos]<<std::endl;
			}
			else{
				throw std::out_of_range("posicion inexistente");
			}
		}
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			for(int i=0;i<list.max;i++){
				out<<list->arr[i]<<" ";
			}
			return out;
		}
		void resize(int new_size){
			T aux =new T[new_size];
			for(int i=0;i<max;i++){
				aux[i]=arr[i];
		
			}	
			arr=aux;
			max=new_size;
                	delete arr;
		}
		void insert(int pos, T e) override{
		}
	        void append(T e) override;
		void prepend(T e) override;
		T remove(int pos) override;
		T get(int pos) override{
			return arr[pos];
		
		
		
		}
		int search(T e) override{
			int pos -1;
			for(int i=0;i<max;i++){
				if(arr[i]==e){
					pos = i;
					break;
				}
			}
			return pos;
		
		}
		bool empty() override{
			bool a;
			if( n>0){
				a=0;	
			} 
			else{
				a=1;
			}
			return a;
		}
		int size() override{
			return n;
		}
};
