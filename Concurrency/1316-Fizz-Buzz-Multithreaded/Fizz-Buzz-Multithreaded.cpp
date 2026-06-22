#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

class FizzBuzz {
private:
    int n;
    int i = 1;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return i > n || (i % 3 == 0 && i % 5 != 0); });

            if (i > n) return;

            printFizz();
            i++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return i > n || (i % 5 == 0 && i % 3 != 0); });

            if (i > n) return;

            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return i > n || (i % 15 == 0); });

            if (i > n) return;

            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return i > n || (i % 3 != 0 && i % 5 != 0); });

            if (i > n) return;

            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};