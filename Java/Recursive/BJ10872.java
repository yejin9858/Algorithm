import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BJ10872 {
    public static void main(String[] args)  throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        System.out.println(factorial(N));
        br.close();
    }

    private static Integer factorial(int n){
        if(n == 1 || n == 0){
            return 1;
        }
        else
            return n * factorial(n-1);
    }
}
