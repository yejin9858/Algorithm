import java.io.*;
import java.util.*;

public class Main {
    public static int t[];
    public static int p[];
    public static int d[];
    public static int N;
    
    public static void main(String args[]) throws IOException{
      input();
      for(int i = N ; i > 0 ; i--){
          int nextDay = i + t[i];
          if(nextDay > N + 1){
              d[i] = d[i + 1];
          }
          else{
              if(d[i + 1] > d[nextDay] + p[i])
                  d[i] = d[i+1];
              else
                d[i] = d[nextDay] + p[i];
          }
      }
      
      System.out.println(d[1]);
    }

    
    public static void input() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        t = new int[N+2];
        p = new int[N+2];
        d = new int[N+2];
        
        for(int i = 1 ; i <= N ; i ++){
            st = new StringTokenizer(br.readLine());
            t[i] = Integer.parseInt(st.nextToken());
            p[i] = Integer.parseInt(st.nextToken());
        }
    }
}