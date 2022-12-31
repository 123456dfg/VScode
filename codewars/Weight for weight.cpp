#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include <numeric>
#include<iterator>
using namespace std;
bool mysort(string s1, string s2){
        auto sum=[](int acc,const char c){return acc+static_cast<int>(c-48);};
        int left=accumulate(s1.begin(),s1.end(),0,sum);
        int right=accumulate(s2.begin(),s2.end(),0,sum);
        if(left==right)return s1<s2;
        else return left<right;
    }
class WeightSort{
public:
    static std::string orderWeight(const std::string &strng){
        vector<string>v;
        istringstream iss(strng);
        copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(v));
        sort(v.begin(),v.end(),mysort);
        ostringstream oss;
        copy(v.begin(),v.end(),ostream_iterator<string>(oss," "));
        string s=oss.str();
        return s.substr(0,s.size()-1);
    }
    
};