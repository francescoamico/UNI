package geometria.figurepiane;

public class Quadrilatero{
    private double l1,l2,l3,l4;
    private Punto p1,p2,p3,p4;

    public Quadrilatero(Punto p1,Punto p2,Punto p3,Punto p4){
        if(Punto.distanza(p1,p2)+Punto.distanza(p2,p3)==Punto.distanza(p1,p3))
            System.out.println("Almeno tre punti allineati o punti in senso non orario-->non \u00E8 un quadrilatero");
        this.l1=Punto.distanza(p1,p2);
        this.l2=Punto.distanza(p2,p3);
        this.l3=Punto.distanza(p3,p4);
        this.l4=Punto.distanza(p4,p1);
        this.p1=p1;
        this.p2=p2;
        this.p3=p3;
        this.p4=p4;
    }

    public double getPerimetro(){
       return this.l1+this.l2+this.l3+this.l4;
    }

    public double getArea(){//formula di Erone
        double sp1=(this.l1+this.l2+Punto.distanza(this.p1,this.p3))/2;
        double sp2=(this.l4+this.l3+Punto.distanza(this.p1,this.p3))/2;
        double a1=Math.sqrt(sp1*(sp1-this.l1)*(sp1-this.l2)*(sp1-Punto.distanza(this.p1,this.p3)))
                    +Math.sqrt(sp2*(sp2-this.l4)*(sp2-this.l3)*(sp2-Punto.distanza(this.p1,this.p3)));
        sp1=(this.l1+this.l4+Punto.distanza(this.p2,this.p4))/2;
        sp2=(this.l2+this.l3+Punto.distanza(this.p2,this.p4))/2;
        double a2=Math.sqrt(sp1*(sp1-this.l1)*(sp1-this.l4)*(sp1-Punto.distanza(this.p2,this.p4)))
                    +Math.sqrt(sp2*(sp2-this.l2)*(sp2-this.l3)*(sp2-Punto.distanza(this.p2,this.p4)));
        return a1<a2 ? a1:a2;
    }

    public double getL1(){
        return this.l1;
    }

    public double getL2(){
        return this.l2;
    }

    public double getL3(){
        return this.l3;
    }

    public double getL4(){
        return this.l4;
    }
}