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

string abbreviation(const std::string & a, const std::string & b)
{
    const std::size_t a_size(a.size());
    const std::size_t b_size(b.size());
    
    std::vector<std::vector<bool>> 
        can_abbre(a_size+1, std::vector<bool>(b_size+1,false));
        
    can_abbre[0][0] = true;
    
    for (std::size_t i = 1; i <= a_size && std::islower(a[i-1]); ++i) 
        can_abbre[i][0] = true ;

    for (std::size_t i = 1; i <= a_size; ++i)
     {
        for (std::size_t j = 1; j <= b_size; ++j)
         {
            if (std::islower(a[i-1]) && can_abbre[i-1][j])
                can_abbre[i][j] = true;
                
            if (can_abbre[i-1][j-1] 
                && ( std::toupper(a[i-1])==b[j-1] || a[i-1]==b[j-1]) )
                can_abbre[i][j] = true;
        }
    }
    
    if (can_abbre[a_size][b_size])
        return "YES";
    else
        return "NO";
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




