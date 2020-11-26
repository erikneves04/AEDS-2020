/**
 *
 * @author Erik Neves
 * @date 2020-11-25
*/

public class ListaEncadeadaPerfis {
    
    private ItemLista Primeiro;
    private int NumeroDeItens;
    
    public int InicializarListaEncadeada(){
        this.Primeiro = null;
        this.NumeroDeItens = 0;
        
        return Const.Sucesso;
    }
    public ItemLista GetPrimeiroItem(){
        return this.Primeiro;
    }
    
    public int InserirNovoItem(Perfil NovoPerfil){
        ItemLista NovoItem = new ItemLista();
        
        if(this.Primeiro != null){
            this.Primeiro.SetAnteriorItemLista(NovoItem);
        }
        NovoItem.InicializarItemLista(NovoPerfil, this.Primeiro, null);
        this.Primeiro = NovoItem;
        this.NumeroDeItens++;
        
        return Const.Sucesso;
    }
    public int RemoverItem(Perfil PerfilAlvo){
        ItemLista DadosPerfis = this.Primeiro;
        boolean DadoEncontrado = false;
        
        
        for(int i=0;i<this.NumeroDeItens;i++){
            if(PerfilAlvo.equals(DadosPerfis.GetDadosItem())){
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
    public boolean DadoContido(Perfil PerfilProcurado){
        boolean DadoEncontrado = false;
        ItemLista DadosLista = this.Primeiro;
        
        for(int i=0;i<this.NumeroDeItens;i++){
            if(PerfilProcurado.equals(DadosLista.GetDadosItem())){
                DadoEncontrado = true;
                break;
            }
            DadosLista = DadosLista.GetProximoItemLista();
        }
        
        return DadoEncontrado;
    }
    public int ImprimirPerfisDaLista(){
        ItemLista DadosLista = this.Primeiro;
        
        if(!this.ListaVazia()){
            System.out.println("+------------------------------------------+");
            System.out.println("| Estes sao os perfis existentes na lista: |");
            System.out.println("+------------------------------------------+");

            System.out.println("| Nome de usuario: ");
            for(int i=0;i<this.NumeroDeItens;i++){
                System.out.println("| " + DadosLista.GetDadosItem().GetUserName());
                DadosLista = DadosLista.GetProximoItemLista();
            }
        }else{
            System.out.println("+-----------------------------------+");
            System.out.println("| Nao ha nenhum perfil nesta lista! |");
            System.out.println("+-----------------------------------+");
        }
        System.out.println("");
        return Const.Sucesso;
    }
    
}
