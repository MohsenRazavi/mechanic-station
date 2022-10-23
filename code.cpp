#include <iostream>
#define MAXCAP 100


using namespace std;

class Worker{
    public:
        string name;
        string job;
        double peyment;

        explicit
            Worker(string name, string job, double payment):name(name),job(job),peyment(peyment){};

        void work(){
            cout<<"I'm workiiingggg !!!";
        }
};

class Customer{
    public:
        string name;
        string car_name;
        string problem_detail;
        double prices[MAXCAP];
        string tools[MAXCAP];
        
        explicit
            Customer(string name, string car_name, string problem_detail):name(name), car_name(car_name), problem_detail(problem_detail){};

        void add_price(double new_price){
            prices[sizeof(prices)+1] = new_price;
        }

        void add_tool(string new_tool_name){
            tools[sizeof(tools)+1] = new_tool_name;
        }

};

class MechanicStation{
    string station_name;
    string station_owner;
    
};


int main(){


    return 0;
}