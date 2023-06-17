public class MyClass {

    public static void main(String[] args) {
        Student obj;
        obj = new Student("Pappu") ;
        System.out.println(obj.data);
    }
}

class Student {
    String data;
    Student(String str) {
        data = str;
    }
}