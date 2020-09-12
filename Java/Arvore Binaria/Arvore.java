/**
 *
 * @author Erik Neves
 */

public class Arvore {
    
    private Item_arvore RaizPrincipal;
    private int NumeroDeInclusoes;

    public void InicializarArvoreVazia(){
        this.RaizPrincipal = null;
        this.NumeroDeInclusoes = 0;
    }
    public void CriarArvore(Item_arvore NovaArvore,int Dado,Item_arvore Esquerda,Item_arvore Direita){
        this.NumeroDeInclusoes++;
        NovaArvore = new Item_arvore();
        NovaArvore.InserirDadosArvore(Dado,Esquerda,Direita);
    }
    public void InserirArvoreOrdenada(Item_arvore NovaArvore,Item_arvore ArvoreAtual){
        if(NovaArvore.GetDado() == ArvoreAtual.GetDado()) return;
        if(NovaArvore.GetDado() > ArvoreAtual.GetDado()){
            if(ArvoreAtual.GetArvoreDireita() == null){
                ArvoreAtual.SetArvoreDireita(NovaArvore);
            }else if (ArvoreAtual.GetArvoreDireita().GetDado() > NovaArvore.GetDado()){
                NovaArvore.SetArvoreDireita(ArvoreAtual.GetArvoreDireita());
                ArvoreAtual.SetArvoreDireita(NovaArvore);
            }else{
                this.InserirArvoreOrdenada(NovaArvore,ArvoreAtual.GetArvoreDireita());
            }
        }else{
            if(ArvoreAtual.GetArvoreEsquerda() == null){
                ArvoreAtual.SetArvoreEsquerda(NovaArvore); 
            }else if(ArvoreAtual.GetDado() < NovaArvore.GetDado()){
                NovaArvore.SetArvoreEsquerda(ArvoreAtual.GetArvoreEsquerda());
                ArvoreAtual.SetArvoreEsquerda(NovaArvore); 
            }else{
                InserirArvoreOrdenada(NovaArvore,ArvoreAtual.GetArvoreEsquerda());
            }
        }
    }
    public Boolean ArvoreVazia(Item_arvore ArvoreAtual){
        return (ArvoreAtual == null) ? true : false;
    }
    public void ImprimirArvore(Item_arvore ArvoreAtual){
        if(this.ArvoreVazia(ArvoreAtual) == false){
            System.out.println("Dado: "+ArvoreAtual.GetDado());

            this.ImprimirArvore(ArvoreAtual.GetArvoreEsquerda());
            this.ImprimirArvore(ArvoreAtual.GetArvoreDireita());
        }
    }
    public Boolean DadoContidoNaArvore(Item_arvore ArvoreAtual,int DadoProcurado){
        if(ArvoreVazia(ArvoreAtual)) return false;
        return ((ArvoreAtual.GetDado() == DadoProcurado) 
        || (DadoContidoNaArvore(ArvoreAtual.GetArvoreDireita(),DadoProcurado) == true) 
        || (DadoContidoNaArvore(ArvoreAtual.GetArvoreEsquerda(),DadoProcurado) == true)) ? true : false;
    }
    public int GetAltura_Arvore(Item_arvore arvore){
        if(ArvoreVazia(arvore)) return 0;
        return (GetAltura_Arvore(arvore.GetArvoreEsquerda()) + GetAltura_Arvore(arvore.GetArvoreDireita()) + 1);
    }
    public int GetNosComDoisFilhos(Item_arvore arvore){
        int Aux = 0;
        if((arvore.GetArvoreDireita() == null) && (arvore.GetArvoreEsquerda() == null)) Aux = 0;
        if((arvore.GetArvoreDireita() != null) && (arvore.GetArvoreEsquerda() != null)) Aux = 1;
    
        if(arvore.GetArvoreDireita() == null || arvore.GetArvoreEsquerda() == null){
            return Aux;
        }else{
            return Aux + ((GetNosComDoisFilhos(arvore.GetArvoreDireita())) + (GetNosComDoisFilhos(arvore.GetArvoreEsquerda())));
        }
    }
    public int GetNosComUmFilhos(Item_arvore arvore){
        int Aux = 0;
        if((this.RaizPrincipal.GetArvoreDireita() == null) && (this.RaizPrincipal.GetArvoreEsquerda() == null)) Aux = 0;
        if((this.RaizPrincipal.GetArvoreDireita() != null) && (this.RaizPrincipal.GetArvoreEsquerda() != null)) Aux = 0;
        if((this.RaizPrincipal.GetArvoreDireita() != null) && (this.RaizPrincipal.GetArvoreEsquerda() == null)) Aux = 1;
        if((this.RaizPrincipal.GetArvoreDireita() == null) && (this.RaizPrincipal.GetArvoreEsquerda() != null)) Aux = 1;
    
        if((this.RaizPrincipal.GetArvoreDireita() == null) && (this.RaizPrincipal.GetArvoreEsquerda() == null)) return Aux;
        if(this.RaizPrincipal.GetArvoreDireita() != null) return Aux + (GetNosComUmFilhos(this.RaizPrincipal.GetArvoreDireita()));
        if(this.RaizPrincipal.GetArvoreEsquerda() != null) return Aux + (GetNosComUmFilhos(this.RaizPrincipal.GetArvoreEsquerda()));
        return 0;
    }
}