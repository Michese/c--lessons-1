#include "exponent.h"
namespace functions
{
    class Sine : public functions_base::BaseFunction
    {
    public:
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