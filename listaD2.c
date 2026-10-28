/*Exercício — Patrulha Variável
Uma empresa de segurança utiliza robôs para patrulhar pontos organizados em uma lista 
circular duplamente encadeada. O robô pode andar no sentido horário (prox) ou anti-
horário (ant). A direção muda dinamicamente durante a patrulha.
Estrutura
typedef struct lista2 {
 char nome[30];
 struct lista2 *ant;
 struct lista2 *prox;
} TLista2;
typedef TLista2 *PLista2;*/