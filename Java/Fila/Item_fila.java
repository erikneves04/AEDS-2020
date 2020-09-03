/**
 *
 * @author Erik Neves
 */

public class Item_fila {

    private int Dado;
    private Item_fila proximo;
    private Item_fila anterior;

    public void InserirItemFila(Item_fila prox,Item_fila ant,int Rdado){
        this.Dado = Rdado;
        this.proximo = prox;
        this.anterior = ant;
    }

    public void SetDado(int Rdado){
        this.Dado = Rdado;
    }
    public int GetDado(){
        return this.Dado;
    }

    public void SetProximo(Item_fila prox){
        this.proximo = prox;
    }
    public Item_fila GetProximo(){
        return this.proximo;
    }
    
    public void SetAnterior(Item_fila ant){
        this.anterior = ant;
    }
    public Item_fila GetAnterior(){
        return this.anterior;
    }
}