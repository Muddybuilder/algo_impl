// 1) set pivot
// 2) rearrange left,pivot,right
// 3) recurrsive call

#include <iostream>
#include <vector>

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start;
    int j = end;

    while (i < j)
    {
        if (arr[i] < pivot)
            i++;
        else if (arr[j] >= pivot)
        {
            j--;
        }
        else
        {
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i], arr[end]);
    return i;
}
void qsort(int arr[], int start_idx, int end_idx)
{
    if (start_idx < end_idx)
    {
        int pos = partition(arr, start_idx, end_idx);

        qsort(arr, start_idx, pos - 1);
        qsort(arr, pos + 1, end_idx);
    }
}
int main()
{

    const int arr_len = 12;
    int test_arr[arr_len] = {5, 2, 9, 3, 10, 4, 123, 11, 1529, 41, 1525, 363};
    std::cout << "original: ";
    for (auto &e : test_arr)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;

    qsort(test_arr, 0, arr_len - 1);

    std::cout << "Result:   ";
    for (auto &e : test_arr)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;

    return 0;
}
