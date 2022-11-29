package persone;
import persone.*;

public class Main{
    public static void main(String[] args){
        Persona p=new Persona("Francesco","Amico");
        Studente s=new Studente("Francesco","Amico","Unipa","0716201");
        Impiegato i=new Impiegato("Francesco","Amico","Azienda",2500.0);
        Dirigente d=new Dirigente("Francesco","Amico","Azienda",2500.0,"Sicurezza");
        
        System.out.print("\n");
        p.presentati();
        System.out.println("-------------------------");
        s.presentati();
        System.out.println("-------------------------");
        i.presentati();
        System.out.println("-------------------------");
        d.presentati();
    }
}