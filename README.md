# Otimização de Oclusão de Objetos (Occlusion Culling)

Este projeto implementa um sistema robusto de descarte de objetos oclusos (*Occlusion Culling*) em **C++**, desenvolvido para otimizar o pipeline de renderização de jogos 2D. O sistema utiliza uma abordagem de varredura unidimensional (Scanline) combinada com ordenação por prioridade de profundidade para determinar eficientemente quais segmentos de objetos devem ser desenhados.

## Sobre o Projeto

Em motores de jogos, processar e renderizar objetos que estão escondidos atrás de outros é um desperdício de recursos computacionais. Este sistema resolve esse problema implementando um algoritmo que:
1.  Recebe objetos com coordenadas 2D (X e Y) e profundidade.
2.  Ordena-os por prioridade (profundidade).
3.  Calcula a visibilidade no eixo X, descartando segmentos totalmente ou parcialmente obstruídos.

O projeto foi desenvolvido como parte da disciplina de Estrutura de Dados (UFMG), simulando uma demanda real de otimização para a empresa fictícia "Jolambs".

## Funcionalidades

* **Algoritmo de Construção de Cena:** Implementação otimizada de complexidade **$O(N^2 \log N)$**.
* **Gerenciamento Manual de Memória:** Implementado **sem o uso de contêineres da STL** (Standard Template Library), focando em alocação dinâmica segura e manipulação direta de memória.
* **Atualização Dinâmica:** Inserção e movimentação de objetos com custo linear **$O(N)$** (utilizando *Insertion Sort* para listas quase ordenadas).
* **Robustez:** Tratamento de *buffer overflow*, validação de entradas e programação defensiva.

## Método e Algoritmo

O núcleo da solução reside na classe `Cena` e no método `ConstruirCena`:

1.  **Priorização:** Os objetos são processados do mais próximo para o mais distante (baseado na coordenada Y).
2.  **Varredura (Scanline):** Para cada objeto, um "cursor" percorre o eixo X verificando lacunas entre os itens já visíveis ("bloqueadores").
3.  **Segmentação:** Se um objeto está parcialmente visível, ele é fatiado em segmentos (`ItemVisivel`) que preenchem as lacunas não ocupadas pelos objetos anteriores.

### Estruturas de Dados
* **Objeto:** Entidade com ID, posição (início/fim X) e profundidade (Y).
* **ItemVisivel:** Representa um segmento contínuo visível de um objeto.
* **Vetores Estáticos/Dinâmicos:** Arrays alocados manualmente para garantir performance e controle de memória.

## Análise de Complexidade

| Operação | Complexidade de Tempo | Descrição |
| :--- | :--- | :--- |
| **Construir Cena** | $O(N^2 \log N)$ | Dominado pela ordenação (*Merge Sort*) dentro do loop de inserção de segmentos. |
| **Novo Objeto ('O')** | $O(N)$ | Inserção em vetor quase ordenado. |
| **Mover Objeto ('M')** | $O(N)$ | Remoção e re-inserção mantendo a ordem. |
| **Espaço (Memória)** | $O(N)$ | Crescimento linear devido à memória auxiliar do *Merge Sort*. |

