#ifndef __CACHE_H__
#define __CACHE_H__


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
		/**@return Retorna a quantidade de palavras por bloco*/
		int Cache::getPalavras();

		/**@return Retorna a quantidade de linhas da cache */
		int Cache::getLinhas();

		/**@return Retorna a quantidade de blocos da memoria principal */
		int Cache::getPrincipal();

		/**@return Retorna o tipo de mapeamento */
		int Cache::getMapeamento();

		/**@return Retorna a quantidade de vias (N-way) */
		int Cache::getVias();

		/**@return Retorna a politica de substituicao */
		int Cache::getPoliticaSubistituicao();

		/**@return Retorna a quantidade de hits*/
		int Cache::getHit();

		/**@return Retorna a quantidade de misses */
		int Cache::getMiss();

		/**@brief Atualiza a quantidade de palavras
		* @param p A nova quantidade de palavras */
		void Cache::setPalavras(int p);

		/**@brief Atualiza a quantidade de linhas
		* @param l A nova quantidade de linhas*/
		void Cache::setLinhas(int l);

		/**@brief Atualiza a quantidade de blocos da memoria principal
		* @param m A nova quantidade de blocos da memoria principal*/
		void Cache::setPrincipal(int m);

		/**@brief Atualiza a nova forma de mapeamento
		* @param mp A nova nova forma de mapeamento*/
		void Cache::setMapeamento(int mp);

		/**@brief Atualiza a quantidade de vias (N-way)
		* @param v A nova quantidade de vias (N-way)*/
		void Cache::setVias(int v);

		/**@brief Atualiza a politica de substituicao 
		* @param s A nova politica de substituicao */
		void Cache::setPoliticaSubistituicao(int s);

		/**@brief Atualiza a quantidade de hits
		* @param h A nova quantidade de hits*/
		void Cache::setHit(int h);

		/**@brief Atualiza a quantidade de misses
		* @param ms A nova quantidade de misses*/
		void Cache::setMiss(int ms);
};
#endif //__CACHE_H__