import java.util.Scanner;

/**
 *
 * @author Erik Neves
 */
public class PilhaMain {
    /**
     * @param args the command line arguments
     */
    public static int UserInteract(){
        Scanner inputInteract = new Scanner(System.in);
        int DadoAuxiliar;

        System.out.print("Digite o dado(): ");
        DadoAuxiliar = inputInteract.nextInt();

        return DadoAuxiliar;
    }
    public static void main(String[] args) {
        final Scanner input = new Scanner(System.in);
        Pilha pilha = new Pilha();

        pilha.Inicializar_pilha();
        int Escolha_do_usuario = -1;
        
        while(Escolha_do_usuario != 0){
            
            System.out.println("\n+--------------------+");
            System.out.println("| Implementacao Pilha |");
            System.out.println("+--------------------+");
            System.out.println("[00] Encerrar.");
            System.out.println("[01] Inserir um novo dado.");
            System.out.println("[02] Remover um dado.");
            System.out.println("[03] Checar estado da pilha.");
            System.out.println("[04] Imprimir os dados.");
            System.out.println("[05] Limpar a pilha.");
            System.out.print("Escolha: ");
            Escolha_do_usuario = input.nextInt();
            System.out.println("");
            
            switch(Escolha_do_usuario){            
                case 0:
                    System.out.println("| Encerrando |");
                break;
                case 1:
                    pilha.Insere_dado(UserInteract());
                break;
                case 2:
                    System.out.println("Dado removido: "+pilha.Remove_dado()); 
                break;
                case 3:
                    System.out.println("Esta vazia: "+pilha.Lista_vazia()); 
                break;
                case 4:
                    pilha.Imprimir_lista();
                break;
                case 5:
                    pilha.Limpar_lista();
                break;
                default:
                    System.out.println("| Escolha invalida |");
                break;
            }
            System.out.println("");
        }
    }
}
