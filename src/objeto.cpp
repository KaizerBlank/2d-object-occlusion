#include"../include/objeto.hpp"

// Construtor padrão para Objeto.
Objeto::Objeto(){ 
    this->_id = -1;
    this->_x = 0.0;
    this->_y = 0.0;
    this->_largura = 0.0;
}

// Construtor parametrizado para Objeto.
Objeto::Objeto(int id, double x, double y, double largura){
    this->_id = id;
    this->_x = x;
    this->_y = y;
    this->_largura = largura;
}

// Atualiza a posição (coordenadas X e Y) do objeto.
void Objeto::AtualizaPosicao(double novo_x, double novo_y){
    this->_x = novo_x;
    this->_y = novo_y;
}

int Objeto::getId() const {
    return this->_id;
}

double Objeto::getInicioX() const {
    return this->_x - (this->_largura/2);
}

double Objeto::getFimX() const {
    return this->_x + (this->_largura/2);
}

double Objeto::getY() const {
    return this->_y;
}

double Objeto::getLargura() const {
    return this->_largura;
}