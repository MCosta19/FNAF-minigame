#ifndef MESA_HPP
#define MESA_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Mesa : public ObjetoDeJogo {
public:
    Mesa(int posL, int posC) : 
        ObjetoDeJogo("Mesa", Sprite("rsc/mesa.img"), posL, posC) {}
};

#endif