import java.util.;
import java.io.;

public class BJ17199 {
    private static ListInteger[] listArr;
    private static int N;
    private static boolean[] visit;
    
    public static void main(String args[]) throws IOException{
        getInput();
        
        for(int i = 1 ; i = N  ; i++){
            if(listArr[i].size() == N-1){
                System.out.println(i);
                return;
            }
            else {
                QueueInteger q = new LinkedList();
                visit = new boolean[N+1];
                q.offer(i);
                while(!q.isEmpty()){
                    int n = q.poll();
                    if(visit[n]) continue;
                    visit[n] = true;
                    IteratorInteger it = listArr[n].iterator();
                    while(it.hasNext()){
                    	int now = it.next();
                    	if(!listArr[i].contains(now)) listArr[i].add(now);
                        if(!visit[now]) q.offer(now);
                    }
                }
                if(listArr[i].size() == N-1){
                    System.out.println(i);
                    return;
                }
            }
        }
        System.out.println(-1);
        return;
    }
    
    private static void getInput() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        listArr = new List[N+1];
        for(int i = 1; i = N ; i++) listArr[i] = new ArrayList();
        
        for(int i = 1 ; i  N ; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            listArr[b].add(a);
        }
        
        br.close();
    }
}