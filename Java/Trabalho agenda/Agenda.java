// Importações
import java.util.HashMap;
import java.util.Scanner;
/**
 * Classe principal de uma agenda, responsavel pelas interações principais com o usuario além de usar a classe
 *                  Interacoes como uma interface entre o código e o usuario em si.
 *  Baseada no armazenamento de registros, que por sua vez guardam os dados dos contatos. Estes registros são 
 * armazenados em um HashMap, onde a identificação(CPF ou CNPJ) de um contato é usada como chave-de-acesso para
 *                             seu registro nessa estrutura de dados.
 * @author Erik Neves
 */
public class Agenda {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
    
        // Declaração de variaveis
        HashMap<String,Registro> DadosAgenda = new HashMap<>();
        Scanner input = new Scanner(System.in);
        int EscolhaDoUsuario = -1;
        
        // Impressao mensagem de boa vindas
        System.out.println("\t+-----------------------------------+");
        System.out.println("\t| Bem vindo a BARCHIELO'S agenda!!! |");
        System.out.println("\t+-----------------------------------+\n");
        
        Registro[] tst = new Registro[2];
        tst[0] = new Registro("erik","12345678910");
        tst[1] =  new Registro("neves","12345678910111");
        
        DadosAgenda.put("12345678910", tst[0]);
        DadosAgenda.put("12345678910111", tst[1]);
        
        tst[0].AddEndereco("Jacaranda", 240, "Casa", "Jardim montanhes", "ibirite", "MG", "32410351");
        tst[0].AddEndereco("dad", 250, "Casa", "Jardim montanhes", "texas", "MG", "32410351");
        
        tst[1].AddEndereco("Jacaranda", 240, "Casa", "Jardim montanhes", "ibirite", "MG", "32410351");
        tst[1].AddEndereco("dad", 250, "Casa", "Jardim montanhes", "texas", "MG", "32410351");
        
        tst[0].AddTelefone("31975734705");
        tst[0].AddTelefone("31992675219");
        tst[0].AddTelefone("31992675241");
        
        tst[1].AddTelefone("31975734705");
        
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