#include "LeastSquareMethod.h"
#include <math.h>

LeastSquareMethod *LeastSquareMethod::instance = nullptr;

LeastSquareMethod::LeastSquareMethod()
{
}

/*
LeastSquareMethod::LeastSquareMethod(vector<double>& y, vector<double>& x, int highestPower)
: highestPower(highestPower), y(y), x(x)
{
}
*/

LeastSquareMethod::~LeastSquareMethod()
{
}

vector<double> & LeastSquareMethod::handle(double *y, double *x, int size, int highestPower)
{
    this->coefficient_.clear();
    this->highestPower_ = highestPower;

    int n = size, m = highestPower;

    int row = this->highestPower_ + 2;
    vector<double> a((m + 1) * row);

    for (int i = 0; i <= m; ++i)
    {
        int j;
        for (j = 0; j <= m; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                a[i * row + j] += pow(x[k], i + j);
            }
        }

        for (int k = 0; k < n; ++k)
        {
            a[i * row + j] += y[k] * pow(x[k], i);
        }
    }

    for (int k = 0; k <= m - 1; ++k)
    {
        for (int i = k + 1; i <= m; ++i)
        {
            double t = -a[i * row + k] / a[k * row + k];
            for (int j = k + 1; j <= m + 1; ++j)
            {
                a[i * row + j] += a[k * row + j] * t;
            }
        }
    }

    for (int i = m; i >= 0; --i)
    {
        for (int j = i + 1; j <= m; ++j)
        {
            a[i*row + m + 1] -= a[i*row + j] * a[j * row + m + 1];
        }
        a[i*row + m + 1] /= a[i*row + i];
    }

    this->coefficient_.resize(m + 1);
    for (int i = 0; i <= m; ++i)
    {
        this->coefficient_[i] = a[i * row + m + 1];
    }

    return this->coefficient_;
}

vector<double> & LeastSquareMethod::handle(vector<double>& y, vector<double>& x, int highestPower)
{
    this->highestPower_ = highestPower;
    y_ = y;
    x_ = x;
    return this->handle(&y[0], &x[0], (int)y.size(), highestPower);
}

vector<double>& LeastSquareMethod::getCoefficient()
{
    return this->coefficient_;
}

double LeastSquareMethod::getY(const vector<double> &coefficient, double x)
{
    double res = 0;

    vector<double>::const_iterator it1;
    double tmp = 1;
    for (it1 = coefficient.begin(); it1 != coefficient.end(); ++it1)
    {
        res += *it1 * tmp;
        tmp *= x;
    }

    return res;
}

double LeastSquareMethod::getY(double x)
{
    double res = 0;

    vector<double>::const_iterator it1;
    double tmp = 1;
    for (it1 = coefficient_.begin(); it1 != coefficient_.end(); ++it1)
    {
        res += *it1 * tmp;
        tmp *= x;
    }

    return res;
}
