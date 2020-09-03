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
    public void Insere_dado(int Dado){
        Item_lista Novo_dado = new Item_lista();
        Item_lista Dados_lista = this.primeiro;
        Item_lista Ultimo_dado = null;
        Boolean UltimoEncontrado = false;

        for(int i=0;i<this.Numero_de_itens;i++){
            if(i == (this.Numero_de_itens - 1) && Dados_lista != null){
                UltimoEncontrado = true;
                Ultimo_dado = Dados_lista;
                break;
            }
            Dados_lista = Dados_lista.GetProximo();
        }

        if(UltimoEncontrado == true){
            Novo_dado.InsereDadosItemLista(this.primeiro,Dado);
            Ultimo_dado.SetProximo(Novo_dado);
        }else{
            Novo_dado.InsereDadosItemLista(Novo_dado,Dado);
        }

        this.Numero_de_itens++;
        this.primeiro = Novo_dado;
    }
    public boolean Remove_dado(int Dado){  
        Item_lista Dados_lista = this.primeiro;
        Item_lista Dado_anterior = null;
        Item_lista Ultimo_dado = null;
        boolean InformacaoEncontrada = false;
        Boolean UltimoEncontrado = false;

        for(int i=0;i<this.Numero_de_itens;i++){
            if(i == (this.Numero_de_itens - 1) && Dados_lista != null){
                UltimoEncontrado = true;
                Ultimo_dado = Dados_lista;
                break;
            }
            Dados_lista = Dados_lista.GetProximo();
        }
        Dados_lista = this.primeiro;
        
        for(int i=0;i<this.Numero_de_itens;i++){
            if(Dados_lista.GetInfo() == Dado){                
                InformacaoEncontrada = true; 
                break;
            }         
            Dado_anterior = Dados_lista;
            Dados_lista = Dados_lista.GetProximo();     
        }
        
        if(InformacaoEncontrada == true){
            this.Numero_de_itens--;
            if(Dado_anterior == null){
                this.primeiro = this.primeiro.GetProximo();
                Ultimo_dado.SetProximo(this.primeiro);
            }else{
                Dado_anterior.SetProximo(Dados_lista.GetProximo());
            }  
        }

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

            System.out.println("Ind.    Dado");
            for(int i=0,j=1;i<this.Numero_de_itens;i++,j++){
                System.out.println(" "+j+"       "+Dados_lista.GetInfo());
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

