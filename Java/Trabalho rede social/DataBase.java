import java.io.*;
import java.util.ArrayList;

/**
 *
 * @author Erik Neves
 * @date 2020-11-28
*/

public class DataBase {  
    // TODO tratamento de exceções brabo
    public int LoadData(HashTable table)throws FileNotFoundException, IOException,ClassNotFoundException{
        Perfil PerfilAtual;
        ArrayList<Perfil> DadosPerfis = new ArrayList<>();
        ArrayList<int[]> NumeroDeLikesPostagens = new ArrayList<>();
        
        FileInputStream ArquivoPerfis = new FileInputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Perfis.bin");
        FileInputStream ArquivoPostagens = new FileInputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Posts.bin");
        FileInputStream ArquivoFollows = new FileInputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Follows.bin");
        FileInputStream ArquivoLikes = new FileInputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Likes.bin");
        
        ObjectInputStream ObjetoRead_perfis = new ObjectInputStream(ArquivoPerfis);
        ObjectInputStream ObjetoRead_posts = new ObjectInputStream(ArquivoPostagens);
        ObjectInputStream ObjetoRead_follows = new ObjectInputStream(ArquivoFollows);
        ObjectInputStream ObjetoRead_likes = new ObjectInputStream(ArquivoLikes);
        
        int NumeroDePerfis = ObjetoRead_perfis.read();
        int[] NumeroDeFollows = new int[NumeroDePerfis];
        
        for(int i=0; i<NumeroDePerfis;i++){
            SaveModel DadosLeitura = new SaveModel();
            PerfilAtual = new Perfil();
            DadosPerfis.add(PerfilAtual);
            DadosLeitura = (SaveModel) ObjetoRead_perfis.readObject();
            int NumPosts = DadosLeitura.GetNumeroDePostagens();
            int NumFollows = DadosLeitura.GetNumeroDePerfisSeguidos();
            NumeroDeFollows[i] = NumFollows;
            
            // Carregamento no perfil atual;
            PerfilAtual.SetInformacoesPerfil(DadosLeitura.GetId(),DadosLeitura.GetNomeCompleto(),DadosLeitura.GetNomeUsuario(), true);
             
            int[] LikesPostagensDoPerfil = new int[NumPosts];
            NumeroDeLikesPostagens.add(LikesPostagensDoPerfil);
            
            for(int j=0;j<NumPosts;j++){
                Postagem DadosPostagens = new Postagem();
                int Id = ObjetoRead_posts.readInt();
                String Texto = (String)ObjetoRead_posts.readObject();
                int NumLikes = ObjetoRead_posts.readInt();
                LikesPostagensDoPerfil[j] = NumLikes;
                DadosPostagens.InserirDadosPostagem(Id, Texto, PerfilAtual.GetUserName());
                PerfilAtual.Postagens.InserirNovoItem(DadosPostagens);
            }
            table.InserirNovoItem(PerfilAtual);
        }
        
        ItemListaPost DadosPosts;
        for(int i=0;i<NumeroDePerfis;i++){
            DadosPosts = DadosPerfis.get(i).Postagens.GetPrimeiroItem();
            for(int j=0;j<DadosPerfis.get(i).Postagens.GetNumeroDeItens();j++){
                if(DadosPosts.GetProximoItemLista() != null) DadosPosts = DadosPosts.GetProximoItemLista();
            }
            for(int j=0;j<DadosPerfis.get(i).Postagens.GetNumeroDeItens();j++){
                for(int k=0;k<NumeroDeLikesPostagens.get(i)[j];k++){
                    // Leitura dos nomes de usuario
                    String procurado = (String)ObjetoRead_likes.readObject();
                    Perfil PerfilAux = table.GetPerfil(procurado);
                    DadosPosts.GetDadosItem().Curtidas.InserirNovoItem(PerfilAux);
                    PerfilAux.PostagensCurtidas.InserirNovoItem(DadosPosts.GetDadosItem());
                }
                DadosPosts = DadosPosts.GetAnteriorItemLista();
            }
        }
        
        for(int i=0;i<NumeroDePerfis;i++){
            for(int j=0;j<NumeroDeFollows[i];j++){
                // Leitura nome de usuario
                String procurado = (String)ObjetoRead_follows.readObject();
                Perfil PerfilAux = table.GetPerfil(procurado);
                DadosPerfis.get(i).Seguindo.InserirNovoItem(PerfilAux);
                PerfilAux.Seguidores.InserirNovoItem(DadosPerfis.get(i));
            }
        }
        
        return Const.Sucesso;      
    }
    
