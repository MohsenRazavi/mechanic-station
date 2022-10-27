#include <iostream>

using namespace std;

#include "exec.cpp"

int main(){
int a, b;
MechanicStation local_station;
b = welcome();
if (b==3) return 0;
local_station = make_station();
while(1){
a = station_management(local_station);
switch (a)
{
case 1:
station_info(local_station);
break;

case 2:
change_owner(local_station);
break;

case 3:
add_worker(local_station);
break;

case 4:
add_customer(local_station);
break;

case 5:
remove_from_customer_cart(local_station);
break;

case 6:
add_item_to_customer_cart(local_station);
break;

case 7:
customer_list(local_station);
break;

case 8:
reckoning_with_customer(local_station);
break;

case 9:
view_workers(local_station);
break;

case 10:
exit();
return 0;
break;

}
}

    return 0;
}