#ifndef CRIANCA_HPP
#define CRIANCA_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Crianca : public ObjetoDeJogo {
public:
    Crianca(int posL, int posC, bool satisfeita = false) : 
        ObjetoDeJogo("Crianca", 
            satisfeita ?
                Sprite("rsc/crianca_feliz.img") :
                Sprite("rsc/crianca_triste.img"),
            posL, posC),
        satisfeita(satisfeita) {}
    
    void receberBolinho() { 
        *this = Crianca(getPosL(), getPosC(), true);
    }
    
    bool estaSatisfeita() const { return satisfeita; }

private:
    bool satisfeita;
};

#endif