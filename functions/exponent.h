#include "base/baseFunction.h"
namespace functions
{
    using namespace std;
    class Exponent : public functions_base::BaseFunction
    {
    public:
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