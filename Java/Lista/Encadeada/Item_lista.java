/**
 *
 * @author Erik Neves
 */
public class Item_lista {
    
    private Item_lista proximo;
    private int Info;
    
    public void InsereDadosItemLista(final Item_lista prox, final int valor) {
        this.Info = valor;
        this.proximo = prox;
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

}
