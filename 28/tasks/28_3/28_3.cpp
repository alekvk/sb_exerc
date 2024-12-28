#include <iostream> 
#include <thread> 
#include <mutex> 
#include <chrono>
#include <queue> 

std::string dish[] = {"Pizza", "Soup", "Steak", "Salad", "Sushi"};

std::string GetTypeDish() {
    std::srand(time(nullptr));
    return dish[rand() % 5];  
}

struct Order
{
    Order(int in_id): 
        id(in_id),
        name(GetTypeDish())
    {}
   
    int id;
    std::string name;
};

std::queue<Order> orders, deliveries;
std::mutex mutex_output, mutex_orders, mutex_deliveries;

void GetOrder(int max_deliver) 
{
    for(static int i = 1; i <= max_deliver; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 6 + 5));
        Order order(i);

        mutex_output.lock();
        std::cout<<"Order accepted  "
        << "number: " <<i<<" dish: " << order.name<<std::endl;
        mutex_output.unlock();

        mutex_orders.lock();
        orders.push(order);
        mutex_orders.unlock();
    }
}

void Cooking(int max_deliver) 
{
    
    for(static int i = 1; i <= max_deliver;){ 
        if(!orders.empty()) {
            mutex_orders.lock();
            Order order = orders.front();
            orders.pop();
            mutex_orders.unlock();
            
            mutex_output.lock();
            std::cout<<"Order number "<<order.id
            <<"  dish: "<<order.name<<" is being prepared"<<std::endl;
            mutex_output.unlock();

            std::this_thread::sleep_for(std::chrono::seconds(rand() % 11 + 5));
            mutex_output.lock();
            std::cout<<"Order number "<<order.id<<" is ready"<<std::endl;
            mutex_output.unlock();

            mutex_deliveries.lock();
            deliveries.push(order);
            mutex_deliveries.unlock();
            ++i;
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }
    

};

void Courier(int max_deliver, int courier_time)
{
  
    for(static int i = 1; i <= max_deliver;) {
        std::this_thread::sleep_for(std::chrono::seconds(courier_time));
        
        if (!deliveries.empty()) {
            mutex_deliveries.lock();
            mutex_output.lock();
            std::cout<<"The courier picked up the orders: ";

            for (; !deliveries.empty(); deliveries.pop()) {
                Order order = deliveries.front();
                std::cout<<order.id<<"  ";
                ++i; 
            }
            
            std::cout<<"\n";   
            mutex_deliveries.unlock();
            mutex_output.unlock();
        } 
    }
}


int main() {

    int max_deliver = 10;
    int courier_time = 30;

    std::thread order(GetOrder, max_deliver);
    std::thread kitchen(Cooking, max_deliver);
    std::thread deliver(Courier, max_deliver, courier_time);    
        
    order.join();
    kitchen.join();
    deliver.join();

    return 0; 
}