/**
 * @file	cache.cpp
 * 	Implementacao da classe Cache para representar uma memoria Cache
 */
#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include <iomanip>
using std::setw;

#include "cache.h"

/**  Construtor padrao */
Cache::Cache(){
	miss=0;
	hit=0;
}

/* Destrutor padrao */
Cache::~Cache(){
	if(getMapeamento()==3){
		for(int i=0; i<getVias(); i++) delete[] matriz[i];
		delete[] matriz;
		for(int i=0; i<getVias(); i++) delete[] freqMatriz[i];
		delete[] freqMatriz;
	}
	else {
		delete[] vetor;
		delete[] freq;
	}
}

/** Retorna a quantidade de palavras por bloco*/
int Cache::getPalavras(){
	return qtdPalavras;		
}

/** Retorna a quantidade de linhas da cache */
int Cache::getLinhas(){
	return qtdLinhas;
}

/** Retorna a quantidade de blocos da memoria principal */
int Cache::getPrincipal(){ 
	return memPrincipal;
}

/** Retorna o tipo de mapeamento */
int Cache::getMapeamento(){
	return mapeamento;
}

/** Retorna a quantidade de vias () */
int Cache::getVias(){ 
	return vias;
}

/** Retorna a politica de substituicao */
int Cache::getSubstituicao(){
	return polSubstituicao;
}

/** Retorna a quantidade de hits*/
int Cache::getHit(){ 
	return hit;
}

/** Retorna a quantidade de misses */
int Cache::getMiss(){
	return miss;
}

/** Retorna o vetor de frequencia*/
int* Cache::getFreq(){
	return freq;
}

/** Retorna o vetor de cache */
int* Cache::getVetor(){
	return vetor;
}

/** Retorna matriz de cache ()*/
int** Cache::getMatriz(){ 
	return matriz;
}

/** Retorna a matriz de frequencia ()*/
int** Cache::getFreqMatriz(){
	return freqMatriz;
}

/** Atualiza a quantidade de palavras
*  p A nova quantidade de palavras */
void Cache::setPalavras(int p){ 
	qtdPalavras = p;
}

/** Atualiza a quantidade de linhas
	*  l A nova quantidade de linhas*/
void Cache::setLinhas(int l){ 
	qtdLinhas = l;
}

/** Atualiza a quantidade de blocos da memoria principal
	*  m A nova quantidade de blocos da memoria principal*/
void Cache::setPrincipal(int m){
	memPrincipal = m;
}

/** Atualiza a nova forma de mapeamento
	*  mp A nova nova forma de mapeamento*/
void Cache::setMapeamento(int mp){
	mapeamento = mp;
}

/** Atualiza a quantidade de vias ()
	*  v A nova quantidade de vias ()*/
void Cache::setVias(int v){ 
	vias = v;
}

/** Atualiza a politica de substituicao 
	*  s A nova politica de substituicao */
void Cache::setSubstituicao(int s){
	polSubstituicao = s;
}

/** Atualiza a quantidade de hits
	*  h A nova quantidade de hits*/
void Cache::setHit(int h){ 
	hit = h;
}

/** Atualiza a quantidade de misses
	*  ms A nova quantidade de misses*/
void Cache::setMiss(int ms){ 
	miss = ms;
}

/** Atualiza o vetor de frequencia 
	*  fr O novo vetor de frequencia */
void Cache::setFreq(int* fr){ 
	freq = fr; 
}

/** Atualiza o vetor de cache 
	*  vt O novo vetor de cache */
void Cache::setVetor(int* vt){ 
	vetor = vt;
}

/** Atualiza a matriz de cache ()
	*  m A nova matriz de cache ()*/
void Cache::setMatriz(int** m){ 
	matriz = m;
}

/** Atualiza a matriz de frequencia () 
	*  fm A nova matriz de frequencia () */
void Cache::setFreqMatriz(int** fm){
	freqMatriz = fm;
}

/** Funcao que calcula a quantidade maxima de enderecos da memoria da principal
	* Retorna a quantidade maxima de enderecos*/
int Cache::memPalavras(){
	return getPalavras()*getPrincipal();
} 

/** Funcao que solicita o endereco de memoria que sera buscado na cache 
	* Retorna o endereco */
int Cache::solicitarEndereco(){
	int end;
	cout << "===========================================" << endl;
	cout << endl << "--- Simulador de Cache ---" << endl;
	do{
		cout << "Enderecos validos: " << 0 << " - " << memPalavras()-1 << endl;
		cout << "Sair: -1" << endl;
		cout << "Digite a opcao: ";
		cin >> end;

		if((end<-1 or end >= memPalavras())){
			cerr << endl << "Endereco errado! Tente novamente..." << endl;
		}
	}while(end<-1 or end >= memPalavras());
	return end;
}

/** Funcao que calcula o bloco que o endereco esta na memoria principal
	* end O endereco
	* Retorna o bloco da principal */ 
int Cache::calcBlocoPrincipal(int end){
	return ((end - (end % getPalavras()))/getPalavras());
}

