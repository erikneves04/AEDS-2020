import java.util.Arrays;

/**
 *
 * @author Erik Neves
 * @date 2020-11-26
*/

public class Buscas {
    public int BuscaPorLargura(Perfil Inicial){
        ListaEncadeadaPerfis PerfisAcessiveis = new ListaEncadeadaPerfis();
        PerfisAcessiveis.InicializarListaEncadeada();
        ListaEncadeadaPerfis Fila = new ListaEncadeadaPerfis();
        Fila.InicializarListaEncadeada();
        
        boolean[] ArestrasCarregadas = new boolean[Interacoes.ContagemIdentificadores];
        Arrays.fill(ArestrasCarregadas,false);
        int[] NumeroDeLoadsPorNivel = new int[Const.DistanciaPerfis];
        Arrays.fill(NumeroDeLoadsPorNivel,0);
        
        int ContagemDeCarregamentos = 0;
        int ProfundidadeAtual = 0;
        int LenQue_CarregadosPeloAtua = 0;
        ItemLista Follows;
        Perfil Atual = Inicial;
        
        PerfisAcessiveis.InserirNovoItem_MODOFILA(Atual);
        NumeroDeLoadsPorNivel[0] = Inicial.Seguindo.GetNumeroDeItens();
        while(ProfundidadeAtual < Const.DistanciaPerfis){
            LenQue_CarregadosPeloAtua = 0;
            Follows = Atual.Seguindo.GetPrimeiroItem();
            while(Follows != null){
                if(!ArestrasCarregadas[Follows.GetDadosItem().GetIdPerfil()] && !ArestrasCarregadas[Atual.GetIdPerfil()]){
                    Fila.InserirNovoItem_MODOFILA(Follows.GetDadosItem());
                    PerfisAcessiveis.InserirNovoItem(Follows.GetDadosItem());
                    LenQue_CarregadosPeloAtua++;
                }
                Follows = Follows.GetProximoItemLista();
            }
            if((ProfundidadeAtual+1) < Const.DistanciaPerfis)NumeroDeLoadsPorNivel[ProfundidadeAtual+1] += LenQue_CarregadosPeloAtua;
            ContagemDeCarregamentos++;
            ArestrasCarregadas[Atual.GetIdPerfil()] = true;
            System.out.println("Loads do nivel("+ProfundidadeAtual+"): "+NumeroDeLoadsPorNivel[ProfundidadeAtual]);
            if(NumeroDeLoadsPorNivel[ProfundidadeAtual] == ContagemDeCarregamentos){
                ProfundidadeAtual++;
                ContagemDeCarregamentos = 0;
                System.out.println("Carregamentos: "+ContagemDeCarregamentos+" Nivel: "+ProfundidadeAtual);
            }
            
            System.out.println("Atual: "+Atual.GetUserName()+" Count: "+ContagemDeCarregamentos+" Nivel: "+ProfundidadeAtual);
            
            if(!Fila.ListaVazia()){
                Atual = Fila.RemoverItem_MODOFILA();
            }else{
                break;
            }
        }
        
        PerfisAcessiveis.ImprimirPerfisDaLista();
        
        return Const.Sucesso;
    }
}
