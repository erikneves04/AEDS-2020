/**
 * Classe com os dados de uma pessoa juridica, com seus respectivos getters e setters.
 * @author Erik Neves
 */
public class PessoaJuridica extends Pessoa {
    
    private static final int NumeroDeCaracteresCNPJ = 14;
    private static final String MensagemException = "Numero de cpf invalido.Formato de 14 digitos.";
    
    /**
     * Construtor responsagel por inicializar o numero(CNPJ) dessa pessoa.
     * @param numero
     * @throws IllegalStateException Exceção levantada caso o numero não seja um CNPJ valido.
     */
    public PessoaJuridica(String numero) throws IllegalStateException{
        if(!PessoaJuridica.Valida(numero)){
            throw new IllegalStateException(PessoaJuridica.MensagemException);
        }
        this.Numero = numero;
    }   
    
    /**
     * Metodo responsavel por setar o numero(CNPJ) dessa pessoa.
     * @param numero Dado que ira sobreescrever o antigo.
     * @throws IllegalStateException Exceção levantada caso o numero não seja um CNPJ valido.
     */
    @Override
    public void SetNumero(String numero) throws IllegalStateException{
        if(!PessoaJuridica.Valida(numero)){
            throw new IllegalStateException(PessoaJuridica.MensagemException);
        }
        this.Numero = numero;
    }
    
    /**
     * Metodo responsavel por por validar o formato de um CNPJ
     * @param numero a ser validado
     * @return true caso seja valido
     */
    protected static boolean Valida(String numero){
        if(numero.length() != PessoaJuridica.NumeroDeCaracteresCNPJ){return false;} 
        return numero.substring(0).matches("[0-9]*");
    }
    
}
