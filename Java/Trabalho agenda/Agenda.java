import java.util.HashMap;
import java.util.Scanner;
/**
 *
 * @author Erik Neves
 */
public class Agenda {
    
    //TODO MAXIMO DO MAXIMO -> Adicionar uma forma de cancelamento em loops infinitos ate que o user insira um dado valido.
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
    
        // Esta variavel poderia ser declarada na classe Interacoes,
        //  mas por hora quero manter a "origem" dos dados na Main.
        HashMap<String,Registro> DadosAgenda = new HashMap<>();
        Scanner input = new Scanner(System.in);
        int EscolhaDoUsuario = -1;
        
        
        System.out.println("\t+-----------------------------------+");
        System.out.println("\t| Bem vindo a BARCHIELO'S agenda!!! |");
        System.out.println("\t+-----------------------------------+\n");
        
        DadosAgenda.put("12345678910", new Registro("erik","12345678910"));
        DadosAgenda.put("12345678910111", new Registro("neves","12345678910111"));
        
        // Exibição do menu de funcionalidades básicas.
        while(EscolhaDoUsuario != 0){
            System.out.println("Funcionalidades disponiveis:");
            System.out.println("[00] Encerrar o software.");
            System.out.println("[01] Criar um novo contato.");
            System.out.println("[02] Remover um contato.");
            System.out.println("[03] Alterar os dados de um contato.");
            System.out.println("[04] Visualizar informacoes basicas de TODOS os contatos.");
            System.out.println("[05] Visualizar informacoes completas de TODOS os contatos..");
            System.out.print("Escolha: ");
            try{
                EscolhaDoUsuario = Integer.parseInt(input.nextLine());
            }catch(NumberFormatException e){
                EscolhaDoUsuario = -1;
            }
            System.out.println("");
            
            switch(EscolhaDoUsuario){
                case 0:
                    System.out.println("   +----------------------------------------------+");
                    System.out.println("   |             Encerrando o software            |");
                    System.out.println("   | A BARCHIELO'S COMPANY agradece a preferencia |");
                    System.out.println("   +----------------------------------------------+\n");
                break;
                case 1:
                    Interacoes.AdicionarRegistro(DadosAgenda);
                break;
                case 2:
                    Interacoes.ApagarRegistro(DadosAgenda);
                break;
                case 3:
                    Interacoes.AlterarDados(DadosAgenda);
                break;
                case 4:
                    Interacoes.ImprimirInfos_B(DadosAgenda);
                break;
                case 5:
                    Interacoes.ImprimirInfos_TC(DadosAgenda);
                break;
                default:
                    System.out.println("\t+--------------------------------------+");
                    System.out.println("\t| Escolha invalida... Tende novamente! |");
                    System.out.println("\t+--------------------------------------+\n");
                break;
            }
            
        }   
        
    }   
}