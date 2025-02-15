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

AverageDeviation::AverageDeviation(StandartDeviation &mean) : m_mean{mean}
{
}

void AverageDeviation::Set(double value)
{
    m_buffer.push_back(value);
}

double AverageDeviation::Result() const
{
    double result = 0.;
    double mean = m_mean.Result();
    StandartDeviation sd;

    for (size_t i = 0; i < m_buffer.size(); i++)
    {
        sd.Set(std::pow(m_buffer[i] - mean, 2));
    }

    result = std::sqrt(sd.Result());

    return result;
}
