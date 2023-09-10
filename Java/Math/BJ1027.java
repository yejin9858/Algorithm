import java.io.*;
import java.util.*;

public class BJ1027{
    private static int[] b;
    private static int N, answer = 0;
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        b = new int[N];
        for(int i = 0 ; i < N  ; i ++){
            b[i] = Integer.parseInt(st.nextToken());
        }
        
        for(int i =  0 ; i <  N ; i++){
            int now = 0;
            double slope = 1000000000;
            for(int j = i-1; j >= 0 ; j--){
                double ns = (double)(b[i] - b[j]) / (i-j);
                if(ns < slope) {
                    slope = ns;
                    now++;
                }
            }
            slope = -1000000000;
            for(int j = i+1; j < N ; j++){
                double ns = (double)(b[i] - b[j]) / (i-j);
                if(ns > slope){
                    slope = ns;
                    now++;
                }
            }
            if(answer < now){
                answer = now;
            }
        }
        
        System.out.println(answer);
        
    }
}