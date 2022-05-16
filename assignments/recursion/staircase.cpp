#include <iostream>

int cache[1000];

/*
 * Complete the 'stepPerms' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int stepPerms(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;
    else if (n < 1)
        return 0;
    else if (cache[n] != 0)
        return cache[n];
    else
    {
        cache[n] = (stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3)) % 10000000007;
        return cache[n];
    }
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        cache[i] = 0;
    }

    std::cout << "n = 1: " << stepPerms(1) << std::endl;
    std::cout << "n = 3: " << stepPerms(3) << std::endl;
    std::cout << "n = 5: " << stepPerms(5) << std::endl;
    std::cout << "n = 7: " << stepPerms(7) << std::endl;

    return 0;
}
