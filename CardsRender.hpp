#ifndef CARDSRENDER_HPP
#define CARDSRENDER_HPP

#include "Hands.hpp"
#include <cstdarg>


/**
 * @brief
 * Ez a kártyák kiírását valósítja meg
 */
namespace Renderer {
    void renderCards(Hand *hand);
    /*https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf*/
    inline std::string format(const char* fmt, ...){
        int size = 512;
        char* buffer = 0;
        buffer = new char[size];
        va_list vl;
        va_start(vl, fmt);
        int nsize = vsnprintf(buffer, size, fmt, vl);
        if(size<=nsize){ //fail delete buffer and try again
            delete[] buffer;
            buffer = 0;
            buffer = new char[nsize+1]; //+1 for /0
            nsize = vsnprintf(buffer, size, fmt, vl);
        }
        std::string ret(buffer);
        va_end(vl);
        delete[] buffer;
        return ret;
    }
    std::string getCardsString(Hand *hand);
    std::string getCardStringFormLine(Card *card, int line);
}



#endif
