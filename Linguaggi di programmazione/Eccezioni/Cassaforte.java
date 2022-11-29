import java.util.Scanner;

public class Cassaforte{
    private String psw="qwerty";
    private int t=0;

    public Cassaforte(){
        this.resetPsw();
    }

    public String getSecretMessage(String psw){
        if(t==3){
            System.out.println("Cassaforte bloccata");
            throw new RuntimeException();
        }else{
            if(this.psw.equals(psw)==false){
                t++;
                return "Password errata! Riprovare";
            }else{
                t=0;
                return "Sono il messaggio secreto";
            }
        }
    }

    public void resetPsw(){
        Scanner scan=new Scanner(System.in);
        String psw="";
        do{
            System.out.print("Inserire nuova password :: ");
            psw=scan.next();
        }while(psw.length()<6 || 
            !(psw.contains("0")||psw.contains("1")||psw.contains("2")||psw.contains("3")||psw.contains("4")
            ||psw.contains("5")||psw.contains("6")||psw.contains("7")||psw.contains("8")||psw.contains("9")));
        this.psw=psw;
    }
}