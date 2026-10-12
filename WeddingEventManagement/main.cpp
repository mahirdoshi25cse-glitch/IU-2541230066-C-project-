
#include <iostream>
#include <exception>
#include "EventManager.h"

using namespace std;

int main()
{
    try
    {
        EventManager manager;
        manager.menu();
    }
    catch (const exception& e)
    {
        cerr << "\nAn unexpected error occurred: "
             << e.what() << endl;

        return 1;
    }

    return 0;
}
