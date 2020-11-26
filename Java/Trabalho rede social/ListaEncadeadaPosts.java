/**
 *
 * @author Erik Neves
 * @date 2020-11-26
*/

public class ListaEncadeadaPosts {
    private ItemListaPost Primeiro;
    private int NumeroDeItens;
    
    public int InicializarListaEncadeada(){
        this.Primeiro = null;
        this.NumeroDeItens = 0;
        
        return Const.Sucesso;
    }
    public ItemListaPost GetPrimeiroItem(){
        return this.Primeiro;
    }
    
    public int InserirNovoItem(Postagem NovaPostagem){
        ItemListaPost NovoItem = new ItemListaPost();
        
        if(this.Primeiro != null){
            this.Primeiro.SetAnteriorItemLista(NovoItem);
        }
        NovoItem.InicializarItemLista(NovaPostagem, this.Primeiro, null);
        this.Primeiro = NovoItem;
        this.NumeroDeItens++;
        
        return Const.Sucesso;
    }
    public int RemoverItem(Postagem PostagemAlvo){
        ItemListaPost DadosPerfis = this.Primeiro;
        boolean DadoEncontrado = false;
        
        
        for(int i=0;i<this.NumeroDeItens;i++){
            if(PostagemAlvo.equals(DadosPerfis.GetDadosItem())){
                if(DadosPerfis.GetAnteriorItemLista() == null){
                    this.Primeiro = this.Primeiro.GetProximoItemLista();
                    if(this.Primeiro != null) this.Primeiro.SetAnteriorItemLista(null);
                }else{
                    DadosPerfis.GetAnteriorItemLista().SetProximoItemLista(DadosPerfis.GetProximoItemLista());
                    if(DadosPerfis.GetProximoItemLista() != null){
                        DadosPerfis.GetProximoItemLista().SetAnteriorItemLista(DadosPerfis.GetAnteriorItemLista());
                    }
                } 
                this.NumeroDeItens--;
                DadoEncontrado = true;
                break;
            }
            DadosPerfis = DadosPerfis.GetProximoItemLista();
        }
        
        if(!DadoEncontrado){
            return Const.Dado_nao_encontrado;
        }
        
        return Const.Sucesso;
    }
    public boolean ListaVazia(){
        return(this.NumeroDeItens == 0);
    }
    public boolean DadoContido(Postagem Post){
        boolean DadoEncontrado = false;
        ItemListaPost DadosLista = this.Primeiro;
        
        if(Post == null) return DadoEncontrado;
        
        for(int i=0;i<this.NumeroDeItens;i++){
            if(Post.equals(DadosLista.GetDadosItem())){
                DadoEncontrado = true;
                break;
            }
            DadosLista = DadosLista.GetProximoItemLista();
        }
        
        return DadoEncontrado;
    }
    public int ImprimirPostsDaLista(Perfil AtualUser){
        ItemListaPost DadosLista = this.Primeiro;
        
        if(!this.ListaVazia()){
            System.out.println("+-----------------------------------------+");
            System.out.println("| Estes sao os posts existentes na lista: |");
            System.out.println("+-----------------------------------------+");
            for(int i=0;i<this.NumeroDeItens;i++){
                System.out.println("| Id: " + DadosLista.GetDadosItem().GetIdPostagem());
                System.out.println("| Post: " + DadosLista.GetDadosItem().GetTextoPostagem());
                if(AtualUser != null){    
                    if(DadosLista.GetDadosItem().Curtidas.PerfilExistente(AtualUser.GetUserName())){
                        System.out.println("| -> Voce curtiu essa postagem.");
                    }
                }
                DadosLista = DadosLista.GetProximoItemLista();
                System.out.println("+--------");
            }
        }else{
            System.out.println("+---------------------------------+");
            System.out.println("| Nao ha nenhum post nesta lista! |");
            System.out.println("+---------------------------------+");
        }
        System.out.println("");
        
        return Const.Sucesso;
    }
    public Postagem GetPostagem(int id){
        Postagem procurada = null;
        ItemListaPost DadosLista = this.Primeiro;
        
        for(int i=0;i<this.NumeroDeItens;i++){
            if(DadosLista.GetDadosItem().GetIdPostagem() == id){
                procurada = DadosLista.GetDadosItem();
                break;
            }
            DadosLista = DadosLista.GetProximoItemLista();
        }
        
        return procurada;
    }
}
