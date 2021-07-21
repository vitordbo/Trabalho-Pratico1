#include <iostream>
#include <windows.h>
#include "binario.h"     // chamando os arquivos ".h" das fun��es bin�rias
#include "genetico.h"    // chamando os arquivos ".h" das fun�oes gen�ticas
using namespace std;

// exercico de revis�o lab 06  
// definindo as cores 
#define red "\033[31m"
#define green "\033[32m"
#define default "\033[m"


int main()
{
	SetConsoleCP(1252); // acentos
	SetConsoleOutputCP(1252); // acentos

	unsigned short valorum, valordois, valortres, valorquatro, valorcinco, valorseis;  

	cout << "Entre com 6 solu��es iniciais (n�meros entre 0 e 65535): " << endl;
	cin >> valorum; 
	cin >> valordois;
	cin	>> valortres;
	cin >> valorquatro;
	cin >> valorcinco;
	cin>> valorseis;    
	
	system("cls");  // limpar tela

	cout << "  Resultado da Avalia��o " << endl;
	cout << " ------------------------" << endl;
	                 
	/* 
	
	  Levando em consiera��o que o peso m�ximo suportado pela mochila � 20 Kg => devemos usar a fun��o avaliar
	  Usando fun��o avaliar => retorna true se o valor for menor ou igual ao m�ximo permitido dentro da mochila 
	  Retorna false se o valor for maior do que a mochila consegue comportar

	*/
	
	if (funcaoavaliar(valorum) == true)             
		cout << green << "OK" << endl << default;   // Se o valor retornardo for true => escreve "OK" com a cor verde
	else
		cout << red << "X" << endl << default;      // Se o valor retornado for false => escreve "X" com a cor vermelha
	                                                
	if (funcaoavaliar(valordois) == true)
		cout << green << "OK" << endl << default;   // definindo cores com o "green" e voltando para o normal com o "default"
	else
		cout << red << "X" << endl << default;      // definindo cores com o "red" e voltando para o normal como o "default" 


	if (funcaoavaliar(valortres) == true)           // testando para os restantes do valores iniciais (valortres)
		cout << green << "OK" << endl << default;
	else
		cout << red << "X" << endl << default;

	if (funcaoavaliar(valorquatro) == true)         // testando para os restantes do valores iniciais (valorquatro)
		cout << green << "OK" << endl << default;
	else
		cout << red << "X" << endl << default;

	if (funcaoavaliar(valorcinco) == true)         // testando para os restantes do valores iniciais (valorcinco)
		cout << green << "OK" << endl << default;
	else
		cout << red << "X" << endl << default;

	if (funcaoavaliar(valorseis) == true)          // testando para os restantes do valores iniciais (valorseis) 
		cout << green << "OK" << endl << default;
	else
		cout << red << "X" << endl << default;

	cout << " ------------------------" << endl;          // pulando para a poxima etapa => (usando varia��es das solu��es iniciais)

	

    // chamando outras fun��es dentro da fun��o avaliar => avaliar os novos resultados derivados das muta��es e cruzamentos 


	if (funcaoavaliar(cruzamentopontounico(valorum,valordois)) == true)     // Avaliando e usando a fun��o cruzamento de ponto �nico 
		cout << green << "OK" << endl << default;                           // gera uma nova solu��o a partir de duas solu��es existentes, 
	else                                                                    // copiando parte dos bits da primeira solu��o e o restante da
		cout << red << "X" << endl << default;                              // segunda solu��o.


	if (funcaoavaliar(cruzamentoaritmetico(valortres,valorquatro)) == true)   // Avaliando e usando a fun��o cruzamneto aritmetico 
		cout << green << "OK" << endl << default;                             // gera uma nova solu��o a partir de duas existentes,
	else                                                                      // usando o bit 1 nas posi��es em que ambas solu��es iniciais sejam 1 
		cout << red << "X" << endl << default;                               // e 0, caso contr�rio. Ou seja, aplica um "AND" entre as solu��es


	if (funcaoavaliar(mutacaosimples(valorcinco)) == true)               //Avaliando e usando a fun��o muta��o simples 
		cout << green << "OK" << endl << default;                        //muta��o simples modifica um bit de uma solu��o existente,
	else                                                                 //obtendo assim uma nova solu��o
		cout << red << "X" << endl << default;


	if (funcaoavaliar(mutacaodupla(valorseis)) == true)                  //Avaliando e usando a fun��o muta��o dupla 
		cout << green << "OK" << endl << default;                        //a muta��o dupla tem o mesmo comportamento da simples,
	else                                                                 //solu��o tem dois bits modificados, no lugar de apenas um.
		cout << red << "X" << endl << default;

	
	system("pause");
	return 0;

}
