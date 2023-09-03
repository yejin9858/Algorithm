import java.util.*;
import java.io.*;

public class BJ1253 {
    private static long[] numbers;
    private static int N, answer = 0;
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        numbers = new long[N];
        
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < N ; i++){
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        br.close();
        
        Arrays.sort(numbers);
        
        for(int i = 0 ; i < N ; i++){
            int left = 0, right = N-1;
            
            while(true){
                if(left == i) left++;
                if(right == i) right--;
                
                if(left >= right) break;
                
                if(numbers[left] + numbers[right] > numbers[i]) right--;
                else if(numbers[left] + numbers[right] < numbers[i]) left++;
                else{
                    answer++;
                    break;
                }
            }
        }
        
        System.out.println(answer);
        
    }
}