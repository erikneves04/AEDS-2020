/**
 * Classe com os dados de uma pessoa juridica, com seus respectivos getters e setters.
 * @author Erik Neves
 */
public class PessoaJuridica extends Pessoa {
    
    /**
     * Construtor responsagel por inicializar o numero dessa pessoa.
     * @param numero
     */
    public PessoaJuridica(String numero){
        this.Numero = numero;
    }   
    
    /**
     * Metodo responsavel por setar o numero dessa pessoa.
     * @param numero Dado que ira sobreescrever o antigo.
     */
    @Override
    public void SetNumero(String numero) {
        this.Numero = numero;
    }
    
    /**
     * Metodo responsavel por comparar dois numeros.
     * @param numero Dado para a comparação(retorna verdadeiro se forem iguais).
     */
    private boolean Valida(String numero){
        return (this.Numero.equals(numero));
    }
    
}
