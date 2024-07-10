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
