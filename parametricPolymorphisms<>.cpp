#include <iostream>
using namespace std;
class A{
    private:
    int num;
    public:
    A(){}
    A(int numArg):num{numArg}{
        
    }
    A operator+(A& obj2)
    {
        A obj;
        obj.num=this->num+obj2.num;
        return obj;
    }
    
    void print(){
        cout<<this->num;
    }
};

/*********************************************************/
template<typename OperandType>
OperandType add(OperandType operand1,OperandType operand2){
    OperandType result=operand1+operand2;
    return result;
}
/*************************************************************/


int main(){
    int result =add<int>(10,20);
    cout<<result<<endl;
    float fresult=add<float>(1.2,1.6);
    cout<<fresult<<endl;
    
    A obj1(1);
    A obj2(2);
    A robj;
    
    robj=add<A>(obj1,obj2);
    robj.print();
    
    
    return 0;
}
