#include "exponent.h"
namespace functions
{
    class Sine : public functions_base::BaseFunction
    {
        public:
        void print() override {
            cout << this->x << endl;
        }
    };

} // namespace functions