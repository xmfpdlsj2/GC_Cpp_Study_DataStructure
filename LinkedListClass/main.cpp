#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> v1{ 1, 3, 5, 6 };

    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;
    }
    for (int x : v1)
    {
        std::cout << x << std::endl;
    }
}
