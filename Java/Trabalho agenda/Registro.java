/**
 *
 * @author Notebook
 */
public class Registro {

    private Pessoa pessoa;
    private String Nome;
    private final ListaEncadeada<Telefone> Telefones = new ListaEncadeada<>();
    private final ListaEncadeada<Endereco> Enderecos = new ListaEncadeada<>();
    
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
    
    public void SetNome(String NewNome){this.Nome = NewNome;}
    public String GetNome(){return this.Nome;}
    
    public void AddTelefone(String telefone) throws IllegalStateException{
        this.Telefones.add(new Telefone(telefone));
    }
    public void RemoveTelefone(String telefone){
        for(int i=0;i<this.Telefones.GetNElements();i++){
            if(telefone.equals(this.Telefones.GetDataIndex(i).GetTelefone())){
                this.Telefones.remove(i);
                break;
            }
        }
    }
    public String[] ObtemTelefones(){ 
        String[] ArrayTelefones = new String[this.Telefones.GetNElements()];  
        for(int i=0;i<this.Telefones.GetNElements();i++){
            ArrayTelefones[i] = this.Telefones.GetDataIndex(i).GetTelefone();
        }  
        return ArrayTelefones;    
    }
    
    public void AddEndereco(String logradouro, int numero, String complemento, String bairro, String cidade, String estado, String cep){
        this.Enderecos.add(new Endereco(logradouro,numero,complemento,bairro,cidade,estado,cep));
    }
    public void RemoveEndereco(int Id){ 
        for(int i=0;i<this.Enderecos.GetNElements();i++){
            if(this.Enderecos.GetDataIndex(i).GetId() == Id){
                this.Enderecos.remove(i);
                break;
            }
        }
    }
    public EnderecoContainer[] ObtemEnderecos(){
        EnderecoContainer[] ArrayEnderecos = new EnderecoContainer[this.Enderecos.GetNElements()];
        for(int i=0;i<this.Enderecos.GetNElements();i++){
            Endereco aux = this.Enderecos.GetDataIndex(i);
            ArrayEnderecos[i] = new EnderecoContainer(aux.GetId(),aux.GetLogradouro(),aux.GetNumero(),aux.GetComplemento(),aux.GetBairro(),aux.GetCidade(),aux.GetEstado(),aux.GetCEP());
        }  
        return ArrayEnderecos;
    }
        
    public void Imprimir(){
        System.out.println("\nEste registri se refere a uma pessoa: "+pessoa.TipoPessoa);
        System.out.println("Nome: "+this.Nome+"\n Identificacao: "+pessoa.Numero);
        
        System.out.println("+-----------------------------------+");
        System.out.println("| Este registro possui: "+this.Telefones.GetNElements()+" telefones.");
        System.out.println("");
        for(int i=0;i<this.Telefones.GetNElements();i++){
            if(i == this.Telefones.GetNElements() - 1){
                System.out.println("| "+this.Telefones.GetDataIndex(i).GetTelefone()+" |");
            }else{
                System.out.println("| "+this.Telefones.GetDataIndex(i).GetTelefone()+" | "+this.Telefones.GetDataIndex(i+1).GetTelefone());
                i++;
            }
        }
        
        System.out.println("+-----------------------------------+");
        System.out.println("| Este registro possui: "+this.Enderecos.GetNElements()+" enderecos.");
        System.out.println("");
        for(int i=0;i<this.Enderecos.GetNElements();i++){
            Endereco aux = this.Enderecos.GetDataIndex(i);
            System.out.println("| Id: "+aux.GetId());
            System.out.println("| Logradouro: "+aux.GetLogradouro());
            System.out.println("| Numero: "+aux.GetNumero());
            System.out.println("| Complemento: "+aux.GetComplemento());
            System.out.println("| Bairro: "+aux.GetBairro());
            System.out.println("| Cidade: "+aux.GetCidade());
            System.out.println("| Estado: "+aux.GetEstado());
            System.out.println("| Cep: "+aux.GetCEP());
            System.out.println("+-----------------------------------+");
        }
    }
    
}
