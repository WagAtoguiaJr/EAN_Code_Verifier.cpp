/******************************************************************************

    Universidade do Vale do Itajaí - Escola Politécnica
                Curso de Ciência da Computação
                  Algoritmos e Programação I

                Verificador de Código de Barras

Professor:
Michael Douglas Cabral Alves (michaeld@univali.br)

Equipe:
Gabriel Joaquim Schlindwein Odisi (gabriel.8525404@edu.univali.br)
Guilherme Keller de Souza (guilherme.8535469@edu.univali.br)
Wagner Atoguia Lima Junior (wagatoguia@edu.univali.br)

*******************************************************************************/

// Inclusão das bibliotecas necessárias
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <cmath>

// Definindo o namespace como std
using namespace std;

int main()
{
    // Definindo o idioma do teclado
    setlocale(LC_ALL,"Portuguese");

    // Declaração de variáveis
	long long int code;
	int soma, verificador;

	// Entrada de dados
	cout << "Digite o código de barras (sem espaços):"<< endl;
	cin >> code;

	system("cls"); // comando para limpar a tela do usuário

    // Verificação para evitar loop infinito
	if (code >= pow(10, 18)) {
		cout << "\a\a\aERRO: código inválido!"<< endl
			 << "O código digitado utrapassou o limite de dígitos!" << endl
			 << "O código de barras deve conter exatamente 13 dígitos. Reinicie o programa.";
		return 1;
	}

	// Verificação de quantidade de dígitos
	while ((code < 1000000000000) || (code >= 10000000000000)) {
		cout << "ERRO: código inválido!" << endl
		     << "O código de barras deve conter exatamente 13 dígitos, sem qualquer espaço entre eles."<< endl;

		// Reentrada de dados
		cout << endl << "Digite novamente o código de barras correto:"<< endl;
		cin >> code;

		system("cls");

		// Verificação para evitar loop infinito
		if (code >= pow(10, 18)) {
			cout << "\a\a\aERRO: código inválido!"<< endl
			 << "O código digitado utrapassou o limite de dígitos!" << endl
			 << "O código de barras deve conter exatamente 13 dígitos. Reinicie o programa.";
			return 2;
		}
	}

    // Distribuição dos dígitos do código digitado corretamente
	int d12 = code / 1000000000000;
	int d11 = (code / 100000000000) % 10;
	int d10 = (code / 10000000000) % 10;
	int d9 = (code / 1000000000) % 10;
	int d8 = (code / 100000000) % 10;
	int d7 = (code / 10000000) % 10;
	int d6 = (code / 1000000) % 10;
	int d5 = (code / 100000) % 10;
	int d4 = (code / 10000) % 10;
	int d3 = (code / 1000) % 10;
	int d2 = (code / 100) % 10;
	int d1 = code / 10 % 10;
	int d0 = code % 10;

    // Processamento dos dados
	soma = d12 + d11*3 + d10 + d9*3 + d8 + d7*3 + d6 + d5*3 + d4 + d3*3 + d2 + d1*3;
	verificador = (((soma / 10) + 1) * 10) - soma;

	// Substituição em caso de verificador múltiplo de 10
	if (verificador % 10 == 0){
	    verificador = 0;
	}

	// Verificação da consistência do dígito verificador
	if (verificador == d0){
	    cout << "Código de barras está correto!";
	}
	else{
	    cout << "Atenção! Código de barras com dígito verificador inconsitente.";
	}

	return 0;
}
