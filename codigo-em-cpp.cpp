#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{

	// declarações
	string entradaDadaPeloUsuario;
	bool numero_esta_com_ponto;
	double numeroFloatDigitado;

	regex regexParaNumeroComPonto("(\\+|-)?([[:digit:]]+)?(\\.|,)[[:digit:]][[:digit:]]");

	// loop para pedir o numero
	do{

		printf("\nDigite um numero flutuante com uma virgula ou ponto e dois digitos no final\n");

		// pegando a frase digitada
		cin>>entradaDadaPeloUsuario;

		// verificação
		numero_esta_com_ponto = regex_match(
				entradaDadaPeloUsuario,
				regexParaNumeroComPonto
				);

		// inssitencia
	} while (! numero_esta_com_ponto);


	// se por um acaso o usuario digitou virgula então vou trocar por ponto
	replace(
			// começo da string
			entradaDadaPeloUsuario.begin(),
			// final da string
			entradaDadaPeloUsuario.end(),
			// trocar esse
			',',
			// por esse
			'.'
	       );

	//
	numeroFloatDigitado = stod(entradaDadaPeloUsuario);

	printf(
			"\nresultado do numero flutuante: %f\n",
			numeroFloatDigitado
	      );

	return 0;
}
