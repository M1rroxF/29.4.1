#include <iostream>
#include <vector> // vector<>
#include <fstream> // ofstream, ifstream
#include <string> // stoi()
#include <cstdlib> // rand()
#include <map> // map<>
#include <ctime> // time_t, tm*
#include <iomanip> // get_time(), put_time(), get_time()
#include <thread>
#include <mutex>

using namespace std;

int random(const int& min, const int& max)
{
    return rand() % (max - (min-1)) + min;
}

void sleep(int sec)
{
    this_thread::sleep_for(chrono::seconds( sec ));
}

string random_meal()
{
    int r = random(1, 5);

    if (r == 1)
        return "pizza";
    if (r == 2)
        return "steak";
    if (r == 3)
        return "soup";
    if (r == 4)
        return "salad";
    if (r == 5)
        return "sushi";

    return "nullptr";
}

//////////////////////////////////////////

mutex print;
mutex push;

bool go_kitchen = true;
bool go_courier = true;

vector<string> orders;
vector<string> to_courier;

void kitchen()
{
    while(go_kitchen)
    {
        while (orders.empty());
        int n = orders.size()-1;

        print.lock();
        cout << "now cooking: " << orders[n] << endl;
        print.unlock();
        sleep(random(5, 15));

        print.lock();
        cout << orders[n] << " is ready" << endl;
        print.unlock();

        {
            push.lock();
            to_courier.push_back(orders[n]);
            if (orders.size() == n + 1)
                orders.resize(n);
            else {
                for (int i = n; i < orders.size() - 1; i++)
                    orders[i] = orders[i + 1];
                orders.resize(orders.size() - 1);
            }
            push.unlock();
        }
    }
}

void courier()
{
    while (go_courier)
    {
        sleep(30);

        print.lock();
        cout << "courier took orders" << endl;
        print.unlock();

        push.lock();
        to_courier.clear();
        push.unlock();
    }
}

int main()
{
    thread th_kitchen(kitchen);
    thread th_courier(courier);
    for (int i = 0; i < 10; i++)
    {
        sleep(random(5, 10));

        push.lock();
        print.lock();

        orders.push_back(random_meal());
        cout << "add to order: " << orders[orders.size()-1] << endl;

        print.unlock();
        push.unlock();
    }
    go_kitchen = false;
    go_courier = false;

    th_kitchen.join();
    th_courier.join();
}