# include <stdio.h>

// Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

//Constantes
    #define TamanhoDoTabuleiro 10
    #define TamanhoDoNavio 3
    const int agua = 0;
    const int navio = 3;
    const int verdadeiro = 1;
    const int falso = 0;

//Inicio do Tabuleiro
    void inciodoTabuleiro(int tabuleiro[TamanhoDoTabuleiro][TamanhoDoTabuleiro]){
        for (int i = 0; i < TamanhoDoTabuleiro; i++) {
            for (int j = 0; j < TamanhoDoTabuleiro; j++) {
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
                linha_atual += i; // Novos navios adicionados
            } else if (orientacao == 'A') {
                linha_atual += i; //Navio diagonal baixo-direita
                coluana_atual += i;
            } else if (orientacao == 'B') {
                linha_atual +i; // navio diagonal baixo-esqueda
                coluana_atual -i;
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
            } else if (orientacao == 'A') {
                linhaEscolha += i; //posição navio diagonal baixo direita
                colunaEscolha += i;
            } else if (orientacao == 'B'){
                linhaEscolha += i; //posição navio diagonal baixo esquerda
                colunaEscolha -= i;
            }
        tabuleiro[linhaEscolha][colunaEscolha] = vetordoNavio[i];
        }
    }

//Exibir Tabuleiro
    void ExibirTabuleiro(int tabuleiro[TamanhoDoTabuleiro][TamanhoDoTabuleiro]){
        printf("\n##### Tabuleiro de Batalha Naval ####\n");
        printf("    ");
        for (int j = 0; j < TamanhoDoTabuleiro; j++){
            printf("%2d ", j);
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
        int navio_vetor[TamanhoDoNavio] = {navio, navio, navio}; // apenas uma variável para o vetor navio

        inciodoTabuleiro(tabuleiro);

//Coordenadas. Houve alteração, novas coordenadas para novos navios.
        // navio 1
        int l1 = 1, c1 = 1;
        //navio 2
        int l2 = 4, c2 = 8;
        //navio 3
        int l3 = 6, c3 = 1;
        //navio 4
        int l4 = 2, c4 = 7;
    
        printf("### Posição ###\n");
//Navio Horizontal
        if (validarPosisao(tabuleiro, l1, c1, 'H') == verdadeiro) {
            posionarNavio(tabuleiro, l1, c1, 'H', navio_vetor);
            printf("Navio Horizontal posicionado em (%d, %d) com sucesso.\n", l1, c1);
        } else {
            printf("Erro ao posicionar Navio Horizontal. \n");
        }
//Navio Vertical
        if (validarPosisao(tabuleiro, l2, c2, 'V') == verdadeiro) {
            posionarNavio(tabuleiro, l2, c2, 'V', navio_vetor);
            printf("Navio vertical Posicionado em (%d, %d) com sucesso.\n", l2, c2);
        } else {
            printf("Erro ao posicionar navio vertical.\n");
        }
//Navio Diagonal Direita-Baixo
        if (validarPosisao(tabuleiro, l3, c3, 'A') == verdadeiro){
            posionarNavio(tabuleiro, l3, c3, 'A', navio_vetor);
            printf("Navio diagonal Baixo Direita em (%d, %d).\n", l3, c3);
        } else {
            printf("Erro ao Posicionar navio diagonal Baixo Direita.\n");
        }
//Navio Diagonal Baixo esquerda
        if (validarPosisao(tabuleiro, l4, c4, 'B') == verdadeiro){
            posionarNavio(tabuleiro, l4, c4, 'B', navio_vetor);
            printf("Navio diagonal Baixo Esquerda em (%d, %d).\n", l4, c4);
        } else {
            printf("Erro ao Posicionar navio diagonal Baixo Esquerda.\n");
        }
        ExibirTabuleiro(tabuleiro);

        return 0;
    }