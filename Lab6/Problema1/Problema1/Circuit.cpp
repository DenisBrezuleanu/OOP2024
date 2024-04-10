#include "Circuit.h"
#include <stdlib.h>
#include <stdio.h>

Circuit::Circuit() {
	this->crt = 0;
	this->maxindex = 100;
	this->masini = (Car**)malloc(this->maxindex * sizeof(Car*));
	this->timpi = (float*)malloc(this->maxindex * sizeof(float));

}
void Circuit::SetLength(float cat) {
	this->lcircuit = cat;
}
void Circuit::SetWeather(Weather cum) {
	this->wcircuit = cum;
}
void Circuit::AddCar(Car* nou) {
	if (this->crt + 1 < this->maxindex)
		this->masini[this->crt++] = nou;
}
void Circuit::Race() {
	for (int i = 0; i < this->crt; i++)
	{
		if (this->masini[i]->GetCoverd() < this->lcircuit)//nu ajunge la final
			this->timpi[i] = -1;
		else {
			this->timpi[i] = this->lcircuit / this->masini[i]->GetSpeed(this->wcircuit);
		}
	}
}
void Circuit::ShowFinalRanks()// it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
{
	printf("-----------------------------------------------------\n");
	printf("Masinile care au terminat cursa: \n");
	float aux;
	Car* aux2;
	for (int i = 0; i < this->crt - 1; i++)
		for (int j = i + 1; j < this->crt; j++)
			if (this->timpi[i] > this->timpi[j])
			{
				aux = this->timpi[i];
				this->timpi[i] = this->timpi[j];
				this->timpi[j] = aux;

				aux2 = this->masini[i];
				this->masini[i] = this->masini[j];
				this->masini[j] = aux2;
			}
	int ordine = 1;
	for (int i = 0; i < this->crt; i++)
		if (this->timpi[i] > 0)
			printf("%d. Masina %s a terminat cursa in %.3f minute\n", ordine++, this->masini[i]->tip, this->timpi[i] * 60);
	printf("-----------------------------------------------------\n");
}
void Circuit::ShowWhoDidNotFinis() // it is possible that some cars don't have enough fuel to finish the circuit
{
	printf("-----------------------------------------------------\n");
	printf("Masinile care NU au terminat cursa: \n");
	for (int i = 0; i < this->crt; i++)
		if (this->timpi[i] == -1)
			printf("Masina %s NU a terminat cursa.\n", this->masini[i]->tip);
		else break;
	printf("-----------------------------------------------------\n");
}