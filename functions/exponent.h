#include "base/baseFunction.h"
namespace functions
{
    using namespace std;
    class Exponent : public functions_base::BaseFunction
    {
    public:
        void setParams(int a, int b, int x) override
        {
            this->a = a;
            this->b = b;
            this->x = x;
        }
        void setParams(int params[3]) override
        {
            this->a = params[0];
            this->b = params[1];
            this->x = params[2];
        }
        int getResult() override
        {
            return this->a * exp(this->b * this->x);
        }
        void print() override
        {
            cout << "f(" << x << ") = " << a << " * exp^( " << b << " * " << x << " ) = " << this->getResult() << endl;
        }
    };
} // namespace functions