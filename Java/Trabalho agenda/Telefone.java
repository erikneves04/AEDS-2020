/**
 * Classe com os dados de um telefone, com seus respectivos getters e setters.
 * @author Erik Neves
 */
public class Telefone {
    
    private static final int NumeroDeCaracteresTotal = 11;
    private static final String MensagemException = "Numero de telefonde invalido.Formato de 9 digitos, mais o DDD.";
    
    /**
     * Variavel reponsavel por armazenar o numero de telefone de uma pessoa.
     */
    private String Numero;
    
    /**
     * Construtor responsagel por inicializar o numero dessa pessoa.
     * @param numero
     */
    public Telefone(String numero) throws IllegalStateException{
        if(!this.Valida(numero)){
            throw new IllegalStateException("Numero de telefonde invalido.Formato de 9 digitos, mais o DDD.");
        }
        this.Numero = numero;
    }
    
    /**
     * Metodo responsavel por setar o numero deste objeto.
     * @param numero Dado que ira sobreescrever o antigo.
     */
    public void SetTelefone(String numero) throws IllegalStateException{
        if(!this.Valida(numero)){
            throw new IllegalStateException(Telefone.MensagemException);
        }
        this.Numero = numero;
    }
    /**
     * Metodo de retorno da variavel numero deste objeto.
     * @return String com o numero.
     */
    public String GetTelefone(){return this.Numero;}
    
    /**
     * Metodo responsavel por validar um numero de telefone.
     * @param numero A ser verificado.
     * @return true se ele foi valido.
     */
    protected boolean Valida(String numero){  
        if(numero.length() != Telefone.NumeroDeCaracteresTotal){return false;} 
        return numero.substring(0).matches("[0-9]*");
    }
    
}
