/** 
 * 
 * @file StrucMemory.h
 *
 **/


#include <iostream>
#include "StrucMemory.h"
using namespace std;

/**
 * @class StrucMemory 
 * @brief criacao de objetos.
 * @param blocos numero ode blocos.
 * @param endereco numero do endereco.
 * @param conteudo conteudo endereco.
 **/




	

	/** Construtor Padrao **/
	StrucMemory::StrucMemory(int b,int e,int c): blocos(b), endereco(e), conteudo(c) { }
	
	

	/** Destrutor 
	 * @brief Destrutor do objeto.
	 * **/
 
	StrucMemory::~StrucMemory() { }
	
			
	/** Get **/
	int StrucMemory::get_blocos(){
		return this->blocos;
	}
	int StrucMemory::get_endereco(){
		return this->endereco;
	}
	int StrucMemory::get_conteudo(){
		return this->conteudo;
	}
	

	/** Set **/
	void StrucMemory::set_blocos(int argblocos){		
		this->blocos = argblocos;
	}
	void StrucMemory::set_endereco(int argendereco){
		this->endereco = argendereco;
	}
	void StrucMemory::set_conteudo(int argconteudo){
		this->conteudo = argconteudo;
	}


	/** 
	 * ostream operador sobre escrita.
	 * @param ostream referencia objeto.
	 * @param const StrucMemory objeto.
	 * @return ostream objeto.
	 * **/
	ostream& operator <<(ostream& oss, const StrucMemory& obj){
			oss<<obj.blocos<<"--"<<obj.endereco<<"--"<<obj.conteudo<<endl;
		return oss;
	}

