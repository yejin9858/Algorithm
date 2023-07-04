import java.io.*;
import java.util.*;
    
public class Main {
    public static int N;
    public static int maxValue = 2;
    
    public static class Game{
        int[][] board;
        int bf;
        public Game(int[][] board){
            this.board = board;
        }
        
        int[][] turn(int dir){
            int[][] newBoard = new int[N][N];
            switch(dir){
            case 1:
                for(int i = 0 ; i < N ; i++){
                    for(int j = 0 ; j < N ; j ++){
                        newBoard[j][N-1-i] = board[i][j];
                    }
                }
                break;
            case 2:
                for(int i = 0 ; i < N ; i++){
                    for(int j = 0 ; j < N ; j ++){
                        newBoard[N-1-i][N-1-j] = board[i][j];
                    }
                }
                break;
            case 3:
                for(int i = 0 ; i < N ; i++){
                    for(int j = 0 ; j < N ; j ++){
                        newBoard[N-1-j][i] = board[i][j];
                    }
                }
                break;
            default:
                for(int i = 0 ; i < N ; i++){
                    for(int j = 0 ; j < N ; j ++){
                        newBoard[i][j] = board[i][j];
                    }
                }
                break;
            }
            return newBoard;
        }
        
        Game move(int dir){
            //돌리기
            int[][] nowBoard = turn(dir);
            
            //합치기
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N-1 ; j ++){
                    if(nowBoard[i][j] != 0){
                        for(int p = j+1 ; p < N ;p++){
                            if(nowBoard[i][p] == 0) {
                                continue;
                            }
                            if(nowBoard[i][j] == nowBoard[i][p]){
                                nowBoard[i][j] *=2;
                                maxValue = maxValue < nowBoard[i][j] ? nowBoard[i][j] : maxValue;
                                nowBoard[i][p] = 0;
                            }
                            j = p-1;
                            break;
                        }
                    }
                }
            }
            
            //이동
            for(int i = 0; i < N ; i++){
                int index = 0;
                for(int j = 0; j < N; j ++){
                    if(nowBoard[i][j] != 0){
                        int bf = nowBoard[i][index];
                        nowBoard[i][index++] = nowBoard[i][j];
                        nowBoard[i][j] = bf;
                    }
                }
            }
  
            return new Game(nowBoard);
        }
    }
    
    public static void main(String args[]) throws IOException{
      doGame(getInput(), 0);
      System.out.println(maxValue);
    }
    
    private static void doGame(Game game, int count){
        if(count >= 5) return;
        for(int dir = 0 ; dir < 4 ; dir++){
            doGame(game.move(dir), count + 1);
        }
    }
    
    private static Game getInput() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int[][] board = new int[N][N];
        for(int i = 0 ; i <  N ; i ++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < N ; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                maxValue = maxValue < board[i][j] ? board[i][j] : maxValue;
            }
        }
        br.close();
        return new Game(board);
    }
}