import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ11279 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        for(int i = 0 ; i < N ; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            if(num == 0) {
                System.out.println(
                        maxHeap.size() == 0 ? 0 : maxHeap.poll()
                );
            }
            else{
                maxHeap.add(num);
            }
        }
    }
}
