#include <iostream>

using namespace std;
class DynamicArray{
    private:
    int *arr;
    int *newarr;
    int index;
    int size;
    friend ostream& operator<<(ostream& os, const DynamicArray& dArr);
    
    
    public:
    
    DynamicArray(int SizeArg):size{SizeArg}{
        this->index=0;
        this->arr=new int[SizeArg];
    }
    void add(int data)
    {
        if(this->index<this->size)
        {
            this->arr[this->index]=data;
            this->index++; 
        }
        else
        {
            this->size++;
            this->newarr=new int[size];
            for(int i=0;i<size-1;i++)
            {
                this->newarr[i]=this->arr[i];
            }
            this->newarr[size-1]=data;
            this->index++;
            delete[] this->arr;
            this->arr=this->newarr;
        }
    }
    int operator[](int indexArg)
    {
        return this->arr[indexArg];
    }
    ~DynamicArray(){
        delete[] arr;
    }
};

ostream& operator<<(ostream& os, const DynamicArray& dArr){
   
    for(int i=0;i<dArr.size;i++)
    {
           os<<dArr.arr[i]<<" ";
    }
 return os;
}

int main(){
    DynamicArray numbers(2);
    numbers.add(10);
    numbers.add(20);
    numbers.add(30);
    numbers.add(40);
    numbers.add(50);
    numbers.add(60);
    cout<<numbers<<endl; // 10,20,30  
    int value=numbers[1];
    cout<<value<<endl; //20
   return 0;
  
};
