#ifndef CARDSRENDER_HPP
#define CARDSRENDER_HPP

#include "Hands.hpp"
#include <cstdarg>
#include <string>


/**
 * @brief
 * Ez a kártyák kiírását valósítja meg
 */
namespace Renderer {
    /**
     * @brief 
     * Ez felel azért hogy láthatóak legyenek a kártyák. 
     * @param hand 
     * @param os 
     */
    void renderCards(Hand *hand, std::ostream& os = std::cout);

    /**
     * @brief 
     * https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
     * Ez a függvény megformázza a kártyákat és visszaadja azt std::string-be.
     * @param fmt
     * @param ...
     * @return std::string
     */
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
}



#endif
