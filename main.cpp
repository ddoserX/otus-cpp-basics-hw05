#include "statistics.hpp"
#include <iostream>

int main()
{
    Min min{};
    Max max{};
    StandartDeviation sd{};
    AverageDeviation ad{sd};

    double value = 0.;
    while (std::cin >> value)
    {
        if (std::cin.good() == false)
        {
            std::cout << "Invalid data!" << std::endl;
            return -1;
        }

        min.Set(value);
        max.Set(value);
        sd.Set(value);
        ad.Set(value);
    }

    std::cout << "Min = " << min.Result() << std::endl;
    std::cout << "Max = " << max.Result() << std::endl;
    std::cout << "SD = " << sd.Result() << std::endl;
    std::cout << "AD = " << ad.Result() << std::endl;

    return 0;
}