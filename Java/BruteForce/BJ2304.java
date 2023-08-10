import java.io.*;
import java.util.*;

public class BJ2304 {
    public static int[] pillar = new int[1001];
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        

        int N = Integer.parseInt(st.nextToken());
        int maxLoc = 0;
        for(int i = 0; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int H = Integer.parseInt(st.nextToken());
            pillar[L] = H;
            maxLoc = H > pillar[maxLoc] ? L : maxLoc;
        }
        int space = pillar[maxLoc];
        int height = 0;
        for(int i = 0 ; i < maxLoc ; i++){
            if(height < pillar[i]) height = pillar[i];
            space += height;
        }
        height = 0;
        for(int i = 1000 ; i > maxLoc ; i--){
            if(height < pillar[i]) height = pillar[i];
            space += height;
        }
        
        System.out.println(space);
        br.close();
        
    }
}
