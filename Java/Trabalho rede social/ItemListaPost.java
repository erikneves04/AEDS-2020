/**
 *
 * @author Erik Neves
 * @date 2020-11-26
*/

public class ItemListaPost {
    private Postagem DadosItem;
    private ItemListaPost ItemProximo;
    private ItemListaPost ItemAnterior;
    
    public int InicializarItemLista(Postagem Dados, ItemListaPost prox, ItemListaPost ant){
        this.DadosItem = Dados;
        this.ItemProximo = prox;
        this.ItemAnterior = ant;
        
        return Const.Sucesso;
    }
    
    public Postagem GetDadosItem(){
        return this.DadosItem;
    }
    
    public ItemListaPost GetProximoItemLista(){
        return this.ItemProximo;
    }
    public int SetProximoItemLista(ItemListaPost prox){
        this.ItemProximo = prox;
        
        return Const.Sucesso;
    }
    
    public ItemListaPost GetAnteriorItemLista(){
        return this.ItemAnterior;
    }
    public int SetAnteriorItemLista(ItemListaPost ant){
        this.ItemAnterior = ant;
        
        return Const.Sucesso;
    }
}
