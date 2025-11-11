# include <stdio.h>

// Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

//Constantes
    #define TamanhoDoTabuleiro 10;
    #define TamanhoDoNavio 3;
    const int agua = 0;
    const int navio = 3;
    const int verdadeiro = 1;
    const int falso = 0;

//Inicio do Tabuleiro
    void inciodoTabuleiro(int tabuleiro[TamanhoDoTabuleiro][TamanhoDoTabuleiro]){
        for (int i = 0; i < TamanhoDoTabuleiro; i++){
            for (int j = 0; j < TamanhoDoTabuleiro; j++){
                tabuleiro[i][j] = agua;
            }
        }
    }

//Validação da posição do navio
    int validarPosisao(int tabuleiro[TamanhoDoTabuleiro][TamanhoDoTabuleiro],
                        int linhaInicial,
                        int colunaInicial,
                        char orientacao) {
        for (int i = 0; i < TamanhoDoNavio; i++){
            int linha_atual = linhaInicial;
            int coluana_atual = colunaInicial;

            if (orientacao == 'H') {
                coluana_atual += i;
            } else if (orientacao == 'V') {
                linha_atual += i;
            } else {
                return falso; //Orientação inválida
            }
//Verificando se a linha é válida
            if (linha_atual >= TamanhoDoTabuleiro || coluana_atual >= TamanhoDoTabuleiro || 
            linha_atual < 0 || coluana_atual < 0) {
            return falso;
        }
//Verificar se existe Sobreposição
            if (tabuleiro[linha_atual][coluana_atual] == navio) {
                return falso;
            }
        }
        return verdadeiro; //Se tudo estiver certo no loop, retorna o verdadeiro
    }

//Marcando a posição do navio.
    void posionarNavio(int tabuleiro[TamanhoDoTabuleiro][TamanhoDoTabuleiro],
                        int linhaInicial,
                        int colunaInicial,
                        char orientacao,
                        const int vetordoNavio[]){
    for (int i = 0; i < TamanhoDoNavio; i++){
        int linhaEscolha = linhaInicial;
        int colunaEscolha = colunaInicial;

            if (orientacao == 'H'){
                colunaEscolha += i;
            } else if (orientacao == 'V'){
                linhaEscolha += i;
            }
        tabuleiro[linhaEscolha][colunaEscolha] = vetordoNavio[i];
        }
    }

//Exibir Tabuleiro
    void ExibirTabuleiro(int tabuleiro[TamanhoDoTabuleiro][TamanhoDoTabuleiro]){
        printf("\n##### Tabuleiro de Batalha Naval ####\n");
        printf("   ");
        for (int j = 0; j < TamanhoDoTabuleiro; j++){
            printf("%2d", j);
        }
        printf("\n");

        for (int i = 0; i < TamanhoDoTabuleiro; i++) {
            printf("%2d |", i);
            for (int j = 0; j < TamanhoDoTabuleiro; j++) {
                printf("%2d ", tabuleiro[i][j]);
            }
            printf("|\n");
        }
        printf("--------------------------------------\n");
        printf("Legenda: %d = Agua | %d = Navio\n", agua, navio);
    }

    int main() {
        int tabuleiro[TamanhoDoTabuleiro][TamanhoDoTabuleiro];
        int navioHorizontal_vetor[TamanhoDoNavio] = {navio, navio, navio};
        int navioVertical_vetor[TamanhoDoNavio] = {navio, navio, navio};

        inciodoTabuleiro(tabuleiro);

//Coordenadas
        int linhaN1 = 1;
        int colunaN1 = 2;
        int linhaN2 = 4;
        int colunaN2 = 3;
    
        printf("### Posição ###\n");
//Navio Horizontal
        if (validarPosisao(tabuleiro, linhaN1, colunaN1, 'H') == verdadeiro) {
            posionarNavio(tabuleiro, linhaN1, colunaN1, 'H', navioHorizontal_vetor);
            printf("Navio Horizontal posicionado em (%d, %d) com sucesso.\n", linhaN1, colunaN1);
        } else {
            printf("Erro ao posicionar Navio Horizontal. \n");
        }
//Navio Vertical
        if (validarPosisao(tabuleiro, linhaN2, colunaN2, 'V') == verdadeiro) {
            posionarNavio(tabuleiro, linhaN2, colunaN2, 'V', navioVertical_vetor);
            printf("Navio vertical Posicionado em (%d, %d) com sucesso.\n", linhaN2, colunaN2);
        } else {
            printf("Erro ao posicionar navio vertical.\n");
        }
        ExibirTabuleiro(tabuleiro);

        return 0;
    }