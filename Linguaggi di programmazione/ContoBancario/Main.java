public class Main{
    public static void main(String[] args){
        
        ContoBancario uno=new ContoBancario();
        ContoBancario due=new ContoBancario();

        System.out.println("Id conto 1 :: "+uno.getId());
        System.out.println("Id conto 2 :: "+due.getId());

        uno.versa(50.52);
        due.versa(23.12);

        System.out.println("Saldo conto 1 :: "+uno.getSaldo());
        System.out.println("Saldo conto 2 :: "+due.getSaldo());

        uno.trasferisci(12.8,due);

        System.out.println("\nTrasferimento da conto 1 a conto 2...\n");

        System.out.println("Saldo conto 1 :: "+uno.getSaldo());
        System.out.println("Saldo conto 2 :: "+due.getSaldo());

    }
}