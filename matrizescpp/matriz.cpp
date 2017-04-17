#include <iostream>
#include <cstdlib>

#include "matriz.h"
using namespace std;

//#define NULL 0

Matriz::Matriz(int nlin, int ncol){
  // armazena linhas e colunas
  this->nlin = nlin;
  this->ncol = ncol;

  if(nlin <= 0 || ncol <=0){
    x = NULL;
    return;
  }
  
  // aloca a memoria auxiliar e da matriz
  x = new float* [nlin];
  if( x == NULL){
    exit(0);
  }
  // cout << "x = " << x;
  x[0] = new float [nlin*ncol];
  if( x[0] == NULL){
    exit(0);
  }
  // ajusta os enderecos
  for(int i=1; i<nlin; i++){
    x[i] = x[i-1] + ncol;
  }

}

Matriz::~Matriz(){
  if (x != NULL){
    delete [] x[0];
    delete [] x;
  }
}

Matriz::Matriz(Matriz &m){
  nlin = m.nlin;
  ncol = m.ncol;
  if(nlin == 0 || ncol == 0){
    x = NULL;
    return;
  }
  x = new float*[nlin];
  if(x == NULL){
    exit(0);
  }
  x[0] = new float[nlin*ncol];
  if(x[0] == NULL){
    exit(0);
  }
  for(int i=1; i<nlin; i++){
    x[i] = x[i-1] + ncol;
  }
  // copia a matriz
  for(int i=0; i<nlin*ncol; i++){
    x[0][i] = m.x[0][i];
  }
}



float& Matriz::operator()(int i, int j){
  if(i>=0 && i<nlin && j>=0 && j<ncol){
    return(x[i][j]);
  }
  exit(0);
}

Matriz Matriz::operator+(const Matriz &m){
  Matriz retorno(nlin, ncol);
  for(int i=0; i<nlin*ncol; i++){
    retorno.x[0][i] = x[0][i] + m.x[0][i];
  }
  return(retorno);
}

Matriz Matriz::operator=(const Matriz &m){
  // teste se o objeto repassado eh o mesmo
  // que executa o metodo
  if( this == &m){
    return(*this);
    // return(m);
  }
  // apenas copia os valores se as matrizes
  // tem o mesmo tamanho
  if(nlin == m.nlin && ncol == m.ncol){
    for(int i=0; i<nlin*ncol; i++){
      x[0][i] = m.x[0][i];
    }
    return(*this);
  }

  if(x != NULL){
    delete [] x[0];
    delete [] x;
  }
  nlin = m.nlin;
  ncol = m.ncol;
  x = new float*[nlin];
  if(x == NULL){
    exit(0);
  }
  x[0] = new float[nlin*ncol];
  if(x[0] == NULL){
    exit(0);
  }
  for(int i=1; i<nlin; i++){
    x[i] = x[i-1] + ncol;
  }
  // copia a matriz
  for(int i=0; i<nlin*ncol; i++){
    x[0][i] = m.x[0][i];
  }
  return(*this);
}

void Matriz::rand(void){
  for(int i=0; i<nlin; i++){
    for(int j=0; j<ncol; j++){
      x[i][j] = ((float)std::rand())/RAND_MAX;
    }
  }
}

void Matriz::print(void){
  for(int i=0; i<nlin; i++){
    for(int j=0; j<ncol; j++){
      cout << x[i][j] << " ";
    }
    cout << endl;
  }
}

Matriz Matriz::operator*(float a){
  Matriz ret(nlin, ncol);
  for(int i=0; i<nlin*ncol; i++){
    ret.x[0][i] = a*x[0][i];
  }
  return(ret);
}

Matriz operator*(float a, const Matriz &m){
  Matriz ret(m.nlin, m.ncol);
  for(int i=0; i<m.nlin*m.ncol; i++){
    ret.x[0][i] = a*m.x[0][i];
  }
  return(ret);
}














