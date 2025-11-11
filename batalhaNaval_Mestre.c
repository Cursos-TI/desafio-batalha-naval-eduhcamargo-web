#include <stdio.h>

#define TamanhoTabuleiro 10
#define TamanhoNavio 3
#define TamanhoHabilidade 5 //impar para possuir centro

const int agua = 0;
const int navio = 3;
const int MarcadeHabilidade = 5;
const int Afetado = 1;
const int Nao_afetado = 0;
const int Verdadeiro = 1;
const int Falso = 0;

//Tipos de Habilidades
enum TipoHabilidade {
    Cone,
    Cruz,
    Octaedro
};

//Valor Absoluto
int valorAbsoluto(int n){
    if (n < 0) {
        return -n;
    }
    return n;
}

//Função Básica

void InicioTabuleiro(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro]) {
    for (int i = 0; i < TamanhoTabuleiro; i++) {
        for (int j = 0; j < TamanhoTabuleiro; j++)
        {
            tabuleiro[i][j] = agua;
        }
    }    
}

//Função Geometrica

void CriarMatrizdeHabilidade(int matriz[TamanhoHabilidade][TamanhoHabilidade], enum TipoHabilidade tipo){
    int centro = TamanhoHabilidade / 2;
    int raioMaximo = centro;

    for (int i = 0; i < TamanhoHabilidade; i++) {
        for (int j = 0; j < TamanhoHabilidade; j++) {
            //Usando valor absoluto
            int dist_linha = valorAbsoluto(i - centro);
            int dist_coluna = valorAbsoluto(j - centro);
            int afetado = Nao_afetado;

            switch (tipo) {
                case Cone:
                    if (i < 3) {
                        if (valorAbsoluto(j - centro) <= i){
                            afetado = Afetado;
                        }
                    }
                    break;
                case Cruz:
                    if (i == centro || j == centro) {
                        afetado = Afetado;
                    }
                    break;
                case Octaedro:
                    if (dist_linha + dist_coluna <= raioMaximo) {
                        afetado = Afetado;
                    }
                    break;
            }
            matriz[i][j] = afetado;
        }
    }
}

//Aplicar Habilidades e Exibir Tabuleiro

void aplicarHabilidade(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro],
                       int origem_l,
                       int origem_c,
                       int matrizHabilidade[TamanhoHabilidade][TamanhoHabilidade]) {
    int raio = TamanhoHabilidade / 2;

    for (int i = 0; i < TamanhoHabilidade; i++) {
        for (int j = 0; j < TamanhoHabilidade; j++)
        {
            int alvo_l = origem_l + (i - raio);
            int alvo_c = origem_c + (j - raio);

            if (alvo_l >= 0 && alvo_l < TamanhoTabuleiro &&
                alvo_c >= 0 && alvo_c < TamanhoTabuleiro &&
                matrizHabilidade[i][j] == Afetado &&
                tabuleiro[alvo_l][alvo_c] != navio)
            {
                tabuleiro[alvo_l][alvo_c] = MarcadeHabilidade;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro]) {
    printf("\n### Tabuleiro Mestre: Habilidades e Navios ###\n");
    printf("    ");
    for (int j = 0; j < TamanhoTabuleiro; j++)
    {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TamanhoTabuleiro; i++)
    {
        printf("%2d |", i);
        for (int j = 0; j < TamanhoTabuleiro; j++){
            int valor = tabuleiro[i][j];

        if (valor == navio){
            printf(" 3 ");
        } else if (valor == MarcadeHabilidade) {
            printf(" 5 ");
        } else {
            printf(" %d ", valor);
            }
        }
        printf("|\n");
    }
    printf("----------------------------------------------------------\n");
    printf("Legenda: 0 = Agua | 3 = Navio | 5 = Area Afetada \n");
}

//Função Main

int main() {

    int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro];
    int matrizHabilidade[TamanhoHabilidade][TamanhoHabilidade];

    InicioTabuleiro(tabuleiro);

//posição dos navios
    tabuleiro[9][6] = navio; tabuleiro[9][7] = navio; tabuleiro[9][8] = navio;
    tabuleiro[1][9] = navio; tabuleiro[2][9] = navio; tabuleiro[3][9] = navio;

//Aplicação das habilidades
    printf("### Habilidades ###\n");

//Cone
    CriarMatrizdeHabilidade(matrizHabilidade, Cone);
    aplicarHabilidade(tabuleiro, 2, 2, matrizHabilidade);
    printf(" Cone aplicado em (2, 2).\n");

//Cruz
    CriarMatrizdeHabilidade(matrizHabilidade, Cruz);
    aplicarHabilidade(tabuleiro, 4, 6, matrizHabilidade);
    printf("Cruz aplicada em (5, 8).\n");

//Octaedro
    CriarMatrizdeHabilidade(matrizHabilidade, Octaedro);
    aplicarHabilidade(tabuleiro, 7, 3, matrizHabilidade);
    printf("Octaedro aplicado em (8, 5).\n");

//Exibir Resultado.
    exibirTabuleiro(tabuleiro);

    return 0;

}