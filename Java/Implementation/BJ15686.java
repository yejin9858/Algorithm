import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int M;
    static List<Pos> chickenLocationList = new ArrayList<>();
    static List<Pos> houseLocationList = new ArrayList<>();
    static boolean[] visit;
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        getInput();

        calculateChickenDistance(0, 0);

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
    }

    private static void calculateChickenDistance(int now, int count) {
        if(count == M) {
            int distance = 0;
            for (int i = 0; i < houseLocationList.size(); i++) {
                int houseToChicken = Integer.MAX_VALUE;
                for (int j = 0; j < chickenLocationList.size(); j++) {
                    if (visit[j])
                        houseToChicken = Math.min(Math.abs(chickenLocationList.get(j).x - houseLocationList.get(i).x)
                                        + Math.abs(chickenLocationList.get(j).y - houseLocationList.get(i).y),
                                houseToChicken);
                }
                distance += houseToChicken;
            }
            ans = Math.min(distance, ans);
            return;
        }

        for(int i = now; i < chickenLocationList.size() ; i++){
            if(!visit[i]) {
                visit[i] = true;
                calculateChickenDistance(i + 1, count + 1);
                visit[i] = false;
            }
        }
    }

    private static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0 ; i <  N ; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < N ; j++){
                int now = Integer.parseInt(st.nextToken());
                if(now == 1) houseLocationList.add(new Pos(i,j));
                else if(now == 2) chickenLocationList.add(new Pos(i,j));
            }
        }

        visit = new boolean[chickenLocationList.size()];
        br.close();
    }

    private static class Pos{
        int x;
        int y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
