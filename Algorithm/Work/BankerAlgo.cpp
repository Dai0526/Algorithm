#include <exception>
#include <iostream>

using namespace std;

void Bankers(){

}

int main(){
    
    try{
        Bankers();
    }catch(exception & ex){
        cerr << ex.what() << endl;
        return 1;
    }catch(...){
        cerr << "Unknow exception" << endl;
        return 1;
    }

    return 0;
}