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
	int param=-1;
	srand(time(NULL));
	ifstream arquivo;
	Cache dados;
	abrirArquivo(&arquivo);

	loadData(&dados, &arquivo);
	dados.startCache();
	dados.startMemPrincipal();
	param=dados.mainCache();
	if(param==1){
		dados.show();
	}
	if(param==-1){
		cout<<"COMANDO ERRADO !!!!!! Finalizando...."<<endl;
	}
	
	return 0;
}
