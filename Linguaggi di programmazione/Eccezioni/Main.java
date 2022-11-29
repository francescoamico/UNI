import java.util.InputMismatchException;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        /*
        Scanner scan = new Scanner(System.in);
        int x,y=1;
        while(y!=0){
            try{
                System.out.print("Inserire intero :: ");
                x=scan.nextInt();
                System.out.print("\nInverso moltiplicativo :: "+(double)1/x);
                y=0;
            }
            catch(InputMismatchException ex){
                System.out.println("Il valore inserito non \u00E8 un intero");
                scan.nextLine();
            }
        }
        scan.close();*/

        /*
        Scanner scan = new Scanner(System.in);
        Cassaforte c = new Cassaforte();
        int x=0;
        while(x!=1){
            System.out.print("Inserire password :: ");
            try{
                System.out.println(c.getSecretMessage(scan.next()));
            }catch(RuntimeException ex){
                System.out.println("Non \u00E8 pi\u00F9 possibile accedere alla cassaforte!");
                x=1;
            }
        } 
        scan.close();
        */
        
        Scanner scan=new Scanner(System.in);
        Aereo aereo=new Aereo(5);
        String nc;
        int x=0;
        while(x!=5){
            System.out.println("\n1)Stampa posti liberi.\n2)Stampa lista passeggeri.\n3)Assegna posto ad un passeggero.\n4)Cancella assegnazione.\n5)Esci.");
            x=scan.nextInt();
            switch(x){
                case 1:
                    aereo.postiLiberi();
                    break;
                case 2:
                    aereo.listaPasseggeri();
                    break;
                case 3:
                    scan.nextLine();
                    System.out.print("Inserire nome e cognome :: ");
                    nc=scan.nextLine();
                    aereo.aggiungiPasseggero(nc);
                    break;
                case 4:
                    scan.nextLine();
                    System.out.print("Inserire nome e cognome :: ");
                    nc=scan.nextLine();
                    aereo.eliminaPasseggero(nc);
                    break;
                case 5:
                    break;
            }
        }
        scan.close();
    }
}