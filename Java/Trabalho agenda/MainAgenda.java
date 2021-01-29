// Importações
import java.util.Scanner;
/**
 * Classe principal de uma agenda que tem como objetivo dar ao usuario as principais opções de ramos possiveis na
 *                          manipulação de seus contatos atraves de uma agenda.
 * @author Erik Neves
 */
public class MainAgenda {
    
    /**
     * @param args the command line argumentsw
     */
    public static void main(String[] args) {
    
        // Declaração de variaveis
        Agenda MinhaAgendaFeliz = new Agenda();
        Scanner input = new Scanner(System.in);
        int EscolhaDoUsuario = -1;
        
        // Impressao mensagem de boa vindas
        System.out.println("\t+-----------------------------------+");
        System.out.println("\t| Bem vindo a BARCHIELO'S agenda!!! |"); 
        System.out.println("\t+-----------------------------------+\n");
        // E sim eu não consegui pensar em um nome melhor que tivesse barchielo tb rsrsrs
        
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
                    // Finalização com êxito do código
                    System.out.println("   +----------------------------------------------+");
                    System.out.println("   |             Encerrando o software            |");
                    System.out.println("   | A BARCHIELO'S COMPANY agradece a preferencia |");
                    System.out.println("   +----------------------------------------------+\n");
                break;
                case 1:
                    MinhaAgendaFeliz.AdicionarRegistro();
                break;
                case 2:
                    MinhaAgendaFeliz.ApagarRegistro();
                break;
                case 3:
                    MinhaAgendaFeliz.AlterarDados();
                break;
                case 4:
                    MinhaAgendaFeliz.ImprimirInfos_B();
                break;
                case 5:
                    MinhaAgendaFeliz.ImprimirInfos_TC();
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