#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string abbreviation(string a, string b)
{
    const std::size_t aSize = a.size();
    const std::size_t bSize = b.size();
    
    std::vector<std::vector<bool>> isAbbreviable(aSize + 1, std::vector<bool>(bSize + 1, false));
    
    isAbbreviable[0][0] = true;
    
    for (std::size_t i = 1; i <= aSize && std::islower(a[i - 1]); ++i) 
        isAbbreviable[i][0] = true;

    for (std::size_t i = 1; i <= aSize; ++i)
    {
        for (std::size_t j = 1; j <= bSize; ++j)
        {
            if (std::islower(a[i - 1]) && isAbbreviable[i - 1][j])
                isAbbreviable[i][j] = true;
                
            if (isAbbreviable[i - 1][j - 1] && (std::toupper(a[i - 1]) == b[j - 1] || a[i - 1] == b[j - 1]))
                isAbbreviable[i][j] = true;
        }
    }
    
    return isAbbreviable[aSize][bSize] ? "YES" : "NO";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
