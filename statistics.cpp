#include "statistics.hpp"

Min::Min() : m_result{std::numeric_limits<double>::max()}
{
}

void Min::Set(double value)
{
    if (m_result > value)
    {
        m_result = value;
    }
}

double Min::Result() const
{
    return m_result;
}

const char *Min::Name() const
{
    return "Min";
}

Max::Max() : m_result{std::numeric_limits<double>::lowest()}
{
}

void Max::Set(double value)
{
    if (m_result < value)
    {
        m_result = value;
    }
}

double Max::Result() const
{
    return m_result;
}

const char *Max::Name() const
{
    return "Max";
}

StandartDeviation::StandartDeviation() = default;

StandartDeviation::StandartDeviation(const std::vector<double> &arr) : m_buffer{arr}
{
}

void StandartDeviation::Set(double value)
{
    m_buffer.push_back(value);
}

double StandartDeviation::Result() const
{
    double result = 0.;

    for (size_t i = 0; i < m_buffer.size(); ++i)
    {
        result += m_buffer[i];
    }

    result /= m_buffer.size();

    return result;
}

const char *StandartDeviation::Name() const
{
    return "SD";
}

void AverageDeviation::Set(double value)
{
    m_buffer.push_back(value);
}

double AverageDeviation::Result() const
{
    double result = 0.;
    StandartDeviation mean{m_buffer};
    StandartDeviation sd;

    for (size_t i = 0; i < m_buffer.size(); i++)
    {
        sd.Set(std::pow(m_buffer[i] - mean.Result(), 2));
    }

    result = std::sqrt(sd.Result());

    return result;
}

const char *AverageDeviation::Name() const
{
    return "AD";
}
