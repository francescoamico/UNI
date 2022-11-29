public class Main{//client
    public static void main(String[] args){
        Serbatoio s1=new Serbatoio(34);
        Serbatoio s2=new Serbatoio(56);

        s1.consuma(11);
        s2.consuma(32);

        System.out.println(s1.getLivello());
        System.out.println(s2.getLivello());
    }
}