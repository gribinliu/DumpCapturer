// testconsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "breakpad.h"
#include <locale>

int avoidInlineFunction = 1;

void TestFunction() {
    if (avoidInlineFunction == 2)
    {
        // It never uses this code path, it only exists to avoid
        // this function to be inlined.
        TestFunction();
    }

    int* invalid_ptr = reinterpret_cast<int*>(0x42);
    *invalid_ptr = 0xdeadbeef;
}


int main()
{
    google_breakpad::setupBreakpad(_T("."));
    TestFunction();
    return 0;
}

