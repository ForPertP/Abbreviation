using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'abbreviation' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING a
     *  2. STRING b
     */

    public static string abbreviation(string a, string b)
    {
        int aSize = a.Length;
        int bSize = b.Length;
        
        bool[,] isAbbreviable = new bool[aSize + 1, bSize + 1];
        
        isAbbreviable[0, 0] = true;
        
        for (int i = 1; i <= aSize && char.IsLower(a[i - 1]); ++i)
            isAbbreviable[i, 0] = true;

        for (int i = 1; i <= aSize; ++i)
        {
            for (int j = 1; j <= bSize; ++j)
            {
                if (char.IsLower(a[i - 1]) && isAbbreviable[i - 1, j])
                    isAbbreviable[i, j] = true;
                    
                if (isAbbreviable[i - 1, j - 1] && (char.ToUpper(a[i - 1]) == b[j - 1] || a[i - 1] == b[j - 1]))
                    isAbbreviable[i, j] = true;
            }
        }
        
        return isAbbreviable[aSize, bSize] ? "YES" : "NO";
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int q = Convert.ToInt32(Console.ReadLine().Trim());

        for (int qItr = 0; qItr < q; qItr++)
        {
            string a = Console.ReadLine();

            string b = Console.ReadLine();

            string result = Result.abbreviation(a, b);

            textWriter.WriteLine(result);
        }

        textWriter.Flush();
        textWriter.Close();
    }
}
