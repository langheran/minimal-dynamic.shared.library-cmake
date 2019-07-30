#include <iostream>
#include <sstream>
#include <string>
#include "module.h"

using namespace std;

int main()
{
    cout << module_init(72);
    cout << module_init(12);
    cin.get();
    return 0;
}