/** Funcao principal que direciona a politica de substituicao, mapeamento,  etc. */
void Cache::mainCache(){
	short int end=1;
	while(end>=0 and end<getPalavras()*getPrincipal()){ //MAX_ENDERECO_POSSIVEIS
		end = solicitarEndereco();
		if(end==-1) return;

		cout << "Bloco da principal: " << calcBlocoPrincipal(end) << endl;
		if(getMapeamento()==3){
			cout << mapeamentoCache(calcBlocoPrincipal(end)) << endl;
		} else {
			
			cout << "Mapeado no bloco " << mapeamentoCache(calcBlocoPrincipal(end)) << " da memoria cache" << endl;
		}
	}
}
/** Funcao que direciona para qual tipo de mapeamento deve ser executado
	* end O endereco 
	* Retorna o local de substituicao */
int Cache::mapeamentoCache(int end){
	int mapeado=-1;
	if(1==getMapeamento()){
		cout << "Mapeamento Direto" << endl;
		int* v = getVetor();
		cout << "Buscando o bloco " << end;
		if(v[end % getLinhas()]==end) {
			cout << endl << endl << " -> --- HIT ---" << endl << endl;
			setHit(getHit()+1);
		}
		else {
			cout << endl << endl << " -> --- MISS ---" << endl << endl;
			setMiss(getMiss()+1);
			v[end % getLinhas()]=end;
		}
		mapeado = end % getLinhas();
		exibirCache();
		setVetor(v);
		//Sem Politica de Substituicao
	} else if (2==getMapeamento()){
		cout << "Mapeamento Totalmente Associativo" << endl;
		mapeado = substituicaoCache(getVetor(), getFreq(), end);
		exibirCache();
		if(1!=getSubstituicao()) exibirFreq();

		//Com politica de substituicao

	} else if (3==getMapeamento()){
		cout << "Mapeamento Parcialmente Associativo" << endl;
		cout << "Substituido em: " << viasCache(end) << endl;
		//Com politica de substituicao

	} else {
		cerr << "Mapeamento nao reconhecido! Abortando operacoes..." << endl;
		exit(1);
	}
	return mapeado;
}

/** Funcao que atualiza o vetor de frequencia para FIFO
	* f O vetor de frequencia */
void Cache::atualizarFrequenciaFIFO(int *f){	
	for (int i=0; i<getLinhas(); i++) {
		f[i]--;
	}
}

/** Funcao que direciona para qual tipo de substituicao deve ser executada
	* v O vetor de cache
	* f O vetor de frequencia
	* end O endereco
	* Retorna o local de substituicao */
int Cache::substituicaoCache(int *v, int *f, int end){

	//Comum a todos
	if(1==getSubstituicao()) cout << "Substituicao Aleatoria" << endl;
	if(2==getSubstituicao()) cout << "Substituicao FIFO" << endl;
	if(3==getSubstituicao()) cout << "Substituicao LFU" << endl;
	if(4==getSubstituicao()) cout << "Substituicao LRU" << endl;
	cout << "Buscando o bloco " << end;

	bool freeFlag=false;
	int aux=-1;

	if(4==getSubstituicao()){
		for (int i=0; i<getLinhas(); i++) {
			f[i]--;
			if(f[i]<0) f[i]=0;
		}
	}	

	for(int i=0; i<getLinhas(); i++){
		if(v[i]==end){
			cout << endl << endl << " -> --- HIT ---" << endl << endl;
			setHit(getHit()+1);
			if(3==getSubstituicao()){
				f[i]++;
			}
			if(4==getSubstituicao()){
				f[i]=getLinhas();
			}
			return i;
		}
		if(!freeFlag and v[i]==-1) {
			freeFlag=true;
			aux=i;
		}
	}
	cout << endl << endl << " -> --- MISS ---" << endl << endl;
	setMiss(getMiss()+1);

	if(freeFlag) {
		v[aux]=end;
		if(2==getSubstituicao()){
			f[aux]=getLinhas();
			atualizarFrequenciaFIFO(f);
		}
		if(3==getSubstituicao()){
			f[aux]=1;
		}
		if(4==getSubstituicao()){
			f[aux]=getLinhas();
		}
		return aux;
	} 
	else {
		if(1==getSubstituicao()){
			//RANDOM
			aux = rand() % getLinhas();
			v[aux]=end;
			return aux;		
			//Com Politica de Escrita
		} else if (2==getSubstituicao()){
			//FIFO		
			aux=f[0];
			int auxI=0;
			for(int i=1; i<getLinhas(); i++){
				if(f[i]<aux) {
					aux=f[i];
					auxI=i;
				}
			}
			v[auxI]=end;
			f[auxI]=getLinhas();
			atualizarFrequenciaFIFO(f);
			cout << endl;
		
			return auxI;
			//Com politica de substituicao e Escrita

		} else if (3==getSubstituicao()){
			//cout << "Substituicao LFU" << endl;
			aux=f[0];
			int auxI=0;
			for(int i=1; i<getLinhas(); i++){
				if(aux>f[i]) {
					aux=f[i];
					auxI=i;
				}
			}
			v[auxI]=end;
			f[auxI]=1;
			return auxI;
			//Com politica de substituicao e Escrita

		} else if (4==getSubstituicao()){
			//cout << "Substituicao LRU" << endl;
			aux=f[0];
			int auxI=0;
			for(int i=1; i<getLinhas(); i++){
				if(aux > f[i]) {
					aux=f[i];
					auxI=i;
				}
			}
			v[auxI]=end;
			f[auxI]=getLinhas();
			return auxI;
			//Com politica de substituicao e Escrita

		}else {
			cerr << "Politica de substituicao nao reconhecida! Abortando operacoes..." << endl;
			exit(1);
		}
	}
	
	return -1;
}


