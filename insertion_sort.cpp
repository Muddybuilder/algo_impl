#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;
void insertion_sort(vector<int> &orig_vec){
    cout << "Original " << ": ";
    for(auto &e:orig_vec){
        cout<<e<<" ";
    }
    cout<<endl;

    for (auto iter = next(orig_vec.begin(),1); iter != orig_vec.end(); iter++){
        auto cur_iter {iter};
        auto prev_iter {prev(iter,1)};
        while(*cur_iter < *prev_iter){
            auto tmp = *cur_iter;
            *cur_iter-- = *prev_iter;
            *prev_iter-- = tmp;
        }

        for(auto &e:orig_vec){
            cout<<e<<" ";
        }
        cout<<endl;
    }
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