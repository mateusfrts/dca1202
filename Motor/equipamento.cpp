#include "equipamento.h"
#include <cstring>
#include <iostream>

using namespace std;

Equipamento::Equipamento() : preco(0){
  cout << "construtor default Equipamento\n";
}

Equipamento::Equipamento(float _preco){
  cout << "construtor args Equipamento\n";
  preco = _preco;
}

Equipamento::~Equipamento(){
  cout << "destrutor Equipamento\n";
}

void Equipamento::setNome(const char *_nome){
  strcpy(nome,_nome);
}

void Equipamento::setFabricante(const char *_fabricante){
  strcpy(fabricante,_fabricante);
}

void Equipamento::setPreco(float _preco){
  preco=_preco;
}

char* Equipamento::getNome(void){
  return nome;
}

char* Equipamento::getFabricante(void){
  return fabricante;
}

float Equipamento::getPreco(void){
  return preco;
}
