// Importações
import java.util.ArrayList;
/**
 * Classe que engloba os dados de uma pessoa, seja ela fisica ou jurica.
 * Tambem é responsavel por manipular seus telefones, enderecos, nome e identificador(CPF ou CNPJ).
 * @author Erik Neves
 */
public class Registro {
    
    /**
     * Objeto que armazena o tipo dessa pessoa(Fisica ou Juridica).
     */
    private Pessoa pessoa;
    /**
     * Stirng contendo o nome desse registro
     */
    private String Nome;
    /**
     * Lista duplamente encadeada responsavel por armazenar os telefones deste registro.
     */
    private final ArrayList<Telefone> Telefones = new ArrayList<>();
    /**
     * Lista duplamente encadeada responsavel por armazenar os enderecos deste registro.
     */
    private final ArrayList<Endereco> Enderecos = new ArrayList<>();
    
    /**
     * Construtor resposavel por inicializar os dados e criar o objeto de acordo com o 
     *           tipo de identificação passado como parametro.
     * @param nome
     * @param identificacao CPF ou CNPJ.
     * @throws IllegalStateException Exceção levantada caso a identificacao não se enquadre no formato de um CPF ou CNPJ.
     */
    public Registro(String nome, String identificacao) throws IllegalStateException {  
        if(PessoaFisica.Valida(identificacao)){
            this.pessoa = new PessoaFisica(identificacao);
        }else if(PessoaJuridica.Valida(identificacao)){
            this.pessoa = new PessoaJuridica(identificacao);
        }else{
            throw new IllegalStateException(identificacao+"(identificacao invalida)");
        }     
        this.Nome = nome;
    }
    
    /**
     * Metodo responsavel por retornar o numero de identificacao deste registro(CPF ou CNPJ).
     * @return String contendo o numero.
     */
    public String GetIdentificacao(){return this.pessoa.GetNumero();}
    /**
     * Metodo responsavel por identificar se este registro se refere a uma pessoa fisica ou juridica.
     * @return String contendo o tipo de identificacao(CPF ou CNPJ).
     */
    public String GetTipoIdentificacao(){
        if(this.pessoa instanceof PessoaFisica){
            return "CPF";
        }else{
            return "CNPJ";
        }
    }
    
    /**
     * Metodo responsavel por alterar o nome deste registro.
     * @param NewNome
     */
    public void SetNome(String NewNome){this.Nome = NewNome;}
    /**
     * Metodo responsavel por retornar o nome deste registro.
     * @return String - contendo o nome.
     */
    public String GetNome(){return this.Nome;}
    
    /**
     * Metodo responsavel por adicionar um novo numero de telefone aos dados deste registro.
     * @param telefone
     * @throws IllegalStateException Exceção levantada caso o telefone não esteja em um formato valido.
     */
    public void AddTelefone(String telefone) throws IllegalStateException{
        this.Telefones.add(new Telefone(telefone));
        
    }

    /**
     * Metodo responsavel por remover um telefone presente nos dados deste registro.
     * @param telefone Alvo
     */
    public void RemoveTelefone(String telefone){
        for(int i=0;i<this.Telefones.size();i++){
            if(telefone.equals(this.Telefones.get(i).GetTelefone())){
                this.Telefones.remove(i);
                break;
            }
        }
    }
    
    /**
     * Metodo responsavel por copiar e carregar os telefones deste registro em um array.
     * @return String[] - contendo todos os telefones.
     */
    public String[] ObtemTelefones(){ 
        String[] ArrayTelefones = new String[this.Telefones.size()];  
        for(int i=0;i<this.Telefones.size();i++){
            ArrayTelefones[i] = this.Telefones.get(i).GetTelefone();
        }  
        return ArrayTelefones;    
    }
    
    /**
     * Metodo responsavel por criar um novo endereco e armazenalo nos dados deste registro.
     * @param logradouro
     * @param numero
     * @param complemento
     * @param bairro
     * @param cidade
     * @param estado
     * @param cep 
     */
    public void AddEndereco(String logradouro, int numero, String complemento, String bairro, String cidade, String estado, String cep){
        this.Enderecos.add(new Endereco(logradouro,numero,complemento,bairro,cidade,estado,cep));
    }
    
