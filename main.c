/**
 * DESAFIO: BATALHA NAVAL EM C
 * Nível: Novato, Aventureiro e Mestre
 * 
 * Este programa simula o posicionamento de navios e habilidades especiais usando:
 * - MATRIZES: Tabuleiro 10x10 e áreas de efeito das habilidades
 * - VALIDAÇÕES: Limites do tabuleiro e sobreposição de navios
 * - CONSTRUÇÃO DINÂMICA: Matrizes de habilidade (Cone, Cruz, Octaedro)
 * - SOBREPOSIÇÃO: Aplicação das habilidades no tabuleiro com pontos de origem
 * 
 * Autor: Matheus Torres
 * Data: 18/02/2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

/**
 * Estrutura para representar um ponto no tabuleiro (linha, coluna)
 */
typedef struct {
    int linha;
    int coluna;
} Ponto;

// ==================== FUNÇÕES DE VALIDAÇÃO ====================

/**
 * Verifica se uma posição está dentro dos limites do tabuleiro
 */
bool posicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && 
            coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// ==================== FUNÇÕES DE POSICIONAMENTO DE NAVIOS ====================

/**
 * Verifica se um navio horizontal pode ser posicionado
 */
bool podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                             int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA) return false;
    }
    return true;
}

/**
 * Verifica se um navio vertical pode ser posicionado
 */
bool podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                           int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) return false;
    }
    return true;
}

/**
 * Verifica se um navio na diagonal principal pode ser posicionado
 */
bool podePosicionarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                    int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || 
        coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return false;
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != AGUA) return false;
    }
    return true;
}

/**
 * Verifica se um navio na diagonal secundária pode ser posicionado
 */
bool podePosicionarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                                     int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || 
        coluna - TAMANHO_NAVIO + 1 < 0) return false;
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != AGUA) return false;
    }
    return true;
}

/**
 * Posiciona os navios no tabuleiro
 */
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== POSICIONANDO NAVIOS ===\n\n");
    
    // Navio Horizontal
    int linhaH = 2, colunaH = 3;
    if (podePosicionarHorizontal(tabuleiro, linhaH, colunaH)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = NAVIO;
        }
        printf("  ✓ Navio horizontal em [%d,%d]\n", linhaH, colunaH);
    }
    
    // Navio Vertical
    int linhaV = 5, colunaV = 7;
    if (podePosicionarVertical(tabuleiro, linhaV, colunaV)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = NAVIO;
        }
        printf("  ✓ Navio vertical em [%d,%d]\n", linhaV, colunaV);
    }
    
    // Navio Diagonal Principal
    int linhaDP = 0, colunaDP = 0;
    if (podePosicionarDiagonalPrincipal(tabuleiro, linhaDP, colunaDP)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaDP + i][colunaDP + i] = NAVIO;
        }
        printf("  ✓ Navio diagonal principal em [%d,%d]\n", linhaDP, colunaDP);
    }
    
    // Navio Diagonal Secundária
    int linhaDS = 4, colunaDS = 6;
    if (podePosicionarDiagonalSecundaria(tabuleiro, linhaDS, colunaDS)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaDS + i][colunaDS - i] = NAVIO;
        }
        printf("  ✓ Navio diagonal secundária em [%d,%d]\n", linhaDS, colunaDS);
    }
}

// ==================== FUNÇÕES DE CRIAÇÃO DE HABILIDADES ====================

/**
 * Cria a matriz de habilidade em formato de CONE
 * - FORMA: Triangular, expandindo para baixo
 * - LÓGICA: Largura progressiva = 2*i + 1
 */
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    printf("\n=== CRIANDO HABILIDADE CONE ===\n");
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int centro = TAMANHO_HABILIDADE / 2;
            int inicio = centro - i;
            int fim = centro + i;
            
            habilidade[i][j] = (j >= inicio && j <= fim) ? 1 : 0;
        }
    }
    
    printf("Matriz da habilidade (1 = área afetada):\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("  ");
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
}

