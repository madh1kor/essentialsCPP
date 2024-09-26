// Online C++ compiler to run C++ program online
#include <iostream>
//interface -> Abstarction
using namespace std;
class IBlock{
    
    public:
    virtual void update()=0;
};
class SpreeBreachHandler{
    private:
    IBlock* blk;
    public :
    SpreeBreachHandler(IBlock* blkArg):blk{blkArg} {}
    void sendmessage(){
        blk->update();
    }
};
class UpdateCluster:public IBlock{
    public:
       void update(){
           cout<<"UpdateCluster"<<endl;
         
       }
};
class SpeedController:public IBlock{
    public:
       void update(){
           cout<<"SpeedController"<<endl;
         
       }
};


int main() {
    // Write C++ code here
    UpdateCluster uc;
    SpeedController sc;
    
    SpreeBreachHandler bh1{&uc};
    bh1.sendmessage();
    SpreeBreachHandler bh2{&sc};
    bh2.sendmessage();
    
    
    std::cout << "Try programiz.pro";
        
    return 0;
}
