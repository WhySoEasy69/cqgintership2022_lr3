#include "TokenCounter.h"


TokenCounter::TokenCounter(const std::string& i_substr) : substr(i_substr) {
        buff.reserve(i_substr.size());
 }
 void TokenCounter::operator()(const char& c) {
     buff = buff + c;
     if (c != substr[buff.size() - 1]) {
         buff.erase(begin(buff));
     }
     else if (buff.size() == substr.size()) {
         if (buff == substr) {
             counter++;
             buff.clear();
         }
         else {
             buff.erase(begin(buff));
         }
     }
 }

 size_t TokenCounter::GetTokenCount() const {
     return counter;
}