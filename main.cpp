#include "functions/sine.h"
#include <random>
#include <ctime>
using namespace functions;
using namespace functions_base;

int main()
{
    srand(time(NULL));
    int size = rand() % 10 + 1;
    BaseFunction **array = new BaseFunction *[size];
    for (int row = 0; row < size; row++)
    {
        if (rand() % 2 == 1)
        {
            array[row] = new Sine();
        }
        else
        {
            array[row] = new Exponent();
        }
    }
    
    



    for (int row = 0; row < size; row++)
    {
        delete[] array[row];
    }
    delete[] array;

    return 0;
}