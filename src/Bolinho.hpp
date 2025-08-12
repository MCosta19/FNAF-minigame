#ifndef BOLINHO_HPP
#define BOLINHO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Bolinho : public ObjetoDeJogo {
public:
    Bolinho(int posL, int posC) : 
        ObjetoDeJogo("Bolinho", Sprite("rsc/bolinho.img"), posL, posC),
        respawnTimer(0) {}

    void update() override {
        if (!getActive() && respawnTimer > 0) {
            --respawnTimer;
            if (respawnTimer == 0) {
                ativarObj();
            }
        }
    }

    void desativarComRespawn(int delay) {
        desativarObj();
        respawnTimer = delay;
    }

private:
    int respawnTimer;
};

#endif
