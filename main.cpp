#include "func_registros.h"
//#include "func_ordenainteiros.h"

int main(int argc, char** argv) {
	int opcao, indice;
	
    RegTempo Lista[] = {
		{-10.50, 10, 20, 03, 2017, 15, 45, "Rua 4, Varzea Grande", "876ijdu"},
		{15.56, 2, 20, 03, 2015, 13, 7, "Av. J. Muller, Cuiaba", "123jhcx"},
		{5.00, 60, 7, 5, 2009, 12, 59, "Lote 567  Santo Antonio", "jad1234"},
		{30.00, 12, 26, 10, 2019, 8, 30, "Lote 213 Lucas do R. Verde", "87123h"},
		{24.00, 40, 15, 9, 2000, 10, 32, "Rua Argentina Rondonopolis", "3hdb12"}
	};

	do {
		opcao = menu_registros();
		switch (opcao) {
			case (1):
				cadastro(Lista);
				cin.get();
				break;
			case (2):
				listagem(Lista);
                cin.get();
				break;
			case(3):
                ordena_por_temp(Lista);
                listagem(Lista);
                cin.get();
				break;
			case(4):
                ordena_por_umid(Lista);
                listagem(Lista);
                cin.get();
				break;
			case(5):
				indice = busca_codigo(Lista);
                mostra_busca(Lista, indice);
                cin.get();
                break;
			default:
				opcao = 0;
				break;
		}
	} while (opcao !=0);
	
	return 0;
}