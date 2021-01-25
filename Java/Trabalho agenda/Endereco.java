/**
 * Classe com os dados de um endereço, com seus respectivos getters e setters.
 * @author Erik Neves
 */
public class Endereco extends EnderecoContainer {
    
    /**
     * Construtor responsavel por inicializar os dados deste objeto.
     * @param logradouro
     * @param numero
     * @param complemento
     * @param bairro
     * @param cidade
     * @param estado
     * @param cep 
     */
    public Endereco(String logradouro, int numero, String complemento, String bairro, String cidade, String estado, String cep){
        super();
        this.Logradouro = logradouro;
        this.Numero = numero;
        this.Complemento = complemento;
        this.Bairro = bairro;
        this.Cidade = cidade;
        this.Estado = estado;
        this.CEP = cep;
    }
    
    /**
     * Metodo de retorno da variavel id deste objeto.
     * @return int contendo o valor da variavel id.
     */
    public int GetId(){return this.Id;}
    
    /**
     * Metodo responsavel por setar o valor da variavel logradouro.
     * @param logradouro Dado que ira sobreescrever o antigo.
     */
    public void SetLogradouro(String logradouro){this.Logradouro = logradouro;}
    /**
     * Metodo de retorno da variavel logradouro deste objeto.
     * @return String contendo o valor da variavel logradouro.
     */
    public String GetLogradouro(){return this.Logradouro;}
    
    /**
     * Metodo responsavel por setar o valor da variavel numero.
     * @param numero Dado que ira sobreescrever o antigo.
     */
    public void SetNumero(int numero){this.Numero = numero;}
    /**
     * Metodo de retorno da variavel numero deste objeto.
     * @return int contendo o valor da variavel numero.
     */
    public int GetNumero(){return this.Numero;}
    
    /**
     * Metodo responsavel por setar o valor da variavel complemento.
     * @param complemento Dado que ira sobreescrever o antigo.
     */
    public void SetComplemento(String complemento){this.Complemento = complemento;}
    /**
     * Metodo de retorno da variavel complemento deste objeto.
     * @return String contendo o valor da variavel complemento.
     */
    public String GetComplemento(){return this.Complemento;}
    
    /**
     * Metodo responsavel por setar o valor da variavel bairro.
     * @param bairro Dado que ira sobreescrever o antigo.
     */
    public void SetBairro(String bairro){this.Bairro = bairro;}
    /**
     * Metodo de retorno da variavel bairro deste objeto.
     * @return String contendo o valor da variavel bairro.
     */
    public String GetBairro(){return this.Bairro;}
    
    /**
     * Metodo responsavel por setar o valor da variavel cidade.
     * @param cidade Dado que ira sobreescrever o antigo.
     */
    public void SetCidade(String cidade){this.Cidade = cidade;}
    /**
     * Metodo de retorno da variavel cidade deste objeto.
     * @return String contendo o valor da variavel cidade.
     */
    public String GetCidade(){return this.Cidade;}
    
    /**
     * Metodo responsavel por setar o valor da variavel estado.
     * @param estado Dado que ira sobreescrever o antigo.
     */
    public void SetEstado(String estado){this.Estado = estado;}
    /**
     * Metodo de retorno da variavel estado deste objeto.
     * @return String contendo o valor da variavel estado.
     */
    public String GetEstado(){return this.Estado;}
    
    /**
     * Metodo responsavel por setar o valor da variavel cep.
     * @param cep Dado que ira sobreescrever o antigo.
     */
    public void SetCEP(String cep){this.CEP = cep;}
    /**
     * Metodo de retorno da variavel cep deste objeto.
     * @return String contendo o valor da variavel cep.
     */
    public String GetCEP(){return this.CEP;}
    
}