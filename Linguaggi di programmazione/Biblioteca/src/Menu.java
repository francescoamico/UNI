package biblioteca;
import java.util.*;
/**
    @author Francesco Amico
    @version 1.0
*/
public class Menu{
    /**menu che permette di stampare il catalogo, aggiungere libri e ricercare per autore */
    public static void start(){
        Scanner scan=new Scanner(System.in);
        Catalogo catalogo=new Catalogo();
        String titolo,casaEditrice,nome,cognome;
        double prezzo;
        Autore[] autori;
        Documento doc;
        int x=1,n;

        while(x>0 && x<5){
            System.out.println("\n\n1)stampa catalogo\n2)inserisci documento\n3)cancella\n4)ricerca per id\n5)esci");
            x=scan.nextInt();
            switch(x){
                case 1:
                    catalogo.stampaCatalogo();
                    break;
                case 2:
                    System.out.print("1)Libro\n2)Dizionario");
                    n=scan.nextInt();
                    System.out.print("Inserisci prezzo :: ");
                    prezzo=scan.nextDouble();
                    System.out.print("Quanti autori? ");
                    x=scan.nextInt();

                    autori=new Autore[x];
                    cognome=scan.nextLine();//consuma linea
                    for(int i=0;i<x;i++){
                        System.out.println("\n\nAutore "+(i+1));
                        System.out.print("Cognome :: ");
                        cognome=scan.nextLine();
                        System.out.print("Nome :: ");
                        nome=scan.nextLine();
                        autori[i]=new Autore(nome,cognome);
                    }

                    System.out.print("\n\nInserisci titolo :: ");
                    titolo=scan.nextLine();
                    System.out.print("Inserisci casa editrice :: ");
                    casaEditrice=scan.nextLine();

                    doc= n==1? new Libro(titolo,autori,prezzo,casaEditrice):new Dizionario(titolo,autori,prezzo,casaEditrice);
                    catalogo.aggiungiLibro(doc);
                    x=2;
                    break;
                case 3:
                    System.out.print("Inserisci id :: ");
                    n=scan.nextInt();
                    catalogo.cancella(n);
                    break;
                case 4:
                    System.out.print("Inserisci id :: ");
                    n=scan.nextInt();
                    catalogo.ricerca(n);
                    break;
                default: break;
            }
        }
        scan.close();
    }

}