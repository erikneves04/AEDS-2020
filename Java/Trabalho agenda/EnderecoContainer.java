/**
 * Classe com os dados de um endereço, com seus atributos copiados de um Endereco e definidos 
 *              como publicos somente para acesso fora da classe registro.
 * @author Erik Neves
 */
public class EnderecoContainer {
    
    /**
     * Variavel reponsavel por armazenar o Id deste endereço.
     */
    public final int Id;
    
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
     * @param Id
     * @param logradouro
     * @param numero
     * @param complemento
     * @param bairro
     * @param cidade
     * @param estado
     * @param cep 
     */
    public EnderecoContainer(int Id,String logradouro, int numero, String complemento, String bairro, String cidade, String estado, String cep){
        this.Id = Id;
        this.Logradouro = logradouro;
        this.Numero = numero;
        this.Complemento = complemento;
        this.Bairro = bairro;
        this.Cidade = cidade;
        this.Estado = estado;
        this.CEP = cep;
    }
}
