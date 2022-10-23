#include <iostream>
#define MAXCAP 100


using namespace std;

class Worker{
    public:
    string name;
    string job;
    double peyment;

    Worker(string name, string job, double payment):name(name),job(job),peyment(peyment){};

    void work(){
        cout<<"I'm workiiingggg !!!";
    }
};
class Customer{
    public:
    string name;
    string car_name;
    string probliem_detail;
    double prices[MAXCAP];
    string tools[MAXCAP];

    void add_price(double new_price){
        prices[sizeof(prices)+1] = new_price;
    }

    void add_tool(string new_tool_name){
        tools[sizeof(tools)+1] = new_tool_name;
    }
};
class MechanicStation{};


int main(){


    return 0;
}