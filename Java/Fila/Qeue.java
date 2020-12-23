/**
 * A queue made from a doubly linked list.
 * @author Erik Neves
 * @param <DataType> Type of data that will be stored and manipulated.
 */
public class Queue<DataType>{  
    private int NumeroDeItens = 0;
    private ItemLista<DataType> primeiro = null;
    
    /**
     * Method responsible for return the number of elements in the list
     * @return Number of list elements.
    */
    public int GetNElements(){return this.NumeroDeItens;}
    
    /**
     * Method responsible for add new data at the end of the row.
     * @param NewData The object to be stored.
    */
    public void add(DataType NewData){       
        ItemLista<DataType> NovoItem =  new ItemLista<>();
        try{
            DataType DadoAnterior = this.GetDataIndex(this.NumeroDeItens);
            ItemLista<DataType> DadosLista = this.primeiro;
            for(int i=0;i<this.NumeroDeItens;i++){
                if(DadosLista.GetDadosItem().equals(DadoAnterior)){break;}
                DadosLista = DadosLista.GetProximo();
            }

            DadosLista.SetProximo(NovoItem);
            if(DadosLista.GetProximo() != null){DadosLista.GetProximo().SetAnterior(NovoItem);}
            NovoItem.InicializarItem(NewData,DadosLista.GetProximo(), DadosLista);
        }catch(IndexOutOfBoundsException exception){
            this.primeiro = NovoItem;
            NovoItem.InicializarItem(NewData,null, null);
        }
        
        this.NumeroDeItens++;
    }
    
    /**
     * Method responsible for remove the first item from a queue
     * @return reference to the removed object.
     * @throws IllegalStateException when trying to remove something from an empty list.
    */
    public DataType remove() throws IllegalStateException{
        
        if(this.EmptyList()){throw new IllegalStateException("Empty list");}
        
        if(this.primeiro == null){return null;}
        DataType DadosItem = this.primeiro.GetDadosItem();
        
        if(this.primeiro.GetProximo() != null){this.primeiro.GetProximo().SetAnterior(null);}
        this.primeiro = this.primeiro.GetProximo();
        this.NumeroDeItens--;
        
        return DadosItem;
    }
    
    /**
     * Method responsible for check if there is any data in the list.
     * @return true if the list is empty or false if it is not.
    */
    public boolean EmptyList(){return (this.NumeroDeItens == 0);}
    
    /**
     * Method responsible for replace the data stored in a certain position.
     * @param NewData The object to be stored.
     * @param index Element position.
     * @throws IndexOutOfBoundsException if index is less than 0 or index is greater than the number of itensin the list.
    */
    public void SetDataindex(DataType NewData, int index) throws IndexOutOfBoundsException{
        if(index < 0 || index > this.NumeroDeItens ){
            throw new IndexOutOfBoundsException("List size: "+this.NumeroDeItens+" index: "+index);
        }
        if(this.EmptyList()){
            throw new IndexOutOfBoundsException("Empty list");
        }
        
        ItemLista<DataType> DadosLista = this.primeiro;
        for(int i=0;i<index;i++){
            DadosLista = DadosLista.GetProximo();
        }
        
        DadosLista.SetDadosItem(NewData);
    }
    
    /**
     * Method responsible for locate the object at the specified position.
     * @param index Element position.
     * @return The object.
     * @throws IndexOutOfBoundsException if index is less than 0 or index is greater than the number of itensin the list.
    */
    public DataType GetDataIndex(int index) throws IndexOutOfBoundsException{
        if(index < 0 || index > this.NumeroDeItens ){
            throw new IndexOutOfBoundsException("List size: "+this.NumeroDeItens+" index: "+index);
        }
        if(this.EmptyList()){
            throw new IndexOutOfBoundsException("Empty list");
        }
        
        ItemLista<DataType> DadosLista = this.primeiro;
        for(int i=0;i<index;i++){
            if(DadosLista.GetProximo() != null)DadosLista = DadosLista.GetProximo();
        }
        return DadosLista.GetDadosItem();
    }   

    /**
     * List item responsible for encapsulating data DataType and allowing this reference of the 
     *                          anterior and posterior.
     * @author Erik Neves
     * @param <DataType> Type of data that will be stored and manipulated.
    */
    private class ItemLista<DataType> { 
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
}