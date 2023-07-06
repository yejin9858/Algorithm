import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class BJ14890 {
    
    public static int[][] map;
    public static int answer = 0;
    public static int N;
    public static int L;
    
    public static void main(String args[]) throws IOException{
        getInput();
        for (int i = 0; i < N; i++) {
            checkRow(i);
            checkColumn(i);
        }
        System.out.println(answer);
    }
    
    private static void checkColumn(int col) {
        boolean[] checkSlope = new boolean[N]; 

        for (int i = 0; i < N - 1; i++) {
            int difference = map[i][col] - map[i + 1][col];

            if (difference > 1 || difference < -1) return;
            else if (difference == -1) { 
                for (int j = 0; j < L; j++) { 
                    if (i - j < 0 || checkSlope[i - j]) return;
                    if (map[i][col] != map[i - j][col]) return;
                    checkSlope[i - j] = true;
                }
            } else if (difference == 1) { 
                for (int j = 0; j < L; j++) { 
                    if (i + 1 + j >= N || checkSlope[i + 1 + j]) return;
                    if (map[i + 1][col] != map[i + 1 + j][col]) return;
                    checkSlope[i + 1 + j] = true; 
                }
            }
        }
        answer++;

    }

    private static void checkRow(int row) {
        boolean[] checkSlope = new boolean[N];

        for (int i = 0; i < N - 1; i++) {
            int difference = map[row][i] - map[row][i + 1];

            if (difference > 1 || difference < -1) return;
            else if (difference == -1) {
                for (int j = 0; j < L; j++) {
                    if (i - j < 0 || checkSlope[i - j]) return;
                    if (map[row][i] != map[row][i - j]) return;
                    checkSlope[i - j] = true;
                }
            } else if (difference == 1) {
                for (int j = 0; j < L; j++) {
                    if (i + 1 + j >= N || checkSlope[i + 1 + j]) return;
                    if (map[row][i + 1] != map[row][i + 1 + j]) return;
                    checkSlope[i + 1 + j] = true; 
                }
            }
        }
        answer++;
    }
    
    public static void getInput() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        map = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        br.close();
    }
}