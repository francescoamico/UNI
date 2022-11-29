package geometria.figurepiane;

public class Quadrato extends Rettangolo{
    public Quadrato(Punto p1,Punto p2,Punto p3,Punto p4){
        super(p1,p2,p3,p4);
        if(super.getL1()!=super.getL2()||super.getL2()!=super.getL3()||super.getL3()!=super.getL4())
            System.out.println("I lati non sono tutti uguali-->non \u00E8 un quadrato");
    }
}