#include <iostream>
#include <vector>
#include <random>
auto get_left_idx = [](int i){return i<<1;};
auto get_right_idx = [](int i){return get_left_idx(i)+1;};

void heapify(std::vector<int> &arr, int size, int idx)
{
    if (idx < size)
    {
        int cur_val = arr[idx];
        int largest = idx;
        if (get_left_idx(idx) < size && arr[get_left_idx(idx)] > cur_val)
        {
            largest = get_left_idx(idx);
        }
        if (get_right_idx(idx) < size && arr[get_right_idx(idx)] > arr[largest])
        {
            largest = get_right_idx(idx);
        }
        if (largest != idx)
        {
            std::swap(arr[largest], arr[idx]);
            heapify(arr, size, largest);
        }
    }
}

void build_max_heap(std::vector<int> &arr, int heap_size)
{
    for (int i = (heap_size - 1) / 2; i >= 0; i--)
    {
        heapify(arr, heap_size, i);
    }
}

void heap_sort(std::vector<int> &vec)
{
    int heap_size = vec.size();
    build_max_heap(vec, heap_size);
    for (int i = heap_size - 1; i > 0; i--)
    {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

int main()
{
    std::vector<int> vec;
    std::random_device rand_gen;
    std::mt19937 g(rand_gen());
    std::uniform_int_distribution<> dist(1, 100);
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(dist(g));
    }
    std::cout << "Original:   ";
    for (auto &e : vec)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;

    heap_sort(vec);

    std::cout << "Result:     ";
    for (auto &e : vec)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}