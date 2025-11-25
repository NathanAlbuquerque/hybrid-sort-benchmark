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

> **$n_0 = 175$** elementos

Este valor foi configurado no arquivo `main.c` (`#define N0_HIBRIDO 175`) para otimizar o algoritmo híbrido.

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

Ao rodar o programa, será gerada uma tabela no terminal similar a esta:

| Algoritmo | Mínimo(s) | Máximo(s) | Média(s) | Moda(s) | Desvio P. |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Insertion** | 0,000109 | 0,000305 | 0,000139 | 0,000130 | 0,000034 |
| **Merge** | 0,006052 | 0,017014 | 0,007144 | 0,006257 | 0,001205 |
| **Híbrido** | 0,001120 | 0,00163 | 0,001291 | 0,001138 | 0,00001 |
> ☝️*Valores encontrados no dispositivo em que fizemos os testes. Irá variar em qualquer outro dispositivo!.*

## 👥 Autores

* **Nathan Reinaldo de Albuquerque**
* **Jonathan Cleyber Mascarenhas Júnior**
* **Caio Guilherme Araújo Sousa**
* **Aloísio Souza Gonçalves**
* **Diego Ted Rodrigues Bogea**

---
*Trabalho desenvolvido para a disciplina de Estrutura de Dados/Análise de Algoritmos.*
