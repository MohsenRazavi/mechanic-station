#include <iostream>
#define MAXCAP 100


using namespace std;

// declarations

int choose_oprations(string opration_list[], int num_of_oprations);
int start();


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

int start(){
cout<<"WELLCOME"<<endl;
string oprations[3] = {"Start", "Help", "Quit"};
return choose_oprations(oprations, 3);
}


void executation(){
start();


}