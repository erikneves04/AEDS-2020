/**
 *
 * @author Erik Neves
*/

public class Lista {
    
    private Item_lista primeiro;
    private int Numero_de_itens;

    public void Inicializar_lista(){
        this.Numero_de_itens = 0;
        this.primeiro = null;
    }
    public void Insere_dado(final int Dado) {
        final Item_lista Novo_dado = new Item_lista();

        Novo_dado.InsereDadosItemLista(this.primeiro,null, Dado);
        if(this.primeiro != null){
            this.primeiro.SetAnterior(Novo_dado);
        }
        this.Numero_de_itens++;
        this.primeiro = Novo_dado;
    }
    public boolean Remove_dado(final int Dado) {
        Item_lista Dados_lista = this.primeiro;
        boolean InformacaoEncontrada = false;
        
        for(int i=0;i<this.Numero_de_itens;i++){
            if(Dados_lista.GetInfo() == Dado){                
                InformacaoEncontrada = true;
                break;
            }         
            Dados_lista = Dados_lista.GetProximo();     
        }

        if(Dados_lista.GetAnterior() == null){
            this.primeiro = this.primeiro.GetProximo();
            if(this.primeiro != null){
                this.primeiro.SetAnterior(null);
            }
        }else{
            Dados_lista.GetAnterior().SetProximo(Dados_lista.GetProximo());
            if(Dados_lista.GetProximo() != null){
                Dados_lista.GetProximo().SetAnterior(Dados_lista.GetAnterior());
            }
        }       
        this.Numero_de_itens--;
        
        return InformacaoEncontrada;
    }
    public boolean Lista_vazia(){
        boolean EstadoLista;

        if(this.Numero_de_itens == 0 && this.primeiro == null){
            EstadoLista = true;
        }else{
            EstadoLista = false;
        }

        return EstadoLista;
    }
    public void Imprimir_lista(){
        Item_lista Dados_lista = this.primeiro;

        if(this.Lista_vazia() != true){
            System.out.println("+---------------------------+");
            System.out.println("| Imprimindo dados da lista |");
            System.out.println("+---------------------------+\n");

            System.out.println("Ind.    Dado    Ant.");
            for(int i=0,j=1;i<this.Numero_de_itens;i++,j++){
                if(Dados_lista.GetAnterior() == null){
                    System.out.println(" "+j+"       "+Dados_lista.GetInfo()+"      null");
                }else{
                    System.out.println(" "+j+"       "+Dados_lista.GetInfo()+"       "+Dados_lista.GetAnterior().GetInfo());
                }
                Dados_lista = Dados_lista.GetProximo();
            }
        }else{
            System.err.println("\n| Lista Vazia |\n");
        }
    }
    public void Limpar_lista(){
        this.Numero_de_itens = 0;
        this.primeiro = null;
    }

}

