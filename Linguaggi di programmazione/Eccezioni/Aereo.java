import java.util.ArrayList;

public class Aereo{

    private String[] listaPasseggeri;

    public Aereo(int n){
        this.listaPasseggeri=new String[n];//aereo di n posti
    }

    public void postiLiberi(){
        int c=0;
        System.out.println("Posti liberi :");
        for(int i=0;i<this.listaPasseggeri.length;i++){
            if(this.listaPasseggeri[i]==null){
                System.out.println("Posto "+i);
                c++;
            }
        }
        if(c==0) System.out.println("Nessun posto libero");
    }

    public void listaPasseggeri(){
        int c=0;
        System.out.println("Lista passeggeri :");
        for(int i=0;i<this.listaPasseggeri.length;i++){
            if(this.listaPasseggeri[i]!=null){
                System.out.println("Nome cognome posto :: "+this.listaPasseggeri[i]+" "+i);
                c++;
            }
        }
        if(c==0) System.out.println("Nessun passeggero");
    }

    public void aggiungiPasseggero(String nc){
        int i=0;
        try{
            while(this.listaPasseggeri[i]!=null){i++;}
            this.listaPasseggeri[i]=nc;
        }catch(IndexOutOfBoundsException ex){
            System.out.println("Impossibile aggiungere "+nc+"! Nessun posto disponibile.");
        }
    }
    
    public void eliminaPasseggero(String nc){
        int i=0;
        try{
            while(this.listaPasseggeri[i]!=nc){i++;}
            this.listaPasseggeri[i]=null;
        }catch(IndexOutOfBoundsException ex){
            System.out.println(nc+" non \u00E8 presente!");
        }
    }

}