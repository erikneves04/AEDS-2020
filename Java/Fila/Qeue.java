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
}