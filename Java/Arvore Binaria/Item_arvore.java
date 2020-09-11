/**
 *
 * @author Erik Neves
 */

public class Item_arvore {

    private int Dado;
    private Item_arvore Direita;
    private Item_arvore Esquerda;
   
    public void InserirDadosArvore(int DadoAux,Item_arvore EsquerdaAux,Item_arvore DireitaAux){
        this.Dado = DadoAux;
        this.Direita = DireitaAux;
        this.Esquerda = EsquerdaAux;
    }

    public int GetDado(){
        return this.Dado;
    }
    public void SetDado(int DadoAux){
        this.Dado = DadoAux;
    }

    public Item_arvore GetArvoreDireita(){
        return this.Direita;
    }
    public void SetArvoreDireita(Item_arvore DireitaAux){
        this.Direita = DireitaAux;
    }

    public Item_arvore GetArvoreEsquerda(){
        return this.Esquerda;
    }
    public void SetArvoreEsquerda(Item_arvore EsquerdaAux){
        this.Esquerda = EsquerdaAux;
    }

}   