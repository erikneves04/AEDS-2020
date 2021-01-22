/**
 * Classe abstrata com os dados de uma pessoa, com seus respectivos getters e setters.
 * @author Erik Neves
 */
abstract class Pessoa {

    /**
     * Variavel reponsavel por armazenar o numero dessa pessoa.
     */
    protected String Numero;
    
    /**
     * Metodo responsavel por setar o numero dessa pessoa.
     * @param numero Dado que ira sobreescrever o antigo.
     */
    public abstract void SetNumero(String numero);
    /**
     * Metodo de retorno da variavel numero deste objeto.
     * @return String com o numero
     */
    public String GetNumero(){return this.Numero;}
    
}
