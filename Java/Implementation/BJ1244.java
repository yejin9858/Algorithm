import java.io.*;
import java.util.*;

public class BJ1244{
    private static int[] switchs;
    private static int switchCount;
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        switchCount = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        
        switchs = new int[switchCount+1];
        for(int i = 1 ; i <= switchCount ; i++){
            switchs[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        
        int studentCount = Integer.parseInt(st.nextToken());
        for(int i = 0 ; i < studentCount ; i++){
        st = new StringTokenizer(br.readLine());
            int sex = Integer.parseInt(st.nextToken());
            int switchNum = Integer.parseInt(st.nextToken());
            
            changeSwtichStatus(sex, switchNum);
        }
        
        for(int i = 1 ; i <= switchCount ;){
            for(int j = 0; j < 20 && i<= switchCount; j++, i++){
                bw.write(switchs[i] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
    
    private static void changeSwtichStatus(int sex, int switchNum){
        if(sex == 1){
            for(int i = switchNum ; i <= switchCount ; i+=switchNum)
                switchs[i] = switchs[i] == 1 ? 0 : 1;
        }else{
            switchs[switchNum] = switchs[switchNum] == 1 ? 0 : 1;
            for(int i = 1; switchNum - i > 0 && switchNum + i <= switchCount; i++){
                if(switchs[switchNum-i] == switchs[switchNum+i]){
                    switchs[switchNum-i]  = switchs[switchNum-i] == 1 ? 0 : 1;
                    switchs[switchNum+i]  = switchs[switchNum+i] == 1 ? 0 : 1;
                }
                else break;
            }
        }
    }
}