/**
 * List item responsible for encapsulating data DataType and allowing this reference of the 
 *                          anterior and posterior.
 * @author Erik Neves
 * @param <DataType> Type of data that will be stored and manipulated.
 */
public class ItemLista<DataType> { 
    private DataType dados;
    private ItemLista<DataType> proximo;
    private ItemLista<DataType> anterior;
    
    /**
     * Method responsible for initialize the data for this object.
     * @param Data The object to be stored.
     * @param prox Item after the current item.
     * @param ant Item before the current item.
     */
    public void InicializarItem(DataType Data, ItemLista<DataType> prox, ItemLista<DataType> ant){
        this.dados = Data;
        this.proximo = prox;
        this.anterior = ant;
    }
    
    /**
     * Method responsible for replace the currently saved object with another one.
     * @param NewDados New object.
     */
    public void SetDadosItem(DataType NewDados){this.dados = NewDados;}
    /**
     * Method responsible for return an object stored in the list.
     * @return The object with the data.
     */
    public DataType GetDadosItem(){return this.dados;}
    
    /**
     * Method responsible for replace the reference of the next list item.
     * @param prox Next item to be indexed.
     */
    public void SetProximo(ItemLista<DataType> prox){this.proximo = prox;}
    /**
     * Method responsible for return the next referenced item.
     * @return Next item.
     */
    public ItemLista<DataType> GetProximo(){return this.proximo;}
    
    /**
     * Method responsible for replaces the reference of the previous item.
     * @param ant Previous item to be indexed.
     */
    public void SetAnterior(ItemLista<DataType> ant){this.anterior = ant;}
    /**
     * Method responsible for return a reference to the previous item in the list.
     * @return Previous item.
     */
    public ItemLista<DataType> GetAnterior(){return this.anterior;}  
}
