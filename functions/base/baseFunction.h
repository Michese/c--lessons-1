#include <iostream>
namespace functions_base
{
    class BaseFunction
    {
    public:
        virtual void print() = 0;

    protected:
        int a, b, x;
    };
} // namespace functions_base