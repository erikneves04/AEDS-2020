/**
 * Classe com os dados de uma pessoa fisica, com seus respectivos getters e setters.
 * @author Erik Neves
 */
public class PessoaFisica extends Pessoa{

    private static final int NumeroDeCaracteresCPF = 11;
    private static final String MensagemException = "Numero de cpf invalido.Formato de 11 digitos.";
    
    /**
     * Construtor responsagel por inicializar o numero(CPF) dessa pessoa.
     * @param numero
     */
    public PessoaFisica(String numero){
        super("Fisica");
        if(!this.Valida(numero)){
            throw new IllegalStateException(PessoaFisica.MensagemException);
        }
        this.Numero = numero;
    }   
    
    /**
     * Metodo responsavel por setar o numero(CPF) dessa pessoa.
     * @param numero Dado que ira sobreescrever o antigo.
     */
    @Override
    public void SetNumero(String numero) throws IllegalStateException{
        if(!this.Valida(numero)){
            throw new IllegalStateException(PessoaFisica.MensagemException);
        }
        this.Numero = numero;
    }
    
    /**
     * Metodo responsavel por validar o formato de um CPF
     * @param numero a ser validado
     * @return true se o numero for valido
     */
    protected static boolean Valida(String numero){
        if(numero.length() != PessoaFisica.NumeroDeCaracteresCPF){return false;} 
        return numero.substring(0).matches("[0-9]*");
    }
    
}
