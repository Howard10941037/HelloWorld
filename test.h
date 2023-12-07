#ifndef _TEST_H_
#define _TEST_H_
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <complex>
#include "exception.h"
#include <iomanip>

using namespace std;
class Cmain
{
public:
    typedef std::complex<double> Complex;
    struct Denomination
    {
        int thousand;
        int five_hun;
        int two_hun;
        int one_hun;
        int fifty;
        int ten;
        int five;
        int one;
    };
    struct Drinks
    {
        char cola[5] = "Cola";
        int price_cola = 15;
        char tea[5] = "Tea";
        int price_tea = 10;
        int price_water = 100;
    };
    void first_thread_job();
    static void second_thread_job(string x);
    static void multi(int level, vector<int> nums);
    static void merge(std::vector<int> &arr, int l, int m, int r);
    static void mergeSort(std::vector<int> &arr);
    static void backtrack(vector<int> &nums, vector<int> &v);
    static void vendor_main();
    static inline int vendor_coin();
    static inline void vendor_buy(int drink_price, char drink_name[5], char request, int *input_mp);
    static void changes(int input_m, int price);
    static inline void calculate_change(int output_m, Denomination &Deno);
    static inline void printDenomination(Denomination &deno, const int denominations[]);
    static int jump(vector<int> &nums);
    static inline void zero_padding(std::vector<Complex> &x);
    static inline void printVector(const std::vector<Complex> &vec);
    static inline void fft(std::vector<Complex> &a, int threads);
    static void FFT(std::vector<Complex> &x);
    vector<complex<double>> gen_sin(vector<complex<double>> x);

    vector<complex<double>> x;

    enum STATE
    {
        multithread = 0,
        multiple_tab = 1,
        complx = 2,
        casher = 3,
        vendor = 4,
        bitrev = 5
    };

    Cmain();
    ~Cmain();
};

#endif