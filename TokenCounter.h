#pragma once
#include <string>
#include <algorithm>

class TokenCounter {
public:
    TokenCounter(const std::string& i_substr); 
    void operator()(const char& c); 
    size_t GetTokenCount() const; 
private:
    std::string buff;
    std::string substr;
    size_t counter = 0;
};