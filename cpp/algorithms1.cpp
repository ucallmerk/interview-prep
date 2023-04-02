//Basic counting, find how many times and object or a number is in a given list
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
static void lets_count()
{
    //count how many times a number is present in a vector
    vector<int> ve{1,2,3,4,53,-1,0,2,4,3,2,20};
    int target = 2;
    //using vector member functions v.begin() and v.end()
    int cnt = count(ve.begin(), ve.end(), target);

    cout << target << " found " << cnt <<" no of times"<< endl;

    //Using non-memer iterator begin() and end()
    cnt = count(begin(ve), end(ve), target);
    cout << target << " found " << cnt <<" no of times in vector"<< endl;

    //using c-type array
    int ar[] = {1,2,3,4,53,-1,0,2,4,3,2,20,11,};
    cnt = count(begin(ar), end(ar), target);
    cout << target << " found " << cnt <<" no of times in array"<< endl;

}

static void lets_count_odds()
{
    //count how many numbers match a given condition
    vector<int> ve{1,2,7,3,4,53,-1,0,2,4,3,25,20};

    //using a lambda to run the check if (val%2 != 0) for all elements
    int cnt = count_if(ve.begin(), ve.end(), [](auto val){return val % 2 != 0;});

    cout << " found " << cnt <<" no of odds"<< endl;

}

static void lets_count_primes()
{
    //count how many numbers match a given condition
    vector<int> ve{1,2,3,5,7,11,15,17,19,21,23,25,27,29,49};

    //using a lambda to run the check if (val%2 != 0) for all elements
    int cnt = count_if(ve.begin(), ve.end(), 
    [](auto val){ 
        if (val<=1) return false;

        for(int i=2; i*i <= val; i++){
            if (val % i == 0)
                return false;
        }
        return true;
    });

    cout << " found " << cnt <<" no of primes"<< endl;

}
int main(int arcgc, char* argv[])
{
    //match based unconditional counting std::count()
    lets_count();

    //match based conditional counting std::count_if()
    lets_count_odds();

    lets_count_primes();
}