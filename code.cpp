#include <iostream>

using namespace std;

class Worker{
    public:
    string name;
    string job;
    int peyment;

    Worker(string name, string job, int payment):name(name),job(job),peyment(peyment){};

    void work(){
        cout<<"I'm workiiingggg !!!";
    }
};
class Customer{};
class MechanicStation{};


int main(){


    return 0;
}