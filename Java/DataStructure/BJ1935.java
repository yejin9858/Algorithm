import java.io.*;
import java.util.*;

public class BJ1935{
    private static double[] alphabets;
    private static int N;
    private static Stack<Double> s = new Stack<>();
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        alphabets = new double[N];
        
        st = new StringTokenizer(br.readLine());
        String expression = st.nextToken();
        for(int i = 0 ; i < N ; i++){
            st = new StringTokenizer(br.readLine());
            alphabets[i] = Double.parseDouble(st.nextToken());

            
        }
        
        for(char c : expression.toCharArray()){
            if(c >= 'A' && c <= 'Z'){
                s.push(alphabets[c - 'A']);
            }
            else{
                double n2 = s.pop();
                double n1 = s.pop();
                s.push(calculate(n1, n2, c));
            }
        }
        
        System.out.printf("%.2f", Math.round(s.pop() * 100) /(double)100);
        
    }
    
    private static double calculate(double n1, double n2, char op){
        switch(op){
        case '+': 
            return n1 + n2;
        case '-': 
            return n1 - n2;
        case '*':
            return n1 * n2;
        default:
            return n1 / n2;
        }
    }
}