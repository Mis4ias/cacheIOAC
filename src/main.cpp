/**
 * @file	main.cpp
 * @brief	Implementacao da funcao principal do programa
 */
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include "arquivo.h"
#include "cache.h"

/**@brief Funcao principal */
int main (){
	srand(time(NULL));
	ifstream arquivo;
	Cache dados;
	abrirArquivo(&arquivo);

	loadData(&dados, &arquivo);

	arquivo.close();
	cout << "===========================================" << endl;
	cout << "Palavras por bloco: 	  -> " << dados.getPalavras() << endl;
	cout << "Linhas da cache: 	  -> " << dados.getLinhas() << endl;
	cout << "Blocos da principal: 	  -> " << dados.getPrincipal() << endl;
	cout << "Mapeamento: 		  -> " << dados.getMapeamento() << endl;
	cout << "Vias: 			  -> " << dados.getVias() << endl;
	cout << "Politica de Substituicao: -> " << dados.getPoliticaSubistituicao() << endl;

	dados.criar();
	dados.mainCache();
	
	cout << "===========================================" << endl;

	cout << "Hit:	-> " << dados.getHit() << endl;
	cout << "Miss: 	-> " << dados.getMiss() << endl;
	cout << "Total:  -> " << dados.getHit()+dados.getMiss() << endl;
	if(dados.getHit()+dados.getMiss()>0) {
		float porcentagem = (1.0*dados.getHit()/(1.0*dados.getHit()+1.0*dados.getMiss()));
		cout << "Porcentagem de acertos: " << porcentagem*100 << "%" << endl;
	}

	cout << "Encerrando simulador... Thank you for using" << endl;
	return 0;
}