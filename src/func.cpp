//
// Created by Артём Гавриков on 28.12.2022.
//
#include "../inc/Blocks.hpp"
#include "../inc/Platforma.hpp"
#include "../inc/func.hpp"

void Lowit(std::vector<Blocks>* blocks, Platforma* plat){
    if (plat ->Getstack() == 15){
        plat->Low();
        for( int i = 0; i < blocks->size();i++) {
            blocks->at(i).Low();
        }
    }
}