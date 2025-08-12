#include "FaseRestaurante.hpp"
#include <iostream>

void FaseRestaurante::init() {
    fred = new Fred(5, 10);
    objs.push_back(fred);

    criancas.push_back(new Crianca(10, 20));
    criancas.push_back(new Crianca(10, 40));
    criancas.push_back(new Crianca(15, 30));
    criancas.push_back(new Crianca(15, 50));
    for (auto crianca : criancas) objs.push_back(crianca);

    mesas.push_back(new Mesa(8, 25));
    mesas.push_back(new Mesa(8, 45));
    mesas.push_back(new Mesa(13, 35));
    for (auto mesa : mesas) objs.push_back(mesa);
}

unsigned FaseRestaurante::run(SpriteBuffer &screen) {
    std::string input;
    
    while (true) {
        // Processa input
        getline(std::cin, input);
        
        // Salva posição atual para colisões
        int posL = fred->getPosL(), posC = fred->getPosC();
        
        // Movimentação
        if (input == "w") fred->moveUp(1);
        else if (input == "s") fred->moveDown(1);
        else if (input == "a") fred->moveLeft(1);
        else if (input == "d") fred->moveRight(1);
        else if (input == "q") return Fase::END_GAME;

        // Verifica colisões com mesas
        for (auto mesa : mesas) {
            if (fred->colideCom(*mesa)) {
                fred->moveTo(posL, posC);
                break;
            }
        }

        // Verifica entrega de bolinhos
        for (auto crianca : criancas) {
            if (!crianca->estaSatisfeita() && fred->colideCom(*crianca) && fred->temBolinho()) {
                crianca->receberBolinho();
                fred->entregarBolinho();
            }
        }

        // Verifica vitória
        bool todasSatisfeitas = true;
        for (auto crianca : criancas) {
            if (!crianca->estaSatisfeita()) {
                todasSatisfeitas = false;
                break;
            }
        }
        if (todasSatisfeitas) return Fase::LEVEL_COMPLETE;

        // Renderização
        update();
        draw(screen);
        system("clear");
        show(screen);
    }
}