# ⚓ DESAFIO COMPLETO: BATALHA NAVAL EM C
### Níveis: Novato, Aventureiro e Mestre (Consolidados)

[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Status: Concluído](https://img.shields.io/badge/status-concluído-brightgreen.svg)]()
[![Faculdade: Estácio](https://img.shields.io/badge/faculdade-estácio-blue.svg)]()

---

## 📋 Sobre o Projeto

Este programa é a **versão completa e consolidada** dos três níveis do desafio de Batalha Naval da faculdade de Ciência da Computação. Em um **único arquivo**, implementei todos os requisitos dos níveis:

- **🌊 Nível Novato**: Posicionamento de navios horizontais e verticais
- **⚔️ Nível Aventureiro**: Adição de navios diagonais
- **🏆 Nível Mestre**: Habilidades especiais com áreas de efeito (Cone, Cruz e Octaedro)

O programa constrói um tabuleiro 10x10, posiciona 4 navios sem sobreposição e aplica 3 habilidades especiais com diferentes formatos de área de efeito, demonstrando conceitos avançados de manipulação de matrizes em C.

---

## 🎯 Elementos Implementados

| Elemento | Descrição | Técnica Utilizada | Nível |
|----------|-----------|-------------------|-------|
| **NAVIO HORIZONTAL** | 3 posições na mesma linha | Vetores e matrizes | Novato |
| **NAVIO VERTICAL** | 3 posições na mesma coluna | Vetores e matrizes | Novato |
| **NAVIO DIAGONAL PRINCIPAL** | 3 posições na diagonal (i+i, j+i) | Matrizes e loops | Aventureiro |
| **NAVIO DIAGONAL SECUNDÁRIA** | 3 posições na diagonal (i+i, j-i) | Matrizes e loops | Aventureiro |
| **HABILIDADE CONE** | Formato triangular expansivo | Condicionais + distância | Mestre |
| **HABILIDADE CRUZ** | Formato de cruz (mesma linha/coluna) | Condicionais | Mestre |
| **HABILIDADE OCTAEDRO** | Formato de losango | Distância Manhattan | Mestre |

---

## 🧠 Conceitos de Programação Demonstrados

### Nível Novato (Base do Projeto)
✅ Declaração e inicialização de matrizes 10x10  
✅ Preenchimento com valores padrão (0 para água)  
✅ Posicionamento de elementos em coordenadas específicas  
✅ Validação de limites do tabuleiro  
✅ Exibição formatada com loops aninhados

### Nível Aventureiro (Navios Diagonais)
✅ Posicionamento em diagonal (linha e coluna variando juntas)  
✅ Validação de limites para diagonais  
✅ Verificação de sobreposição entre todos os navios  
✅ Múltiplas orientações no mesmo tabuleiro

### Nível Mestre (Habilidades Especiais)
✅ **Matrizes de Habilidade 5x5**: Representação de áreas de efeito
✅ **Construção Dinâmica com Condicionais**:
  - **Cone**: `if (j >= inicio && j <= fim)` - largura progressiva
  - **Cruz**: `if (i == centro || j == centro)` - mesma linha/coluna
  - **Octaedro**: `if (abs(i-centro) + abs(j-centro) <= 2)` - distância Manhattan

✅ **Sobreposição de Matrizes**: Centralização da habilidade no ponto de origem
✅ **Validação de Limites em Tempo Real**: Verificação antes de aplicar cada célula
✅ **Múltiplas Camadas**: Tabuleiro final com água (0), navios (3) e habilidades (5)
✅ **Cálculo de Distância**: Uso da função `abs()` para formas geométricas

---

## 🚀 Como Compilar e Executar

### No Linux/Mac:
```bash
gcc main.c -o main
./main
```

### No Windows (com MinGW):
```bash
gcc main.c -o main.exe
main.exe
```

### No VS Code (com Code Runner):
Apenas abra o arquivo e pressione `Ctrl + Alt + N`

---

## 🎮 Fluxo do Programa

```
INÍCIO
  ↓
INICIALIZAR TABULEIRO 10x10 com ÁGUA (0)
  ↓
POSICIONAR NAVIOS (validações automáticas)
  ├── Navio Horizontal [2,3]
  ├── Navio Vertical [5,7]
  ├── Navio Diagonal Principal [0,0]
  └── Navio Diagonal Secundária [4,6]
  ↓
EXIBIR TABULEIRO COM NAVIOS
  ↓
CRIAR MATRIZES DE HABILIDADE (5x5)
  ├── CONE (formato triangular)
  ├── CRUZ (formato de cruz)
  └── OCTAEDRO (formato de losango)
  ↓
APLICAR HABILIDADES AO TABULEIRO
  ├── Cone: origem [3,5]
  ├── Cruz: origem [7,2]
  └── Octaedro: origem [5,8]
  ↓
EXIBIR TABULEIRO FINAL
  ↓
FIM
```

---

## 📊 Exemplo de Saída (Habilidades)

```
=== CRIANDO HABILIDADE CONE ===
Matriz da habilidade (1 = área afetada):
  0 0 1 0 0 
  0 1 1 1 0 
  1 1 1 1 1 
  1 1 1 1 1 
  1 1 1 1 1 

=== CRIANDO HABILIDADE CRUZ ===
Matriz da habilidade (1 = área afetada):
  0 0 1 0 0 
  0 0 1 0 0 
  1 1 1 1 1 
  0 0 1 0 0 
  0 0 1 0 0 

=== CRIANDO HABILIDADE OCTAEDRO ===
Matriz da habilidade (1 = área afetada):
  0 0 1 0 0 
  0 1 1 1 0 
  1 1 1 1 1 
  0 1 1 1 0 
  0 0 1 0 0 
```

---

## 📊 Tabuleiro Final (Exemplo)

```
=== TABULEIRO BATALHA NAVAL ===
    0  1  2  3  4  5  6  7  8  9 
   -----------------------------
 0 | 3  0  0  0  0  0  0  0  0  0 
 1 | 0  3  0  0  0  0  0  0  0  0 
 2 | 0  0  3  3  3  0  5  5  5  0 
 3 | 0  0  0  5  5  5  5  5  5  0 
 4 | 0  0  0  0  5  5  5  0  0  0 
 5 | 0  0  0  0  0  0  0  0  5  0 
 6 | 0  0  0  0  0  0  0  0  5  0 
 7 | 0  5  5  5  5  5  0  0  5  0 
 8 | 0  0  5  5  5  0  0  0  0  0 
 9 | 0  0  0  0  0  0  0  0  0  0 

LEGENDA:
0 = Água
3 = Navio
5 = Área afetada por habilidade
```

---

## 🔍 Validação dos Requisitos por Nível

### 🌊 Nível Novato (Requisitos Atendidos)
- [x] Tabuleiro 10x10 inicializado com 0 (água)
- [x] Posicionamento de navio horizontal (tamanho 3)
- [x] Posicionamento de navio vertical (tamanho 3)
- [x] Validação de limites do tabuleiro
- [x] Validação de sobreposição
- [x] Exibição formatada com loops aninhados

### ⚔️ Nível Aventureiro (Requisitos Atendidos)
- [x] Posicionamento de navio diagonal principal
- [x] Posicionamento de navio diagonal secundária
- [x] Total de 4 navios no tabuleiro
- [x] Validação de limites para diagonais
- [x] Verificação de sobreposição entre todos os navios

### 🏆 Nível Mestre (Requisitos Atendidos)
- [x] Matriz de habilidade CONE (5x5 com formato triangular)
- [x] Matriz de habilidade CRUZ (5x5 com formato de cruz)
- [x] Matriz de habilidade OCTAEDRO (5x5 com formato de losango)
- [x] Construção dinâmica com condicionais
- [x] Pontos de origem definidos para cada habilidade
- [x] Sobreposição das matrizes no tabuleiro
- [x] Validação de limites durante a sobreposição
- [x] Valores diferentes para água (0), navio (3) e habilidade (5)
- [x] Uso obrigatório de loops aninhados e condicionais

---

## 📁 Estrutura do Projeto

```
📦 desafio-batalha-naval
 ┣ 📜 batalha_naval.c    # Código fonte único (todos os níveis)
 ┗ 📜 README.md          # Documentação completa
```

---

## 🛠️ Funções Implementadas

| Função | Responsabilidade | Técnica |
|--------|------------------|---------|
| `posicaoValida()` | Verifica limites do tabuleiro | Condicional simples |
| `podePosicionarHorizontal()` | Valida navio horizontal | Loop + condicional |
| `podePosicionarVertical()` | Valida navio vertical | Loop + condicional |
| `podePosicionarDiagonalPrincipal()` | Valida diagonal principal | Loop + condicional |
| `podePosicionarDiagonalSecundaria()` | Valida diagonal secundária | Loop + condicional |
| `posicionarNavios()` | Posiciona os 4 navios | Múltiplos loops |
| `criarHabilidadeCone()` | Cria matriz do cone | Largura progressiva |
| `criarHabilidadeCruz()` | Cria matriz da cruz | Mesma linha/coluna |
| `criarHabilidadeOctaedro()` | Cria matriz do octaedro | Distância Manhattan |
| `aplicarHabilidade()` | Sobrepõe habilidade no tabuleiro | Translação de matriz |
| `exibirTabuleiro()` | Mostra tabuleiro formatado | Loops aninhados |

---

## 💡 Detalhamento das Habilidades

### 🔺 Habilidade CONE
```
Formato:     0 0 1 0 0
             0 1 1 1 0
             1 1 1 1 1
             1 1 1 1 1
             1 1 1 1 1
Lógica:      Largura = 2*i + 1 (progressão: 1,3,5,7,9)
```

### ✝️ Habilidade CRUZ
```
Formato:     0 0 1 0 0
             0 0 1 0 0
             1 1 1 1 1
             0 0 1 0 0
             0 0 1 0 0
Lógica:      i == centro || j == centro
```

### 💎 Habilidade OCTAEDRO
```
Formato:     0 0 1 0 0
             0 1 1 1 0
             1 1 1 1 1
             0 1 1 1 0
             0 0 1 0 0
Lógica:      |i-centro| + |j-centro| <= 2
```

---

## 👨‍💻 Autor

**Matheus Torres**  
Curso: Ciência da Computação  
Data: 18/02/2026  
GitHub: [Zer0G0ld](https://github.com/Zer0G0ld)
