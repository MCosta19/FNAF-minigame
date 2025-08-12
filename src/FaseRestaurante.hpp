#ifndef FASERESTAURANTE_HPP
#define FASERESTAURANTE_HPP

#include "ASCII_Engine/Fase.hpp"
#include "Fred.hpp"
#include "Crianca.hpp"
#include "Mesa.hpp"
#include <vector>

class FaseRestaurante : public Fase {
public:
    FaseRestaurante() : Fase("Restaurante", Sprite("rsc/restaurante.img")) {}
    
    void init() override;
    unsigned run(SpriteBuffer &screen) override;

private:
    Fred* fred;
    std::vector<Crianca*> criancas;
    std::vector<Mesa*> mesas;
};

#endif