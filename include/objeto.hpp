#ifndef OBJETO_H
#define OBJETO_H
#include<iostream>

class Objeto
{
    private:
    int _id; 
    double _x, _y, _largura;

    public:
    Objeto();
    Objeto(int id, double x, double y, double largura);
    void AtualizaPosicao(double novo_x, double novo_y);


    int getId() const;
    double getInicioX() const;
    double getFimX() const;
    double getY() const;
    double getLargura() const;

    ~Objeto(){
        
    }

};







#endif
