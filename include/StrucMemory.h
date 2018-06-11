/** 
 * 
 * @file StrucMemory.h
 *
 **/


#ifndef __STRUCMEMORY_H__
#define __STRUCMEMORY_H__


#include <ostream>



/**
 * @class StrucMemory 
 * @brief criacao de objetos.
 * @param blocos numero ode blocos.
 * @param endereco numero do endereco.
 * @param conteudo conteudo endereco.
 **/


class StrucMemory {

	private: int blocos;
	private: int endereco;
	private: int conteudo;


	/** Construtor Padrao **/
	public: StrucMemory(int argblocos, int argendereco, int argconteudo);
	

	/** Destrutor 
	 * @brief Destrutor do objeto.
	 * **/
	public: ~StrucMemory() {	}	
	
			
	/** Get **/
	public: int get_blocos();
	public: int get_endereco();
	public: int get_conteudo();
	

	/** Set **/
	public: void set_blocos(int argblocos);
	public: void set_endereco(int argendereco);
	public: void set_conteudo(int argconteudo);


	/** 
	 * ostream operador sobre escrita.
	 * @param ostream referencia objeto.
	 * @param const StrucMemory objeto.
	 * @return ostream objeto.
	 * **/
	friend std::ostream& operator <<(std::ostream& oss, const StrucMemory& obj){
			oss<<obj.blocos<<"--"<<obj.endereco<<"--"<<obj.conteudo<<std::endl;
	return oss;
	}
};
#endif // __StrucMemory___
