#include <iostream>
#define MAXCAP 100


using namespace std;


class Tool{
    public:
    string name = "";
    double price = 0.0;

    Tool(string name, double price):name(name),price(price){}
    Tool(){}

    void print_tool(){
        cout<<name<<"-> "<<price<<endl; 
    }
};

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

        Tool cart[MAXCAP];
        int cart_size = 0;
        
        Customer(string name, string car_name, string problem_detail):name(name),car_name(car_name),problem_detail(problem_detail){}
        Customer(){}


        void represent(){
            cout<<name<<" | "<<car_name<<" | "<<problem_detail<<endl;
        }
        

        void add_to_cart(const Tool& new_tool){
            cart[cart_size] = new_tool;
            cart_size++;
            cout<<"Successful !"<<endl;
        }

        int remove_from_cart(string tool_name){
            for (int i = 0 ; i < cart_size; i++){
                if (cart[i].name == tool_name){
                    cart[i] = Tool();
                    cart_size--;
                    return i;
                } 
            }
            cout<<tool_name<<" not found !"<<endl;
        }

        void print_cart(){
            for (int i = 0; i < cart_size; i++){
                cart[i].print_tool();
            }
        }


        double reckoning(){
            double sum = 0;
            for(int i=0; i<cart_size; i++){
                sum += cart[i].price;
            }
            return sum;
        }



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

        void represent(){
            cout<<station_owner<<"->"<<station_name<<endl;
            list_workers();
            list_customers();
        }

        void add_worker(const Worker& new_worker){
            worker_list[num_of_workers] = new_worker;
            num_of_workers++;
            cout<<"Successful !"<<endl;
        }

        void add_customer(const Customer& new_customer){
            customer_list[num_of_customers] = new_customer;
            num_of_customers++;
            cout<<"Successful !"<<endl;        
        }
    
        void list_workers(){
            cout<<"<workers ";
            for(int i = 0; i < num_of_workers; i++){
                cout<<worker_list[i].name<<" ";
            }
            cout<<">"<<endl;
        }

        void list_customers(){
            cout<<"<customers ";
            for(int i = 0; i < num_of_customers; i++){
                cout<<customer_list[i].name<<" ";
            }
            cout<<">"<<endl;
        }

        void add_to_customer_cart(Customer& customer, const Tool new_tool){
            customer.add_to_cart(new_tool);
        }

        void remove_from_customer_cart(Customer& customer, const string tool_name){
            customer.remove_from_cart(tool_name);
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
// m.represent();

m.add_worker(a);
m.add_worker(b);
m.add_customer(c);
m.add_customer(d);

m.add_to_customer_cart(c, Tool("charkh", 50.6));
m.add_to_customer_cart(c, Tool("panke", 120));
m.add_to_customer_cart(c, Tool("fanar", 24.3));

// c.add_to_cart(Tool("charkh", 50.6));

c.print_cart();

m.remove_from_customer_cart(c, "fanar");

c.print_cart();

cout<<c.reckoning();

    return 0;
}