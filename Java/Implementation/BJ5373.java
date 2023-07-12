import java.util.*;
import java.io.*;

public BJ5373 Main {
    
    public static int[] sideEdges = {0,1,2,5,8,7,6,3};
     
    //b = 0 1 2 3 : 상 우 하 좌(시계방향)
    //neighborhood[a][b] a번 면의 b방향 이웃면
    public static char[][] neighborhood = 
    {{1, 5, 3, 4}, {2, 5, 0, 4}, {1, 4, 3, 5},
     {2, 4, 0, 5}, {1, 0, 3, 2}, {1, 2, 3, 0}};
     
    //blocks[a][b][c] a번 면이 neighborhood[a][b] 면과 닿는 모서리 시계방향
    public static char[][][] blocks =
    {{{6,7,8},{0,3,6},{6,7,8},{8,5,2}},
     {{2,1,0},{2,1,0},{2,1,0},{2,1,0}},
     {{2,1,0},{0,3,6},{2,1,0},{8,5,2}},
     {{6,7,8},{6,7,8},{6,7,8},{6,7,8}},
     {{0,3,6},{0,3,6},{8,5,2},{8,5,2}},
     {{8,5,2},{0,3,6},{0,3,6},{8,5,2}}};
    
    //cube[a][b][c] a번 면의 b번째 블럭
    public static char[][] oriCube =
    {{'r','r','r','r','r','r','r','r','r'},
     {'w','w','w','w','w','w','w','w','w'},
     {'o','o','o','o','o','o','o','o','o'},
     {'y','y','y','y','y','y','y','y','y'},
     {'g','g','g','g','g','g','g','g','g'},
     {'b','b','b','b','b','b','b','b','b'}};
     
    public static char[][] cube;
     
    public static void main(String args[]) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
      
        int t = Integer.parseInt(st.nextToken());
      
        while(t-- > 0){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            
            cube = new char[6][9];
            for(int i = 0 ; i < 6; i++){
                for(int j = 0; j < 9; j++){
                    cube[i][j] = oriCube[i][j];
                }
            }
            
            for(int i= 0 ; i < n ; i++){
                String line = st.nextToken();
                int side = findSide(line.charAt(0));
                int dir = (line.charAt(1) == '+') ? 1 : -1;
                turnCube(side, dir);
            }
            printAnswer(bw);
        }
        br.close();
        
        bw.flush();
        bw.close();
    }
    
    private static void turnCube(int side, int dir){

        turnSide(side, dir);
        
        turnEdge(side, dir);
    }
    
    private static void turnEdge(int side, int dir){
        char[] before = new char[3];
        for(int j = 0 ; j < 3 ; j++){
            before[j] 
            = cube[neighborhood[side][0]][blocks[side][0][j]];
        }
        
        int beforeEdge = (4 - dir) % 4; 
        int edge = 0;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                cube[neighborhood[side][edge]][blocks[side][edge][j]] 
                = cube[neighborhood[side][beforeEdge]][blocks[side][beforeEdge][j]];
            }
            edge = beforeEdge;
            beforeEdge = (4 + beforeEdge - dir) % 4; 
        }
        
        for(int j = 0 ; j < 3 ; j++){
            cube[neighborhood[side][edge]][blocks[side][edge][j]] = before[j];
        }
    }
    
    private static void turnSide(int side, int dir){
        char[] cubeSideBlocks = new char[8];
        for(int i = 0; i < 8 ; i++){
            cubeSideBlocks[i] = cube[side][sideEdges[i]];
        }
        
        for(int i = 0 ; i < 8; i++){
            cube[side][sideEdges[i]] = cubeSideBlocks[(i - dir * 2 + 8) % 8];
        }
    }
    
    private static void printAnswer(BufferedWriter bw) throws IOException{
        for(int i = 0; i < 3; i++){
            for(int j = i * 3 ; j < i * 3 + 3 ; j++){
                bw.write(cube[1][j]);
            }
            bw.write("\n");
        }
    }
    
    private static int findSide(char side){
        switch(side){
        case 'F' : return 0;
        case 'U' : return 1;
        case 'B' : return 2;
        case 'D' : return 3;
        case 'L' : return 4;
        case 'R' : return 5;
        default: return -1;    
        }
    }
}