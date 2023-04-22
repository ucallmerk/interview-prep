#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

/* Using a global variable as a condition*/
static bool door_locked;
static mutex door_lock_mt;
static condition_variable restroom_waitlist;
/* Thread function */
static void use_restroom( int id)
{
    int used_restroom = 0;
    int i = 0;
    while(i < 10 ){
        unique_lock get_door_lock(door_lock_mt);
        while (door_locked) { 
            restroom_waitlist.wait(get_door_lock);
        }
        /* Critical section, race condition happens here*/
        door_locked =true; /* Before first thread can update the lock, second thread might already be here..*/
        /* There is a posisbility when both threads might be executing this same code, same time*/
        cout  << id << " using restoorm : "<< i <<" time "<< endl;  
        used_restroom++;
        door_locked = false;
        i++;
        get_door_lock.unlock();
        restroom_waitlist.notify_one();
        /* Uncomment this to Give the threads a chance - alternatively*/
        //this_thread::sleep_for(chrono::milliseconds(100));
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