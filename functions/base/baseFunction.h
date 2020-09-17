#include <iostream>
#include <cmath>
namespace functions_base
{
    class BaseFunction
    {
    public:
        virtual void setParams(int a, int b, int x) = 0;
        virtual void setParams(int params[3]) = 0;
        virtual int getResult() = 0;
        virtual void print() = 0;

    protected:
        int a, b, x;
    };
} // namespace functions_base