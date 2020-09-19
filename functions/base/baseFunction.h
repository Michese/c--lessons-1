#include <iostream>
#include <cmath>
namespace functions_base
{
    class BaseFunction
    {
    public:
        void setParams(int a, int b, int x)
        {
            this->a = a;
            this->b = b;
            this->x = x;
        }
        void setParams(int params[3])
        {
            this->a = params[0];
            this->b = params[1];
            this->x = params[2];
        }
        virtual int getResult() = 0;
        virtual void print() = 0;

    protected:
        int a, b, x;
    };
} // namespace functions_base