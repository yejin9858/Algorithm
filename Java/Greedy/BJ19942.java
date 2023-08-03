import java.io.*;
import java.util.*;

public class Main {
    private static boolean ate[];
    private static char[] table;
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int answer = 0;
        table = st.nextToken().toCharArray();
        ate = new boolean[N];
        
        for(int i = 0 ; i < N ; i++){
            if(table[i] == 'H'){
                int min = (i - K < 0) ? 0 : i - K;
                int max = (i + K >= N) ? N-1 : i + K;
                for(int j = min ; j <= max ; j++){
                    if(table[j] == 'P' && ate[j] == false){
                        ate[j] = true;
                        answer ++;
                        break;
                    }
                }
            }
        }
        System.out.println(answer);
    }
}