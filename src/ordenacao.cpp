#include "../include/ordenacao.hpp"

// Ordena um vetor de Objetos pela coordenada Y (profundidade) usando Insertion Sort.
void insertionSort(Objeto vetor[], int tamanho){ 
    assert(vetor != nullptr && "Vetor não pode ser nulo.");
    assert(tamanho >= 0 && "Tamanho não pode ser negativo.");
    int i,j;
    Objeto aux;
    for (i = 1; i < tamanho; i++){
        aux = vetor[i];
        j = i - 1;
        while ((j>= 0) && aux.getY() < vetor[j].getY()) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}

// Função principal do Merge Sort para ordenar ItensVisiveis por ID.
void mergeSort(ItensVisiveis vetor[], int tamanho){ 
    assert(vetor != nullptr && "Vetor não pode ser nulo.");
    assert(tamanho >= 0 && "Tamanho não pode ser negativo.");
    if (tamanho > 1) {
        mergeSortRecursivo(vetor, 0, tamanho - 1);
    }
}

// Função recursiva do Merge Sort.
void mergeSortRecursivo(ItensVisiveis vetor[], int inicio, int fim){
    if (inicio >= fim) {
        return;
    }
    int meio = inicio + (fim - inicio) / 2;
    mergeSortRecursivo(vetor, inicio, meio);
    mergeSortRecursivo(vetor, meio + 1, fim);
    merge(vetor, inicio, meio, fim);
}

// Junta dois sub-vetores ordenados por ID.
void merge(ItensVisiveis vetor[], int inicio, int meio, int fim){
    int nl = meio - inicio + 1;
    int nr = fim - meio;
    ItensVisiveis* esquerda = nullptr;
    ItensVisiveis* direita = nullptr;
    // Bloco try-catch para garantir que a memória foi alocada corretamente.
    try { 
        esquerda = new ItensVisiveis[nl];
        direita = new ItensVisiveis[nr];
    } catch (const std::bad_alloc& e) {
        std::cerr << "ERRO: Falha ao alocar memória no mergeSort. " << e.what() << std::endl;
        delete[] esquerda;
        delete[] direita;
        return;
    }

    for (int i = 0; i < nl; i++){
        esquerda[i] = vetor[inicio + i];
    }
    for (int j = 0; j < nr; j++){
        direita[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while(i < nl && j < nr){
        if (esquerda[i].id_objeto <= direita[j].id_objeto){
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while(i < nl){
        vetor[k] = esquerda[i];
        i++;
        k++;
    }
    while(j < nr){
        vetor[k] = direita[j];
        j++;
        k++;
    }

    delete[] esquerda;
    delete[] direita;
}

// Função principal do Merge Sort para ordenar ItensVisiveis pela coordenada X.
void mergeSortPorX(ItensVisiveis vetor[], int tamanho) {
    assert(vetor != nullptr && "Vetor não pode ser nulo.");
    assert(tamanho >= 0 && "Tamanho não pode ser negativo.");
    if (tamanho > 1) {
        mergeSortRecursivoPorX(vetor, 0, tamanho - 1);
    }
}

// Função recursiva do Merge Sort por X.
void mergeSortRecursivoPorX(ItensVisiveis vetor[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    int meio = inicio + (fim - inicio) / 2;
    mergeSortRecursivoPorX(vetor, inicio, meio);
    mergeSortRecursivoPorX(vetor, meio + 1, fim);
    mergePorX(vetor, inicio, meio, fim);
}

// Junta dois sub-vetores ordenados por x_inicial_visivel.
void mergePorX(ItensVisiveis vetor[], int inicio, int meio, int fim) {
    int nl = meio - inicio + 1;
    int nr = fim - meio;
    ItensVisiveis* esquerda = nullptr;
    ItensVisiveis* direita = nullptr;
    try {
        esquerda = new ItensVisiveis[nl];
        direita = new ItensVisiveis[nr];
    } catch (const std::bad_alloc& e) {
        std::cerr << "ERRO: Falha ao alocar memória no mergeSort. " << e.what() << std::endl;
        delete[] esquerda;
        delete[] direita;
        return;
    }
    for (int i = 0; i < nl; i++) {
        esquerda[i] = vetor[inicio + i];
    }
    for (int j = 0; j < nr; j++) {
        direita[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < nl && j < nr) {
        if (esquerda[i].x_inicial_visivel <= direita[j].x_inicial_visivel) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < nr) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    delete[] esquerda;
    delete[] direita;
}