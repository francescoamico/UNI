package geometria.figurepiane;

public class Rombo extends Parallelogramma{
    private double d1,d2;

    public Rombo(Punto p1,Punto p2,Punto p3,Punto p4){
        super(p1,p2,p3,p4);
        if(Punto.distanza(p1, p3)==Punto.distanza(p2, p4)||(super.getL1()!=super.getL2()||super.getL2()!=super.getL3()||super.getL3()!=super.getL4()))
            System.out.println("Diagonali congruenti e/o lati diversi-->non \u00E8 un rombo");
        this.d1=Punto.distanza(p1,p3);
        this.d2=Punto.distanza(p2,p4);   
    }

    public double getD1(){
        return this.d1;
    }

    public double getD21(){
        return this.d2;
    }
}