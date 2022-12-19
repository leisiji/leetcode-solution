#include <iostream>
class Solution
{
private:
    static constexpr int LIMIT = INT32_MIN >> 1;
public:
    int divide(int dividend, int divisor);
};

int Solution::divide(int dividend, int divisor)
{
    if (dividend == 0) {
        return 0;
    } else if (divisor == 1) {
        return dividend;
    } else if (divisor == -1) {
        if (dividend > -INT32_MAX) {
            return -dividend;
        } else {
            return INT32_MAX;
        }
    }

    bool minus = false;

    if (dividend < 0) {
        if (divisor > 0) {
            divisor = -divisor;
            minus = true;
        }
    } else {
        if (divisor < 0) {
            minus = true;
        } else {
            divisor = -divisor;
        }
        dividend = -dividend;
    }

    if (dividend > divisor) {
        return 0;
    }

    int right = divisor, left = divisor;
    int right_index = 1, left_index = 1;

    while (right > dividend) {
        left = right;
        left_index = right_index;
        right_index = right_index << 1;
        if (right <= LIMIT) {
            int tmp = divide(dividend - left, divisor);
            if (minus) {
                left_index = -left_index;
                tmp = -tmp;
            }
            return tmp + left_index;
        }
        right += right;
    }

    if (right == dividend) {
        if (minus) {
            right_index = -right_index;
        }
        return right_index;
    }

    while (right - left < divisor) {
        int mid = (left >> 1) + (right >> 1);
        int mid_index = (right_index + left_index) >> 1;
        if (mid > dividend) {
            left = mid;
            left_index = mid_index;
        } else if (mid < dividend) {
            right = mid;
            right_index = mid_index;
        } else {
            if (minus) {
                mid_index = -mid_index;
            }
            return mid_index;
        }
    }

    if (minus) {
        left_index = -left_index;
    }

    return left_index;
}

int main(int argc, char *argv[])
{
    Solution s;

    // std::cout << s.divide(7, 3) << std::endl;
    // std::cout << s.divide(100, 23) << std::endl;
    // std::cout << s.divide(100, -23) << std::endl;
    // std::cout << s.divide(100000, 23) << std::endl;
    // std::cout << s.divide(INT32_MAX, 2) << std::endl;
    // std::cout << s.divide(INT32_MAX, 22) << std::endl;
    // std::cout << s.divide(INT32_MIN, -1) << std::endl;
    // std::cout << s.divide(INT32_MIN, 2) << std::endl;

    // std::cout << s.divide(INT32_MIN, -INT32_MAX-1) << std::endl;
    // std::cout << s.divide(INT32_MIN, INT32_MIN) << std::endl;
    // std::cout << s.divide(INT32_MAX, -INT32_MAX) << std::endl;
    // std::cout << s.divide(10, -10) << std::endl;

    // std::cout << s.divide(-20, 2) << std::endl;
    std::cout << s.divide(-1021989372, -82778243) << std::endl;

    return 0;
}
