#include "statistics.hpp"
#include <iostream>

int main()
{
    const size_t statisticsSize = 4;
    IStatistics *statistics[statisticsSize];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new StandartDeviation{};
    statistics[3] = new AverageDeviation{};

    double value = 0.;
    while (std::cin >> value)
    {
        if (std::cin.good() == false)
        {
            std::cout << "Invalid data!" << std::endl;
            return -1;
        }

        for (size_t i = 0; i < statisticsSize; i++)
        {
            statistics[i]->Set(value);
        }
    }

    for (size_t i = 0; i < statisticsSize; i++)
    {
        std::cout << statistics[i]->Name() << " = " << statistics[i]->Result() << std::endl;
    }

    return 0;
}