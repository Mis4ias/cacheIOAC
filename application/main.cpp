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
	dados.startCache();
	dados.startMemPrincipal();
	dados.show();
	return 0;
}
