#include "test.h"
Cmain::Cmain()
{
}
Cmain::~Cmain()
{
}

void Cmain::first_thread_job()
{
    cout << "This is the first thread " << endl;
}
//
void Cmain::second_thread_job(string x)
{
    cout << "This is the second thread " << x << endl;
}
void Cmain::multi(int level, vector<int> nums)
{
    // nums: the increasing variables in the loop. level: the number of the loops
    if (level == 2)
    {
        cout << nums[0] << "*" << nums[1] << "=" << nums[0] * nums[1] << endl;
        return;
    }
    for (nums[level] = 1; nums[level] <= 9; nums[level]++)
    {
        multi(level + 1, nums);
    }
}

void Cmain::printDenomination(Denomination &deno, const int denominations[])
{
    //
    for (int i = 0; i < sizeof(deno) / sizeof(int); ++i)
    {
        std::cout << denominations[i] << ": " << *(&deno.thousand + i) << std::endl;
    }
}
void Cmain::calculate_change(int output_m, Denomination &deno)
{
    while (output_m > 0)
    {
        if (output_m >= 1000)
        {
            deno.thousand++;
            output_m -= 1000;
        }
        else if (output_m >= 500 && output_m < 1000)
        {
            deno.five_hun++;
            output_m -= 500;
        }
        else if (output_m >= 200 && output_m < 500)
        {
            deno.two_hun++;
            output_m -= 200;
        }
        else if (output_m >= 100 && output_m < 200)
        {
            deno.one_hun++;
            output_m -= 100;
        }
        else if (output_m >= 50 && output_m < 100)
        {
            deno.fifty++;
            output_m -= 50;
        }
        else if (output_m >= 10 && output_m < 50)
        {
            deno.ten++;
            output_m -= 10;
        }
        else if (output_m >= 5 && output_m < 10)
        {
            deno.five++;
            output_m -= 5;
        }
        else if (output_m >= 1 && output_m < 5)
        {
            deno.one++;
            output_m -= 1;
        }
    }
}

//
void Cmain::changes(int input_m, int price)
{
    Cmain::Denomination *Deno;
    volatile int output_m = input_m - price;

    cout << "Price: " << price << endl;
    cout << "Input: " << input_m << endl;
    cout << "Changes: " << output_m << endl;
    Deno = new Cmain::Denomination;

    try
    {
        if (output_m <= 0)
            throw CException("Not enough");
        const int denominations[] = {1000, 500, 200, 100, 50, 10, 5, 1};
        // Denomination: 1000; 500; 200; 100; 50; 10; 5; 1
        calculate_change(output_m, *Deno);
        printDenomination(*Deno, denominations);
    }
    catch (const CException &e)
    {
        std::cerr << e.what() << '\n';
    }
    delete Deno;
}

vector<complex<double>> Cmain::gen_sin(vector<complex<double>> x)
{
    vector<complex<double>> sinx(x.size());
    for (int i = 0; i < x.size(); i++)
        sinx[i] = sin(x[i]);

    return sinx;
}

