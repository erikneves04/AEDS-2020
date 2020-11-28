/**
 *
 * @author Erik Neves
 * @date 2020-11-25
*/
import java.util.ArrayList;

public class HashTable {
    
    private int NumeroDePerfis = 0;
    private int NumeroDeColunas = 0;
    private ArrayList<ItemLista> DadosTabela = new ArrayList<>();
    
    private int GetIndexPerfil(String user){
        int count = 0;
        byte[] bytes = new byte[user.length()];
        
        bytes = user.getBytes();
        
        for(int i=0;i<bytes.length;i++){
            count += (int)bytes[i];
        }
        
        return (count/10);
    }
    
    public int InserirNovoItem(Perfil NovoPerfil){
        int IndexNovoPerfil = this.GetIndexPerfil(NovoPerfil.GetUserName());
        ItemLista NovoItem = new ItemLista();
        ItemLista DadosColuna;
        
        if(this.NumeroDeColunas < IndexNovoPerfil){
            for(int i = this.NumeroDeColunas;i<IndexNovoPerfil;i++){
                this.DadosTabela.add(i,null);
            }
            this.NumeroDeColunas = IndexNovoPerfil;
        }
        IndexNovoPerfil -= 1;
        if(this.DadosTabela.get(IndexNovoPerfil) == null){
            NovoItem.InicializarItemLista(NovoPerfil, null, null);
            this.DadosTabela.set(IndexNovoPerfil, NovoItem);
        }else{
            DadosColuna = this.DadosTabela.get(IndexNovoPerfil);
            while(DadosColuna.GetProximoItemLista() != null){
                if(DadosColuna.GetProximoItemLista() != null ){
                    DadosColuna = DadosColuna.GetProximoItemLista();
                }
            }
            NovoItem.InicializarItemLista(NovoPerfil,null,DadosColuna);
            DadosColuna.SetProximoItemLista(NovoItem);        
        }
        this.NumeroDePerfis++;
        
        return Const.Sucesso;
    }
    public int RemovePerfilByObjetc(Perfil Alvo){
        int Index = (this.GetIndexPerfil(Alvo.GetUserName()) - 1);
        ItemLista DadosColuna = this.DadosTabela.get(Index);
        
        boolean PerfilEncontrado = false;
        while(DadosColuna != null && !PerfilEncontrado){
            if(DadosColuna.GetDadosItem().equals(Alvo)){
                PerfilEncontrado = true;
                
                if(DadosColuna.GetAnteriorItemLista() == null){
                    if(DadosColuna.GetProximoItemLista() != null){
                        DadosColuna.GetProximoItemLista().SetAnteriorItemLista(null);
                        this.DadosTabela.set(Index, DadosColuna.GetProximoItemLista());
                    }else{
                        this.DadosTabela.set(Index,null);
                    } 
                }else{
                   DadosColuna.GetAnteriorItemLista().SetProximoItemLista(DadosColuna.GetProximoItemLista());
                   if(DadosColuna.GetProximoItemLista() != null){
                       DadosColuna.GetProximoItemLista().SetAnteriorItemLista(DadosColuna.GetAnteriorItemLista());
                   }
                }
                
                break;
            }
            DadosColuna = DadosColuna.GetProximoItemLista();
        }
        
        this.NumeroDePerfis--;
        return (PerfilEncontrado) ? Const.Sucesso : Const.Dado_nao_encontrado;
    }
    private boolean TabelaVazia(){
        return (this.NumeroDePerfis == 0);
    }
    public boolean PerfilExistente(String NomeProcurado){
        boolean PerfilEncontrado = false;
        ItemLista DadosColuna;
        int IndexProcurado = (this.GetIndexPerfil(NomeProcurado) - 1);
        
        if(this.NumeroDeColunas > IndexProcurado){
            DadosColuna = this.DadosTabela.get(IndexProcurado);
            while(DadosColuna != null){
                if(NomeProcurado.equals(DadosColuna.GetDadosItem().GetUserName())){
                    PerfilEncontrado = true;
                    break;
                }
                DadosColuna = DadosColuna.GetProximoItemLista();
            }
        }
        
        return PerfilEncontrado;
    }
    public Perfil GetPerfil(String procurado){
        Perfil PefilAlvo = null;
        ItemLista DadosColuna;
        int Index = (this.GetIndexPerfil(procurado) - 1);
        
        try{
            DadosColuna = this.DadosTabela.get(Index);
        }catch(IndexOutOfBoundsException e){
            return PefilAlvo;
        }
        
        while(DadosColuna != null){
            if(DadosColuna.GetDadosItem().GetUserName().equals(procurado)){
                PefilAlvo = DadosColuna.GetDadosItem();
                break;
            }
            DadosColuna = DadosColuna.GetProximoItemLista();
        }
        
        return PefilAlvo;
    }
    public int ImprimirTodosOsPerfis(){
        ItemLista DadosPerfis;
        
        if(this.TabelaVazia()){
            System.out.println("\n+--------------------------+");
            System.out.println("| Nenhum perfil armazenado |");
            System.out.println("+--------------------------+\n");
        }else{
            System.out.println("\n+--------------------+");
            System.out.println("| Perfis armazenados |");
            System.out.println("+--------------------+");
            System.out.println("| User name:");
            
            for(int i=0;i<this.NumeroDeColunas;i++){
                DadosPerfis = this.DadosTabela.get(i);
                while(DadosPerfis != null){
                    System.out.println("| " +DadosPerfis.GetDadosItem().GetUserName());
                    DadosPerfis = DadosPerfis.GetProximoItemLista();
                }
            }
            System.out.println("");
        }
        
        
        return Const.Sucesso;
    }
    public int ImprimirTodosOsPerfisQueCurtiram(){
        ItemLista DadosPerfis;
        
        if(this.TabelaVazia()){
            System.out.println("\n+----------------------------+");
            System.out.println("| Nenhuma curtida nesse post |");
            System.out.println("+----------------------------+\n");
        }else{
            System.out.println("\n+----------------------+");
            System.out.println("| Perfis que curtiram: |");
            System.out.println("+----------------------+");
            System.out.println("| User name:");
            
            for(int i=0;i<this.NumeroDeColunas;i++){
                DadosPerfis = this.DadosTabela.get(i);
                while(DadosPerfis != null){
                    System.out.println("| " +DadosPerfis.GetDadosItem().GetUserName());
                    DadosPerfis = DadosPerfis.GetProximoItemLista();
                }
            }
            System.out.println("");
        }
        
        
        return Const.Sucesso;
    }
    public int RemoverTodasAsCurtidasDeUmPost(Postagem post){
        ItemLista DadosColuna;
        
        for(int i=0;i< this.NumeroDeColunas;i++){
            DadosColuna = this.DadosTabela.get(i);
            while(DadosColuna != null){
               DadosColuna.GetDadosItem().PostagensCurtidas.RemoverItem(post);
               DadosColuna = DadosColuna.GetProximoItemLista();
            }
        }
         
        return Const.Sucesso;
    }
    public Perfil DeletarPerfil(Perfil AtualUser, Perfil Alvo){
        boolean AtualAlvo = AtualUser.equals(Alvo);
        
        if(Alvo == null) return AtualUser;
        
        // remoção do follow de outros perfis em cima deste
        ItemLista Seguidores = Alvo.Seguidores.GetPrimeiroItem();
        while(Seguidores != null){
            Seguidores.GetDadosItem().Seguindo.RemoverItem(Alvo);
            Seguidores = Seguidores.GetProximoItemLista();
        }
        
        // remoção dos perfis que o alvo segue
        ItemLista Seguindo = Alvo.Seguindo.GetPrimeiroItem();
        while(Seguindo != null){
            Seguindo.GetDadosItem().Seguidores.RemoverItem(Alvo);
            Seguindo = Seguindo.GetProximoItemLista();
        }
        
        // remoção do index desse perfil em postagens que ele curtiu
        ItemListaPost PostagensCurtidas = Alvo.PostagensCurtidas.GetPrimeiroItem();
        while(PostagensCurtidas != null){
            PostagensCurtidas.GetDadosItem().Curtidas.RemovePerfilByObjetc(Alvo);
            PostagensCurtidas = PostagensCurtidas.GetProximoItemLista();
        }
        
        // remoção do index das postagens de perfis que a curtiram
        ItemListaPost Postagens = Alvo.Postagens.GetPrimeiroItem();
        while(Postagens != null){
            Postagens.GetDadosItem().Curtidas.RemoverTodasAsCurtidasDeUmPost( Postagens.GetDadosItem());
            Postagens = Postagens.GetProximoItemLista();
        }
        
        this.RemovePerfilByObjetc(Alvo);
        return (!AtualAlvo) ? AtualUser : null;
    }
}
