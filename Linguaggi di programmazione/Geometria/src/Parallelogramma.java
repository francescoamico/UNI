package geometria.figurepiane;

public class Parallelogramma extends Trapezio{

    public Parallelogramma(Punto p1,Punto p2,Punto p3,Punto p4){
        super(p1,p2,p3,p4);
        if((p4.getY()-p1.getY())/(p4.getX()-p1.getX())!=(p3.getY()-p2.getY())/(p3.getX()-p2.getX()))//coefficienti angolari diversi
            System.out.println("I lati non sono a due a due paralleli-->non \u00E8 un parallelogramma");
    }
}