void Cmain::merge(std::vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void Cmain::mergeSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {
            int mid = std::min(left_start + curr_size - 1, n - 1);
            int right_end = std::min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}
void Cmain::backtrack(vector<int> &nums, vector<int> &v)
{
    vector<vector<int>> ans;
    if (nums.empty())
    {
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back(nums[i]);
        nums.erase(nums.begin() + i);
        backtrack(nums, v);
        nums.insert(nums.begin() + i, v.back());
        v.pop_back();
    }
}
int Cmain::vendor_coin()
{
    char input_coin = 0;
    cout << "Enter the coin(0 for 5, 1 for 10): ";
    cin >> input_coin;
    if (input_coin == '0')
        return 5;
    else if (input_coin == '1')
        return 10;
    else
        return 0;
    return 10;
}

void Cmain::vendor_buy(int drink_price, char drink_name[5], char request, int *input_mp)
{
    cout << "Buy the " << drink_name << "? (y/n)" << endl;
    cin >> request;
    if (request == 'y')
    {
        cout << drink_name << " drops." << endl;
        *input_mp -= drink_price;
    }
    else if (request == 'n')
    {
    }
    else
        cout << "invalid" << endl;
}

void Cmain::vendor_main()
{
    Cmain::Drinks *Drink;
    Drink = new Cmain::Drinks;
    int *input_mp = new int;
    char request;
    while (true)
    {
        *input_mp += vendor_coin();

        if (*input_mp >= Drink->price_tea && *input_mp < Drink->price_cola)
        {
            // vendor_buy_tea(*Drink, request, input_mp);
            vendor_buy(Drink->price_tea, Drink->tea, request, input_mp);
        }
        else if (*input_mp >= Drink->price_cola)
        {
            // vendor_buy_tea(*Drink, request, input_mp);
            vendor_buy(Drink->price_tea, Drink->tea, request, input_mp);
            vendor_buy(Drink->price_cola, Drink->cola, request, input_mp);
        }
        cout << "Continue? (y/n)" << endl;
        cin >> request;
        if (request == 'y')
            continue;
        else if (request == 'n')
            break;
        else
            cout << "invalid" << endl;
    }
    cout << "Changes: " << *input_mp << endl;
    delete Drink;
    delete input_mp;
}

int Cmain::jump(vector<int> &nums)
{

    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = max(nums[i] + i, nums[i - 1]);
    }

    int ind = 0;
    int ans = 0;

    while (ind < nums.size() - 1)
    {
        ans++;
        ind = nums[ind];
    }

    return ans;
}

void Cmain::zero_padding(std::vector<Complex> &x)
{
    int n = x.size();
    int nextPowerOfTwo = 1;

    while (nextPowerOfTwo < n)
    {
        nextPowerOfTwo *= 2;
    }
    x.resize(nextPowerOfTwo, 0);
}

// Cooley-Tukey FFT算法
void Cmain::fft(std::vector<Complex> &a, int threads)
{
    int n = a.size();
    if (n <= 1)
        return;

    // 將序列分為偶數和奇數索引
    std::vector<Complex> even, odd;
    for (int i = 0; i < n; i += 2)
    {
        even.push_back(a[i]);
        odd.push_back(a[i + 1]);
    }

    thread evenThread(fft, std::ref(even), threads / 2);
    thread oddThread(fft, std::ref(odd), threads / 2);

    evenThread.join();
    oddThread.join();
    // 遞迴計算偶數和奇數索引的FFT
    // fft(even);
    // fft(odd);

    // 合併遞迴結果
    for (int i = 0; i < n / 2; ++i)
    {
        Complex t = std::polar(1.0, -2.0 * M_PI * i / n) * odd[i];
        a[i] = even[i] + t;
        a[i + n / 2] = even[i] - t;
    }
    // int n = a.size();
    // if (n <= 1) {
    //     return;
    // }

    // // 比特反轉
    // for (int i = 0; i < n; ++i) {
    //     int j = 0;
    //     for (int bit = 0; (1 << bit) < n; ++bit) {
    //         j |= (i & (1 << bit)) >> bit << (int)log2(n) - 1 - bit;
    //     }
    //     if (j > i) {
    //         std::swap(a[i], a[j]);
    //     }
    // }

    // int ctr = 0;
    // // 遞迴計算
    // for (int len = 2; len <= n; len *= 2) {
    //     double angle = -2 * M_PI / len;
    //     std::complex<double> wlen(cos(angle), sin(angle));
    //     for (int i = 0; i < n; i += len) {
    //         std::complex<double> w(1);
    //         for (int j = 0; j < len / 2; ++j) {
    //             std::complex<double> u = a[i + j];
    //             std::complex<double> v = a[i + j + len / 2] * w;
    //             a[i + j] = u + v;
    //             a[i + j + len / 2] = u - v;
    //             w *= wlen;
    //             ctr++;
    //         }
    //     }
    // }
}

// 輸出向量的值
void Cmain::printVector(const std::vector<Complex> &vec)
{
    std::cout << std::fixed << std::setprecision(6);
    for (const Complex &val : vec)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
}

void Cmain::FFT(std::vector<Complex> &x)
{
    // 將向量補齊成2的冪
    zero_padding(x);

    // 執行FFT
    fft(x, 2);

    // 輸出結果
    std::cout << "DFT result: " << endl;
    printVector(x);
}