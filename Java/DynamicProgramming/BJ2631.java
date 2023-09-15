import java.io.*;
import java.util.*;

public class BJ2631 {
    private static int[] numbers;
    private static int[] d;
    private static int N, ans = 0;
    
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        numbers = new int[N];
        d = new int[N];
        
        for(int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        
        d[0] = 1;
        for(int i = 1; i < N ; i++){
            d[i] = 1;
            for(int j = 0; j < i ; j++){
                if(numbers[i] > numbers[j]) d[i] = Math.max(d[i], d[j] + 1);
            }
            ans = (ans > d[i]) ? ans : d[i];
        }
        
        System.out.println(N-ans);
    }
}