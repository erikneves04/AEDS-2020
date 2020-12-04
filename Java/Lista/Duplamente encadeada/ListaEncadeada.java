/**
 * A double-linked list that encapsulates its elements and facilitates access to them,
 *                  facilitating hash tables for example.
 * @author Erik Neves
 * @param <DataType> Type of data that will be stored and manipulated.
 */
public class ListaEncadeada<DataType>{  
    private int NumeroDeItens = 0;
    private ItemLista<DataType> primeiro = null;
    
    /**
     * Method responsible for return the number of elements in the list
     * @return Number of list elements.
    */
    public int GetNElements(){return this.NumeroDeItens;}
    
    /**
     * Method responsible for add new data at the beginning of the list.
     * @param NewData The object to be stored.
    */
    public void add(DataType NewData){
        this.add(NewData,0);
    }
    
    /**
     * Method responsible for add new data at the position indicated in index.
     * @param NewData The object to be stored.
     * @param index Element position.
     * @throws IndexOutOfBoundsException if index is less than 0 or index is greater than the number of itensin the list + 1.
    */
    public void add(DataType NewData, int index) throws IndexOutOfBoundsException{
        if(index < 0 || index > (this.NumeroDeItens + 1)){
            throw new IndexOutOfBoundsException("List size: "+this.NumeroDeItens+" index: "+index);
        }
        
        ItemLista<DataType> NovoItem =  new ItemLista<>();
        if(index == 0){
            if(this.primeiro != null){this.primeiro.SetAnterior(NovoItem);}
            NovoItem.InicializarItem(NewData, this.primeiro, null);
            this.primeiro = NovoItem;
        }else{
            DataType DadoAnterior = this.GetDataIndex(index-1);
            ItemLista<DataType> DadosLista = this.primeiro;
            for(int i=0;i<this.NumeroDeItens;i++){
                if(DadosLista.GetDadosItem().equals(DadoAnterior)){break;}
                DadosLista = DadosLista.GetProximo();
            }
            
            DadosLista.SetProximo(NovoItem);
            if(DadosLista.GetProximo() != null){DadosLista.GetProximo().SetAnterior(NovoItem);}
            NovoItem.InicializarItem(NewData,DadosLista.GetProximo(), DadosLista);
        }
        this.NumeroDeItens++;
    }
    
    /**
     * Method responsible for remove an object from the list.
     * @param DataAlvo Target. 
    */
    public void remove(DataType DataAlvo){
        ItemLista<DataType> DadosLista = this.primeiro;
        
        for(int i=0;i<this.NumeroDeItens;i++){
            if(DataAlvo.equals(DadosLista.GetDadosItem())){       
                if(DadosLista.GetAnterior() == null){
                    if(this.primeiro.GetProximo() != null){this.primeiro.GetProximo().SetAnterior(null);}
                    this.primeiro = this.primeiro.GetProximo();
                }else{
                    DadosLista.GetAnterior().SetProximo(DadosLista.GetProximo());
                    if(DadosLista.GetProximo() != null){DadosLista.GetProximo().SetAnterior(DadosLista.GetAnterior());}
                }
                
                this.NumeroDeItens--;
                break;
            }
            DadosLista = DadosLista.GetProximo();
        }
    }
    
    /**
     * Method responsible for removes an object from its index in the list.
     * @param index Position of the object.
     * @throws IndexOutOfBoundsException if index is less than 0 or index is greater than the number of itensin the list.
    */
    public void remove(int index) throws IndexOutOfBoundsException{
        if(index < 0 || index > this.NumeroDeItens ){
            throw new IndexOutOfBoundsException("List size: "+this.NumeroDeItens+" index: "+index);
        }
        
        ItemLista<DataType> DadosLista = this.primeiro;
        for(int i=0;i<index;i++){
            DadosLista = DadosLista.GetProximo();
        }
        
        if(DadosLista == null){return;}   
        this.remove(DadosLista.GetDadosItem()); 
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