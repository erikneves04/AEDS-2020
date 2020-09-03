/**
 *
 * @author Erik Neves
*/

public class Pilha {

    private int Numero_de_itens;
    private Item_pilha primeiro;

    public void Inicializar_pilha(){
        this.Numero_de_itens = 0;
        this.primeiro = null;
    }
    public void Insere_dado(final int Dado) {
        final Item_pilha Novo_dado = new Item_pilha();

        Novo_dado.InsereDadosItemPilha(this.primeiro, Dado);
        this.Numero_de_itens++;
        this.primeiro = Novo_dado;
    }
    public int Remove_dado(){
        int Dado_removido = 0;

        if(this.primeiro != null){
            Dado_removido = this.primeiro.GetDado();
            this.Numero_de_itens--;
            this.primeiro = this.primeiro.GetProximo();
        }

        return Dado_removido;
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
        Item_pilha Dados_lista = this.primeiro;

        if(this.Lista_vazia() != true){
            System.out.println("+---------------------------+");
            System.out.println("| Imprimindo dados da pilha |");
            System.out.println("+---------------------------+\n");

            System.out.println("Ind.    Dado");
            for(int i=0,j=this.Numero_de_itens;i<this.Numero_de_itens;i++,j--){
                System.out.println(" "+j+"       "+Dados_lista.GetDado());
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