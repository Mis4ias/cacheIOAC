#include "StrucMemory.h"
#include "cache.h"
#include <vector>
#include <iostream>

using namespace std;
	Cache::Cache(){
		hit=0;
		miss=0;
	}
	/** Retorna a quantidade de palavras por bloco*/
	int Cache::getPalavras()			{ return qtdPalavras;		}
	/** Retorna a quantidade de linhas da cache */
	int Cache::getLinhas()				{ return qtdLinhas;			}
	/** Retorna a quantidade de blocos da memoria principal */
	int Cache::getPrincipal()			{ return memPrincipal;		}
	/** Retorna o tipo de mapeamento */
	int Cache::getMapeamento()			{ return mapeamento;		}
	/** Retorna a quantidade de vias (N-way) */
	int Cache::getVias()				{ return vias;				}
	/** Retorna a politica de substituicao */
	int Cache::getPoliticaSubistituicao()		{ return polSubstituicao;	}
	/** Retorna a quantidade de hits*/
	int Cache::getHit()					{ return hit;				}
	/** Retorna a quantidade de misses */
	int Cache::getMiss()				{ return miss;				}
	/** Atualiza a quantidade de palavras
	*  p A nova quantidade de palavras */
	void Cache::setPalavras(int p)		{ qtdPalavras = p; 		}
	/** Atualiza a quantidade de linhas
	*  l A nova quantidade de linhas*/
	void Cache::setLinhas(int l)		{ qtdLinhas = l; 		}
	/** Atualiza a quantidade de blocos da memoria principal
	*  m A nova quantidade de blocos da memoria principal*/
	void Cache::setPrincipal(int m)		{ memPrincipal = m; 	}
	/** Atualiza a nova forma de mapeamento
	*  mp A nova nova forma de mapeamento*/
	void Cache::setMapeamento(int mp)	{ mapeamento = mp; 		}
	/** Atualiza a quantidade de vias (N-way)
	*  v A nova quantidade de vias (N-way)*/
	void Cache::setVias(int v)			{ vias = v; 			}
	/** Atualiza a politica de substituicao 
	*  s A nova politica de substituicao */
	void Cache::setPoliticaSubistituicao(int s)	{ polSubstituicao = s; 	}
	/** Atualiza a quantidade de hits
	*  h A nova quantidade de hits*/
	void Cache::setHit(int h)			{ hit = h;				}
	/** Atualiza a quantidade de misses
	*  ms A nova quantidade de misses*/
	void Cache::setMiss(int ms)			{ miss = ms;			}
	
	void Cache::startCache(){
		StrucMemory aux (0, 0, 0);
		for(int i=0;i<qtdLinhas;i++){	
			for(int j=0;j<qtdPalavras;j++){	
				
				cache.push_back(make_pair(i, aux));

			}		
		}
		
	}
	void Cache::startMemPrincipal(){
		StrucMemory aux (0, 0, 0);
		for(int i=0;i<(qtdPalavras*memPrincipal);i++)		
			principalMemoria.push_back(aux);
				
	}
	void Cache::show(){
		cout<<"--- Cache ---"<<endl;
		for(int i=0;i<(qtdPalavras*qtdLinhas);i++){
			cout<<cache[i].first<<"--"<<cache[i].second<<endl;
		}
		cout<<"--- Principal ---"<<endl;

		for(int j=0;j<(qtdPalavras*memPrincipal);j++){
			cout<<principalMemoria[j]<<endl;
		}
	}