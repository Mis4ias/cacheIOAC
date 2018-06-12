#include "StrucMemory.h"
#include "cache.h"
#include <vector>
#include <iostream>
#include <string>
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
	*  ms A nova quantidade dse misses*/
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
		int cont=0;
		for(int i=1;i<=(qtdPalavras*memPrincipal);i++){			
			StrucMemory aux (cont, i-1, 0);
			principalMemoria.push_back(aux);
			if(i%4==0)
				cont++;
		}
	}
	void Cache::show(){
		cout<<"--- Cache ---"<<endl;
		cout<<"L--B--E--C"<<endl;
		for(int i=0;i<(qtdPalavras*qtdLinhas);i++){
			cout<<cache[i].first<<"--"<<cache[i].second<<endl;
		}
		cout<<"--- Principal ---"<<endl;
		cout<<"B--E--C"<<endl;
		for(int j=0;j<(qtdPalavras*memPrincipal);j++){
			cout<<principalMemoria[j]<<endl;
		}
	}

	void Cache::mainCache(){
		bool stop=true;
		bool achou=false;
		string entrada;
		string comando;
		int ende=0;
		int pos;
		while(stop){
			cout<<"Digite o Comando::";
			getline(cin,entrada);
			pos = entrada.find(" ");
			comando = entrada.substr(0,pos);
			ende=stoi(entrada.substr(pos,(entrada.size()-pos)));
			if(comando.compare("Read")==0){
				for(int i=0;i<cache.size();i++){
					if(cache[i].second.get_endereco()==ende){
						cout<<"HIT Linha"<<cache[i].first<<endl;
						hit+=1;
						achou=true;
					}
				}
				if(achou==false){
					//erros aqui 
					for(int j=0;j<principalMemoria.size();j++){
						if(principalMemoria[j].get_blocos()==(ende/qtdPalavras)){
							for(int m=0;m<cache.size();m++){
								if(cache[m].first==(ende%qtdLinhas)){
									for(int n=0;n<qtdPalavras;n++){
										cache[m+n].second=principalMemoria[j+n];
									}
								}
							}
						}
					}
					cout<<"MISS -> Alocado na linha"<<ende%qtdLinhas<<"Bloco"<<ende/qtdPalavras<<"substituido"<<endl;
				}
			}
		
					
			
			stop=false;
		}
	
	}