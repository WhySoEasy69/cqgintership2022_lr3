// sqgintership_lr3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TokenCounter.h"
#include "TokenCounterTest.h"


void GetTokenCount(const std::string& str, const std::string& substr) {

    TokenCounter SubStrCounter(substr);
    std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
    std::cout << SubStrCounter.GetTokenCount() << " " << substr << " in " << str << '\n';

}

int main()
{
    TokenCounterTest(); 

    GetTokenCount("aaabb", "aa"); 
    GetTokenCount("aaabb", "a");
    GetTokenCount("aaabb", "ab");
    GetTokenCount("aaabb", "");
    GetTokenCount("aaabb", "aaabb");
    GetTokenCount("aaabb", "aaabbb");
    GetTokenCount("ababababababa", "aba"); 
    GetTokenCount("", ""); 
    GetTokenCount("AaBabbAbAABB,123/923A  Bab", "ab"); 
    GetTokenCount("AaBabbAbAABB,123/923A  Bab", "Ba"); 

    return 0; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
