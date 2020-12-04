
import java.io.Serializable;

/**
 *
 * @author Erik Neves
 * @date 2020-11-28
*/

public class SaveModel implements Serializable{
    
    private String NomeCompleto;
    private String UserName;
    private int Id;
    private int NumeroDePostagens;
    private int NumeroDePerfisSeguidos;
    
    public int InicializarDados(String Nome, String UserName, int Id, int NumPosts, int NumFollows){
        this.NomeCompleto = Nome;
        this.UserName = UserName;
        this.Id = Id;
        this.NumeroDePostagens = NumPosts;
        this.NumeroDePerfisSeguidos = NumFollows;
        
        return Const.Sucesso;
    }

    public String GetNomeCompleto(){return this.NomeCompleto;}
    public String GetNomeUsuario(){return this.UserName;}
    public int GetId() {return this.Id;}
    public int GetNumeroDePostagens(){return this.NumeroDePostagens;}
    public int GetNumeroDePerfisSeguidos(){return this.NumeroDePerfisSeguidos;}
    public int ImprimirDados(){
        
        System.out.println();
        System.out.println(this.Id);
        System.out.println(this.NomeCompleto);
        System.out.println(this.NumeroDePerfisSeguidos);
        System.out.println(this.NumeroDePostagens);
        System.out.println(this.UserName);
        System.out.println();
        
        return Const.Sucesso;
    }
}

/* -> Codigo base em C
typedef struct EstruturaBin{
    char Biografia[Tamanho_MAX_bio];
    char NomeCompleto[Tamanho_MAX_NomeCompleto];
    char NomeUsuario[Tamanho_MAX_usuario];
    unsigned int PerfilID;
    int NumPosts;
    unsigned int NumFollows;
}StructFiles;
*/