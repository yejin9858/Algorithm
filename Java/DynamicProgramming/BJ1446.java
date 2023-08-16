import java.io.*;
import java.util.*;

public class BJ1446 {
    private static PriorityQueue<ShortCut> q = new PriorityQueue<>();
    private static int[] d;
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        d = new int[D+1];
        
        for(int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int dis = Integer.parseInt(st.nextToken());
            if(e <= D)
                q.offer(new ShortCut(s,e,dis));
        }
    
        for(int i = 0 ; i <= D ; i++){
            if(i != 0)   d[i] = d[i-1] + 1;
            while(!q.isEmpty()){
                if(q.peek().e != i) break;
                ShortCut s = q.poll();
                d[i] = d[i] < d[s.s] + s.dis ? d[i] : d[s.s] + s.dis; 
            }
        }
        br.close();
        System.out.println(d[D]);
    }
    
    private static class ShortCut implements Comparable<ShortCut>{
        int s;
        int e;
        int dis;
        
        public ShortCut(int s, int e, int dis){
            this.s = s;
            this.e = e;
            this.dis = dis;
        }
        
        @Override
        public int compareTo(ShortCut o){
            return e - o.e;
        }
    }
}