import java.io.*;
import java.util.*;

public class BJ12919{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        String from = st.nextToken();
        st = new StringTokenizer(br.readLine());
        String to = st.nextToken();
        int targetLen = from.length();
        br.close();
        
        Queue<String> q = new LinkedList<>();
        q.offer(to);
        
        while(!q.isEmpty()){
            String s = q.poll();
            int len = s.length();
            if(s.length() == targetLen){
                if(from.equals(s)){
                    System.out.println("1");
                    return;
                }
                continue;
            }
            
            StringBuilder sb = new StringBuilder(s);
            if(sb.charAt(len-1) == 'A'){
                q.offer(s.substring(0,len-1));
            }
            
            if(sb.charAt(0) == 'B'){
                sb.deleteCharAt(0);
                sb.reverse();
                q.offer(sb.toString());
            }
        }
        System.out.println("0");
        return;
    }
}