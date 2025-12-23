#include "../include/cena.hpp"
#include "../include/objeto.hpp"
#include "../include/ordenacao.hpp"
#include "../include/cena.hpp"
#include <fstream>
#include <string>
#include <limits>
#include <ios>

const int MAX_OBJETOS = 100;

int main(){

    Objeto vetorObjetos[MAX_OBJETOS];
    int totalObjetos = 0;

    char tipo_comando;

    while (std::cin >> tipo_comando){
        if (tipo_comando == 'O'){
            int id;
            double x, y, largura;
            std::cin >> id >> x >> y >> largura;
            // Confirma se a entrada é válida.
            if (!std::cin){ 
                std::cerr << "ERRO: Entrada inválida. Esperavam-se números." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            } else { 
                // Confirma que o limite de objetos não foi excedido.
                if (totalObjetos < MAX_OBJETOS){
                vetorObjetos[totalObjetos] = Objeto(id, x, y, largura);
                totalObjetos++;
                insertionSort(vetorObjetos, totalObjetos);
            } else {
                std::cerr << "ERRO: Capacidade máxima de objetos atingida." << std::endl;
            }
        }

        } else if (tipo_comando == 'M'){
            bool encontrado = false;
            int tempo, id;
            double x, y;
            std::cin >> tempo >> id >> x >> y;
            // Confirma se a entrada é válida.
            if (!std::cin){
                std::cerr << "ERRO: Entrada inválida para o comando 'M'." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            for(int i = 0; i < totalObjetos; i++){
                if(vetorObjetos[i].getId() == id) { 
                    vetorObjetos[i].AtualizaPosicao(x, y);
                    encontrado = true;
                    break;
                }
            }
            // Caso o ID não seja encontrado, imprime um aviso.
            if (!encontrado){
                std::cerr << "AVISO: Objeto com ID " << id << " não encontrado para movimentação." << std::endl;
            }
            insertionSort(vetorObjetos, totalObjetos);

        } else if (tipo_comando == 'C'){
            int tempo;
            std::cin >> tempo;
            // Confirma se a entrada é válida
            if (!std::cin){ 
                std::cerr << "ERRO: Entrada inválida para o comando 'C'." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            Cena cena;
            cena.ConstruirCena(vetorObjetos, totalObjetos);
            cena.CenaFinal(tempo);
        }
    }
    
    
    return 0;
}