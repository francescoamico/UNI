package biblioteca;
import java.lang.*;
import java.util.*;

public class Catalogo{

    private ArrayList<Documento> catalogo;

    public Catalogo(){
        catalogo=new ArrayList<Documento>();
    }
 
    public ArrayList<Documento> getCatalogo(){
        return (this.catalogo);
    }
    
    public void stampaCatalogo(){
        System.out.print("\nCatalogo:");
        for(int i=0;i<catalogo.size();i++)
            catalogo.get(i).info();
    }
   
    public void aggiungiLibro(Documento doc){
        this.catalogo.add(doc);
    }
 
    public void ricerca(int id){
        for(int i=0;i<catalogo.size();i++){
            if(catalogo.get(i).getId()==id) 
                catalogo.get(i).info();
        }
    }

    public void cancella(int id){
        for(int i=0;i<catalogo.size();i++){
            if(catalogo.get(i).getId()==id) catalogo.remove(i);
        }
    }

}