import java.io.*;
import java.util.*;

public class BJ16235{

    public static int N, M, K;
    public static int[][] ground;
    public static int[][] A;
    public static PriorityQueue<Tree> trees = new PriorityQueue<>();

    public static Queue<Tree> deadTrees = new LinkedList<>();
    public static int[][] near = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};


    public static void main(String args[]) throws IOException {
        getInput();
        while (K-- > 0) oneYear();
        System.out.println(trees.size());
    }

    public static void oneYear() {
        spring();
        summer();
        autumn();
        winter();
    }

    public static void spring() {
        int count = trees.size();
        Queue<Tree> newTrees = new LinkedList<>();

        for (int i = 0; i < count; i++) {
            Tree t = trees.poll();
            if (ground[t.x][t.y] >= t.age) {
                ground[t.x][t.y] -= t.age;
                t.age++;
                newTrees.add(t);
            }
            else {
                deadTrees.add(t);
            }
        }

        while(!newTrees.isEmpty()){
            trees.add(newTrees.poll());
        }
    }

    public static void summer() {
        while(!deadTrees.isEmpty()){
            Tree t = deadTrees.poll();
            ground[t.x][t.y] += (int)(t.age / 2);
        }
    }


    public static void autumn() {
        Queue<Tree> tempTrees = new LinkedList<>();
        for (Tree t : trees) {
            if (t.age % 5 == 0) {
                tempTrees.add(t);
            }
        }

        while (!tempTrees.isEmpty()) {
            Tree t = tempTrees.poll();
            for (int i = 0; i < 8; i++) {
                int nx = t.x + near[i][0];
                int ny = t.y + near[i][1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    trees.add(new Tree(nx, ny, 1));
                }
            }
        }
    }

    public static void winter() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ground[i][j] += A[i][j];
            }
        }
    }

    public static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        ground = new int[N][N];
        A = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                ground[i][j] = 5;
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            int age = Integer.parseInt(st.nextToken());
            trees.add(new Tree(x, y, age));
        }

        br.close();
    }

    public static class Tree implements Comparable<Tree> {
        int x;
        int y;
        int age;

        public Tree(int x, int y, int age) {
            this.x = x;
            this.y = y;
            this.age = age;
        }

        @Override
        public int compareTo(Tree o) {
            return Integer.compare(this.age, o.age);
        }
    }
}