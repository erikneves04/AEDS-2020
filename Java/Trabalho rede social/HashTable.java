/**
 *
 * @author Erik Neves
 * @date 2020-11-25
*/
import java.util.ArrayList;

public class HashTable {
    
    int NumeroDePerfis;
    int NumeroDeColunas;
    ArrayList<ItemLista> DadosTabela = new ArrayList<>();
    
    //Implementação da inserção na tabela hash;
    
    private int GetIndexPerfil(String user){
        int count = 0;
        byte[] bytes = new byte[user.length()];
        
        bytes = user.getBytes();
        
        for(int i=0;i<bytes.length;i++){
            count += (int)bytes[i];
        }
        
        return (count/10);
    }
    
    public int InserirNovoItem(Perfil NovoPerfil){
        int IndexNovoPerfil = this.GetIndexPerfil(NovoPerfil.GetUserName());
        ItemLista NovoItem = new ItemLista();
        ItemLista DadosColuna;
        
        if(this.NumeroDeColunas < IndexNovoPerfil){
            for(int i = this.NumeroDeColunas;i<IndexNovoPerfil;i++){
                this.DadosTabela.add(i,null);
            }
            this.NumeroDeColunas = IndexNovoPerfil;
        }
        IndexNovoPerfil -= 1;
        if(this.DadosTabela.get(IndexNovoPerfil) == null){
            NovoItem.InicializarItemLista(NovoPerfil, null, null);
            this.DadosTabela.add(IndexNovoPerfil, NovoItem);
        }else{
            DadosColuna = this.DadosTabela.get(IndexNovoPerfil);
            while(DadosColuna.GetProximoItemLista() != null){
                if(DadosColuna.GetProximoItemLista() != null ){
                    DadosColuna = DadosColuna.GetProximoItemLista();
                }
            }
            NovoItem.InicializarItemLista(NovoPerfil,null,DadosColuna);
            DadosColuna.SetProximoItemLista(NovoItem);        
            
        }
        this.NumeroDePerfis++;
        
        return Const.Sucesso;
    }
    public boolean PerfilExistente(String NomeProcurado){
        boolean PerfilEncontrado = false;
        ItemLista DadosColuna;
        int IndexProcurado = (this.GetIndexPerfil(NomeProcurado) - 1);
        
        if(this.NumeroDeColunas > IndexProcurado){
            DadosColuna = this.DadosTabela.get(IndexProcurado);
            while(DadosColuna != null){
                if(NomeProcurado.equals(DadosColuna.GetDadosItem().GetUserName())){
                    PerfilEncontrado = true;
                    break;
                }
                DadosColuna = DadosColuna.GetProximoItemLista();
            }
        }
        
        return PerfilEncontrado;
    }
}
