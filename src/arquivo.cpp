/**
 * @file	arquivo.cpp
 * 	Implementacao de funcoes que envolvem arquivos e cache
 */

#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <cstdlib>
using std::exit;

#include "arquivo.h"
#include "cache.h"

/** Funcao que abre o arquivo e verifica se eh valido */
void abrirArquivo(ifstream *arquivo){
	string arq;
	cout << "Digite o endereco do arquivo: ";
	cin >> arq;
	

	arquivo->open(arq);
	if(!(*arquivo)){
		cerr << "Impossivel abrir o arquivo!" << endl;
		exit(1);
	}
	else{
		cout << "Arquivo aberto!" << endl;
	}

}

/** Funcao que carrega os dados na Cache */
void loadData(Cache* dados, ifstream* arquivo){
	string aux;

	getline(*arquivo, aux);
	dados->setPalavras(atoi(aux.c_str()));

	getline(*arquivo, aux);
	dados->setLinhas(atoi(aux.c_str()));

	getline(*arquivo, aux);
	dados->setPrincipal(atoi(aux.c_str()));

	getline(*arquivo, aux);
	dados->setMapeamento(atoi(aux.c_str()));

	getline(*arquivo, aux);
	dados->setVias(atoi(aux.c_str()));

	getline(*arquivo, aux);
	dados->setSubstituicao(atoi(aux.c_str()));
}