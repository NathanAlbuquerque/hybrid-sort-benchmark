# Hybrid Sort Benchmark 📊

Este repositório contém a implementação e análise de desempenho do trabalho de **Análise Teórica vs. Empírica de Algoritmos de Ordenação** (3ª Avaliação - 3AV).

O projeto compara um algoritmo quadrático (**Insertion Sort**) com um log-linear (**Merge Sort**), determina o limiar de eficiência ($n_0$) e implementa uma solução **Híbrida** otimizada.

## 📂 Estrutura do Projeto

O código foi modularizado para facilitar a colaboração e manutenção:

* `main.c`: Gerencia o fluxo do experimento, repetições e coleta de estatísticas.
* `sorts.c` / `sorts.h`: Implementação dos algoritmos (Insertion, Merge e Hybrid).
* `utils.c` / `utils.h`: Funções auxiliares (geração de vetores, medição de tempo, etc).
* `Makefile`: Automação de compilação (para ambientes Unix/Linux).

## ⚙️ Algoritmos & Configuração

* **Quadrático:** Insertion Sort ( $O(n²)$ )
* **Log-linear:** Merge Sort ( $O(n log n)$ )
* **Híbrido:** Merge Sort modificado que alterna para Insertion Sort em subvetores pequenos.

### O Fator $n_0$
Através de testes empíricos realizados na máquina de teste, determinou-se que o ponto de cruzamento (crossover) onde o Merge Sort supera o Insertion Sort é:

> **$n_0 = 158$** elementos

Este valor foi configurado no arquivo `main.c` (`#define N0_HIBRIDO 158`) para otimizar o algoritmo híbrido.
> Aqui você adiciona/substitui o valor do n0 encontrado em seu dispositivo

## 🚀 Como Executar

Você precisa de um compilador C (GCC) instalado.

### 🪟 No Windows (Sem Make)
Se você não tem o `make` instalado, compile manualmente pelo terminal (CMD, PowerShell ou VS Code):

```powershell
# 1. Compile todos os arquivos juntos (incluindo a biblioteca matemática -lm)
gcc main.c sorts.c utils.c -o benchmark.exe -lm

# 2. Execute o programa
.\benchmark.exe
```

### 🐧 No Linux / MacOS (Com Make)
Basta utilizar o arquivo `Makefile` incluído:

```bash
# Compila o projeto
make

# Executa o benchmark
make run

# (Opcional) Limpa arquivos compilados
make clean
```

## 🧪 Metodologia do Experimento

1.  **Tamanho dos Vetores:** 10.000 elementos.
2.  **Cenários de Teste:**
    * Vetor Ordenado (Melhor caso para Insertion).
    * Vetor Inversamente Ordenado (Pior caso).
    * Vetor Aleatóriamente Ordenado (Opcional).
3.  **Precisão:** Cada teste é repetido **100 vezes** para garantir consistência estatística.
4.  **Métricas:** Mínimo, Máximo, Média, Moda e Desvio Padrão dos tempos de execução.

## 📊 Resultados Esperados

Ao rodar o programa, será gerado tabelas no terminal similares a estas:
> Vetor Ordenado 

| Algoritmo | Mínimo(s) | Máximo(s) | Média(s) | Moda(s) | Desvio P. |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Insertion** | 0,000109 | 0,000305 | 0,000139 | 0,000130 | 0,000034 |
| **Merge** | 0,006052 | 0,017014 | 0,007144 | 0,006257 | 0,001205 |
| **Híbrido** | 0,001120 | 0,00163 | 0,001291 | 0,001138 | 0,00001 |
> Vetor Inverso

| Algoritmo | Mínimo(s) | Máximo(s) | Média(s) | Moda(s) | Desvio P. |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Insertion** | 2,386518 | 3,079592 | 2,532056 | 2,386518 | 0,167599 |
| **Merge** | 0,005585 | 0,016663 | 0,006775 | 0,005696 | 0,001475 |
| **Híbrido** | 0,004417 | 0,005813 | 0,004856 | 0,004596 | 0,000341 |
> ☝️*Todos os valores acima foram encontrados no dispositivo em que fizemos os testes (Acer Aspire F5). Irá variar em qualquer outro dispositivo, dependendo de suas configurações!*

## 👥 Autores

* **Nathan Reinaldo de Albuquerque**
* **Jonathan Cleyber Mascarenhas Júnior**
* **Caio Guilherme Araújo Sousa**
* **Aloísio Souza Gonçalves**
* **Diego Ted Rodrigues Bogea**

---
*Trabalho desenvolvido para a disciplina de Estrutura de Dados/Análise de Algoritmos.*
