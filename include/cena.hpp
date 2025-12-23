#ifndef CENA_H
#define CENA_H
#include "objeto.hpp"

const int MAX_SAIDA = 100;

struct ItensVisiveis
{
    int id_objeto;
    double x_inicial_visivel;
    double x_final_visivel;
};

class Cena
{
private:
    int _tempo;
    ItensVisiveis itens[100];
    int totalitens;
public:
    Cena();
    void AdicionarItem(int id, double inicio, double fim);
    void ConstruirCena(Objeto vetorObjetos[], int totalobjetos);
    void CenaFinal(int tempo);
    void LimparItens();
    ~Cena(){
        
    }
    ItensVisiveis* getItens() { return itens; }
    int getTotalItens() const { return totalitens; }
};






#endif