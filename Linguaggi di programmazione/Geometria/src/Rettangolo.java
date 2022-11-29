package geometria.figurepiane;

public class Rettangolo extends Parallelogramma{
    public Rettangolo(Punto p1,Punto p2,Punto p3,Punto p4){
        super(p1,p2,p3,p4);
        if((p1.getX()!=p4.getX()||p2.getX()!=p3.getX()))
            System.out.println("Gli angolo interni non sono retti-->non \u00E8 un rettangolo");
    }
}