/**
 * @file	arquivo.h
 * @brief	Definicao de funcoes que envolvem arquivos e cache
 * @author	Misael Damasceno 
 * @since	11/06/2018
 * @date 	11/06/2018
 */
#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
using std::ifstream;

#include "cache.h"

/**@brief Funcao que abre o arquivo e verifica se eh valido */
void abrirArquivo(ifstream *arquivo);

/**@brief Funcao que carrega os dados na Cache */
void loadData(Cache* dados, ifstream *arquivo);

#endif
