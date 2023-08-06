import java.io.*;
import java.util.*;

public class BJ17484 {
    private static int[][] space;
    private static int[][][] cost;
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        space = new int[N][M];
        cost = new int[N][M][3];
        for(int i = 0 ; i <  N ; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < M ; j++){
                space[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for(int j = 0 ; j < M ; j++){
            if(j - 1 >= 0) {
                cost[1][j-1][0] = space[0][j] + space[1][j-1];
            }
            cost[1][j][1] = space[0][j] + space[1][j];
            if(j + 1 < M) {
                cost[1][j+1][2] = space[0][j] + space[1][j+1];
            }
            
        }
        
        for(int i = 1; i < N-1 ; i++){
            for(int j = 0 ; j < M; j++){
                for(int k = 0; k < 3 ; k++){
                    if(cost[i][j][k] == 0) continue;
                    if(j-1 >= 0 && k!=0){
                        if(cost[i+1][j-1][0] == 0 
                        || cost[i+1][j-1][0] > cost[i][j][k] + space[i+1][j-1])
                            cost[i+1][j-1][0] = cost[i][j][k] + space[i+1][j-1];
                    }
                    if(k!=1){
                        if(cost[i+1][j][1] == 0 
                        || cost[i+1][j][1] > cost[i][j][k] + space[i+1][j])
                            cost[i+1][j][1] = cost[i][j][k] + space[i+1][j];
                    }
                    if(j+1 < M && k!=2){
                        if(cost[i+1][j+1][2] == 0 
                        || cost[i+1][j+1][2] > cost[i][j][k] + space[i+1][j+1])
                            cost[i+1][j+1][2] = cost[i][j][k] + space[i+1][j+1];
                    }
                }
            }
        }
        
        int answer = Integer.MAX_VALUE;
        for(int j = 0 ; j < M ; j++){
            for(int k = 0; k < 3 ; k++){
                if(cost[N-1][j][k] != 0 && cost[N-1][j][k] < answer)
                    answer = cost[N-1][j][k];
            }
        }
        
        System.out.println(answer);
    }
}