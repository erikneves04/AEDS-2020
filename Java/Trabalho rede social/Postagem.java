/**
 *
 * @author Erik Neves
 * @date 2020-11-26
*/

public class Postagem {
    
    private int Id;
    private String Conteudo;
    private String Owner;
    public HashTable Curtidas;
    
    public int InserirDadosPostagem(int id,String post,String user){
        this.Id = id;
        this.Conteudo = post;
        this.Owner = user;
        this.Curtidas = new HashTable();
        
        return Const.Sucesso;
    }
    
    public int GetIdPostagem(){
        return this.Id;
    }
    public String GetOwner(){
        return this.Owner;
    }
    
    public int SetTextoPostagem(String NewText){
        this.Conteudo = NewText;
        
        return Const.Sucesso;
    }
    public String GetTextoPostagem(){
        return this.Conteudo;
    }
    
    public int DetalharPostagem(){
        
        System.out.println("\nId: "+this.Id);
        System.out.println("Post: "+this.Conteudo);
        this.Curtidas.ImprimirTodosOsPerfisQueCurtiram();
        
        return Const.Sucesso;
    }
    
}
