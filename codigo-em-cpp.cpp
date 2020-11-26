#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
	// declarações
	string entradaDadaPeloUsuario;
	bool numero_esta_com_ponto;
	float numeroFloatDigitado;
	regex regexParaNumeroComPonto("((\\+|-)?[[:digit:]]+\\.)((([[:digit:]]+)?))?");
	// loop para pedir o numero
	do{
		printf("Digite numero com ponto (obrigatorio) \n");
		// pegando a frase digitada
		cin>>entradaDadaPeloUsuario;
		// verificações
		numero_esta_com_ponto = regex_match(
				entradaDadaPeloUsuario,
				regexParaNumeroComPonto
				);
		// inssitencia
	} while (! numero_esta_com_ponto);
	// conversões
	numeroFloatDigitado = stof(entradaDadaPeloUsuario);
	printf(
			"resultado em float %f",
			numeroFloatDigitado
	      );
}
