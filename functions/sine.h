#include "exponent.h"
namespace functions
{
    class Sine : public functions_base::BaseFunction
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
        int getResult()
        {
            return this->a * sin(this->x * this->b);
        }
        void print() override
        {
            cout << "f(" << x << ") = " << a << " * sin( " << b << " * " << x << " ) = " << this->getResult() << endl;
        }
    };

} // namespace functions