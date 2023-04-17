#include <iostream>
#include <vector>

using namespace std;

void doQuicksort(vector<int> &input, int low, int high)
{
    /* left marker, to keep track of the last element that's smaller than pivot*/
    auto left = low; 
    auto pi = input[high]; // choose pivot
    /* left marker, to keep track of first element that's greater than pivot*/
    auto right = high-1;
    if(low >= high) //Return if no elemnts left to be sorted
        return;
    while(left <= right) { // note the = sign
        while((left <= right) && (input[left] < pi)) {
            left++;
        }
        while((left <= right) && (input[right] > pi)) {
            right--;
        }
        //might appear redundant, but there's a corner case
        if (left <= right ) {
            /* Trackers stopped, but incremented by 1 (post increment in line 17 & 20)
                which means left is now pointing to an element that's greater than pivot
                & Right i spointing to an element which is smaller than pivot, so swap them.
            */
            swap(input[left], input[right]);
            left++; right--;
        }
    }
    /* Markers have crossed, there are no more smaller elements on the left
       Move pivot into it's place
    */
    swap(input[left], input[high]);
    /*Repeat sort on left partition and right partition*/
    doQuicksort(input, low, left-1);
    doQuicksort(input, left+1, high);
}

int main(int argc, char** argv)
{
    cout<< "Let's do a quick sort!"<<endl;
    //you need an inpur list
    // identify a pivot element
    //SPlit into subarrays comparing against pivot
    //update the pointers
    //Continue to sort subarrays
    vector<int> input{4, -10, -10, 10,20,5, -1,6};

    /* low = 0, high = input length*/
    doQuicksort(input, 0, input.size()-1);
    for(auto v: input)
        cout<<" "<< v;
    
}