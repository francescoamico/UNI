package geometria.figurepiane;

public class Trapezio extends Quadrilatero{
    double h;

    public Trapezio(Punto p1,Punto p2,Punto p3,Punto p4){
        super(p1,p2,p3,p4);
        if((p2.getY()-p1.getY())/(p2.getX()-p1.getX())!=(p3.getY()-p4.getY())/(p3.getX()-p4.getX()))//coefficienti angolari diversi
            System.out.println("Non ci sono lati opposti paralleli-->non \u00E8 un trapezio");

    }
}