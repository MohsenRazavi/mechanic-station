#include <iostream>
#include <stdlib.h>

#include "code.cpp"

using namespace std;

// declarations

int choose_oprations(string opration_list[], int num_of_oprations);
int welcome();
MechanicStation make_station();
void help();
void station_info(MechanicStation station);
int station_management(MechanicStation station);
void change_owner(MechanicStation& station);
void add_worker(MechanicStation& station);
void add_customer(MechanicStation& station);
void remove_from_customer_cart(MechanicStation& station);
void add_item_to_customer_cart(MechanicStation& station);
void exit();


// definations

int choose_oprations(string opration_list[], int num_of_oprations){
    int opr=0;
    cout<<"Choose opration :"<<endl;
    for (int i = 0; i<num_of_oprations; i++){
        cout<<i+1<<"- "<<opration_list[i]<<endl;
    }
    while (1){
        cin>>opr;
        if (opr>=1 && opr <=num_of_oprations+1)
            return opr;
        else{
            cout<<"Invalid! Try again."<<endl;
        }
    }
}

int welcome(){
    system("clear");
    cout<<"<-- Welcome To Mechanic Station Admin -->"<<endl;
    string oprations[3] = {"Start", "Help", "Quit"};
    return choose_oprations(oprations, 3);
}

void help(){
    char c;
    system("clear");
    cout<<"<-- Help -->"<<endl;
    cout<<"Start and use :)"<<endl;
    cout<<"Enter any thing to continue ...";
    cin>>c;
}   


MechanicStation make_station(){
system("clear");
cout<<"<-- Building Your Mechanic Station -->"<<endl;
string name, owner_name;
cout<<"Enter name : "<<endl;
cin>>name;
cout<<"Enter owner name : "<<endl;
cin>>owner_name;

MechanicStation new_station(name, owner_name);
cout<<"The station Succesfully built."<<endl;

n_delay(1);

return new_station;

}

void station_info(MechanicStation station){
system("clear");
char c;

cout<<"<-- "<<station.station_name<<" Info -->"<<endl;
cout<<"Owner name :"<<station.station_owner<<endl;
station.list_workers();
station.list_customers();

cout<<"Enter any thing to continue ..."<<endl;
cin>>c;

}

int station_management(MechanicStation station){
system("clear");
cout<<"<-- "<<station.station_name<<" Management -->"<<endl;
string oprations[7] = {"Show info", "Change owner", "Add worker", "Add customer", "Remove item from customer cart", "Add item to customer cart", "Exit"};
int s = choose_oprations(oprations, 7);

return s;
}

void change_owner(MechanicStation& station){
    system("clear");
    string name;
    cout<<"<-- Change "<<station.station_name<<" Owner -->"<<endl;
    cout<<"Last owner : "<<station.station_owner<<endl;
    cout<<"Enter new owner name : ";
    cin>>name;
    station.station_owner = name;
    cout<<"Owner set to "<<station.station_owner<<" succsfully !"<<endl;
    n_delay(3);
}

void add_worker(MechanicStation& station){
    system("clear");
    string name, job;
    double payment;
    cout<<"<-- Add Worker To "<<station.station_name<<" Station -->"<<endl;
    cout<<"Enter workers name :"<<endl;
    cin>>name;
    cout<<"Enter workers job :"<<endl;
    cin>>job;
    cout<<"How much is his/her payment ($) ?"<<endl;
    cin>>payment;

    station.add_worker(Worker(name, job, payment));

    cout<<name<<" added to station succsfully !"<<endl;
    n_delay(3);
}


void add_customer(MechanicStation& station){
    system("clear");
    string name, car_name, problem_detail;
    cout<<"<-- Add Customer To "<<station.station_name<<" Station -->"<<endl;
    cout<<"Enter customer name :"<<endl;
    cin>>name;
    cout<<"Enter customer car :"<<endl;
    cin>>car_name;
    cout<<"What is his/her problem ?"<<endl;
    cin>>problem_detail;

    station.add_customer(Customer(name, car_name, problem_detail));

    cout<<name<<" added to station succsfully !"<<endl;
    n_delay(3);
}

void remove_from_customer_cart(MechanicStation& station){
    system("clear");
    string name, tool;
    int found = 0;
    cout<<"<-- Remove Item From Customer Cart -->"<<endl;
    station.list_customers();
    int i = 0;
    while(not found){
    cout<<"Enter customer name :"<<endl;
    cin>>name;
    for(i; i < station.num_of_customers;i++){
        if (station.customer_list[i].name == name){
        found = 1;
        break;
        }
    }
    if(not found)
    cout<<"Invalid name! Try again"<<endl;
    }
    found = 0;
    station.customer_list[i].print_cart();
    cout<<"Enter tool name :"<<endl;
    cin>>tool;
    station.remove_from_customer_cart(station.customer_list[i], tool);
    cout<<tool<<" deleted succesfully from "<<station.customer_list[i].name<<" cart!"<<endl;
    n_delay(3);
}

void add_item_to_customer_cart(MechanicStation& station){
    system("clear");
    string name, tool_name;
    double tool_price;
    int found = 0;
    cout<<"<-- Add Item To Customer Cart -->"<<endl;
    station.list_customers();
    int i = 0;
    while(not found){
    cout<<"Enter customer name :"<<endl;
    cin>>name;
    for(i; i < station.num_of_customers;i++){
        if (station.customer_list[i].name == name){
        found = 1;
        break;
        }
    }
    if(not found)
    cout<<"Invalid name! Try again"<<endl;
    }
    station.customer_list[i].print_cart();
    cout<<"Enter tool name :"<<endl;
    cin>>tool_name;

    cout<<"Enter tool price :"<<endl;
    cin>>tool_price;

    station.add_to_customer_cart(station.customer_list[i] ,Tool(tool_name, tool_price));
    cout<<tool_name<<" added succesfully to "<<station.customer_list[i].name<<" cart!"<<endl;
    n_delay(3);

}

void exit(){
        system("clear");
        cout<<"Take life easy ! :)"<<endl;
        n_delay(5);
}