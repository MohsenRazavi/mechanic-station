#include <iostream>
#define MAXCAP 100


using namespace std;

class Worker{
    public:
        string name = "Kargar";
        string job = "Kargari";
        double peyment = 0.0;

        Worker(string name, string job, double payment):name(name),job(job),peyment(payment){}
        Worker(){}

        void work(){
            cout<<name<<": I'm workiiingggg !!!"<<endl;
        }
};


class Customer{
    public:
        string name = "Moshtari";
        string car_name = "Pride";
        string problem_detail = "Doesn't move";
        double prices[MAXCAP];
        string cart[MAXCAP];
        
        Customer(string name, string car_name, string problem_detail):name(name),car_name(car_name),problem_detail(problem_detail){}
        Customer(){}


        void represent(){
            cout<<name<<" | "<<car_name<<" | "<<problem_detail<<endl;
        }
        
        void add_price(double new_price){
            prices[sizeof(prices)] = new_price;
            cout<<"Successful !"<<endl;
        }

        void add_to_cart(string new_tool){
            cart[sizeof(cart)] = new_tool;
            cout<<"Successful !"<<endl;
        }

        int remove_from_cart(string tool_name){
            for (int i = 0 ; i < sizeof(cart); i++){
                if (cart[i] == tool_name){
                    cart[i] = "";
                    return i;
                } 
            }
        }

        void delete_price(int index){
            prices[index] = 0;
            cout << "Successful !"<<endl;
        }

        double reckoning(){
            double sum = 0;
            for(int i=0; i<sizeof(prices); i++){
                sum += prices[i];
            }
            return sum;
        }



};


class MechanicStation{
    public:
        string station_name = "Mechanici";
        string station_owner = "Oosa";

        Worker worker_list[MAXCAP];
        Customer customer_list[MAXCAP];

        MechanicStation(string station_name, string station_owner):station_name(station_name),station_owner(station_owner){}
        MechanicStation(){}

        void represent(){
            cout<<station_owner<<"->"<<station_name<<endl;
        }

        void add_worker(Worker new_worker){
            worker_list[sizeof(worker_list)] = new_worker;
            cout<<"Successful !"<<endl;
        }

        void add_customer(Customer& new_customer){
            customer_list[sizeof(customer_list)] = new_customer;
            cout<<"Successful !"<<endl;        
        }
    
        void list_workers(){
            cout<<"<workers ";
            for(int i = 0; i < sizeof(worker_list); i++){
                cout<<worker_list[i].name<<" ";
            }
            cout<<">"<<endl;
        }

        void list_customers(){
            cout<<"<customers ";
            for(int i = 0; i < sizeof(worker_list); i++){
                cout<<customer_list[i].name<<" ";
            }
            cout<<">"<<endl;
        }

        void add_to_customer_cart(Customer customer, string new_tool, double price){
            customer.add_to_cart(new_tool);
            customer.add_price(price);
        }

        void remove_from_customer_cart(Customer customer, string tool_name){
            int ind = customer.remove_from_cart(tool_name);
            customer.delete_price(ind);
        }
};


int main(){

Worker a("a", "aaa", 2.5);
Worker b("b", "bbb", 1.95);

// a.work();
// b.work();

Customer c("c", "c_car", "c_prob");
Customer d("d", "d_car", "d_prob");

// c.represent();
// d.represent();

MechanicStation m("m", "mm");
m.represent();

m.add_worker(a);
m.add_customer(c);
m.list_workers();
m.list_customers();
m.add_worker(b);
m.add_customer(d);
m.list_workers();
m.list_customers();

    return 0;
}