/**
 * Cria a matriz de habilidade em formato de CRUZ
 * - FORMA: Braços nas quatro direções
 * - LÓGICA: i == centro || j == centro
 */
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    printf("\n=== CRIANDO HABILIDADE CRUZ ===\n");
    
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
    }
    
    printf("Matriz da habilidade (1 = área afetada):\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("  ");
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
}

/**
 * Cria a matriz de habilidade em formato de OCTAEDRO (losango)
 * - FORMA: Diamante/Quadrado rotacionado
 * - LÓGICA: Distância Manhattan |i-centro| + |j-centro| <= 2
 */
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    printf("\n=== CRIANDO HABILIDADE OCTAEDRO ===\n");
    
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int distancia = abs(i - centro) + abs(j - centro);
            habilidade[i][j] = (distancia <= 2) ? 1 : 0;
        }
    }
    
    printf("Matriz da habilidade (1 = área afetada):\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("  ");
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
}

// ==================== FUNÇÕES DE APLICAÇÃO DE HABILIDADES ====================

/**
 * Aplica uma habilidade ao tabuleiro a partir do ponto de origem
 * - TÉCNICA: Translação de matriz (centralização no ponto de origem)
 * - VALIDAÇÃO: Verifica limites do tabuleiro em tempo real
 */
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       Ponto origem, const char* nomeHabilidade) {
    
    printf("\n=== APLICANDO HABILIDADE %s ===\n", nomeHabilidade);
    printf("Ponto de origem: [%d,%d]\n", origem.linha, origem.coluna);
    
    int centro = TAMANHO_HABILIDADE / 2;
    int posicoesAfetadas = 0;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origem.linha + (i - centro);
                int colunaTab = origem.coluna + (j - centro);
                
                if (posicaoValida(linhaTab, colunaTab)) {
                    if (tabuleiro[linhaTab][colunaTab] == AGUA) {
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                    }
                    posicoesAfetadas++;
                }
            }
        }
    }
    
    printf("Posições afetadas dentro do tabuleiro: %d\n", posicoesAfetadas);
}

// ==================== FUNÇÃO DE EXIBIÇÃO DO TABULEIRO ====================

/**
 * Exibe o tabuleiro formatado com legenda
 * - USO: Loops aninhados para percorrer a matriz
 * - FORMATAÇÃO: Números de linha/coluna e linhas separadoras
 */
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
    printf("    ");
    
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ==================== FUNÇÃO PRINCIPAL ====================

int main() {
    // Inicialização do tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    
    printf("========================================\n");
    printf("  BATALHA NAVAL - NÍVEL MESTRE\n");
    printf("========================================\n");
    printf("Autor: Matheus Torres\n");
    printf("Data: 18/02/2026\n");
    printf("========================================\n");
    
    // PASSO 1: Posicionar os navios
    posicionarNavios(tabuleiro);
    exibirTabuleiro(tabuleiro);
    
    // PASSO 2: Criar as matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);
    
    // PASSO 3: Definir pontos de origem
    Ponto origemCone = {3, 5};
    Ponto origemCruz = {7, 2};
    Ponto origemOctaedro = {5, 8};
    
    // PASSO 4: Aplicar as habilidades
    aplicarHabilidade(tabuleiro, cone, origemCone, "CONE");
    aplicarHabilidade(tabuleiro, cruz, origemCruz, "CRUZ");
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedro, "OCTAEDRO");
    
    // PASSO 5: Exibir resultado final
    printf("\n=== TABULEIRO FINAL COM HABILIDADES ===\n");
    exibirTabuleiro(tabuleiro);
    
    // Legenda
    printf("LEGENDA:\n");
    printf("0 = Água\n");
    printf("3 = Navio\n");
    printf("5 = Área afetada por habilidade\n");
    
    printf("\nPOSIÇÕES DAS HABILIDADES:\n");
    printf("- Cone: centrado em [%d,%d]\n", origemCone.linha, origemCone.coluna);
    printf("- Cruz: centrada em [%d,%d]\n", origemCruz.linha, origemCruz.coluna);
    printf("- Octaedro: centrado em [%d,%d]\n", origemOctaedro.linha, origemOctaedro.coluna);
    
    return 0;
}
