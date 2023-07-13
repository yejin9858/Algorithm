import java.io.*;
import java.util.*;

public class Main {

    public static int R, C, T, ans = 0;
    public static int uPurifier =0;
    public static int dPurifier =0;
    public static int room[][];
    public static int copyRoom[][];

    public static int[] xUnit = {0, 1, 0, -1};
    public static int[] yUnit = {1, 0, -1, 0};

    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        room = new int[R][C];
        copyRoom = new int[R][C];

        for(int i = 0; i< R ; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < C; j++){
                room[i][j] = Integer.parseInt(st.nextToken());
                if(room[i][j] == -1) {
                    if(uPurifier == 0) uPurifier = i;
                    else dPurifier = i;
                }
            }
        }

        while(T-- > 0){
            //확산
            for(int i = 0 ; i < R; i++){
                for(int j = 0 ; j < C; j++){
                    if(room[i][j] != 0) spread(i, j);
                }
            }
            for(int i = 0 ; i < R; i++){
                for(int j = 0 ; j < C; j++){
                    room[i][j] = copyRoom[i][j];
                }
            }
            initCopyRoom();

            //공기청정기
            cleaning(uPurifier, 0, 0, -1, -1);
            cleaning(dPurifier, 0, 0, 1, -1);
        }

        for(int i = 0 ; i < R; i++){
            for(int j = 0 ; j < C; j++){
                ans += room[i][j];
            }
        }

        System.out.println(ans + 2);

    }

    private static void cleaning(int i, int j, int direction, int ud, int bf) {

        if((ud == -1 && direction == 1 && i == uPurifier) || (ud == 1 && direction == 3 &&  i== dPurifier)){
            return;
        }
        int next = (room[i][j] == -1) ? 0 : room[i][j];
        room[i][j] = bf;

        int x = i + xUnit[direction];
        int y = j + yUnit[direction];

        if (x >= 0 && x < R && y >= 0 && y < C
            && ((ud == -1 && x <= uPurifier) || (ud == 1 && x >= dPurifier))) {
            cleaning(x, y, direction, ud, next);
        }
        else {
            int newDirection = (direction + ud + 4) % 4;
            cleaning(i + xUnit[newDirection], j + yUnit[newDirection], newDirection, ud, next);
        }
    }

    private static void spread(int i, int j){
        int mise =  room[i][j];
        int way = 0;

        for (int k = 0; k < 4; k++) {
            int x = i + xUnit[k];
            int y = j + yUnit[k];
            if (x >= 0 && x < R && y >= 0 && y < C && room[x][y] != -1) {
                way ++;
                copyRoom[x][y] += mise/5;
            }
        }

        copyRoom[i][j] += mise - (mise/5) * way;
    }

    private static void initCopyRoom(){
        for(int i = 0 ; i < R ; i ++){
            for(int j = 0; j < C; j++){
                copyRoom[i][j] = 0;
            }
        }
    }
}