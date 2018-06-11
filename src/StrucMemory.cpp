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


	/** Construtor Padrao **/
	public: StrucMemory(int argblocos, int argendereco, int argconteudo) {
			this->blocos=argblocos;
			this->endereco=argendereco; 
			this->conteudo=argconteudo; 
	}
	

	/** Destrutor 
	 * @brief Destrutor do objeto.
	 * **/
	public: ~StrucMemory() {	}	
	
			
	/** Get **/
	public: int get_blocos(){
		return this->blocos;
	}
	public: int get_endereco(){
		return this->endereco;
	}
	public: int get_conteudo(){
		return this->conteudo;
	}
	

	/** Set **/
	public: void set_blocos(int argblocos){		
		this->blocos = argblocos;
	}
	public: void set_endereco(int argendereco){
		this->endereco = argendereco;
	}
	public: void set_conteudo(int argconteudo){
		this->conteudo = argconteudo;
	}


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
