#include <iostream>
#define MAXCAP 100


using namespace std;

// declare classes

class Tool;

class Worker;

class Customer;

class MechanicStation;


// class definetion

class Tool{
    public:
    string name = "";
    double price = 0.0;

    Tool(string name, double price):name(name),price(price){}
    Tool(){}

    void print_tool();
};


class Worker{
    public:
        string name = "Kargar";
        string job = "Kargari";
        double peyment = 0.0;

        Worker(string name, string job, double payment):name(name),job(job),peyment(payment){}
        Worker(){}

        void work();

        void represent();
};


class Customer{
    public:
        string name = "Moshtari";
        string car_name = "Pride";
        string problem_detail = "Doesn't move";

        Tool cart[MAXCAP];
        int cart_size = 0;
        
        Customer(string name, string car_name, string problem_detail):name(name),car_name(car_name),problem_detail(problem_detail){}
        Customer(){}

        void represent();
        
        void add_to_cart(const Tool& new_tool);

        void remove_from_cart(string tool_name);

        void print_cart();

        double reckoning();
};
 

class MechanicStation{
    public:
        string station_name = "Mechanici";
        string station_owner = "Oosa";

        Worker worker_list[MAXCAP];
        int num_of_workers = 0;
        Customer customer_list[MAXCAP];
        int num_of_customers = 0;

        MechanicStation(string station_name, string station_owner):station_name(station_name),station_owner(station_owner){}
        MechanicStation(){}

        void represent();

        void add_worker(const Worker& new_worker);

        void add_customer(const Customer& new_customer);
    
        void list_workers();

        void list_customers();

        void add_to_customer_cart(Customer& customer, const Tool new_tool);

        void remove_from_customer_cart(Customer& customer, const string tool_name);
};


// Tool methods
void Tool::print_tool(){
        cout<<name<<"-> "<<price<<endl; 
    }

// Worker methods
void Worker::work(){
            cout<<name<<": I'm workiiingggg !!!"<<endl;
        }

void Worker::represent(){
    cout<<name<<"-"<<job<<endl;
}


//Customer methods
void Customer::represent(){
            cout<<name<<" | "<<car_name<<" | "<<problem_detail<<endl;
        }

void Customer::add_to_cart(const Tool& new_tool){
            cart[cart_size] = new_tool;
            cart_size++;
            cout<<"Successful !"<<endl;
        }

void Customer::remove_from_cart(string tool_name){
    for (int i = 0 ; i < cart_size; i++){
        if (cart[i].name == tool_name){
            cart[i] = Tool();
            cart_size--;
            break;
        } 
    }
    cout<<tool_name<<" not found !"<<endl;
}

void Customer::print_cart(){
            for (int i = 0; i < cart_size; i++){
                cart[i].print_tool();
            }
        }

double Customer::reckoning(){
            double sum = 0;
            for(int i=0; i<cart_size; i++){
                sum += cart[i].price;
            }
            return sum;
        }


//MechanicStation methods

void MechanicStation::represent(){
            cout<<station_owner<<"->"<<station_name<<endl;
            list_workers();
            list_customers();
        }

void MechanicStation::add_worker(const Worker& new_worker){
            worker_list[num_of_workers] = new_worker;
            num_of_workers++;
            cout<<"Successful !"<<endl;
        }

void MechanicStation::add_customer(const Customer& new_customer){
            customer_list[num_of_customers] = new_customer;
            num_of_customers++;
            cout<<"Successful !"<<endl;        
        }

void MechanicStation::list_workers(){
            cout<<"<workers ";
            for(int i = 0; i < num_of_workers; i++){
                cout<<worker_list[i].name<<" ";
            }
            cout<<">"<<endl;
        }

void MechanicStation::list_customers(){
            cout<<"<customers ";
            for(int i = 0; i < num_of_customers; i++){
                cout<<customer_list[i].name<<" ";
            }
            cout<<">"<<endl;
        }

void MechanicStation::add_to_customer_cart(Customer& customer, const Tool new_tool){
            customer.add_to_cart(new_tool);
        }

void MechanicStation::remove_from_customer_cart(Customer& customer, const string tool_name){
            customer.remove_from_cart(tool_name);
        }
