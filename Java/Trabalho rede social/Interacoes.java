import java.util.Arrays;
import java.util.Scanner;
/**
 *
 * @author Erik Neves
 * @date 2020-11-25
*/

public class Interacoes {
    
    private static int ContagemIdentificadores = 0;
    private static int COntagemIdentificadoresPosts = 0;
    
    public Perfil CriarUmNovoPerfil(HashTable table){
        Scanner Input = new Scanner(System.in);
        Perfil NovoPerfil = new Perfil();
        String UserName = null;
        String Name;
        
        System.out.print("Digite seu nome completo: ");
        Name = Input.nextLine();
        
        boolean UserNameDisponivel = false;
        while(!UserNameDisponivel){
            System.out.print("Digite o nome de usuario: ");
            UserName = Input.nextLine();
            if(table.PerfilExistente(UserName)){
                System.out.println("| O nome " +UserName+ " ja esta em uso! |");
            }else{
                UserNameDisponivel = true;
            }
        }
        
        NovoPerfil.SetInformacoesPerfil(Interacoes.ContagemIdentificadores++, Name, UserName, true);
        
        System.out.println("\n+---------------------------+");
        System.out.println("| Perfil criado com sucesso |");
        System.out.println("+---------------------------+\n");
        
        return NovoPerfil;
    }
    public int AlterarInformacoesDoPerfil(HashTable table, Perfil User){
        Scanner Input = new Scanner(System.in);
        boolean[] Alteracoes = new boolean[Const.ALetarcoesPossiveisPerifl];
        Arrays.fill(Alteracoes,false);
        Perfil DataAux = new Perfil();
        String Aux = null;
        
        if(User == null) return Const.UsuarioInvalido;
        
        System.out.println("\n+-------------------------------------------------------+");
        System.out.println("| Aqui voce poderar alterar as informacoes de um perfil |");
        System.out.println("+-------------------------------------------------------+");
        System.out.println("Perfil( nome de usuario ): " + User.GetUserName());
        
        DataAux.SetInformacoesPerfil(User.GetIdPerfil(),User.GetNomeCompleto(),User.GetUserName(),false);
        
        int Escolha_do_usuario = Const.Variavel_de_inicio;
        while(Escolha_do_usuario != Const.Encerrar_loop){
            System.out.println("\nQual alteracao voce deseja fazer: ");
            System.out.println("[00] Encerrar as alteracoes.");
            System.out.println("[01] Alterar seu nome.");
            System.out.println("[02] Alterar seu nome de usuario.");
            System.out.println("[03] Imprimir as informacoes atuais.");
            System.out.print("Escolha: ");
            Escolha_do_usuario = Input.nextInt();
            System.out.println("");
            
            switch(Escolha_do_usuario){
                case 0:
                break;
                case 1:
                    System.out.println("Digite seu nome: ");
                    Aux = Input.next();
                    DataAux.SetNomeCompleto(Aux);
                break;
                case 2:
                    boolean UsuarioDisponivel = false;
                    while(!UsuarioDisponivel){
                        System.out.print("Digite o nome de usuario: ");
                        Aux = Input.next();
                        UsuarioDisponivel = !table.PerfilExistente(Aux);
                        if(!UsuarioDisponivel){
                            System.out.println("\n| O nome de usuario " + Aux + " ja esta em uso |\n");
                        }
                    }
                    DataAux.SetUserName(Aux);
                break;
                case 3:
                    DataAux.ImprimirDadosPerfil();
                break;
                default:
                    System.out.println("\n| Escolha invalida |\n");
                break;
            }   
        }
        
        System.out.println("Essas sao as novas informacoes de seu perfil:");
        DataAux.ImprimirDadosPerfil();
        System.out.println("\nDeseja mante-las ou retroceder as antigas:");
        System.out.println("[00] Manter alteracoes.");
        System.out.println("[01] Descartar alteracoes.");
        System.out.print("Escolha: ");
        Escolha_do_usuario = Input.nextInt();
        
        if(Escolha_do_usuario == 0){
            table.RemovePerfilByObjetc(User);
            User.SetInformacoesPerfil(DataAux.GetIdPerfil(),DataAux.GetNomeCompleto(),DataAux.GetUserName(), false);
            table.InserirNovoItem(User);
            System.out.println("\n| Alteracoes salvas com sucesso |\n");
        }else{
            System.out.println("\n| Alteracoes deletadas com sucesso |\n");
        }
        
        return Const.Sucesso;
    }
    public Perfil AtivarUmPerfil(HashTable table, Perfil AtualUser){
        Scanner Input = new Scanner(System.in);
        Perfil procurado = null;
        String UserName;
        int Escolha_do_usuario = Const.Variavel_de_inicio;
        
        System.out.println("\n+-----------------------+");
        System.out.println("| Ativacao de um perfil |");
        System.out.println("+-----------------------+");
        if(AtualUser != null) System.out.println("Ola @"+AtualUser.GetUserName()+". Espeeramos que voce retorne em breve! =)");
        System.out.println("");
        
        System.out.println("Deseja ver uma lista com os usuarios cadastrados: ");
        System.out.println("[00] Sim.");
        System.out.println("[01] Nao.");
        System.out.print("Escolha: ");
        Escolha_do_usuario = Input.nextInt();
        if(Escolha_do_usuario == 0) table.ImprimirTodosOsPerfis();
        
        System.out.print("Digite o nome de usuario para ativacao: ");
        UserName = Input.next();
        
        procurado = table.GetPerfil(UserName);
        
        if(procurado == null){
            System.out.println("\n| Perfil nao encontrado  |");
            System.out.println("| Procedimento cancelado |\n");
            procurado = AtualUser;
        }else{
            System.out.println("\n| Perfil @"+procurado.GetUserName()+" ativado com sucesso |\n");
        }
        
        return procurado;
    }
    public String GetUserName(HashTable table){
        Scanner Input = new Scanner(System.in);
        String UserName;
        int Escolha_do_usuario = Const.Variavel_de_inicio;
        
        System.out.println("Deseja ver uma lista com os usuarios cadastrados: ");
        System.out.println("[00] Sim.");
        System.out.println("[01] Nao.");
        System.out.print("Escolha: ");
        Escolha_do_usuario = Input.nextInt();
        if(Escolha_do_usuario == 0) table.ImprimirTodosOsPerfis();
        
        System.out.print("Digite o nome de usuario do perfil: ");
        UserName = Input.next();
        
        return UserName;
    }
    private int StartNewFollow(HashTable table, Perfil AtualUser){
        String NomeProcurado;
        Perfil ObjetoProcurado;
        
        System.out.println("+-----------------------+");
        System.out.println("| Seguir um novo perfil |");
        System.out.println("+-----------------------+\n");
        
        NomeProcurado = this.GetUserName(table);
        ObjetoProcurado = table.GetPerfil(NomeProcurado);
        
        if (ObjetoProcurado == null){
            System.out.println("| Perfil nao encontrado |\n");
        }else if(ObjetoProcurado.equals(AtualUser)){
            System.out.println("| Voce nao pode se seguir |\n");
        }else{
            AtualUser.Seguindo.InserirNovoItem(ObjetoProcurado);
            ObjetoProcurado.Seguidores.InserirNovoItem(AtualUser);
            System.out.println("| Perfil @"+ObjetoProcurado.GetUserName()+" seguido com sucesso |\n");
        }
        
        return Const.Sucesso;
    }
    private int StopFollow(HashTable table, Perfil AtualUser){
        Scanner Input = new Scanner(System.in);
        String NomeProcurado;
        Perfil ObjetoProcurado;
        
        System.out.println("+----------------------------+");
        System.out.println("| Deixar de seguir um perfil |");
        System.out.println("+----------------------------+\n");
        
        int Escolha_do_usuario = Const.Variavel_de_inicio;  
        System.out.println("Deseja ver uma lista com os perfis seguidos: ");
        System.out.println("[00] Sim.");
        System.out.println("[01] Nao.");
        System.out.print("Escolha: ");
        Escolha_do_usuario = Input.nextInt();
        if(Escolha_do_usuario == 0) AtualUser.Seguindo.ImprimirPerfisDaLista();
        
        System.out.print("Digite o nome de usuario do perfil: ");
        NomeProcurado = Input.next();
        ObjetoProcurado = table.GetPerfil(NomeProcurado);
        
        if(ObjetoProcurado == null){
            System.out.println("| Perfil nao encontrado |\n");
        }else if(!AtualUser.Seguindo.DadoContido(ObjetoProcurado)){
            System.out.println("| Este perfil nao segue voce |\n");
        }else{
            AtualUser.Seguindo.RemoverItem(ObjetoProcurado);
            ObjetoProcurado.Seguidores.RemoverItem(AtualUser);
            System.out.println("| Voce deixou de seguir @"+ObjetoProcurado.GetUserName()+" |\n");
        }
        
        return Const.Sucesso;
    }
    public int AlterarDadosSeguidores(HashTable table,Perfil AtualUser){
        Scanner Input = new Scanner(System.in);
        int Escolha_do_usuario = Const.Variavel_de_inicio;
        
        if(AtualUser == null) return Const.UsuarioInvalido;
        
        System.out.println("\n+-------------------------------------------+");
        System.out.println("| Aqui voce podera seguir um novo perfil ou |");
        System.out.println("|    deixar de seguir um que voce segue     |");
        System.out.println("+-------------------------------------------+");
        System.out.println("Perfil atual( nome de usuario ): "+AtualUser.GetUserName());
        System.out.println("");
        
        while(Escolha_do_usuario != Const.Encerrar_loop){
            System.out.println("O que voce deseja fazer: ");
            System.out.println("[00] Encerrar alteracoes.");
            System.out.println("[01] Seguir um novo perfil.");
            System.out.println("[02] Deixar de seguir um perfil.");
            System.out.println("[03] Ver seus seguidores.");
            System.out.println("[04] Ver quem voce segue.");
            System.out.print("Escolha: ");
            Escolha_do_usuario = Input.nextInt();
            System.out.println("");
            
            switch(Escolha_do_usuario){
                case 0:
                    System.out.println("| Encerrando alteracoes |\n");
                break;
                case 1:
                    this.StartNewFollow(table, AtualUser);
                break;
                case 2:
                    this.StopFollow(table, AtualUser);
                break;
                case 3:
                    AtualUser.Seguidores.ImprimirPerfisDaLista();
                break;
                case 4:
                    AtualUser.Seguindo.ImprimirPerfisDaLista();
                break;
                default:
                    System.out.println("| Escolha invalida! Tente novamente. |\n");
                break;
            }
        }
        
        return Const.Sucesso;
    }
    private Postagem CriarNovaPostagem(Perfil AtualUser){
        Scanner Input = new Scanner(System.in);
        Postagem NovoPost = new Postagem();
        String ConteudoPost;
        
        System.out.print("Digite o conteudo da postagem: ");
        ConteudoPost = Input.next();
        
        NovoPost.InserirDadosPostagem(COntagemIdentificadoresPosts++, ConteudoPost, AtualUser.GetUserName());
        
        return NovoPost;
    }
    private int DeletarPostagem(Perfil AtualUser){
        Scanner Input = new Scanner(System.in);
        int Escolha_do_usuario = Const.Variavel_de_inicio;
        int PostIdAux;
        Postagem Alvo = null;
        
        System.out.println("Voce deseja ver uma lista com suas postagens: ");
        System.out.println("[00] Sim.");
        System.out.println("[01] Nao;");
        System.out.print("Escolha: ");
        Escolha_do_usuario = Input.nextInt();
        
        if(Escolha_do_usuario == 0) AtualUser.Postagens.ImprimirPostsDaLista();
        
        System.out.print("Digite o Id da postagem: ");
        PostIdAux = Input.nextInt();
        
        Alvo = AtualUser.Postagens.GetPostagem(PostIdAux);
        if(!AtualUser.Postagens.DadoContido(Alvo)){
            System.out.println("| Postagem nao encontrada |\n");
        }else{
            AtualUser.Postagens.RemoverItem(Alvo);
            System.out.println("| Postagem removida com sucesso |\n");
        }
        
        return Const.Sucesso;
    }
    public int AlterarDadosPostagens(HashTable table, Perfil AtualUser){
        Scanner Input = new Scanner(System.in);
        int Escolha_do_usuario = Const.Variavel_de_inicio;
        
        if(AtualUser == null) return Const.UsuarioInvalido;
        
        System.out.println("\n+--------------------------------------------+");
        System.out.println("| Aqui voce podera fazer uma nova ou deletar |");
        System.out.println("|      uma de suas postagens existentes      |");
        System.out.println("+--------------------------------------------+");
        System.out.println("Perfil atual( nome de usuario ): "+AtualUser.GetUserName());
        System.out.println("");
        
        while(Escolha_do_usuario != Const.Encerrar_loop){
            System.out.println("O que voce deseja fazer: ");
            System.out.println("[00] Encerrar alteracoes.");
            System.out.println("[01] Fazer uma nova postagem.");
            System.out.println("[02] Deletar uma postagem existente.");
            System.out.println("[03] Imprimir minhas postagens.");
            System.out.println("[04] Detalhar uma postagem.");
            System.out.print("Escolha: ");
            Escolha_do_usuario = Input.nextInt();
            System.out.println("");
            
            switch(Escolha_do_usuario){
                case 0:
                    System.out.println("| Encerrando alteracoes |\n");
                break;
                case 1:
                    AtualUser.Postagens.InserirNovoItem(this.CriarNovaPostagem(AtualUser));
                    System.out.println("| Postegm realizada com sucesso |\n");
                break;
                case 2:
                    this.DeletarPostagem(AtualUser);
                break;
                case 3:
                    AtualUser.Postagens.ImprimirPostsDaLista();
                break;
                default:
                    System.out.println("| Escolha invalida! Tente novamente. |\n");
                break;
            }
        }
        
        return Const.Sucesso;
    }
}
