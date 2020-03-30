#include <random>

int getRandomNumber(int min, int max)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> range(min, max);
    return range(mt);
}
