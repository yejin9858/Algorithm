import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class BJ1339 {
    
    public static int N;
    public static String[] words;
    public static int[] alphabets = new int[26];
    
    public static void main(String args[]) throws IOException{
        getInput();
        assignNum();
        System.out.println(calculate());
    }
    
    private static int calculate(){
        int answer = 0;
        Arrays.sort(alphabets);
        for(int i = 25,num = 9;; i--){
            if(alphabets[i] == 0) break;
            answer += alphabets[i] * num--;
        }
        return answer;
    }
    
    private static void assignNum(){
        for(int i = 0 ; i <  N ; i++){
            char[] chars = words[i].toCharArray();
            int wordLength = words[i].length();
            int weight = (int)Math.pow(10, wordLength-1);
            for(int j = 0 ; j < wordLength ; j++, weight/=10 ){
                alphabets[chars[j] - 'A'] += weight;
            }
        }
    }
    
    public static void getInput() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        words = new String[N];
        
        for(int i = 0 ; i < N; i ++){
            st = new StringTokenizer(br.readLine());
            words[i] = st.nextToken();
        }
        br.close();
    
    }
}