/** Funcao que realiza as alocacoes dinamicas necessarias e inicializa os vetores com valores default */
void Cache::criar(){
	if(getMapeamento()==3){
		int **m = new int*[getVias()];
		for(int i=0; i<getVias(); i++) m[i]=new int[getLinhas()];

		int **fm = new int*[getVias()];
		for(int i=0; i<getVias(); i++) fm[i]=new int[getLinhas()];

		for(int i=0; i<getVias(); i++){
			for(int j=0; j<getLinhas(); j++){
				m[i][j]=-1;
				fm[i][j]=0;
			}
		}
		setMatriz(m);
		setFreqMatriz(fm);

	} else {
		int* v = new int[getLinhas()];
		int* f = new int[getLinhas()];
		for(int i=0; i<getLinhas(); i++) {
			v[i]=-1;
			f[i]=0;
		}
		if(getSubstituicao()==4) {
			for(int i=0; i<getLinhas(); i++) {
				f[i]=getSubstituicao();
			}
		}
		setVetor(v);
		setFreq(f);
	}
}

/** Funcao que direciona para qual via o endereco deve ser substituido 
	* end O endereco 
	* Retorna o local de substituicao */
int Cache::viasCache(int end){
	int **m = getMatriz();
	int **fm = getFreqMatriz();
	if(getVias()>0){
		cout << "Vias" << endl;
		cout << "Mapeado no bloco " << substituicaoCache(m[end%getVias()], fm[end%getVias()], end) << " da via " << end%getVias() << endl;
		exibirCacheMatriz();
		if(getSubstituicao()==3 or getSubstituicao()==2 or getSubstituicao()==4) exibirFreqMatriz();
		
	
		//matriz
		//bloco da principal indica a via e o bloco

		//Sem Politica de Substituicao
	} else {
		cerr << "Quantidade de vias nao reconhecidas! Abortando operacoes..." << endl;
		exit(1);
	}
	return 0;
}

/** Funcao que imprime o vetor de cache */
void Cache::exibirCache(){
	int *v = getVetor();
	cout << "------- Cache -------" <<endl;
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		if(v[i]==-1) cout << "__";
		else cout << setw(2) << v[i];

		cout << " ";
	}
	cout << "] -> Blocos da memoria principal na cache"<< endl;
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		cout << setw(2) << i << " ";
	}
	cout << "] -> Blocos da cache"<< endl << endl;
}

/** Funcao que imprime o vetor de frequencia */
void Cache::exibirFreq(){
	int *f = getFreq();
	int *v = getVetor();
	cout << "------- Frequencia -------" <<endl;
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		if(v[i]>=0)cout << setw(2) << f[i] << " ";
		else cout << "__ ";
	}
	cout << "] -> Vetor de frequencia dos blocos na cache" << endl;
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		cout << setw(2) << i << " ";
	}
	cout << "] -> Numero do bloco da cache" << endl << endl;
}

/** Funcao que imprime a matriz de cache ()*/
void Cache::exibirCacheMatriz(){
	int **m = getMatriz();
	cout << "------- Cache -------" <<endl;
	for(int i=0; i<getVias(); i++){
		cout << "[ ";
		for (int j=0; j<getLinhas(); j++) {
			if(m[i][j]==-1) cout << "__";
			else cout << setw(2) << m[i][j];

			cout << " ";
		}
		cout << "] -> Via "<< i << endl;
	}
	
	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		cout << setw(2) << i << " ";
	}
	cout << "] -> Numero de blocos da cache"<< endl << endl;
}

/** Funcao que a matriz de frequencia ()*/
void Cache::exibirFreqMatriz(){
	int **m = getMatriz();
	int **fm = getFreqMatriz();
	cout << "------- Frequencia -------" <<endl;
	for(int i=0; i<getVias(); i++){
		cout << "[ ";
		for (int j=0; j<getLinhas(); j++) {
			if(m[i][j]>=0)cout << setw(2) << fm[i][j] << " ";
			else cout << "__ ";
		}
		cout << "] -> Via "<< i << endl;
	}

	cout << "[ ";
	for (int i=0; i<getLinhas(); i++) {
		cout << setw(2) << i << " ";
	}
	cout << "] -> Numero de blocos da cache"<< endl << endl;
}