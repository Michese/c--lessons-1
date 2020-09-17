#include "base/baseFunction.h"
namespace functions {
using namespace std;
class Exponent : public functions_base::BaseFunction {
    public:
    void print() {
        cout << this->x << endl;
    }
};
}