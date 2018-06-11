#ifndef __CACHE_H__
#define __CACHE_H__

#include "StrucMemory.h"
#include <vector>
#include <iostream>
using namespace std;
class Cache{
	private:
		vector<pair<int,StrucMemory>> cache;
		vector<StrucMemory> principalMemoria;
		int qtdPalavras; /**< A quantidade de palavras por bloco*/
		int qtdLinhas; /**< A quantidade de linhas da cache*/
		int memPrincipal; /**< A quantidade de blocos da memoria principal*/
		int mapeamento; /**< O tipo de mapeamento*/
		int vias; /**< A quantidade de vias (quando houver)*/
		int polSubstituicao; /**< A politica de substituicao*/
		int miss;
		int hit;
	public:
		Cache();
		/**@return Retorna a quantidade de palavras por bloco*/
		int getPalavras();

		/**@return Retorna a quantidade de linhas da cache */
		int getLinhas();

		/**@return Retorna a quantidade de blocos da memoria principal */
		int getPrincipal();

		/**@return Retorna o tipo de mapeamento */
		int getMapeamento();

		/**@return Retorna a quantidade de vias (N-way) */
		int getVias();

		/**@return Retorna a politica de substituicao */
		int getPoliticaSubistituicao();

		/**@return Retorna a quantidade de hits*/
		int getHit();

		/**@return Retorna a quantidade de misses */
		int getMiss();

		/**@brief Atualiza a quantidade de palavras
		* @param p A nova quantidade de palavras */
		void setPalavras(int p);

		/**@brief Atualiza a quantidade de linhas
		* @param l A nova quantidade de linhas*/
		void setLinhas(int l);

		/**@brief Atualiza a quantidade de blocos da memoria principal
		* @param m A nova quantidade de blocos da memoria principal*/
		void setPrincipal(int m);

		/**@brief Atualiza a nova forma de mapeamento
		* @param mp A nova nova forma de mapeamento*/
		void setMapeamento(int mp);

		/**@brief Atualiza a quantidade de vias (N-way)
		* @param v A nova quantidade de vias (N-way)*/
		void setVias(int v);

		/**@brief Atualiza a politica de substituicao 
		* @param s A nova politica de substituicao */
		void setPoliticaSubistituicao(int s);

		/**@brief Atualiza a quantidade de hits
		* @param h A nova quantidade de hits*/
		void setHit(int h);

		/**@brief Atualiza a quantidade de misses
		* @param ms A nova quantidade de misses*/
		void setMiss(int ms);
		
		void startCache();
};
#endif //__CACHE_H__
