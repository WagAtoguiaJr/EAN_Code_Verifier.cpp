/******************************************************************************

    Universidade do Vale do Itaja� - Escola Polit�cnica
                Curso de Ci�ncia da Computa��o
                  Algoritmos e Programa��o I

                Verificador de C�digo de Barras

Professor:
Michael Douglas Cabral Alves (michaeld@univali.br)

Equipe:
Gabriel Joaquim Schlindwein Odisi (gabriel.8525404@edu.univali.br)
Guilherme Keller de Souza (guilherme.8535469@edu.univali.br)
Wagner Atoguia Lima Junior (wagatoguia@edu.univali.br)

*******************************************************************************/

// Inclus�o das bibliotecas necess�rias
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

    // Declara��o de vari�veis
	long long int code;
	int soma, verificador;

	// Entrada de dados
	cout << "Digite o c�digo de barras (sem espa�os):"<< endl;
	cin >> code;

	system("cls"); // comando para limpar a tela do usu�rio

    // Verifica��o para evitar loop infinito
	if (code >= pow(10, 18)) {
		cout << "\a\a\aERRO: c�digo inv�lido!"<< endl
			 << "O c�digo digitado utrapassou o limite de d�gitos!" << endl
			 << "O c�digo de barras deve conter exatamente 13 d�gitos. Reinicie o programa.";
		return 1;
	}

	// Verifica��o de quantidade de d�gitos
	while ((code < 1000000000000) || (code >= 10000000000000)) {
		cout << "ERRO: c�digo inv�lido!" << endl
		     << "O c�digo de barras deve conter exatamente 13 d�gitos, sem qualquer espa�o entre eles."<< endl;

		// Reentrada de dados
		cout << endl << "Digite novamente o c�digo de barras correto:"<< endl;
		cin >> code;

		system("cls");

		// Verifica��o para evitar loop infinito
		if (code >= pow(10, 18)) {
			cout << "\a\a\aERRO: c�digo inv�lido!"<< endl
			 << "O c�digo digitado utrapassou o limite de d�gitos!" << endl
			 << "O c�digo de barras deve conter exatamente 13 d�gitos. Reinicie o programa.";
			return 2;
		}
	}

    // Distribui��o dos d�gitos do c�digo digitado corretamente
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

	// Substitui��o em caso de verificador m�ltiplo de 10
	if (verificador % 10 == 0){
	    verificador = 0;
	}

	// Verifica��o da consist�ncia do d�gito verificador
	if (verificador == d0){
	    cout << "C�digo de barras est� correto!";
	}
	else{
	    cout << "Aten��o! C�digo de barras com d�gito verificador inconsitente.";
	}

	return 0;
}
