#ifndef LEASTSQUAREMETHOD_H
#define LEASTSQUAREMETHOD_H

#include <vector>

using namespace std;

class LeastSquareMethod
{
public:
    static LeastSquareMethod *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new LeastSquareMethod();
        }
        return instance;
    }

    vector<double> & handle(vector<double> &y, vector<double> &x, int highestPower = 0);
    vector<double> & handle(double *y, double *x, int size, int highestPower = 0);

    vector<double> & getCoefficient();

    double getY(const vector<double> &coefficient, double x);
    double getY(double x);
private:
    vector<double> y_;
    vector<double> x_;
    vector<double> coefficient_;
    int highestPower_;

    static LeastSquareMethod *instance;

    LeastSquareMethod();
    //LeastSquareMethod(vector< double > &y, vector< double > &x, int highestPower = 0);
    ~LeastSquareMethod();
};



#endif // LEASTSQUAREMETHOD_H
