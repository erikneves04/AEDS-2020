/**
 *
 * @author Erik Neves
 * @date 2020-11-25
*/
import java.util.Scanner;

public class Barchieloschat {
    public static void main(String[] args) {
        
        // Declaração de varíaveis - INICIO
        Scanner InputEscolha = new Scanner(System.in);
        
        int Escolha_do_usuario = Const.Variavel_de_inicio;
        HashTable Usuarios = new HashTable();
        Interacoes Interact = new Interacoes();
        // Declaração de varíaveis - FIM
        
        /* Impressão das mensagens de bem vindo */
        System.out.println("+-------------------------------+");
        System.out.println("| BEM VINDO AO BARCHIELO'S CHAT |");
        System.out.println("+-------------------------------+\n");
        
        
        // EXECUÇÃO DO LOOP PARA TER ACESSO AOS MODULOS DO SOFTWARE - INICIO
        while(Escolha_do_usuario != Const.Encerrar_loop){
            // MENU DE FUNCIONALIDADE / ESCOLHA USUARIO - INICIO
            System.out.println("+-----------------------------+");
            System.out.println("| Funcionalidades do software |");
            System.out.println("+-----------------------------+");
            System.out.println("[00] Encerrar.");
            System.out.println("[01] .");
            System.out.println("[02] Criar um novo perfil.");
            System.out.println("[03] .");
            System.out.println("[04] .");
            System.out.println("[05] .");
            System.out.println("[06] .");
            System.out.println("[07] .");
            System.out.println("[08] .");
            System.out.println("[09] .");
            System.out.println("[10] .");
            System.out.println("[11] .");
            System.out.print("Escolha: ");
            Escolha_do_usuario = InputEscolha.nextInt();
            System.out.println("");
            // MENU DE FUNCIONALIDADE / ESCOLHA USUARIO - FIM
            
            // EXECUÇÃO DE ACORDO COM A ESCOLHA DO USUARIO - INICIO
            switch (Escolha_do_usuario){
                case 0:
                    /* EXECUÇÕES:
                    * Impressão mensagem de encerramento do software
                    * Chamada da função para realização do salvamento 
                    *            dos dados da rede social
                    */
                    System.out.println("            +-----------------------+");
                    System.out.println("            | Encerrando o software |");
                    System.out.println("            +-----------------------+\n");
                break;
                case 1:
                    /* EXECUÇÕES:
                    * Chamada da função para a ativação/troca do perfil que esta em uso.
                    */
                    
                break;
                case 2:
                    /* EXECUÇÕES:
                    * Chamada da função para a inserção de um novo perfil.
                    * @Param Retorno de uma função que coleta os dados para um novo perfil.
                    */
                    Usuarios.InserirNovoItem(Interact.CriarUmNovoPerfil(Usuarios));
                break;
                case 3:
                    /* EXECUÇÕES:
                    * Chamada da função que remove o perfil atual do usuario.
                    */

                break;
                case 4:
                    /* EXECUÇÕES:
                    * Chamada da função que remove um perfil.
                    */

                break;
                case 5:
                    /* EXECUÇÕES:
                    * Chamada da função que imprime para o usuario todos os perfis cadastrados.
                    */

                break;
                case 6:
                    /* EXECUÇÕES:
                    * Chamada da função para realizar alterações nos dados do perfil atual.
                    */

                break;
                case 7:
                    /* EXECUÇÕES:
                    * Chamada da função para realizar alterações em um perfil.
                    */

                break;
                case 8:
                    /* EXECUÇÕES:
                    * Chamada da função para seguir ou deixar de seguir um perfil existente.
                    */

                break;
                case 9:
                    /* EXECUÇÕES:
                    * Chamada da função para fazer ou apagar um post.
                    */

                break;
                case 10:
                    /* EXECUÇÕES:
                    * Chamada da função para navegar nos perfis, partindo do atual e podendo atingir
                    *              todos que ele segue, incluindo o que os demais seguem.
                    */

                break;
                case 11:
                    /* EXECUÇÕES:
                    * Chamada da função para navegar nas recomendações de perfis e postagens
                    */

                break;
                default:
                    /* EXECUÇÕES:
                    * Impressão informando escolha invalida dentre as opções.
                    */
                    System.out.println("+--------------------------------------+");
                    System.out.println("| Escolha invalida... Tente novamente! |");
                    System.out.println("+--------------------------------------+\n");
                break;
            }
        }
        // EXECUÇÃO DO LOOP PARA TER ACESSO AOS MODULOS DO SOFTWARE - FIM
    }
    
}
