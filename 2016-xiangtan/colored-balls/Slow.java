import java.math.*;
import java.io.*;
import java.util.*;

public class Slow {
    public static void main(String[] args) {
        new Slow().run();
    }

    String format(BigInteger p, BigInteger q) {
        BigInteger g = p.gcd(q);
        p = p.divide(g);
        q = q.divide(g);
        return String.format("%d/%d", p, q);
    }

    public void run() {
        InputReader reader = new InputReader(System.in);
        PrintWriter writer = new PrintWriter(System.out);
        try {
            while (true) {
                int a = reader.nextInt();
                int b = reader.nextInt();
                int c = reader.nextInt();
                BigInteger[][][] ways = new BigInteger[a + 1][b + 1][c + 1];
                for (int i = 0; i <= a; ++ i) {
                    for (int j = 0; j <= b; ++ j) {
                        Arrays.fill(ways[i][j], BigInteger.ZERO);
                    }
                }
                ways[a][b][c] = BigInteger.ONE;
                for (int i = a; i >= 1; -- i) {
                    for (int j = b; j >= 1; -- j) {
                        for (int k = c; k >= 1; -- k) {
                            ways[i - 1][j][k] = ways[i - 1][j][k].add(ways[i][j][k].multiply(BigInteger.valueOf(i)));
                            ways[i][j - 1][k] = ways[i][j - 1][k].add(ways[i][j][k].multiply(BigInteger.valueOf(j)));
                            ways[i][j][k - 1] = ways[i][j][k - 1].add(ways[i][j][k].multiply(BigInteger.valueOf(k)));
                        }
                    }
                }
                int n = a + b + c;
                BigInteger[] factorial = new BigInteger[n + 1];
                factorial[0] = BigInteger.ONE;
                for (int i = 1; i <= n; ++ i) {
                    factorial[i] = factorial[i - 1].multiply(BigInteger.valueOf(i));
                }
                BigInteger[] result = new BigInteger[3];
                Arrays.fill(result, BigInteger.ZERO);
                for (int i = 0; i <= a; ++ i) {
                    for (int j = 0; j <= b; ++ j) {
                        for (int k = 0; k <= c; ++ k) {
                            int[] count = new int[]{i, j, k};
                            int p = 0;
                            while (p < 3 && count[p] > 0) {
                                p ++;
                            }
                            if (p < 3) {
                                result[p] = result[p].add(ways[i][j][k].multiply(factorial[i + j + k]));
                            }
                        }
                    }
                }
                writer.println(format(result[0], factorial[n]) + " " + format(result[1], factorial[n]) + " " + format(result[2], factorial[n]));
            }
        } catch (IOException e) {
        } finally {
            writer.close();
        }
    }

    class InputReader {
        InputReader(InputStream in) {
            this.reader    = new BufferedReader(new InputStreamReader(in));
            this.tokenizer = new StringTokenizer("");
        }

        public String nextToken() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                String line = reader.readLine();
                if (line == null) {
                    throw new IOException();
                }
                tokenizer = new StringTokenizer(line);
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        private BufferedReader  reader;
        private StringTokenizer tokenizer;
    }

    private void debug(Object...o) {
        System.err.println(Arrays.deepToString(o));
    }
}
