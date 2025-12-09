#ifndef DEC0006_MINHA_LISTA_ENCADEADA_H
#define DEC0006_MINHA_LISTA_ENCADEADA_H

#include <cstddef>
#include "Elemento.h"
#include "ListaEncadeadaAbstrata.h"
#include "excecoes.h"

using namespace std;

template<typename T>
class MinhaListaEncadeada : public ListaEncadeadaAbstrata<T>
{
public:
    MinhaListaEncadeada();
    ~MinhaListaEncadeada();

    size_t tamanho() const {
        return this->_tamanho;
    };

    bool vazia() const { 
        if(this->_tamanho == 0) return true; 
        else return false;
    };

    size_t posicao(T dado) const {
        if (this->_tamanho == 0) { // throw exception
            throw ExcecaoListaEncadeadaVazia();
        }
        else if (!contem(dado)) { // throw exception
            throw ExcecaoDadoInexistente();
        }

        size_t i = 0;
        Elemento<T> *nodoAtual = this->_primeiro;

        while (nodoAtual != nullptr) {
            if (nodoAtual->dado == dado) {
                return i;
            }
            i++;
            nodoAtual = nodoAtual->proximo;
        }
        return -1;
    };

    bool contem(T dado) const {
        Elemento<T> *nodoAtual = this->_primeiro;

        while (nodoAtual != nullptr) {
            if (nodoAtual->dado == dado) {
                return true;
            }
            nodoAtual = nodoAtual->proximo;
        }

        return false;
    };

    void inserirNoInicio(T dado) {
        Elemento<T> *novoNodo = new Elemento<T> (dado);

        novoNodo->proximo = this->_primeiro;
        this->_primeiro = novoNodo;

        this->_tamanho++;
    };

    void inserir(size_t posicao, T dado) {
        if (this->_tamanho == 0 && posicao != 0 || this->_tamanho < posicao) {
            throw ExcecaoPosicaoInvalida(); // throw exception
        }     
        else if (posicao == 0) {
            inserirNoInicio(dado); // insert in the beginning
        }
        else if (this->_tamanho == posicao) {
            inserirNoFim(dado); // insert in the end
        }
        else {
            Elemento<T> *novoNodo = new Elemento<T> (dado);
            Elemento<T> *nodoAnterior = this->_primeiro;
            size_t count = 0;

            while (count < posicao-1) {
                count++;
                nodoAnterior = nodoAnterior->proximo;
            }

            novoNodo->proximo = nodoAnterior->proximo; 
            nodoAnterior->proximo = novoNodo;   
            
            this->_tamanho++; 
        }
    };

    void inserirNoFim(T dado) {
        if (this->_tamanho == 0) {
            inserirNoInicio(dado);
        }
        else {
            Elemento<T> *novoNodo = new Elemento<T> (dado);
            Elemento<T> *nodoAnterior = this->_primeiro;
            
            while (nodoAnterior->proximo != nullptr) {
                nodoAnterior = nodoAnterior->proximo;
            }

            nodoAnterior->proximo = novoNodo;
            this->_tamanho++;
        }
    };

    T removerDoInicio() {
        if (this->_primeiro == nullptr) { // throw exception
            throw ExcecaoListaEncadeadaVazia();
        }

        Elemento<T> *nodoTemporario = this->_primeiro;
        this->_primeiro = this->_primeiro->proximo;
        T dado = nodoTemporario->dado;

        this->_tamanho--;

        delete nodoTemporario;
        return dado;
    };

    T removerDe(size_t posicao) {
        T dado;

        if (this->_tamanho == 0 || this->_tamanho-1 < posicao) {
            throw ExcecaoPosicaoInvalida(); // throw exception
        }
        else if (posicao == 0) {
            dado = removerDoInicio(); // remove from the beginning
        }
        else if (this->_tamanho-1 == posicao) {
            dado = removerDoFim(); // remove from the end
        }
        else {
            size_t count = 0;
            Elemento<T> *nodoAtual = this->_primeiro;
            Elemento<T> *nodoAnterior = nodoAtual;

            while (nodoAtual != nullptr) {
                if(count < posicao-1) { //previous node position
                    nodoAnterior = nodoAnterior->proximo;
                }
                if (count == posicao) { //actual position
                    break; 
                }

                count++;
                nodoAtual = nodoAtual->proximo;
            }

            Elemento<T> *nodoTemporario = nodoAnterior->proximo;
            nodoAnterior->proximo = nodoTemporario->proximo;
            dado = nodoTemporario->dado;

            delete nodoTemporario;
            this->_tamanho--;
        }

        return dado;
    };

    T removerDoFim() {
        if (this->_tamanho == 0) { // throw exception
            throw ExcecaoListaEncadeadaVazia();
        }

        Elemento<T> *nodoAtual = this->_primeiro;
        Elemento<T> *nodoAnterior = nullptr;

        while (nodoAtual->proximo != nullptr) {
            nodoAnterior = nodoAtual;
            nodoAtual = nodoAtual->proximo;
        }

        if(this->_tamanho > 1) {
            nodoAnterior->proximo = nullptr;
        }
        else {
            this->_primeiro = nullptr;
        }

        T dado = nodoAtual->dado;
        delete nodoAtual;
        this->_tamanho--;

        return dado;
    };

    void remover(T dado) {
        if (this->_tamanho == 0) { // throw exception
            throw ExcecaoListaEncadeadaVazia();
        }

        if (!contem(dado)) { // throw exception
            throw ExcecaoDadoInexistente();
        }

        removerDe (posicao(dado));
    };
};

template<typename T>
MinhaListaEncadeada<T>::MinhaListaEncadeada() {};

template<typename T>
MinhaListaEncadeada<T>::~MinhaListaEncadeada() {
    Elemento<T> *nodoAtual = this->_primeiro;
    Elemento<T> *proximoNodo = nullptr;

    while (nodoAtual != nullptr) {
        proximoNodo = nodoAtual->proximo;
        delete nodoAtual;
        nodoAtual = proximoNodo;
    }

    this->_primeiro = nullptr;
    this->_tamanho = 0;
}

#endif