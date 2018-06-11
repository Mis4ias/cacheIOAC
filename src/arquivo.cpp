/**
 * @file	arquivo.cpp
 * 	Implementacao de funcoes que envolvem arquivos e cache
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "arquivo.h"
#include "cache.h"
using namespace std;

/** Funcao que abre o arquivo e verifica se eh valido */
void abrirArquivo(ifstream *arquivo){
	string arq;
	cout << "*** Bem Vindo ao Simulador de Cache ***"<<endl;
	//cout << "Digite o endereco do arquivo: ";
	//cin >> arq;
	arq = "../data/dados.txt";

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
	dados->setPoliticaSubistituicao(atoi(aux.c_str()));
}