    /**
     * Metodo responsavel por remover um endereco deste registro.
     * @param Id identificador do alvo.
     */
    public void RemoveEndereco(int Id){ 
        for(int i=0;i<this.Enderecos.size();i++){
            if(this.Enderecos.get(i).GetId() == Id){
                this.Enderecos.remove(i);
                break;
            }
        }
    }
    
    /**
     * Sobreescreve os dados salvos de um endereco pelos passados como parametro
     * @param Id Identificador do alvo.
     * @param logradouro
     * @param numero
     * @param complemento
     * @param bairro
     * @param cidade
     * @param estado
     * @param cep
     */
    public void AlterarDadosEndereco(int Id,String logradouro, int numero, String complemento, String bairro, String cidade, String estado, String cep){
        for(int i=0;i<this.Enderecos.size();i++){
            Endereco aux = this.Enderecos.get(i);
            if(aux.GetId() == Id){
                aux.SetLogradouro(logradouro);
                aux.SetNumero(numero);
                aux.SetComplemento(complemento);
                aux.SetBairro(bairro);
                aux.SetCidade(cidade);
                aux.SetEstado(estado);
                aux.SetCEP(cep);
                break;
            }        
        }   
    }
    
    /**
     * Metodo responsavel por copiar e carregar os enderecos deste registro em um array.
     * @return EnderecoContainer[] - contendo todos os enderecos.
     */
    public EnderecoContainer[] ObtemEnderecos(){
        EnderecoContainer[] ArrayEnderecos = new EnderecoContainer[this.Enderecos.size()];
        for(int i=0;i<this.Enderecos.size();i++){
            Endereco aux = this.Enderecos.get(i);
            ArrayEnderecos[i] = new EnderecoContainer(aux.GetId(),aux.GetLogradouro(),aux.GetNumero(),aux.GetComplemento(),aux.GetBairro(),aux.GetCidade(),aux.GetEstado(),aux.GetCEP());
        }  
        return ArrayEnderecos;
    }
        
    /**
     * Metodo responsavel por imprimir todos os dados presentes neste registro.
     */
    public void Imprimir(){
        
        String Type;
        if(this.pessoa instanceof PessoaFisica){Type = "fisica";}else{Type = "juridica";}
           
        System.out.println("Este registro se refere a uma pessoa: "+Type);
        System.out.println("Nome: "+this.Nome+"\nIdentificacao: "+pessoa.Numero);
        
        System.out.println("+-----------------------------------+");
        System.out.println("| Este registro possui: "+this.Telefones.size()+" telefones.");
        for(int i=0;i<this.Telefones.size();i++){
            if(i == this.Telefones.size() - 1){
                System.out.println("| "+this.Telefones.get(i).GetTelefone()+" |");
            }else{
                System.out.println("| "+this.Telefones.get(i).GetTelefone()+" | "+this.Telefones.get(i+1).GetTelefone());
                i++;
            }
        }
        
        System.out.println("+-----------------------------------+");
        System.out.println("| Este registro possui: "+this.Enderecos.size()+" enderecos.");
        for(int i=0;i<this.Enderecos.size();i++){
            System.out.println("+-----------------------------------+");
            Endereco aux = this.Enderecos.get(i);
            System.out.println("| Id: "+aux.GetId());
            System.out.println("| Logradouro: "+aux.GetLogradouro());
            System.out.println("| Numero: "+aux.GetNumero());
            System.out.println("| Complemento: "+aux.GetComplemento());
            System.out.println("| Bairro: "+aux.GetBairro());
            System.out.println("| Cidade: "+aux.GetCidade());
            System.out.println("| Estado: "+aux.GetEstado());
            System.out.println("| Cep: "+aux.GetCEP()); 
        }
        System.out.println("+-----------------------------------+\n");
        
    }
    
}