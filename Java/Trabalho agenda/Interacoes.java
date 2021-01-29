// Importações
import java.util.HashMap;
import java.util.Scanner;
/**
 * Classe responsavel pela coleta de dados e repasse dos mesmos para a estrutura de salvamento(HashMap)
 *                          e inserção correta na estrutura de um registro.
 * @author Erik Neves
 */
public class Interacoes {

    /**
     * Metodo responsavel por criar um novo registro e armazena-lo na estrutura de dados 
     *              a partir das informações fornecidas pelo usuario.
     * @param DadosAgenda 
     */
    public static void AdicionarRegistro(HashMap<String,Registro> DadosAgenda){
        
        Registro NovoRegistro = null;
        Scanner input = new Scanner(System.in);
        int EscolhaDoUsuario = -1;
        
        System.out.println("\t+----------------------------------------+");
        System.out.println("\t| Criacao de um novo registro na agenda: |");
        System.out.println("\t+----------------------------------------+\n");
        
        System.out.println("|  E possivel criar dois tipos de registros:  |");
        System.out.println("- Pessoa Fisica: Formato xxxxxxxxxxx(11 digitos);");
        System.out.println("- Pessoa Juridica: Formato xxxxxxxxxxxxxx(14 digitos);");
        System.out.println("OBS.: O formato inserido ira DEFINIR qual o tipo de pessoa deste registro.\n\n");
        
        
        System.out.println("->  Informacoes basicas deste contato: ");
        
        System.out.print("Digite o nome deste contato: ");
        String nome = input.nextLine();
        String identificacao;
        
        boolean DadosValidos = false;
        while(!DadosValidos){
            System.out.print("Digite a identificacao(CPF ou CNPJ) deste contato:");
            identificacao = input.nextLine();
            
            if(identificacao.equals("cancelar")){
                System.out.println("| Operacao cancelada com sucesso. |\n");
                break;
                //System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
            }
            
            if(DadosAgenda.containsKey(identificacao)){
                System.out.println("\n| Esta identificacao ja esta relacionada a outro registro. |");
                System.out.println("| Tente novamente! |\n");
            }else{
                try{
                    NovoRegistro = new Registro(nome,identificacao); 
                    DadosValidos = true;
                }catch(IllegalStateException e){
                    System.out.println("\nA identificacao {"+identificacao+"} nao se enquadra no formato de em um CPF/CNPJ.");
                    System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                }     
            }    
        }
        System.out.println("");
        
        if(!DadosValidos){return;}
        
        System.out.println("->  Adicionando os telefones deste contato:");
        System.out.println("OBS.: Formato XXXXXXXXXXX(2 digitos DDD + 9 digitos do numero).");
        while(EscolhaDoUsuario != 0){
            System.out.println("Escolha uma das opcoes: ");
            System.out.println("[00] Proxima etapa.");
            System.out.println("[01] Adicionar um telefone.");
            System.out.print("Escolha: ");
            try{
                EscolhaDoUsuario = Integer.parseInt(input.nextLine());
            }catch(NumberFormatException e){
                EscolhaDoUsuario = -1;
            }
            System.out.println("");
            
            switch(EscolhaDoUsuario){
                case 0:
                    // proxima etapa
                break;
                case 1:
                    DadosValidos = false;
                    while(!DadosValidos){                    
                        System.out.print("Digite o numero de telefone: ");
                        String numero = input.nextLine();
                        
                        if(numero.equals("cancelar")){
                            System.out.println("| Operacao cancelada com sucesso. |\n");
                            break;
                            //System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                        }
                        
                        try{
                            NovoRegistro.AddTelefone(numero);
                            DadosValidos = true;
                            System.out.println("");
                        }catch(IllegalStateException e){
                            System.out.println("\nO numero {"+numero+"} nao se enquadra no formato valido de um numero.");
                            System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                        }        
                    }
                break;
                default:
                    System.out.println("\t| Escolha invalida... Tente novamente! |\n");
                break;
            }
        }
        
        
        System.out.println("->  Adicionando os enderecos deste contato:");
        int count = 0;
        EscolhaDoUsuario = -1;
        while(EscolhaDoUsuario != 0){
            System.out.println("Escolha uma das opcoes: ");
            System.out.println("[00] Proxima etapa.");
            System.out.println("[01] Adicionar um endereco.");
            System.out.print("Escolha: ");
            try{
                EscolhaDoUsuario = Integer.parseInt(input.nextLine());
            }catch(NumberFormatException e){
                EscolhaDoUsuario = -1;
            }
            System.out.println("");
            
            switch(EscolhaDoUsuario){
                case 0:
                    // proxima etapa
                break;
                case 1:
                    count++;
                    //String logradouro, int numero, String complemento, String bairro, String cidade, String estado, String cep
                    System.out.print("Digite o logradouro do endereco("+count+"): ");
                    String logradouro = input.nextLine();
                    System.out.print("Digite o complemento do endereco("+count+"): ");
                    String complemento = input.nextLine();
                    System.out.print("Digite o bairro do endereco("+count+"): ");
                    String bairro = input.nextLine();
                    System.out.print("Digite a cidade do endereco("+count+"): ");
                    String cidade = input.nextLine();
                    System.out.print("Digite o estado do endereco("+count+"): ");
                    String estado = input.nextLine();
                    System.out.print("Digite o cep do endereco("+count+"): ");
                    String cep = input.nextLine();
                    
                    DadosValidos = false;
                    int numero = 0;
                    while(!DadosValidos){
                        System.out.print("Digite o numero do endereco("+count+"):");
                        try{
                            numero = Integer.parseInt(input.nextLine());
                            DadosValidos = true;
                        }catch(NumberFormatException e){
                            System.out.println("\n| Numero invalido... Tente novamente! |\n");
                        }   
                    }
                    System.out.println("");
                    
                    NovoRegistro.AddEndereco(logradouro, numero, complemento, bairro, cidade, estado, cep); 
                break;
                default:
                    System.out.println("\t| Escolha invalida... Tente novamente! |\n");
                break;
            } 
        }
       
        DadosAgenda.put(NovoRegistro.GetIdentificacao(), NovoRegistro);
                
        System.out.println("");
    }
    
    /**
     * Metodo responsavel por remover um registro a ser selecionado pelo usuario.
     * @param DadosAgenda 
     */
    public static void ApagarRegistro(HashMap<String,Registro> DadosAgenda){

        System.out.println("\t+-------------------------+");
        System.out.println("\t| Remocao de um registro: |");
        System.out.println("\t+-------------------------+\n");
        
        Scanner input = new Scanner(System.in);
        int EscolhaDoUsuario = -1;
        System.out.println("Deseja ver as informacoes basicas dos contatos existentes: ");
        System.out.println("[00] Sim.");
        System.out.println("[01] Nao.");
        System.out.print("Escolha: "); 
        try{
            EscolhaDoUsuario = Integer.parseInt(input.nextLine());
            System.out.println("");
        }catch(NumberFormatException e){
            System.out.println("| Escolha invalida... Os dados serao impressos para evitar transtornos. |\n");
            EscolhaDoUsuario = 0;
        }
        if(EscolhaDoUsuario != 0 && EscolhaDoUsuario != 1){
            System.out.println("| Escolha invalida... Os dados serao impressos para evitar transtornos. |\n");
            EscolhaDoUsuario = 0;
        }
        if(EscolhaDoUsuario == 0){
            Interacoes.ImprimirInfos_B(DadosAgenda);
        }
        
        String Alvo = null;
        boolean IdentificacaoExistente = false;
        while(!IdentificacaoExistente){
            System.out.print("Digite a identificacao(CPF ou CNPJ) associada ao contato que sera deletado: ");
            Alvo = input.nextLine();
            
            if(Alvo.equals("cancelar")){
                System.out.println("| Operacao cancelada com sucesso. |\n");
                break;
                //System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
            }
            
            if(DadosAgenda.containsKey(Alvo)){
                IdentificacaoExistente = true;
            }else{
                System.out.println("| A identificacao informada("+Alvo+") nao foi encontrada nos registros da agenda. |");
                System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
            }  
        }
        
        if(!IdentificacaoExistente){
            return;
        }
        
        Registro DadoAlvo = DadosAgenda.get(Alvo);
        System.out.println("\n| Contato a ser removido:");
        System.out.println("| Nome: "+DadoAlvo.GetNome());
        System.out.println("| "+DadoAlvo.GetTipoIdentificacao()+": "+DadoAlvo.GetIdentificacao());
        System.out.println("+-----------------------\n");
        
        System.out.println("Decisao final:");
        System.out.println("[00] Remover o contato.");
        System.out.println("[01] Cancelar a remocao.");
        System.out.print("Escolha: ");
        try{
            EscolhaDoUsuario = Integer.parseInt(input.nextLine());
        }catch(NumberFormatException e){
            System.out.println("| Escolha invalida... O registro sera mantido para evitar transtornos. |");
            EscolhaDoUsuario = 1;
        }
        if(EscolhaDoUsuario == 0){
            DadosAgenda.remove(Alvo);
            System.out.println("\n| Registro referente a {"+DadoAlvo.GetIdentificacao()+"("+DadoAlvo.GetTipoIdentificacao()+") foi removido com sucesso. |");
        }else{
            System.out.println("\n| Remocao cancelada. |");
        }
        System.out.println("");
    }
    
    /**
     * Metodo responsavel por imprimir as informacoes basicas(nome e identificacao) de TODOS os contatos cadastrados.
     * @param DadosAgenda 
     */
    public static void ImprimirInfos_B(HashMap<String,Registro> DadosAgenda){
        
        System.out.println("+------------------------------------------------+");
        System.out.println("| Informacoes basicas dos contatos dessa agenda: |");
        System.out.println("+------------------------------------------------+");
        
        Registro[] ArrayReg = new Registro[DadosAgenda.values().size()];
        DadosAgenda.values().toArray(ArrayReg);
        
        for (Registro Dados : ArrayReg) {
            System.out.println("| Nome: "+Dados.GetNome());
            System.out.println("| "+Dados.GetTipoIdentificacao()+": "+Dados.GetIdentificacao());
            System.out.println("+-----------------------");
        }
        
        System.out.println("");
    }
    
    /**
     * Metodo responsavel por imprimir as informacoes completas de TODOS os contatos cadastrados.
     * @param DadosAgenda 
     */
    public static void ImprimirInfos_TC(HashMap<String,Registro> DadosAgenda){
        
        System.out.println("+--------------------------------------------------+");
        System.out.println("| Informacoes completas dos contatos dessa agenda: |");
        System.out.println("+--------------------------------------------------+");
        
        Registro[] ArrayReg = new Registro[DadosAgenda.values().size()];
        DadosAgenda.values().toArray(ArrayReg);
        
        for (Registro Dados : ArrayReg) {
            Dados.Imprimir();
        }
    }
    
    /**
     * Metodo responsavel por alterar os dados de um contato a partir das escolhas do usuario.
     * @param DadosAgenda 
     */
    public static void AlterarDados(HashMap<String,Registro> DadosAgenda){
        
        System.out.println("\t+---------------------------------+");
        System.out.println("\t| Alterar os dados de um contato: |");
        System.out.println("\t+---------------------------------+\n");
        
        Scanner input = new Scanner(System.in);
        int EscolhaDoUsuario = -1;
        System.out.println("Deseja ver as informacoes basicas dos contatos existentes: ");
        System.out.println("[00] Sim.");
        System.out.println("[01] Nao.");
        System.out.print("Escolha: "); 
        try{
            EscolhaDoUsuario = Integer.parseInt(input.nextLine());
            System.out.println("");
        }catch(NumberFormatException e){
            System.out.println("| Escolha invalida... Os dados serao impressos para evitar transtornos. |\n");
            EscolhaDoUsuario = 0;
        }
        if(EscolhaDoUsuario != 0 && EscolhaDoUsuario != 1){
            System.out.println("| Escolha invalida... Os dados serao impressos para evitar transtornos. |\n");
            EscolhaDoUsuario = 0;
        }
        if(EscolhaDoUsuario == 0){
            Interacoes.ImprimirInfos_B(DadosAgenda);
        }
        
        String Alvo = null;
        boolean IdentificacaoExistente = false;
        while(!IdentificacaoExistente){
            System.out.print("Digite a identificacao(CPF ou CNPJ) associada ao contato que sera alterado: ");
            Alvo = input.nextLine();
            
            if(Alvo.equals("cancelar")){
                System.out.println("| Operacao cancelada com sucesso. |\n");
                break;
                //System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
            }
            
            if(DadosAgenda.containsKey(Alvo)){
                IdentificacaoExistente = true;
            }else{
                System.out.println("| A identificacao informada("+Alvo+") nao foi encontrada nos registros da agenda. |");
                System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
            }  
        }
        
        if(!IdentificacaoExistente){
            return;
        }
        
        Registro DadoAlvo = DadosAgenda.get(Alvo);
        System.out.println("\n+-----------------------");
        System.out.println("| Contato a ser alterado:");
        System.out.println("| Nome: "+DadoAlvo.GetNome());
        System.out.println("| "+DadoAlvo.GetTipoIdentificacao()+": "+DadoAlvo.GetIdentificacao());
        System.out.println("+-----------------------\n");
        
        EscolhaDoUsuario = -1;
        while(EscolhaDoUsuario != 0){
            System.out.println("Menu de alteracoes: ");
            System.out.println("[00] Encerrar alteracoes.");
            System.out.println("[01] Imprimir TODAS as informacoes atuais.");
            System.out.println("[02] Alterar o nome.");
            System.out.println("[03] Adicionar um telefone.");
            System.out.println("[04] Remover um telefone.");
            System.out.println("[05] Imprimir os telefones.");
            System.out.println("[06] Adicionar um endereco.");
            System.out.println("[07] Remover um endereco.");
            System.out.println("[08] Imprimir os enderecos.");
            System.out.println("[09] Alterar os dados de um endereco.");
            System.out.print("Escolha: "); 
            try{
                EscolhaDoUsuario = Integer.parseInt(input.nextLine());
            }catch(NumberFormatException e){
                EscolhaDoUsuario = -1;
            }
            System.out.println("");
            
            boolean DadosValidos = false;
            switch(EscolhaDoUsuario){
                case 0:
                    System.out.println("| Alteracoes salvas... Encerrando alteracoes. |\n");
                break;
                case 1:
                    DadoAlvo.Imprimir();
                break;
                case 2:
                    System.out.println("Nome atual: "+DadoAlvo.GetNome());
                    System.out.print("Digite o novo nome deste contato: ");
                    String NewName = input.nextLine();
                    DadoAlvo.SetNome(NewName);
                    System.out.println("");
                break;
                case 3:
                    System.out.println("| Adicione os dados do novo telefone: |\n");
                    DadosValidos = false;
                    while(!DadosValidos){                    
                        System.out.print("Digite o numero de telefone: ");
                        String numero = input.nextLine();
                        
                        if(numero.equals("cancelar")){
                            System.out.println("| Operacao cancelada com sucesso. |\n");
                            break;
                            //System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                        }
                        
                        try{
                            DadoAlvo.AddTelefone(numero);
                            DadosValidos = true;
                            System.out.println("");
                        }catch(IllegalStateException e){
                            System.out.println("\nO numero {"+numero+"} nao se enquadra no formato valido de um numero.");
                            System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                        }        
                    }
                break;
                case 4:
                    System.out.print("Digite o numero do telefone para remove-lo: ");
                    String tel = input.nextLine();
                    DadoAlvo.RemoveTelefone(tel);
                    System.out.println("");
                break;
                case 5:
                    Interacoes.ImprimirTelefonesDeUmContato(DadoAlvo.ObtemTelefones());
                break;
                case 6:
                    System.out.println("| Adicione os dados do novo endereco: |\n");
                    System.out.print("Digite o logradouro do endereco: ");
                    String logradouro = input.nextLine();
                    System.out.print("Digite o complemento do endereco: ");
                    String complemento = input.nextLine();
                    System.out.print("Digite o bairro do endereco: ");
                    String bairro = input.nextLine();
                    System.out.print("Digite a cidade do endereco: ");
                    String cidade = input.nextLine();
                    System.out.print("Digite o estado do endereco: ");
                    String estado = input.nextLine();
                    System.out.print("Digite o cep do endereco: ");
                    String cep = input.nextLine();
                    
                    int numero = 0;
                    DadosValidos = false;   
                    while(!DadosValidos){
                        System.out.print("Digite o numero do endereco: ");
                        try{
                            numero = Integer.parseInt(input.nextLine());
                            DadosValidos = true;
                        }catch(NumberFormatException e){
                            System.out.println("\n| Numero invalido... Tente novamente! |\n");
                        }   
                    }
                    System.out.println("");
                    
                    DadoAlvo.AddEndereco(logradouro, numero, complemento, bairro, cidade, estado, cep);
                    System.out.println("| Endereco adicionando com sucesso! |\n");
                break;
                case 7:
                    System.out.println("| Remocao de um endereco: |\n");
                    
                    System.out.println("Deseja ver uma lista com os enderecos deste contato: ");
                    System.out.println("[00] Sim.");
                    System.out.println("[01] Nao.");
                    System.out.print("Escolha: ");
                    try{
                        EscolhaDoUsuario = Integer.parseInt(input.nextLine());
                    }catch(NumberFormatException e){
                        System.out.println("| Escolha invalida... Os dados serao impressos para evitar transtornos. |\n");
                        EscolhaDoUsuario = 0;
                    }
                    if(EscolhaDoUsuario != 0 && EscolhaDoUsuario != 1){
                        System.out.println("| Escolha invalida... Os dados serao impressos para evitar transtornos. |\n");
                        EscolhaDoUsuario = 0;
                    }
                    if(EscolhaDoUsuario == 0){
                        Interacoes.ImprimirEnderecosDeUmContato(DadoAlvo.ObtemEnderecos());
                    }
                    
                    int IdAlvo = 0;
                    String auxInt;
                    DadosValidos = false;
                    while(!DadosValidos){
                        System.out.print("Digite o Id do endereco a ser removido: ");
                        auxInt = input.nextLine();
                        
                        if(auxInt.equals("cancelar")){
                            System.out.println("| Operacao cancelada com sucesso. |\n");
                            break;
                            //System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                        }
                        
                        try{
                            IdAlvo = Integer.parseInt(auxInt);
                            DadosValidos = true;
                            System.out.println("");
                        }catch(NumberFormatException e){
                            System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                        }
                    }
                    
                    if(!DadosValidos){
                        break;
                    }
                    
                    DadoAlvo.RemoveEndereco(IdAlvo);
                    System.out.println("| Se o endereco(Id:"+IdAlvo+"} estiver contido neste contato ele sera removido... |\n");  
                break;
                case 8:
                    Interacoes.ImprimirEnderecosDeUmContato(DadoAlvo.ObtemEnderecos());
                break;
                case 9:
                    System.out.println("\t+----------------------------------+");
                    System.out.println("\t| Alterar os dados de um endereco: |");
                    System.out.println("\t+----------------------------------+\n");
                    
                    System.out.println("Deseja ver uma lista com os enderecos deste contato: ");
                    System.out.println("[00] Sim.");
                    System.out.println("[01] Nao.");
                    System.out.print("Escolha: ");
                    try{
                        EscolhaDoUsuario = Integer.parseInt(input.nextLine());
                    }catch(NumberFormatException e){
                        System.out.println("| Escolha invalida... Os dados serao impressos para evitar transtornos. |\n");
                        EscolhaDoUsuario = 0;
                    }
                    if(EscolhaDoUsuario != 0 && EscolhaDoUsuario != 1){
                        System.out.println("| Escolha invalida... Os dados serao impressos para evitar transtornos. |\n");
                        EscolhaDoUsuario = 0;
                    }
                    if(EscolhaDoUsuario == 0){
                        Interacoes.ImprimirEnderecosDeUmContato(DadoAlvo.ObtemEnderecos());
                    }
                    
                    int IdAlteracoes = 0;
                    String auxIntAlt;
                    DadosValidos = false;
                    while(!DadosValidos){
                        System.out.print("Digite o Id do endereco a ser alterado: ");
                        auxIntAlt = input.nextLine();
                        
                        if(auxIntAlt.equals("cancelar")){
                            System.out.println("| Operacao cancelada com sucesso. |\n");
                            break;
                            //System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                        }
                        
                        try{
                            IdAlteracoes = Integer.parseInt(auxIntAlt);
                            DadosValidos = true;
                            System.out.println("");
                        }catch(NumberFormatException e){
                            System.out.println("| Tente novamente! Ou digite 'cancelar' para abortar a operacao |\n");
                        }
                    }
                   
                    if(!DadosValidos){
                        break;
                    }
                    
                    EnderecoContainer ContainerAlvo = null;
                    EnderecoContainer[] ArrayEnderecos = DadoAlvo.ObtemEnderecos();
                    for(EnderecoContainer aux : ArrayEnderecos){
                        if(IdAlteracoes == aux.Id){
                            ContainerAlvo = aux;
                            break;
                        }
                    }
                    
                    if(ContainerAlvo == null){
                        System.out.println("| O Id("+IdAlteracoes+") nao foi localizado nos enderecos deste contato.");
                        System.out.println("|         Alteracoes canceladas... Tente novamente!\n");
                        break;
                    }
                    
                    EscolhaDoUsuario = -1;
                    while(EscolhaDoUsuario != 0){
                        System.out.println("Dados alteraveis: ");
                        System.out.println("[00] Encerrar alteracoes.");
                        System.out.println("[01] Logradouro.");
                        System.out.println("[02] Numero.");
                        System.out.println("[03] Complemento.");
                        System.out.println("[04] Bairro.");
                        System.out.println("[05] Cidade.");
                        System.out.println("[06] Estado.");
                        System.out.println("[07] Cep.");
                        System.out.println("[08] Imprimir dados atuais.");
                        System.out.print("Escolha: ");
                        try{
                            EscolhaDoUsuario = Integer.parseInt(input.nextLine());
                        }catch(NumberFormatException e){
                            EscolhaDoUsuario = -1;
                        }
                        System.out.println("");
                        
                        String NewDado = null;
                        if(!(EscolhaDoUsuario < 0 && EscolhaDoUsuario > 8)){
                            System.out.print("Digite o dado que ira sobreescrever o antigo: ");
                            NewDado = input.nextLine();
                            System.out.println("");
                        }
                        
                        switch(EscolhaDoUsuario){
                            case 0:
                                DadoAlvo.AlterarDadosEndereco(ContainerAlvo.Id, ContainerAlvo.Logradouro, ContainerAlvo.Numero, ContainerAlvo.Complemento, ContainerAlvo.Bairro, ContainerAlvo.Cidade, ContainerAlvo.Estado, ContainerAlvo.CEP);
                                System.out.println("| Alteracoes encerradas e salvas. |\n");
                            break;
                            case 1:
                                ContainerAlvo.Logradouro = NewDado;
                            break;
                            case 2:
                                try{
                                    int NovoNumero = Integer.parseInt(NewDado);
                                    ContainerAlvo.Numero = NovoNumero;
                                }catch(NumberFormatException e){
                                    System.out.println("| Numero invalido... Alteracao deste atributo cancelada! |\n");
                                }
                            break;
                            case 3:
                                ContainerAlvo.Complemento = NewDado;
                            break;
                            case 4:
                                ContainerAlvo.Bairro = NewDado;
                            break;
                            case 5:
                                ContainerAlvo.Cidade = NewDado;
                            break;
                            case 6:
                                ContainerAlvo.Estado = NewDado;
                            break;
                            case 7:
                                ContainerAlvo.CEP = NewDado;
                            break;
                            case 8:
                                System.out.println("+-----------------------------------+");
                                System.out.println("| Id: "+ContainerAlvo.Id);
                                System.out.println("| Logradouro: "+ContainerAlvo.Logradouro);
                                System.out.println("| Numero: "+ContainerAlvo.Numero);
                                System.out.println("| Complemento: "+ContainerAlvo.Complemento);
                                System.out.println("| Bairro: "+ContainerAlvo.Bairro);
                                System.out.println("| Cidade: "+ContainerAlvo.Cidade);
                                System.out.println("| Estado: "+ContainerAlvo.Estado);
                                System.out.println("| Cep: "+ContainerAlvo.CEP); 
                                System.out.println("+-----------------------------------+\n");
                            break;
                            default:
                                System.out.println("| Escolha invalida... Tente novamente! |\n");
                            break;
                            
                        }   
                    }
                    
                    EscolhaDoUsuario = -1;
                break;
                default:
                    System.out.println("| Escolha invalida... Tente novamente! |\n");
                break;
            }
        }     
    }
    
    /**
     * Metodo responsavel por imprimir os telefones pertencentes a um contato.
     * @param Telefones Vetor com os telefones
     */
    private static void ImprimirTelefonesDeUmContato(String[] Telefones){
        System.out.println("\t+-------------------------------------+");
        System.out.println("\t| Imprimindo telefones deste contato: |");
        System.out.println("\t+-------------------------------------+\n");

        for(int i=0;i<Telefones.length;i++){
            if(i == Telefones.length - 1){
                System.out.println("| "+Telefones[i]+" |");
            }else{
                System.out.println("| "+Telefones[i]+" | "+Telefones[i+1]);
                i++;
            }
        }
        System.out.println("");
    }
    
    /**
     * Metodo responsavel por imprimir os enderecos de forma detalhada pertencentes a um contato.
     * @param Enderecos Vetor com os enderecos
     */
    private static void ImprimirEnderecosDeUmContato(EnderecoContainer[] Enderecos){
        System.out.println("\t+-------------------------------------+");
        System.out.println("\t| Imprimindo enderecos deste contato: |");
        System.out.println("\t+-------------------------------------+\n");

        for(EnderecoContainer aux : Enderecos){
            System.out.println("+-----------------------------------+");
            System.out.println("| Id: "+aux.Id);
            System.out.println("| Logradouro: "+aux.Logradouro);
            System.out.println("| Numero: "+aux.Numero);
            System.out.println("| Complemento: "+aux.Complemento);
            System.out.println("| Bairro: "+aux.Bairro);
            System.out.println("| Cidade: "+aux.Cidade);
            System.out.println("| Estado: "+aux.Estado);
            System.out.println("| Cep: "+aux.CEP); 
        }
        System.out.println("+-----------------------------------+\n");
    }
}