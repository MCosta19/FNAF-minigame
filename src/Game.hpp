#ifndef GAME_HPP
#define GAME_HPP

#include "FaseRestaurante.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"

class Game {
public:
    static void run() {
        SpriteBuffer buffer(80, 25);
        
        FaseRestaurante restaurante;
        restaurante.init();
        
        int resultado = restaurante.run(buffer);
        
        if (resultado == Fase::LEVEL_COMPLETE)
            std::cout << "🎉 Todas as crianças foram atendidas! Fred é um herói!\n";
        else
            std::cout << "😢 Fred não conseguiu hoje... Tente novamente!\n";
    }
};

#endif