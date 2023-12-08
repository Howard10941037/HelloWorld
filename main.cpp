// #include <stdio.h>
// #include <iostream>
// #include <vector>
// using namespace std;
/*void quicksort(int *array, int left, int right)
{
    if (left >= right) return;

    int i = left, j = right;
    int k = (left + right) / 2;	// 可以隨便選
    int pivot = array[k];
    while (true)
    {
        // 小於等於改成小於，就不必偵測陣列邊界。
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i >= j) return;
        // 代價：等於pivot的數字，一直做交換。
        swap(array[i], array[j]);
        i++; j--;
    }

    // 代價：array[i]不一定就是pivot。
    quicksort(array, left, j);
    quicksort(array, i, right);
}*/
// int Partition(volatile int *arr, int front, int end){
//     int pivot = arr[end];
//     int i = front -1;
//     for (int j = front; j < end; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     i++;
//     swap(arr[i], arr[end]);
//     return i;
// }
// void QuickSort(volatile int *arr, int front, int end){
//     if (front < end) {
//         int pivot = Partition(arr, front, end);
//         QuickSort(arr, front, pivot - 1);
//         QuickSort(arr, pivot + 1, end);
//     }
// }
// int main()
// {
//     volatile int array[] = {2,1,7,5,3};

//     QuickSort(array, 0, 4);

// 	// 代價：array[i]不一定就是pivot。
// 	for(int k = 0; k<5; k++)
// 	{
//         cout<< array[k]<< endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include "fun1.cpp"
// using namespace std;

// ====== output ======
// This is the first thread
// This is the second thread abc
// #include <iostream>
// #include <vector>
// #include <thread>

// using namespace std;
// void first_thread_job(int *nums, int n)
// {

// 	for(int i = 0; i < n; i++)
// 		nums[i]--;
// }
// void second_thread_job(int *nums, int n)
// {
//  for(int i = 0; i < n; i++)
//  	nums[i]+=2;
// }
// int main()
// {
// 	int nums_first[] = {0,1,2,3,4};
// 	int nums_second[] = {5,6,7,8,9,10};

// 	thread first_thread(first_thread_job, nums_first, sizeof(nums_first)/sizeof(int));
// 	thread second_thread(second_thread_job, nums_second, sizeof(nums_second)/sizeof(int));
// 	first_thread.join();
// 	second_thread.join();
// 	for(auto it : nums_first) cout << it << endl;
// 	for(auto it : nums_second) cout << it << endl;
// 	return 0;
// }
#include "test.h"

// #include <thread>
Cmain Cm;
typedef std::complex<double> Complex;
inline void prwrd()
{
    cout << "123" << endl;
}

std::istream &operator>>(std::istream &is, Cmain::STATE &state)
{
    int a;
    is >> a;
    state = static_cast<Cmain::STATE>(a);

    return is;
}

int main()
{
    /* std::vector<int> arr = {12, 11, 13, 5, 6, 7};

     std::cout << "Original array: ";
     for (int num : arr) {
         std::cout << num << " ";
     }
     std::cout << "\n";

     mergeSort(arr);

     std::cout << "Sorted array: ";
     for (int num : arr) {
         std::cout << num << " ";
     }
     std::cout << "\n";

     return 0;*/
    /*vector<int> nums = {2,3,1,1,4,5,2,3};
    int k = jump(nums);
    cout<< k<<endl;
    return k;*/
    /*vector<int> v;
    vector<int> nums = {1,2,3};
    backtrack(nums,v);
    return 0;*/

    volatile int input_m = 0, price = 2000;
    Cmain::STATE state = Cm.bitrev;
    // Cmain::STATE state;
    // cin >> state;
    // vector<complex<double>>  x;

    for (int i = 0; i < 180; i++)
        Cm.x.push_back(complex<double>(M_PI / 180 * i, 1));

    vector<complex<double>> sinx;
    // state = multithread;
    switch (state)
    {
    case Cm.multiple_tab:
    {
        /* code */
        int a = 0;
        Cm.multi(0, vector<int>(2));
        break;
    }
    case Cm.multithread:
    {
        // 建立執行緒
        thread first_thread(&Cmain::first_thread_job, Cm);
        thread second_thread(&Cmain::second_thread_job, "abc");
        //
        first_thread.join();
        second_thread.join();
        break;
    }
    case Cm.complx:
    {
        sinx = Cm.gen_sin(Cm.x);
        for (auto it : sinx)
            cout << it << endl;
        break;
    }
    case Cm.casher:
    {
        // cin >> input_m;
        input_m = 4341;
        Cm.changes(input_m, price);
        break;
    }
    case Cm.vendor:
    {
        Cm.vendor_main();
    }
    case Cm.bitrev:
    {
        std::vector<Complex> x = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}};
        Cm.FFT(x);
    }
    default:
        return 0;
        break;
    }

    return 0;
}
