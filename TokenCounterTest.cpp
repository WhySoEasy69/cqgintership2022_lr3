#include "TokenCounterTest.h"

void TokenCounterTest() {
    std::string str = "aaabb";
    {
        TokenCounter SubStrCounter("aa"); 
        size_t res = 1; 
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount()); 
    }
    {
        TokenCounter SubStrCounter("a");
        size_t res = 3;
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount());
    }
    {
        TokenCounter SubStrCounter("ab");
        size_t res = 1;
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount());
    }
    {
        TokenCounter SubStrCounter("");
        size_t res = 0;
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount());
    }
    {
        TokenCounter SubStrCounter("aaabb");
        size_t res = 1;
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount()); 
    }
    str = ""; 
    {
        TokenCounter SubStrCounter("");
        size_t res = 0;                                                //  1 or 0 ???? 
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount());
    }
    {
        TokenCounter SubStrCounter("a");
        size_t res = 0;
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount());
    }
    str = "ababababababa"; 
    {
        TokenCounter SubStrCounter("aba");
        size_t res = 3;
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount());
    }
    str = "AaBabbAbAABB,123/923A  Bab"; 
    {
        TokenCounter SubStrCounter("ab");
        size_t res = 2;
        std::for_each(str.begin(), str.end(), std::ref(SubStrCounter));
        assert(res == SubStrCounter.GetTokenCount());
    }

    std::cerr << "TokenCounterTest OK !" << '\n'; 
    std::cerr << '\n';
}