import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
public class BJ14891 {
    
    public static int[][] gear = new int[4][8];
    public static int[][] gearSet = {{2,6},{2,6},{2,6}};
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int i = 0; i < 4; i++) {
            st = new StringTokenizer(br.readLine());
            String gearPole = st.nextToken();
            int j = 0;
            for(char c : gearPole.toCharArray()){
                gear[i][j++] = c - '0';
            }
        }
        
        st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        for(int i = 0 ; i < K ; i++){
            st = new StringTokenizer(br.readLine());
            int gearNum = Integer.parseInt(st.nextToken()) - 1;
            int dir = Integer.parseInt(st.nextToken());
            turn(gearNum,  dir, 0);
        }
        
        br.close();
        
        System.out.println(calculateScore());
    }
    
    private static void turn(int num, int dir,int bf) {
        int poleL = (num + 1 < 4) ? gear[num][gearSet[num][0]] : 0;
        int poleR = (num - 1 >= 0) ? gear[num][gearSet[num-1][1]] : 0;
        turnGear(num, dir);
        if(num + 1 < 4 && bf != 1){
            if(poleL != gear[num + 1][gearSet[num][1]]){
                turn(num+1, -1 * dir, -1);
            }
        }
        if(num - 1 >= 0 && bf != -1){
            if(gear[num - 1][gearSet[num-1][0]] != poleR){
                turn(num-1, -1 * dir, 1);
            }
        }

    }
    private static void turnGear(int num, int dir) {
        switch(num){
        case 0:
            gearSet[0][0] = (gearSet[0][0] + 8 - dir)%8;
            break;
        case 1:case 2:
            gearSet[num-1][1] = (gearSet[num-1][1] + 8 - dir)%8;
            gearSet[num][0] = (gearSet[num][0] + 8 - dir)%8;
            break;
        case 3:
            gearSet[2][1] = (gearSet[2][1] + 8 - dir)%8;
            break;
        }
    }

    private static int calculateScore(){
        return gear[0][(gearSet[0][0] + 6)%8]
                + gear[1][(gearSet[0][1] + 2)%8] * 2
                + gear[2][(gearSet[1][1] + 2)%8] * 4
                + gear[3][(gearSet[2][1] + 2)%8] * 8;
    } 
}