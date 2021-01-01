/**
 *         Hash table made from linked lists with collision handling.
 * You can request a column and you will receive a linked list containing your data,
 *         changing this list will also change the data in the table.
 * @author Erik Neves
 * @param <DataType>
 */
public class HashTable<DataType> {
    
    private int NumeroDeColunas = 0;
    public boolean state = false;
    private ListaEncadeada<DataType>[] Datas;
    
    /**
     * Method responsible for return integer equivalent to the number of columns.
     * @return Number of columns.
    */
    public int GetNColumns(){return this.NumeroDeColunas;}
    
    /**
     * Method responsible for add a new object to the hash table.
     * @param NewData The object to be stored.
     * @param HashCode Hash code of the object.
     * @throws IndexOutOfBoundsException if HashCode is less than 0.
    */
    public void add(DataType NewData, int HashCode) throws IndexOutOfBoundsException{       
        if(HashCode < 0){throw new IndexOutOfBoundsException("Hash codes less than zero are not accepted.(index: "+HashCode+")");}
        if(this.NumeroDeColunas == 0 || HashCode > this.NumeroDeColunas){
            ListaEncadeada<DataType>[] NewVector = new ListaEncadeada[HashCode];
            if(this.Datas != null){System.arraycopy(this.Datas,0,NewVector,0,this.NumeroDeColunas);}
            for(int i= this.NumeroDeColunas;i<HashCode;i++){NewVector[i] = new ListaEncadeada<>();}
            
            this.Datas = NewVector;
            this.NumeroDeColunas = HashCode;
        }
        this.getColumn(HashCode).add(NewData);
    }
    
    /**
     * Method responsible for remove an item from the table.
     * @param Target Object to have its reference removed from the table.
     * @param HashCode Hash code of the object.
     * @return true if the data has been found and removed.
     * @throws IndexOutOfBoundsException if HashCode is less than 0 or HashCode is greater than the number of columns in the table.
    */
    public boolean remove(DataType Target, int HashCode) throws IndexOutOfBoundsException{
        if(HashCode < 0 || HashCode > this.NumeroDeColunas){throw new IndexOutOfBoundsException("HashTable size: "+this.NumeroDeColunas+" HashCode: "+HashCode);}
        ListaEncadeada<DataType> ColunaHash = this.getColumn(HashCode);
        boolean Removed = false;
        
        if(ColunaHash.ExistingData(Target)){
            ColunaHash.remove(Target);
            Removed = true;
        }
    
        return Removed;
    }
    
    /**
     * Method responsible for find and return a reference to items in a table column.
     * @param HashCode Column hash code.
     * @return Linked list containing the elements of that hash code.
     * @throws IndexOutOfBoundsException if HashCode is less than 0 or HashCode is greater than the number of columns in the table.
    */
    public ListaEncadeada<DataType> getColumn(int HashCode) throws IndexOutOfBoundsException{
        if(HashCode < 0 || HashCode > this.NumeroDeColunas){throw new IndexOutOfBoundsException("HashTable size: "+this.NumeroDeColunas+" HashCode: "+HashCode);}
        return this.Datas[HashCode - 1];
    }
    
}
