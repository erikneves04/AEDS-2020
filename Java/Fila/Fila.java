/**
 *
 * @author Erik Neves
*/

public class Fila {

    private int Numero_de_itens;
    private Item_fila primeiro;
    private Item_fila ultimo;

    public void Inicializar_fila(){
        this.Numero_de_itens = 0;
        this.primeiro = null;
        this.ultimo = null;
    }
    public void Insere_dado(final int Dado) {
        final Item_fila Novo_dado = new Item_fila();
        this.Numero_de_itens++;

        if(ultimo == null){
            this.primeiro = Novo_dado;
            this.ultimo = Novo_dado;
            Novo_dado.InserirItemFila(null,null,Dado);
        }else{
            Novo_dado.InserirItemFila(this.ultimo,null,Dado);
            this.ultimo.SetAnterior(Novo_dado);
            this.ultimo = Novo_dado;
        }
    }
    public int Remove_dado(){
        int Dado_removido = 0;

        if(this.ultimo != null){
            this.Numero_de_itens--;
            Dado_removido = this.primeiro.GetDado();
            this.primeiro = this.primeiro.GetAnterior();
            this.primeiro.SetProximo(null);
        }
        return Dado_removido;
    }
    public boolean Lista_vazia(){
        boolean EstadoLista;

        if(this.Numero_de_itens == 0 && this.primeiro == null && this.ultimo == null){
            EstadoLista = true;
        }else{
            EstadoLista = false;
        }

        return EstadoLista;
    }
    public void Imprimir_lista(){
        Item_fila Dados_lista = this.primeiro;

        if(this.Lista_vazia() != true){
            System.out.println("+---------------------------+");
            System.out.println("| Imprimindo dados da lista |");
            System.out.println("+---------------------------+\n");

            System.out.println("Ind.    Dado");
            for(int i=0,j=1;i<this.Numero_de_itens;i++,j++){
                System.out.println(" "+j+"       "+Dados_lista.GetDado());
                Dados_lista = Dados_lista.GetAnterior();
            }
        }else{
            System.err.println("\n| Lista Vazia |\n");
        }
    }
    public void Limpar_lista(){
        this.Numero_de_itens = 0;
        this.primeiro = null;
        this.ultimo = null;
    }
}