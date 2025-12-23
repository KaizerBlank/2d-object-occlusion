#include "../include/cena.hpp"
#include "../include/ordenacao.hpp"
#include <iomanip>

// Otimiza uma lista de intervalos (ItensVisiveis) juntando todos que se sobrepõem.
void mesclarItensVisiveis(ItensVisiveis itens[], int& total_itens) { 
    if (total_itens <= 1) return;
    // A ordenação por X é um pré-requisito para a mesclagem.
    mergeSortPorX(itens, total_itens);
    int write_idx = 0; // Aponta para o final da lista mesclada.
    for (int read_idx = 1; read_idx < total_itens; read_idx++) {
        // Se houver sobreposição, estende o item mesclado.
        if (itens[read_idx].x_inicial_visivel <= itens[write_idx].x_final_visivel) {
            itens[write_idx].x_final_visivel = max(itens[write_idx].x_final_visivel, itens[read_idx].x_final_visivel);
        } else {
            // Se não houver, avança para o próximo item.
            write_idx++;
            itens[write_idx] = itens[read_idx];
        }
    }
    // Atualiza o tamanho total do array.
    total_itens = write_idx + 1;
}

// Construtor padrão de Cena.
Cena::Cena(){
    this->_tempo = -1;
    this->totalitens = 0;
}

// Adiciona um item visível à lista final da cena.
void Cena::AdicionarItem(int id, double inicio, double fim){
    // Verifica se o total de itens não excedeu o limite pré-definido.
    if (totalitens < MAX_SAIDA) { 
        this->itens[totalitens].id_objeto = id;
        this->itens[totalitens].x_inicial_visivel = inicio;
        this->itens[totalitens].x_final_visivel = fim;
        totalitens++;
    } else {
        std::cerr << "AVISO: Capacidade máxima de itens visíveis na cena atingida." << std::endl;
    }
}

// Constrói a cena final calculando os segmentos visíveis de cada objeto.
// Pré-condição: o vetorObjetos deve estar ordenado por Y.
void Cena::ConstruirCena(Objeto vetorObjetos[], int totalobjetos) {

    for (int i = 0; i < totalobjetos; i++) {
        const Objeto& objetoAtual = vetorObjetos[i];
        // Para cada objeto, cria uma "sombra" unificada de tudo que está na sua frente.
        ItensVisiveis bloqueadores[MAX_SAIDA]; 
        int numbloquadores = 0;
        // Coleta os segmentos completos de todos os objetos anteriores (j < i).
        for (int j = 0; j < i; j++) {
            if (numbloquadores < MAX_SAIDA) {
                bloqueadores[numbloquadores].id_objeto = -1;
                bloqueadores[numbloquadores].x_inicial_visivel = vetorObjetos[j].getInicioX();
                bloqueadores[numbloquadores].x_final_visivel = vetorObjetos[j].getFimX();
                numbloquadores++;
            }
        }
        // Junta todos os bloqueadores sobrepostos para formar uma "parede" sólida.
        if (numbloquadores > 0) {
            mesclarItensVisiveis(bloqueadores, numbloquadores);
        }

        double inicio_x_obj = objetoAtual.getInicioX();
        double fim_x_obj = objetoAtual.getFimX();

        // Pula objetos com largura zero ou negativa.
        if (inicio_x_obj >= fim_x_obj) continue;

        // O cursor começa no início do objeto atual e avança pelo eixo X.
        double cursor_x = inicio_x_obj;

        // Itera pela "parede" de bloqueadores para encontrar as frestas.
        for (int j = 0; j < numbloquadores; j++) {
            // Se o cursor já passou do fim do objeto atual, não há mais nada a fazer.
            if (cursor_x >= fim_x_obj) break;

            const ItensVisiveis& bloqueador = bloqueadores[j];

            // Se o cursor está antes de um bloqueador, encontramos uma fresta visível.
            if (cursor_x < bloqueador.x_inicial_visivel){
                double fim_do_trecho = min(fim_x_obj, bloqueador.x_inicial_visivel);
                this->AdicionarItem(objetoAtual.getId(), cursor_x, fim_do_trecho);
            }
            // Avança o cursor para o final do bloqueador, ignorando a área coberta.
            cursor_x = max(cursor_x, bloqueador.x_final_visivel);
        }

        // Se, após verificar todos os bloqueadores, o cursor ainda não chegou ao fim do objeto, o trecho final está visível.
        if(cursor_x < fim_x_obj) {
            this->AdicionarItem(objetoAtual.getId(), cursor_x, fim_x_obj);
        }
    }
}

// Imprime a cena final no formato de saída esperado.
void Cena::CenaFinal(int tempo){
    mergeSort(itens, totalitens); // Ordena por ID para corresponder à saída.

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < totalitens; i++){
        std::cout << "S" << " " << tempo << " " << itens[i].id_objeto << " " << itens[i].x_inicial_visivel << " " << itens[i].x_final_visivel << std::endl;
    }
    
}