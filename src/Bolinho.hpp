#ifndef BOLINHO_HPP
#define BOLINHO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Bolinho : public ObjetoDeJogo {
public:
    Bolinho(int posL, int posC) : 
        ObjetoDeJogo("Bolinho", Sprite("rsc/bolinho.img"), posL, posC) {}
};

#endif
