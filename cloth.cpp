#include "cloth.h"


cloth::cloth(int weight, int clothType, int washTemp, bool color) {
    this->weight = weight;
    this->clothType = clothType;
    this->washTemp = washTemp;
    this->color = color;
    this->stance = 0;
}
cloth::cloth() = default;
cloth::~cloth() = default;

int cloth::print()
{
    return this->weight;
}



