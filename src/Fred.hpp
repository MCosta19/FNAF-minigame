#ifndef FRED_HPP
#define FRED_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Fred : public ObjetoDeJogo {
public:
    Fred(int posL, int posC, bool comBolinho = false) : 
        ObjetoDeJogo("Fred", 
            comBolinho ? 
                SpriteAnimado("rsc/fredcom.anm", 2) : 
                SpriteAnimado("rsc/fredsem.anm", 2), 
            posL, posC),
        comBolinho(comBolinho) {}
    
    void pegarBolinho() { 
        *this = Fred(getPosL(), getPosC(), true);
    }
    
    void entregarBolinho() { 
        *this = Fred(getPosL(), getPosC(), false);
    }
    
    bool temBolinho() const { return comBolinho; }

private:
    bool comBolinho;
};

#endif