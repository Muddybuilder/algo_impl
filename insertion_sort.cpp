#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;
void insertion_sort(vector<int> &vec){
    cout << "Original " << ": ";
    for(auto &e:vec){
        cout<<e<<" ";
    }
    cout<<endl;

    for (auto iter = next(vec.begin(),1); iter != vec.end(); iter++){   // n -1 times
        auto cur_iter {iter};
        auto prev_iter {prev(iter,1)};
        while(*cur_iter < *prev_iter){                                  // Worst case: Sum(i), from i=2 to n -> n(n-1)/2 - 1
            std::swap(*cur_iter--, *prev_iter--);
        }

        for(auto &e:vec){
            cout<<e<<" ";
        }
        cout<<endl;
    }                                                                   // This sort algo. has worst case of THETA(n^2)
}



int main(){
    vector<int> unsorted_vec(15);
    iota(unsorted_vec.begin(), unsorted_vec.end(),1);
    
    random_device rand_gen;
    mt19937 g(rand_gen());
 
    shuffle(unsorted_vec.begin(), unsorted_vec.end(), g);


    insertion_sort(unsorted_vec);

    return 0;
}