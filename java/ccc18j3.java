import java.io.BufferedReader;import java.io.IOException;import java.io.InputStreamReader;import java.util.StringTokenizer;public class Main {public static void main(String[] args) throws IOException {BufferedReader br = new BufferedReader(new InputStreamReader(System.in));int cities[] = new int[5], total = 0;StringTokenizer token = new StringTokenizer(br.readLine());for(int i = 1; i < 5; i++) {total += Integer.parseInt(token.nextToken());cities[i] = total;}for(int i = 0; i < 5; i++) {int[] line = new int[5];for(int j = 0; j < 5; j++){line[j] = Math.abs(cities[j] - cities[i]);}System.out.printf("%d %d %d %d %d\n", line[0], line[1], line[2], line[3], line[4]);}}}