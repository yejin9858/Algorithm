import java.io.*;
import java.util.*;

public class BJ1205 {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int newScore = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        Integer[] scores = new Integer[P+1];
        scores[0] = newScore;
        if(N == 0) {
            System.out.println(1);
            return;
        }
        
        st = new StringTokenizer(br.readLine());
        for(int i = 1 ; i <= N ; i++){
            scores[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = N+1 ; i <= P; i++) scores[i] = 0;
        
        Arrays.sort(scores, Comparator.reverseOrder());

        for(int i = 0 ; i < P; i++){
            if(scores[i] == newScore){
                if(P == N && newScore == scores[P]) break;
                System.out.println(i+1);
                return;
            }
        }
        System.out.println(-1);
        
    }
}