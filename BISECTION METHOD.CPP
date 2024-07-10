#include <iostream>
#include <cmath>
#include <iomanip>

// Function definition to calculate the value of the function at a given point
double get_fun(double res) {
    return (res * res * res - 4 * res - 9);
}

// Function to perform the bisection method
double bisect(double int_st, double int_end, double err_all, int mx_iter_cnt) {
    double mid_pt = (int_st + int_end) / 2;
    int iter_cnt = 0;
    std::cout << std::fixed << std::setprecision(6);
    while (iter_cnt < mx_iter_cnt && fabs(int_st - int_end) > err_all) {
        mid_pt = (int_st + int_end) / 2;
        std::cout << "Iteration " << iter_cnt + 1 << ": " << mid_pt << std::endl;
        if (get_fun(int_st) * get_fun(mid_pt) < 0) {
            int_end = mid_pt;
        } else {
            int_st = mid_pt;
        }
        ++iter_cnt;
    }
    return mid_pt;
}

int main() {
    double int_st, int_end, err_all;
    int mx_iter_cnt;
    std::cout << "Enter the first starting point: ";
    std::cin >> int_st;
    std::cout << "Enter the second ending point: ";
    std::cin >> int_end;
    std::cout << "Enter the maximum iterations to be allowed: ";
    std::cin >> mx_iter_cnt;
    std::cout << "Input the number of allowed error points: ";
    std::cin >> err_all;
    double root = bisect(int_st, int_end, err_all, mx_iter_cnt);
    std::cout << "The approximate root is: " << root << std::endl;
    return 0;
}
