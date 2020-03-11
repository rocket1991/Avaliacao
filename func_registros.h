#include <iostream>
#include <math.h>
#include <string.h>
#include<stdlib.h>
using namespace std;


#define TAM 5

typedef struct {
	float temp;
	float umid;
	int dia;
	int mes;
	int ano;
	int hora;
	int min;
	char local[60];
	char cod[20];
} RegTempo;

int menu_registros() {
	int opcao;

	
    cout << "=========================================\n";
	cout << "\t\tMENU DOS REGISTROS\n";
	cout << "=========================================\n";
	cout << "\t1- CADASTRO\n\t2- EXIBIR REGISTROS\n\t3- CLASSIFICACAO DE TEMPERATURAS\n\t4- CLASSIFICACAO DA UMIDADE\n\t5- BUSCAR COLETA POR CODIGO\n\t0- SAIR\n";
	cout << "=========================================\n";
	
	cin >> opcao;
	
	return opcao;
}

void cadastro(RegTempo Lista[TAM]) {
	float aux;
	
	cout << "Entre com: Temperatura (grau celsius), Umidade, Data da coleta (Dia, Mes, Ano, Hora, Minuto), Localidade, Codigo da coleta." << endl;
	
	for (int i = 0; i < TAM; i++) {
		cout << "Reg. de Coleta " << i+1 << ":" << endl;
		cin >> Lista[i].temp >> Lista[i].umid >> Lista[i].dia >> Lista[i].mes >> Lista[i].ano >> Lista[i].hora >> Lista[i].min;
		//cin.get();
		setbuf(stdin, NULL);
		cout << "Digite o Local: " << endl;
		cin.getline(Lista[i].local, 40, '\n');
		cout << "Digite o codigo: " << endl; 
		cin.getline(Lista[i].cod, 20, '\n');
		//cin.getline(Lista[i].local, 40, '\n');
		//cin.getline(Lista[i].cod, 20, '\n');
	}
}

void listagem(RegTempo Lista[TAM]) {
    system("clear");
	cout << "====================================================================================================================================" << endl;
	cout << "\t||Temperatura||\t||Umidade(\%)\t||  Dia  ||\t   Mes  ||\t||Ano||\t\t||Hora||\t||Minuto||\t||Localidade||\t||Codigo de coleta||" << endl;
	cout << "====================================================================================================================================" << endl;
	
	for (int i = 0; i < TAM; i++) {
		cout << "\t\t" << Lista[i].temp << "\t\t\t" << Lista[i].umid << "\t\t\t     " << Lista[i].dia << "\t\t"; 
		cout << "\t" << Lista[i].mes << "\t\t     " << Lista[i].ano << "\t\t" << Lista[i].hora << "\t\t\t" << Lista[i].min << "\t\t"; 
		cout << Lista[i].local << "\t\t" << Lista[i].cod << "" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;

	}
}

void inverte_ordem(RegTempo Lista[TAM]) {
	int i, j, tam;
    tam = 4;
    j = tam;
	RegTempo Aux;
	for (i = 0; i < tam / 2; i++) {
		Aux = Lista[i];
		Lista[i] = Lista[j];
		Lista[j] = Aux;
		j--;
	}
}

void ordena_por_temp(RegTempo Lista[TAM]) {
	
	// Declaração de variaveis
	int i, j;
    RegTempo atual;
	//Implementação do algoritmo
	for (i = 1; i < TAM; i++) {
		atual = Lista[i];
		for (j = i; (j > 0) && (atual.temp < Lista[j - 1].temp); j--)
			Lista[j] = Lista[j - 1];
		Lista[j] = atual;
	}
	//inverte_ordem(Lista);
}

void ordena_por_umid(RegTempo Lista[TAM]) {
	
	// Declaração de variaveis
	int i, j;
    RegTempo atual;
	//Implementação do algoritmo
	for (i = 1; i < TAM; i++) {
		atual = Lista[i];
		for (j = i; (j > 0) && (atual.umid < Lista[j - 1].umid); j--)
			Lista[j] = Lista[j - 1];
		Lista[j] = atual;
	}
}

void ordena_por_cod(RegTempo Lista[TAM]) {
	int i, j;
	RegTempo atual;
	
	for (i = 1; i < TAM; i++) {
		atual = Lista[i];
		for (j = i; (j > 0) && (strcmp(atual.cod, Lista[j - 1].cod) < 0); j--)
			Lista[j] = Lista[j - 1];//strcpy(Lista[j], Lista[j - 1]);
		//strcpy(Lista[j].nome, atual);
		Lista[j] = atual;
	}
}

int busca_codigo(RegTempo Lista[TAM]) {
	char cod[20];
	int inicio, meio, fim, i = 0;
	
    ordena_por_cod(Lista);

    inicio = 0;
	fim = TAM -1;
    
    cout << "Digite o codigo procurado: ";
	cin >> cod;
	
	while (inicio <= fim) {
		meio = (inicio + fim) / 2;
		if (strcmp(cod, Lista[meio].cod) == 0) {
			return meio;
            
		} else if (strcmp(cod, Lista[meio].cod) > 0) {
			inicio = meio +1;
		} else {
            fim = meio - 1;
        }
	}
    return -1;
}

void mostra_busca(RegTempo Lista[TAM], int i) {

    if (i == -1) {
        cout << "O registro nao foi encontrado! Tente novmente" << endl;
        return;
    }
    	
    system("clear");
	cout << "====================================================================================================================================" << endl;
	cout << "\t||Temperatura||\t||Umidade(\%)\t||  Dia  ||\t   Mes  ||\t||Ano||\t\t||Hora||\t||Minuto||\t||Localidade||\t||Codigo de coleta||" << endl;
	cout << "====================================================================================================================================" << endl;

	cout << "\t\t" << Lista[i].temp << "\t\t\t" << Lista[i].umid << "\t\t\t     " << Lista[i].dia << "\t\t"; 
	cout << "\t" << Lista[i].mes << "\t\t     " << Lista[i].ano << "\t\t" << Lista[i].hora << "\t\t\t" << Lista[i].min << "\t\t"; 
	cout << Lista[i].local << "\t\t" << Lista[i].cod << "" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}