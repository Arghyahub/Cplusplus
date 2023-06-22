public class InheritanceJ {
    public static void main(String args[]){

        Parent papa1 = new Parent() ;
        Parent papa2 = new Parent(2) ;
        Parent papa3 = new Parent(2,5) ;

        System.out.println(papa1.money + " -- " + papa1.car);
        System.out.println(papa2.money + " -- " + papa2.car);
        System.out.println(papa3.money + " -- " + papa3.car);
        
        System.out.println("\nBacche k paise\n") ;

        Child baccha1 = new Child(1,3,5,6) ;
        System.out.println(baccha1.money + " -- " + baccha1.car);

        // Not possible 
        // Child baccha2 = new Parent(0, 0) ;

        Parent Mummy = new Child(0, 0, 0, 0) ;
    }
}

class Parent {
    public int money;
    public int car;
    private int clothes;
    Parent(){
        money = 1;
        car = 1;
        clothes = 1;
    }
    Parent(int x) {
        money = x;
        car = x;
    }
    Parent(int x, int y){
        money = x;
        car = y;
    }
}

class Child extends Parent {
    int hw;
    int tiffin;
    Child() {
        hw = 0;
        tiffin = 0;
        // clothes = 1; Private features of parent cannot be accessed
    }
    Child(int x, int y, int m , int c){
        super(m, c) ;
        hw = x;
        tiffin = y;
    }

}