#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <cmath>
#include <cstdlib>
/*
Using pseudo code algorithm from CLRS book.

*/
void merge(int* arr, int l, int m, int r){
    int n1 = m-l+1; //mid-inclusive left arr
    int n2 = r-m;
    int l_arr[n1+1];
    int r_arr[n2+1];

    for(int i=0;i<n1;i++){
        l_arr[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        r_arr[i] = arr[m+1+i];
    }

    l_arr[n1] = std::numeric_limits<int>::max();
    r_arr[n2] = std::numeric_limits<int>::max();

    int i =0,j = 0;
    for(int k = l; k<=r;k++){
        if (l_arr[i] <= r_arr[j])
            arr[k] = l_arr[i++];
        else
            arr[k] = r_arr[j++];

    }


}
void merge_sort(int* arr, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        merge_sort(arr,l, m);
        merge_sort(arr,m+1, r);
        merge(arr,l,m,r);
    }
}

void print_elem(int* arr, int size){
    
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<std::endl;
}
int main(){
    int len = 10;
    int arr[len];

    std::random_device rand_gen; 
    std::mt19937 g(rand_gen());
    std::uniform_int_distribution<> dist(1, 100); 
    for(auto &e:arr){
        e = dist(g);
    }
    std::cout<<"Original:   "; print_elem(arr,len);

    merge_sort(arr,0,len-1);
    std::cout<<"Result:     "; print_elem(arr,len);

}