import java.util.Scanner;

/**
 *
 * @author Erik Neves
 */

public class Main_arvoreBinaria {
    /**
     * @param args the command line arguments
     */

    public static void main(String[] args) {
        final Scanner input = new Scanner(System.in);
        int Escolha_do_usuario = -1;
        
        while(Escolha_do_usuario != 0){
            
            System.out.println("\n+------------------------------+");
            System.out.println("| Implementacao Arvore binaria |");
            System.out.println("+------------------------------+");
            System.out.println("[00] Encerrar.");
            System.out.println("[0x] Funcoes de manipulacao prontas no arquivo Arvore.java .");
            System.out.print("Escolha: ");
            Escolha_do_usuario = input.nextInt();
            System.out.println("");
            
            switch(Escolha_do_usuario){            
                case 0:
                    System.out.println("| Encerrando |");
                break;
                case 1:
                break;
                case 2:
                break;
                default:
                    System.out.println("| Escolha invalida |");
                break;
            }
            System.out.println("");
        }
    }
}