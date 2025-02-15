#pragma once

#include <cmath>
#include <limits>
#include <vector>

class IStatistics
{
public:
    virtual void Set(double) = 0;
    virtual double Result() const = 0;
};

class Min : public IStatistics
{
public:
    Min();
    void Set(double) override;
    double Result() const override;

private:
    double m_result;
};

class Max : public IStatistics
{
public:
    Max();
    void Set(double) override;
    double Result() const override;

private:
    double m_result;
};

class StandartDeviation : public IStatistics
{
public:
    void Set(double) override;
    double Result() const override;

private:
    std::vector<double> m_buffer;
};

class AverageDeviation : IStatistics
{
public:
    AverageDeviation(StandartDeviation &);
    void Set(double) override;
    double Result() const override;

private:
    StandartDeviation &m_mean;
    std::vector<double> m_buffer;
};
