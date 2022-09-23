import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ2630 {
    private static Integer N;
    private static Integer[][] paper;
    private static Integer[] color = {0,0};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        paper = new Integer[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++)
                paper[i][j] = Integer.parseInt(st.nextToken());
        }

        cutPaper(0,0,N);
        System.out.println(color[0]);
        System.out.println(color[1]);

    }
    private static void cutPaper(int x, int y, int n){
        int token = paper[x][y];
        if(n == 1) {
            color[token] ++;
            return;
        }

        int endX = x+n;
        int endY = y+n;

        boolean flag = true;
        for(int i = x ; i < endX && flag ; i++){
            for(int j = y; j < endY ; j++){
                if(paper[i][j] != token) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            color[token] ++;
        }
        else{
            int midX = x+n/2;
            int midY = y+n/2;
            cutPaper(x, y, n/2);
            cutPaper(midX, y, n/2);
            cutPaper(x, midY, n/2);
            cutPaper(midX, midY, n/2);
        }
        return;
    }
}
