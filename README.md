# Hybrid Sort Benchmark 📊

Este repositório contém o código fonte e a análise dos resultados do trabalho de **Análise Teórica (Notação Assintótica) x Análise Empírica (Tempo de Execução)** da 3ª Avaliação (3AV).

O objetivo principal é comparar o desempenho entre o **Insertion Sort** e o **Merge Sort**, encontrar o ponto de interseção ($n_0$) onde a complexidade log-linear supera a quadrática, e desenvolver uma solução híbrida otimizada.

## 🎯 Objetivos

1. Comparar o desempenho do **Insertion Sort** (Quadrático) com o **Merge Sort** (Log-linear).
2. Determinar matematicamente e empiricamente o valor de **$n_0$** (tamanho do vetor onde o Merge Sort passa a ser mais rápido que o Insertion Sort).
3. Implementar um **Algoritmo Híbrido** baseada no Merge Sort, que alterna para Insertion Sort quando o subvetor é pequeno ($n < n_0$).
4. Realizar coleta de dados estatísticos com 100 repetições.

## ⚙️ Algoritmos Escolhidos

O par de algoritmos selecionado pelo grupo foi:

* **Quadrático:** Insertion Sort
* **Log-linear:** Merge Sort

> **Nota sobre o Híbrido:** O algoritmo híbrido utiliza a estrutura de divisão e conquista do Merge Sort, mas interrompe a recursão quando o tamanho da partição atinge o limiar $n_0$, aplicando o Insertion Sort para ordenar esses pequenos blocos de forma mais eficiente.

## 🧪 Metodologia do Experimento

### Coleções de Dados
Os testes foram realizados com vetores de **10.000 elementos** nas seguintes disposições:
* 5.1 Ordenados (Crescente)
* 5.2 Ordem Inversa (Decrescente)

### Métricas Coletadas
Para cada cenário, o experimento foi repetido **100 vezes**, coletando:
* Tempo Mínimo
* Tempo Máximo
* Tempo Médio
* Moda
* Desvio Padrão

## 💻 Especificações do Ambiente (Benchmark)

Conforme solicitado no item 8.1, todos os testes foram executados na seguinte máquina:

* **Processador (CPU):** [Ex: Intel Core i7-10750H @ 2.60GHz]
* **Memória RAM:** [Ex: 16 GB DDR4]
* **Sistema Operacional:** [Ex: Windows 11 / Ubuntu 22.04]
* **Linguagem de Programação:** [Ex: Python 3.10 / C++ (GCC 11.2)]

## 🚀 Como Executar

Instruções para reproduzir o experimento:

{code}bash
# Exemplo de comando para rodar o script (ajuste conforme sua linguagem)
python main.py

# ou se for em C/C++
gcc main.c -o benchmark
./benchmark
{code}

## 📊 Resultados e Análise

### 1. Determinação do $n_0$
O valor de $n_0$ encontrado foi: **[Inserir valor, ex: 45]**.
*Explicação: O Insertion Sort demonstrou ser mais rápido para vetores menores que este valor devido às constantes menores em sua complexidade assintótica, apesar de ser $O(n^2)$.*

### 2. Tabelas de Tempos (em milissegundos ou segundos)

#### 5.1 Vetor Ordenado (10.000 itens)
| Algoritmo | Mínimo | Máximo | Média | Moda | Desvio Padrão |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Insertion Sort** | - | - | - | - | - |
| **Merge Sort** | - | - | - | - | - |
| **Híbrido** | - | - | - | - | - |

#### 5.2 Vetor Inversamente Ordenado (10.000 itens)
| Algoritmo | Mínimo | Máximo | Média | Moda | Desvio Padrão |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Insertion Sort** | - | - | - | - | - |
| **Merge Sort** | - | - | - | - | - |
| **Híbrido** | - | - | - | - | - |

### 3. Gráficos de Performance
> Os gráficos gerados comparando as 100 execuções encontram-se na pasta `/docs` ou abaixo:

![Gráfico Comparativo](caminho/para/seu/grafico.png)
*(Insira aqui os gráficos de linha ou boxplot gerados)*

## 📝 Conclusão

[Escreva aqui se o algoritmo Híbrido conseguiu superar os outros dois ou se ficou próximo do Merge Sort puro. Comente sobre a estabilidade dos tempos usando o Desvio Padrão].

## 👥 Autores

* **[Seu Nome]**
* **[Nome do Colega 1]**
* **[Nome do Colega 2]**

---
*Trabalho desenvolvido para a disciplina de Estrutura de Dados/Análise de Algoritmos, ministrada pelo Prof. Emmanuel Silva Xavier.*

