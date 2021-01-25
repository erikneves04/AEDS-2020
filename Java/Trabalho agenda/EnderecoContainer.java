/**
 * Classe com os dados de um endereço, com seus respectivos getters e setters.
 * @author Erik Neves
 */
public class EnderecoContainer {
    
    /** 
     * Variavel estatica responsavel por armazenar o Id disponivel atual.
     */
    private static int CalculoIDs = 1;
    /**
     *  Metodo estatico responsável setar a variavel "CalculoIDs" para que ela se inicie em determinado Id. 
     * @param Id Identificador inicial.
     */
    public static void SetIDInicial(int Id){
        EnderecoContainer.CalculoIDs = Id;
    }
    
    /**
     * Variavel reponsavel por armazenar o Id deste endereço.
     */
    public final int Id = EnderecoContainer.CalculoIDs++;
    
    /**
     * Variavel reponsavel por armazenar o logradouro deste endereço.
     */
    public String Logradouro;
    /**
     * Variavel reponsavel por armazenar o numero deste endereço.
     */
    public int Numero;
    /**
     * Variavel reponsavel por armazenar o complemento deste endereço.
     */
    public String Complemento;
    /**
     * Variavel reponsavel por armazenar o bairro deste endereço.
     */
    public String Bairro;
    /**
     * Variavel reponsavel por armazenar o cidade deste endereço.
     */
    public String Cidade;
    /**
     * Variavel reponsavel por armazenar o estado deste endereço.
     */
    public String Estado;
    /**
     * Variavel reponsavel por armazenar o cep deste endereço.
     */
    public String CEP;
    
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
    public EnderecoContainer(String logradouro, int numero, String complemento, String bairro, String cidade, String estado, String cep){
        this.Logradouro = logradouro;
        this.Numero = numero;
        this.Complemento = complemento;
        this.Bairro = bairro;
        this.Cidade = cidade;
        this.Estado = estado;
        this.CEP = cep;
    }
    /**
     * Construtor default.
     */
    public EnderecoContainer(){}
}
