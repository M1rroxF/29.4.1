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

class Animal
{
  public:
    string name;
    virtual void yes() = 0;
    virtual void no() = 0;
};

class Dog: virtual public Animal
{
  public:
    Dog()
    {
        name = "Dog";
    }
    void yes()
    {
        cout << "woof";
    }
    void no()
    {
        cout << "bark";
    }
};

class Cat: virtual public Animal
{
  public:
    Cat()
    {
        name = "Cat";
    }
    void yes()
    {
        cout << "purr";
    }
    void no()
    {
        cout << "meow";
    }
};

void meeting(Animal* a, Animal* b)
{
    if (a->name == b->name)
    {
        a->yes();
        cout << " ";
        b->yes();
        cout << endl;
    }
    else
    {
        a->no();
        cout << " ";
        b->no();
        cout << endl;
    }
}

int main()
{
    Animal* a = new Dog();
    Animal* b = new Cat();

    meeting(a, a);
    meeting(a, b);
    meeting(b, a);
    meeting(b, b);
}