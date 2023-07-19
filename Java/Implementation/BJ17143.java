import java.io.*;
import java.util.*;

public class BJ17143 {

    public static int R,C,M;
    public static int fisherman = 0;
    public static int fish = 0;
    public static List<Shark> water = new ArrayList<>();
    public static int[][] dir = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};


    public static void main(String args[]) throws IOException {
        getInput();

        while(true){
            fisherman++;
            catchFish();
            moveSharks();
            if(water.size() == 0 || fisherman == C) {
                System.out.println(fish);
                return;
            }
        }
    }

    public static void catchFish() {
        Shark catchedShark = null;
        for(Shark s : water){
            if(s.y == fisherman){
                if(catchedShark != null){
                    if(s.x < catchedShark.x){
                        catchedShark = s;
                    }
                }
                else catchedShark = s;
            }
        }
        if(catchedShark != null){
            fish += catchedShark.z;
            water.remove(catchedShark);
        }
    }

    public static void moveSharks() {
        int[][] map = new int[R+1][C+1];
        for(int i = 1 ; i <= R ; i++)
            for(int j = 1; j <= C ;j++)
                map[i][j] = -1;
        List<Shark> deadShark = new ArrayList<>();
        for(int i = 0 ; i < water.size() ; i++){
            Shark s = water.get(i);

            //이동
            for(int v = 0; v < s.s; v++){
                s.x += dir[s.d][0];
                s.y += dir[s.d][1];
                if(s.x <= 0 || s.x > R || s.y <= 0 || s.y > C){
                    s.x -= dir[s.d][0];
                    s.y -= dir[s.d][1];
                    s.d = changeDirection(s.d);
                    s.x += dir[s.d][0];
                    s.y += dir[s.d][1];
                }
            }

            //먹기
            if(map[s.x][s.y] != -1){
                if(water.get(map[s.x][s.y]).z < s.z){
                    deadShark.add(water.get(map[s.x][s.y]));
                    map[s.x][s.y] = i;
                }
                else {
                    deadShark.add(s);
                }
            }
            else map[s.x][s.y] = i;
        }

        //죽이기
        for(Shark s : deadShark)  water.remove(s);

    }

    private static int changeDirection(int dir) {
        switch (dir){
            case 1: return 2;
            case 2: return 1;
            case 3: return 4;
            case 4: return 3;
            default: return 0;
        }
    }
    public static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            water.add(new Shark(x,y,s,d,z));

        }

        br.close();
    }

    public static class Shark{
        int x;
        int y;
        int s;
        int d;
        int z;

        public Shark(int x, int y, int s, int d, int z) {
            this.x = x;
            this.y = y;
            this.s = s;
            this.d = d;
            this.z = z;
        }
    }
}