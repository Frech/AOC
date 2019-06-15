#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <omp.h>
#include<windows.h>

using namespace std;

double fatorial(double n) {  //Calcula fatorial
	double fat = 1;

	for (int i = 1; i <= n; ++i) {
		fat = fat * i;
	}
	return fat;
}

double chances_lotofacil() { //Calcula aquantidade numeros que se pode acertar na Lotofácil  (FORMULA DO CONJUNTO)

	double k = 0.0;
	k = (fatorial(25.0) / (fatorial(15.0) * fatorial(10.0)));
	return k;
}

double chances_quina() { //Calcula aquantidade numeros que se pode acertar na Quina  (FORMULA DO CONJUNTO)

	double k = 0.0;
	k = (fatorial(80.0) / (fatorial(5.0) * fatorial(75.0)));
	return k;
}

void calcular(int n) { //Calcula a probabilidade das (n) pessoas ganharem ao mesmo tempo
	double prob_loto = 1.0;
	double prob_quina = 1.0;

//#pragma omp parallel for
	for (int i = 0; i < n; i++)
	{
		prob_loto = prob_loto * (1.0 / chances_lotofacil());
		prob_quina = prob_quina * (1.0 / chances_quina());
	}
	printf("Loto: %ld pessoas:  %.49f \n", n, prob_loto, "\n"); // acertarem na Quina e na Lotofacil
	printf("Quina: %ld pessoas: %.49f \n", n, prob_quina, "\n");

}

int main() {

	double inicio = omp_get_wtime();  //Inicializa a contagem de tempo de execução do programa
	int x = 15001;

	printf("Calculo da Probabilidade de (n) pessoas ganharem juntas na Lotofácil e na Quina \n");
	printf("                          VERSÃO PARALELA                           \n ");          //Cabeçalho
	printf("________________________________________________________________________ \n \n ");

	printf("Formula de Combinacao: n! / p! * (n-p)! \n \n");   //Formula do conjunto
#pragma omp parallel for
	for (int i = 1; i < x; ++i) {    //Chama a função de calcular para um determinado número "n" de pessoas que se deseja calcular a probabilidade
		if (i % 2 == 0)
			calcular(i);
		else
			calcular(i);
	}


	double final = omp_get_wtime();  //Finaliza a contagem de tempo	
	double tempo = final - inicio;
	printf("\n\nTempo: %lf \n", tempo);
	system("pause");
}


