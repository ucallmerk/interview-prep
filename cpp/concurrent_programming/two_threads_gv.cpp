#include <iostream>
#include <thread>
using namespace std;

/* Using a global variable as a lock*/
static bool door_locked;

/* Thread function */
static void use_restroom( int id)
{
    int used_restroom = 0;
    int i = 0;
    while(i < 10){
        if(!door_locked) { /* Critical section, race condition happens here*/
            door_locked =true; /* Before first thread can update the lock, second thread might already be here..*/
            /* There is a posisbility when both threads might be executing this same code, same time*/
            cout  << id << " using restoorm : "<< i <<" time "<< endl;  
            used_restroom++;
        }
        door_locked = false;
        i++;
    }
}

int main(int argc, char** argv)
{
    door_locked = false;
    std::thread threads[2];

    for(int i=0; i<2; i++){
        threads[i] = std::thread(use_restroom, i);
    }
    for(auto& th : threads){
        th.join();
    }

}