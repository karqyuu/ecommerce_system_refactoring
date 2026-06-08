#include <iostream>
#include "test_registry.h"

using namespace std;

int main() 
{
    cout << "--- Starting modular test suite ---" << endl;

    run_test_vip();
    run_test_student();
    run_test_regular();
    run_test_errors();

    cout << "--- All tests passed successfully! ---" << endl;
    return 0;
}