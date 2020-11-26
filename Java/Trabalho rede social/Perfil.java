/**
 *
 * @author Erik Neves
 * @date 2020-11-25
*/

public class Perfil {
    
    private int Id;
    private String NomeCompleto;
    private String NomeUsuario;
    public ListaEncadeadaPerfis Seguindo;
    public ListaEncadeadaPerfis Seguidores;
    public ListaEncadeadaPosts Postagens;
    
    public int SetInformacoesPerfil(int ID, String NCompleto, String NUser, boolean Inicializando){
        this.Id = ID;
        this.NomeCompleto = NCompleto;
        this.NomeUsuario = NUser;
        
        if(Inicializando){
            Seguindo = new ListaEncadeadaPerfis();
            Seguindo.InicializarListaEncadeada();
            Seguidores = new ListaEncadeadaPerfis();
            Seguidores.InicializarListaEncadeada();
            Postagens = new ListaEncadeadaPosts();
            Postagens.InicializarListaEncadeada();
        }
        
        return Const.Sucesso;
    }
    
    public int GetIdPerfil(){
        return this.Id;
    }
    
    public String GetUserName(){
        return this.NomeUsuario;
    }
    public int SetUserName(String NewName){
        this.NomeUsuario = NewName;
        
        return Const.Sucesso;
    }
    
    public String GetNomeCompleto(){
        return this.NomeCompleto;
    }
    public int SetNomeCompleto(String NewName){
        this.NomeCompleto = NewName;
        
        return Const.Sucesso;
    }
    
    public int ImprimirDadosPerfil(){
        System.out.println("Identificador do perfil: " + this.Id);
        System.out.println("Nome completo: " + this.NomeCompleto);
        System.out.println("Nome de usuario " + this.NomeUsuario);
        return Const.Sucesso;
    }
}