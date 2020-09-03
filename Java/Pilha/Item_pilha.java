/**
 *
 * @author Erik Neves
 */

public class Item_pilha {

    private int Dado;
    private Item_pilha proximo;

    public void InsereDadosItemPilha(Item_pilha prox,int Rdado){
        this.Dado = Rdado;
        this.proximo = prox;
    }

    public void SetDado(int Rdado){
        this.Dado = Rdado;
    }
    public int GetDado(){
        return this.Dado;
    }

    public void SetProximo(Item_pilha prox){
        this.proximo = prox;
    }
    public Item_pilha GetProximo(){
        return this.proximo;
    }
}