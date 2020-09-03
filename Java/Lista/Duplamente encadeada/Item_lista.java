/**
 *
 * @author Erik Neves
 */
public class Item_lista {
    
    private Item_lista proximo;
    private Item_lista anterior;
    private int Info;
    
    public void InsereDadosItemLista(final Item_lista prox,final Item_lista ant, final int valor) {
        this.Info = valor;
        this.proximo = prox;
        this.anterior = ant;
    }

    public void SetInfo(final int NovaInfo) {
        this.Info = NovaInfo;
    }

    public int GetInfo() {
        return this.Info;
    }

    public void SetProximo(final Item_lista prox) {
        this.proximo = prox;
    }
    public Item_lista GetProximo(){
        return this.proximo;
    }
    public void SetAnterior(final Item_lista ant) {
        this.anterior = ant;
    }
    public Item_lista GetAnterior(){
        return this.anterior;
    }

}
