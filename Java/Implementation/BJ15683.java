import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;

public class Main {

    static int N;
    static int M;
    static int[][] office;
    static List<CCTV> cctvList = new ArrayList<>();
    static int cctvCount;
    static int ans = 100;
    static int[] xUnit = {0, 1, 0, -1};
    static int[] yUnit = {1, 0, -1, 0};

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        office = new int[N][M];

        for(int i = 0; i < N ; i ++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M ; j++){
                office[i][j] = Integer.parseInt(st.nextToken());
                if(office[i][j] != 0 && office[i][j] != 6)
                    cctvList.add(new CCTV(office[i][j], i, j));
            }
        }
        br.close();

        cctvCount = cctvList.size();
        checkCCTV(0);
        System.out.println(ans);
    }

    private static void checkCCTV(int index){

        if(index== cctvCount){
            ans = Math.min(countBlindSpot(), ans);
            return;
        }

        CCTV cctv = cctvList.get(index);
        int[][] officeCopy = new int[N][M];
        copyOffice(officeCopy);
        switch(cctv.num){
            case 1:
                for(int i = 0; i < 4 ; i ++){
                    cctv1(i, cctv);
                    checkCCTV(index + 1);
                    copyOfficeCopy(officeCopy);
                }
                break;
            case 2:
                for(int i = 0; i < 2 ; i ++){
                    cctv2(i, cctv);
                    checkCCTV(index + 1);
                    copyOfficeCopy(officeCopy);
                }
                break;
            case 3:
                for(int i = 0; i < 4 ; i ++){
                    cctv3(i, cctv);
                    checkCCTV(index + 1);
                    copyOfficeCopy(officeCopy);
                }
                break;
            case 4:
                for(int i = 0; i < 4 ; i ++){
                    cctv4(i, cctv);
                    checkCCTV(index + 1);
                    copyOfficeCopy(officeCopy);
                }
                break;
            case 5:
                cctv5(cctv);
                checkCCTV(index + 1);
                break;
        }
    }

    private static void cctv1(int i, CCTV cctv){
        markCCTVZone(cctv.x + xUnit[i], cctv.y + yUnit[i], xUnit[i], yUnit[i]);
    }

    private static void cctv2(int i, CCTV cctv){
        markCCTVZone(cctv.x + xUnit[i], cctv.y + yUnit[i], xUnit[i], yUnit[i]);
        markCCTVZone(cctv.x - xUnit[i], cctv.y - yUnit[i], -1 * xUnit[i], -1 * yUnit[i]);
    }

    private static void cctv3(int i, CCTV cctv){
        markCCTVZone(cctv.x + xUnit[i], cctv.y + yUnit[i], xUnit[i], yUnit[i]);
        markCCTVZone(cctv.x + xUnit[(i+1)%4], cctv.y + yUnit[(i+1)%4], xUnit[(i+1)%4], yUnit[(i+1)%4]);
    }

    private static void cctv4(int i, CCTV cctv){
        markCCTVZone(cctv.x + xUnit[i], cctv.y + yUnit[i], xUnit[i], yUnit[i]);
        markCCTVZone(cctv.x + xUnit[(i+1)%4], cctv.y + yUnit[(i+1)%4], xUnit[(i+1)%4], yUnit[(i+1)%4]);
        markCCTVZone(cctv.x + xUnit[(i+2)%4], cctv.y + yUnit[(i+2)%4], xUnit[(i+2)%4], yUnit[(i+2)%4]);
    }

    private static void cctv5(CCTV cctv){
        for(int i = 0 ; i < 4  ; i ++){
            markCCTVZone(cctv.x + xUnit[i], cctv.y + yUnit[i], xUnit[i], yUnit[i]);
        }
    }

    private static void markCCTVZone(int x, int y, int ux, int uy){
        for(;x >= 0 && x < N && y >= 0 && y < M; x+= ux, y+= uy){
            if(office[x][y] == 6)
                break;
            else if(office[x][y] == 0)
                office[x][y] = 7;
        }
    }

    private static void copyOffice(int[][] officeCopy){
        for(int i = 0; i < N ; i ++)
            for(int j = 0; j < M ; j++)
                officeCopy[i][j] = office[i][j];
    }

    private static void copyOfficeCopy(int[][] officeCopy){
        for(int i = 0; i < N ; i ++)
            for(int j = 0; j < M ; j++)
                office[i][j] = officeCopy[i][j];
    }

    private static int countBlindSpot(){
        int count= 0;
        for(int i = 0; i < N ; i ++) {
            for (int j = 0; j < M; j++)
                if(office[i][j] == 0)
                    count++;
        }
        return count;
    }

    static class CCTV{
        int num;
        int x;
        int y;

        CCTV(int num, int x, int y){
            this.num = num;
            this.x = x;
            this.y = y;
        }
    }
}