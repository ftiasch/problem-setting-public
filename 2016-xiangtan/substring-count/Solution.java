import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        new Solution().run();
    }

    public void run() {
        InputReader reader = new InputReader(System.in);
        PrintWriter writer = new PrintWriter(System.out);
        try {
            while (true) {
                int n = reader.nextInt();
                int q = reader.nextInt();
                char[] s = reader.nextToken().toCharArray();
                int l = n + 63 >> 6;
                BitSet[] mask = new BitSet[26];
                for (int i = 0; i < 26; ++ i) {
                    mask[i] = new BitSet();
                }
                for (int i = 0; i < n; ++ i) {
                    mask[s[i] - 'a'].set(i);
                }
                while (q > 0) {
                    q --;
                    int index = reader.nextInt() - 1;
                    if (index != -1) {
                        mask[s[index] - 'a'].clear(index);
                        s[index] = reader.nextToken().charAt(0);
                        mask[s[index] - 'a'].set(index);
                    } else {
                        String buffer = reader.nextToken();
                        BitSet result = (BitSet)mask[buffer.charAt(0) - 'a'].clone();
                        for (int i = 1; i < buffer.length(); ++ i) {
                            result.and(mask[buffer.charAt(i) - 'a'].get(i, n));
                        }
                        writer.println(result.cardinality());
                    }
                }
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
