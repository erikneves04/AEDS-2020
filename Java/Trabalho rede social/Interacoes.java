/**
 *
 * @author Erik Neves
 * @date 2020-11-25
*/
import java.util.Scanner;
public class Interacoes {
    
    private static int ContagemIdentificadores = 0;
    
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
        
        NovoPerfil.SetInformacoesPerfil(Interacoes.ContagemIdentificadores++, Name, UserName);
        
        System.out.println("\n+---------------------------+");
        System.out.println("| Perfil criado com sucesso |");
        System.out.println("+---------------------------+\n");
        
        return NovoPerfil;
    }
    
}
