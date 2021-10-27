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

mutex all_func;
string station;

void go(int sec, int num)
{
    this_thread::sleep_for(chrono::seconds(sec));

    all_func.lock();
    while (!station.empty());
    cout << "Train #" << num << " is arrived" << endl;
    station += to_string(num);
    all_func.unlock();
}

int main()
{
    vector<int> sec;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter " << i << " travel time: ";
        int n; cin >> n; sec.push_back(n);
    }

    thread train_1(go, sec[0], 1);
    thread train_2(go, sec[1], 2);
    thread train_3(go, sec[2], 3);

    int n = 0;
    while (n != 3)
    {
        string move;
        cin >> move;

        if (move == "duration")
        {
            if (!station.empty())
            {
                n++;
                cout << "Train #" << station << " left" << endl;
                station.clear();
            }
        }
    }

    train_1.join();
    train_2.join();
    train_3.join();
}