    public int SaveData(HashTable table)throws FileNotFoundException, IOException,ClassNotFoundException{
        ItemLista DadosColuna;
        Perfil PerfilAtual;
        
        File ArqPerfis = new File("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Perfis.bin");
        File ArqPosts = new File("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Posts.bin");
        File ArqFollows = new File("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Follows.bin");
        File ArqLikes = new File("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Likes.bin");
        
        if( ArqPerfis.exists()) ArqPerfis.delete();
        if(  ArqPosts.exists()) ArqPosts.delete();
        if(ArqFollows.exists()) ArqFollows.delete();
        if(  ArqLikes.exists()) ArqLikes.delete();
        
        ArqPerfis.createNewFile();
        ArqPosts.createNewFile();
        ArqFollows.createNewFile();
        ArqLikes.createNewFile();    
        
        FileOutputStream ArquivoPerfis = new FileOutputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Perfis.bin");
        FileOutputStream ArquivoPostagens = new FileOutputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Posts.bin");
        FileOutputStream ArquivoFollows = new FileOutputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Follows.bin");
        FileOutputStream ArquivoLikes = new FileOutputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Likes.bin");
        
        ObjectOutputStream ObjetoSave_perfis = new ObjectOutputStream(ArquivoPerfis);
        ObjectOutputStream ObjetoSave_posts = new ObjectOutputStream(ArquivoPostagens);
        ObjectOutputStream ObjetoSave_follows = new ObjectOutputStream(ArquivoFollows);
        ObjectOutputStream ObjetoSave_likes = new ObjectOutputStream(ArquivoLikes);
        
        // Escrita do numero de perfis do código para facilitar a leitura
        ObjetoSave_perfis.write(table.GetNumeroDePerfis());
                
        for(int i=0;i<table.GetNumeroDeColunas();i++){
            DadosColuna = table.GetColuna(i);
            while(DadosColuna != null){
                SaveModel Modelo = new SaveModel();
                PerfilAtual = DadosColuna.GetDadosItem();      
                int Id = PerfilAtual.GetIdPerfil();     
                int NumPosts = PerfilAtual.Postagens.GetNumeroDeItens();
                int NumFollows = PerfilAtual.Seguindo.GetNumeroDeItens();
                
                Modelo.InicializarDados(PerfilAtual.GetNomeCompleto(),PerfilAtual.GetUserName(), Id, NumPosts, NumFollows);
                ObjetoSave_perfis.writeObject(Modelo);

                
                
                ItemListaPost DadosPost = PerfilAtual.Postagens.GetPrimeiroItem();
                for(int j=0;j<NumPosts;j++){
                    // Escrever o id
                    ObjetoSave_posts.write(DadosPost.GetDadosItem().GetIdPostagem());
                    // Escrever o post
                    ObjetoSave_posts.writeObject(DadosPost.GetDadosItem().GetTextoPostagem());
                    // Escrever o numero de likes
                    ObjetoSave_posts.write(DadosPost.GetDadosItem().Curtidas.GetNumeroDePerfis());
                    
                    ItemLista DadosLikes;
                    for(int k=0;k<DadosPost.GetDadosItem().Curtidas.GetNumeroDeColunas();k++){
                        DadosLikes = DadosPost.GetDadosItem().Curtidas.GetColuna(k);
                        while(DadosLikes != null){
                            // Escrever o nome do usuario que curtiu
                            ObjetoSave_likes.writeObject(DadosLikes.GetDadosItem().GetUserName());
                            DadosLikes = DadosLikes.GetProximoItemLista();
                        }
                    }
                    DadosPost = DadosPost.GetProximoItemLista();
                }
                
                ItemLista DadosFollow = PerfilAtual.Seguindo.GetPrimeiroItem();
                for(int j=0;j<PerfilAtual.Seguindo.GetNumeroDeItens();j++){
                    // Escrever o nome do usuario que o perfil atual segue
                    ObjetoSave_follows.writeObject(DadosFollow.GetDadosItem().GetUserName());
                    DadosFollow = DadosFollow.GetProximoItemLista();
                }
                
                DadosColuna = DadosColuna.GetProximoItemLista();
            }   
        }
        
        return Const.Sucesso;       
    }
    
}

/*
Perfil aux = new Perfil();
        
        aux.SetInformacoesPerfil(0,"erik roberto","erik_neves", true);
        SaveModel saves = new SaveModel();
        saves.InicializarDados(aux.GetNomeCompleto(),aux.GetUserName(), 0, 7, 3);
        saves.ImprimirDados();
        
        ObjetoSave_perfis.writeObject(saves);
        
        Perfil aux2 = new Perfil();
        
        aux2.SetInformacoesPerfil(0,"Reis Neves","Roberto", true);
        SaveModel saves2 = new SaveModel();
        saves2.InicializarDados(aux2.GetNomeCompleto(),aux2.GetUserName(), 1, 10, 5);
        saves2.ImprimirDados();
        
        ObjetoSave_perfis.writeObject(saves2);
        
        ArquivoPerfis.close();
        
        System.out.println("| Saved |");
        
        FileInputStream ArquivoPerfis2 = new FileInputStream("C:\\Users\\Notebook\\Documents\\NetBeansProjects\\Barchielo's chat\\src\\saves\\Perfis.bin");
        ObjectInputStream objetoL = new ObjectInputStream(ArquivoPerfis2);
        
        SaveModel read = (SaveModel)objetoL.readObject();
        read.ImprimirDados();
        
        SaveModel read2 = (SaveModel)objetoL.readObject();
        read2.ImprimirDados();
*/