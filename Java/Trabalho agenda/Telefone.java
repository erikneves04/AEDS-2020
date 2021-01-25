/**
 * Classe com os dados de um telefone, com seus respectivos getters e setters.
 * @author Erik Neves
 */
public class Telefone {
    
    /**
     * Variavel reponsavel por armazenar o numero deste objeto.
     */
    private String Numero;
    
    /**
     * Construtor responsagel por inicializar o numero dessa pessoa.
     * @param numero
     */
    public Telefone(String numero){
        this.Numero = numero;
    }
    
    /**
     * Metodo responsavel por setar o numero deste objeto.
     * @param numero Dado que ira sobreescrever o antigo.
     */
    public void SetTelefone(String numero){this.Numero = numero;}
    /**
     * Metodo de retorno da variavel numero deste objeto.
     * @return String com o numero
     */
    public String GetTelefone(){return this.Numero;}
    
    /**
     * Metodo responsavel por comparar dois numeros.
     * @param numero Dado para a comparação(retorna verdadeiro se forem iguais).
     */
    private boolean Valida(String numero){return (this.Numero.equals(numero));}
    
}
