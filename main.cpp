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