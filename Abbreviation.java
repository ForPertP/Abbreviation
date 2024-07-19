import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'abbreviation' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING a
     *  2. STRING b
     */

    public static String abbreviation(String a, String b) {
        int aSize = a.length();
        int bSize = b.length();
        
        boolean[][] isAbbreviable = new boolean[aSize + 1][bSize + 1];
        
        isAbbreviable[0][0] = true;
        
        for (int i = 1; i <= aSize && Character.isLowerCase(a.charAt(i - 1)); ++i)
            isAbbreviable[i][0] = true;

        for (int i = 1; i <= aSize; ++i)
        {
            for (int j = 1; j <= bSize; ++j)
            {
                if (Character.isLowerCase(a.charAt(i - 1)) && isAbbreviable[i - 1][j])
                    isAbbreviable[i][j] = true;
                    
                if (isAbbreviable[i - 1][j - 1] && (Character.toUpperCase(a.charAt(i - 1)) == b.charAt(j - 1) || a.charAt(i - 1) == b.charAt(j - 1)))
                    isAbbreviable[i][j] = true;
            }
        }
        
        return isAbbreviable[aSize][bSize] ? "YES" : "NO";
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                String a = bufferedReader.readLine();

                String b = bufferedReader.readLine();

                String result = Result.abbreviation(a, b);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
