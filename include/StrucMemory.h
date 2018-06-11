/** 
 * 
 * @file StrucMemory.h
 *
 **/


#ifndef __STRUCMEMORY_H__
#define __STRUCMEMORY_H__


#include <iostream>



/**
 * @class StrucMemory 
 * @brief criacao de objetos.
 * @param blocos numero ode blocos.
 * @param endereco numero do endereco.
 * @param conteudo conteudo endereco.
 **/


class StrucMemory {

private:
	int blocos;
	int endereco;
	int conteudo;

public:
	/** Construtor Padrao **/
	 StrucMemory(int b, int e, int c);
	

	/** Destrutor 
	 * @brief Destrutor do objeto.
	 * **/
	 ~StrucMemory();
	
			
	/** Get **/
	 int  get_blocos();
	 int get_endereco();
	 int get_conteudo();
	

	/** Set **/
	 void set_blocos(int argblocos);
	 void set_endereco(int argendereco);
	 void set_conteudo(int argconteudo);


	/** 
	 * ostream operador sobre escrita.
	 * @param ostream referencia objeto.
	 * @param const StrucMemory objeto.
	 * @return ostream objeto.
	 * **/
	friend std::ostream& operator <<(std::ostream& oss, const StrucMemory& obj);
};
#endif // __StrucMemory___
