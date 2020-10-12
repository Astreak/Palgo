import java.util.Scanner;
import java.io.*;
class Sum{
    int a,b;
    Sum(int a,int b){
      this.a=a;
      this.b=b;
    }
    public String toString(){
      return "this is a class MFs";
    }
  
}
public class A{
    public static void Print(String a) throws IOException{
	System.out.println(a);
    }
    public static void main(String []args){
      Sum s=new Sum(12,23);
      System.out.println(s);
    }
  
}
