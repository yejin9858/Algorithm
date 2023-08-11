import java.io.*;
import java.util.*;

public class BJ20125 {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        
        char[][] cookie = new char[N][N];
        for(int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            String line = st.nextToken();
            for(int j = 0; j < N ; j++){
                cookie[i][j] = line.charAt(j);
            }
        }
        
        boolean flag = false;
        int heartX = 0, heartY = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0; j < N ; j++){
                if(cookie[i][j] == '*'){
                    heartX = i + 1;
                    heartY = j;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        int rArm = 0, lArm = 0;
        for(int i = heartY -1; i >= 0 ; i--){
            if(cookie[heartX][i] == '_') break;
            lArm ++;
        }
        
        for(int i = heartY + 1; i < N ; i++){
            if(cookie[heartX][i] == '_') break;
            rArm ++;
        }
        
        int waist = 0;
        for(int i = heartX + 1; i < N ; i++){
            if(cookie[i][heartY] == '_') break;
            waist++;
        }
        
        int rLeg = 0, lLeg = 0;
        for(int i = heartX + waist +1; i < N ; i++){
            if(cookie[i][heartY - 1] == '_') break;
            lLeg++;
        }
        for(int i = heartX + waist +1; i < N ; i++){
            if(cookie[i][heartY + 1] == '_') break;
            rLeg++;
        }
        System.out.println((heartX+1) + " " + (heartY+1));
        System.out.println(lArm + " " + rArm + " " + waist + " " + lLeg + " " + rLeg);
    }
}