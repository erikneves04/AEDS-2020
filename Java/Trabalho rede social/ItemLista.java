/**
 *
 * @author Erik Neves
 * @date 2020-11-25
*/

public class ItemLista {
    
    private Perfil DadosItem;
    private ItemLista ItemProximo;
    private ItemLista ItemAnterior;
    
    public int InicializarItemLista(Perfil Dados, ItemLista prox, ItemLista ant){
        this.DadosItem = Dados;
        this.ItemProximo = prox;
        this.ItemAnterior = ant;
        
        return Const.Sucesso;
    }
    
    public Perfil GetDadosItem(){
        return this.DadosItem;
    }
    
    public ItemLista GetProximoItemLista(){
        return this.ItemProximo;
    }
    public int SetProximoItemLista(ItemLista prox){
        this.ItemProximo = prox;
        
        return Const.Sucesso;
    }
    
    public ItemLista GetAnteriorItemLista(){
        return this.ItemAnterior;
    }
    public int SetAnteriorItemLista(ItemLista ant){
        this.ItemAnterior = ant;
        
        return Const.Sucesso;
    }
}
