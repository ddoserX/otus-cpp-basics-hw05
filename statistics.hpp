#pragma once

#include <cmath>
#include <limits>
#include <vector>

class IStatistics
{
public:
    virtual void Set(double) = 0;
    virtual double Result() const = 0;
    virtual const char *Name() const = 0;
};

class Min : public IStatistics
{
public:
    Min();
    void Set(double) override;
    double Result() const override;
    const char *Name() const override;

private:
    double m_result;
};

class Max : public IStatistics
{
public:
    Max();
    void Set(double) override;
    double Result() const override;
    const char *Name() const override;

private:
    double m_result;
};

class StandartDeviation : public IStatistics
{
public:
    StandartDeviation();
    StandartDeviation(const std::vector<double> &);
    void Set(double) override;
    double Result() const override;
    const char *Name() const override;

private:
    std::vector<double> m_buffer;
};

class AverageDeviation : public IStatistics
{
public:
    void Set(double) override;
    double Result() const override;
    const char *Name() const override;

private:
    std::vector<double> m_buffer;
};
