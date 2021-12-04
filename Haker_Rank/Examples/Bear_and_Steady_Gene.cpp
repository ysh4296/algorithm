#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */
int A = 0;
int T = 0;
int G = 0;
int C = 0;
void fill_ATGC(string gene){
    for (int i = 0 ; i < (int)gene.size() ; i++){
        if(gene[i] == 'A'){
            A++;
        } else if (gene[i] == 'T'){
            T++;
        } else if (gene[i] == 'G'){
            G++;
        } else {
            C++;
        }
    }
}
int steadyGene(string gene) {
    int return_val = 50000000;
    fill_ATGC(gene);
    int start = -1 ;
    int end = -1;
    int standard = (A+T+G+C)/4;
    while(start < (int)gene.size() && end < (int)gene.size()){
        if(A > standard || T > standard || G > standard || C > standard){
            // end to forward
            if(end < (int)gene.size()){
                end++;
                if(gene[end] == 'A'){
                    A--;
                } else if (gene[end] == 'T'){
                    T--;
                } else if (gene[end] == 'G'){
                    G--;
                } else {
                    C--;
                }
            }
        } else {
            if(return_val > end - start + 1){
                return_val = end - start + 1;
            }
            //start to forward
            if(start == -1){
                start++;
                continue;
            }
            if(start < (int)gene.size()){
                if(gene[start] == 'A'){
                    A++;
                } else if (gene[start] == 'T'){
                    T++;
                } else if (gene[start] == 'G'){
                    G++;
                } else {
                    C++;
                }
                start++;
            }
        }
    }
    return return_val;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

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
