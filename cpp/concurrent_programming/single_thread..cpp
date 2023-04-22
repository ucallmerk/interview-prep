#include <iostream>
#include <thread>
using namespace std;

static bool door_locked;
static void use_restroom( )
{
    int used_restroom = 0;
    int i = 0;
    while(i < 10){
        if(!door_locked) {
            door_locked =true;
            cout << "using restoorm : " << i << endl;  
            used_restroom++;
        }
        door_locked = false;
        i++;
    }
}

int main(int argc, char** argv)
{
    door_locked = false;

    thread t1(use_restroom);
    t1.join();

}