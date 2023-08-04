import java.io.*;
import java.util.*;

public class BJ9017 {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int T = Integer.parseInt(st.nextToken());
        while(T-- > 0){
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            
            st = new StringTokenizer(br.readLine());
            Map<Integer, Integer> freq = new HashMap<>();
            int[] men = new int[N];
            for(int i = 0 ; i < N ;  i ++){
                men[i] = Integer.parseInt(st.nextToken());
                int now = 0;
                if(freq.containsKey(men[i]))
                    now = freq.get(men[i]);
                freq.put(men[i], now+1);
                // System.out.println("put" + men[i] +" " + now);
            }
            
            Map<Integer, Team> teams = new HashMap<>();
            for(int i = 0, j = 1; i < N; i++){
                Team team;
                if(teams.containsKey(men[i])){
                    team = teams.get(men[i]);
                }
                else{
                    if(freq.get(men[i]).equals(6)){
                        team = new Team(men[i]);
                    }
                    else continue;
                }
                
                team.man++;
                if(team.man >= 5) {
                    if(team.man == 5){
                        team.score5 = j;
                    }
                    j++;
                    continue;
                }
                
                team.score += j++;
                teams.put(men[i], team);
                // System.out.println("put" + team.teamNum + " " + team.score);
            }
            
            ArrayList<Team> teamList = new ArrayList<>(teams.values());
            Collections.sort(teamList);
            // for(int i = 0 ; i < teamList.size() ; i++){
            //     System.out.println(teamList.get(i).teamNum + " " + teamList.get(i).score + " " + teamList.get(i).score5);
            // }
            bw.write(teamList.get(0).teamNum + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
    
    private static class Team implements Comparable<Team> {
        int teamNum;
        int man;
        int score;
        int score5;
        
        public Team(int teamNum){
            this.teamNum = teamNum;
            man = 0;
            score = 0;
            score5 = 0;
        }
        
        @Override
        public int compareTo(Team o) {
            if(this.score > o.score)    return 1;
            else if(this.score == o.score){
                if(this.score5 > o.score5)    return 1;
                else    return -1;
            }
            else    return -1;
        }
    }
}